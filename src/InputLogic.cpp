//
// Created by ashley on 12/11/25.
//

#include "../include/InputLogic.h"

#include <fstream>
#include <iostream>
#include <readline/history.h>
#include <readline/readline.h>

#include "../include/registermachine.h"
#include "../include/Util.h"

extern Registermachine rm;

int fileInput(const std::string& filepath) {
    // bad :(
    const std::set<std::string> oneArgFuncs = {"END", "INC", "DEC"};
    rmcli::g_running = true;
    std::ifstream f(filepath);
    if (!f.is_open()) {
        std::cerr << "Could not open file '" << filepath.c_str() << "'" << std::endl;
        return 1;
    }

    std::string s;
    std::vector<std::string> lines;
    while (std::getline(f, s)) {
        lines.push_back(s);
    }

    while (rmcli::g_running) {
        std::vector<std::string> args = splitString(lines[rm.getCounter()], ' ');
        int val {};

        if (args.empty()) {
            rm.incCounter();
            std::cerr << rm.getCounter() << ": Empty line read, will be treated as instruction" << std::endl;
            continue;
        }

        if (!Registermachine::doesFunctionExist(args[0])) {
            std::cerr << rm.getCounter() + 1 << " | Fatal error: unknown function '" << args[0] << "'" << std::endl;
            std::exit(1);
        }

        if (args.size() == 1 && !oneArgFuncs.contains(args[0])) {
            std::cerr << rm.getCounter() + 1 << " | Fatal error: function '" << args[0] << "' requires an argument, but wasn't provided one" << std::endl;
            std::exit(1);
        }

        if (args.size() > 1) {
            try {
                val = std::stoi(args[1]);
            } catch (...) {
                std::cerr << rm.getCounter() + 1 << " | Fatal error: invalid argument entered '" << args[1] << "'" << std::endl;
                std::exit(1);
            }
        }

        Registermachine::matchFunctions(args[0], val);
    }

    f.close();
    return 0;
}

int interactiveInput() {
    // even fucking worse but im so, so eepy
    const std::set<std::string> oneArgFuncs = {"END", "INC", "DEC"};

    while (true) {
        char* raw = readline("rmcli> ");

        // exit if ctrl-d
        if (!raw) break;

        std::string line(raw);

        if (line.empty()) continue;

        if (!line.empty()) add_history(raw);
        free(raw);

        if (line == "quit" || line == "exit") break;

        std::vector<std::string> args = splitString(line, ' ');
        int val {};

        if (args.size() > 2) {
            std::cerr << "Error: too many arguments" << std::endl;
            args.clear();
            continue;
        }

        if (!Registermachine::doesFunctionExist(args[0])) {
            rm.incCounter();
            std::cerr << "Error: unknown function '" << args[0] << "'" << std::endl;
            continue;
        }

        if (args.size() == 1 && !oneArgFuncs.contains(args[0])) {
            rm.incCounter();
            std::cerr << "Error: function '" << args[0] << "' requires an argument, but wasn't provided one" << std::endl;
            continue;
        }

        if (args.size() > 1) {
            try {
                val = std::stoi(args[1]);
            } catch (...) {
                std::cerr << "Error: invalid argument entered '" << args[1] << "'" << std::endl;
                continue;
            }
        }

        Registermachine::matchFunctions(args[0], val);
    }

    return 0;
}
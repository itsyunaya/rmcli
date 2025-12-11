//
// Created by ashley on 02.12.25.
//

#include "Fileinput.h"

#include <fstream>
#include <set>
#include <vector>

#include "../registermachine.h"
#include "../util/Util.h"

extern Registermachine rm;

int fileinput(const std::string& filepath) {
    std::set<std::string> oneArgFuncs = {"END", "INC", "DEC"};

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

        // empty line handling
        if (args.empty()) {
            rm.incCounter();
            std::cerr << rm.getCounter() << ": Empty line read, will be treated as instruction" << std::endl;
            continue;
        }

        if (args.size() > 1 && !oneArgFuncs.contains(args[0])) {
            try {
                val = std::stoi(args[1]);
            } catch (const std::invalid_argument&) {
                std::cerr << rm.getCounter() + 1 << " | Fatal error: Invalid argument entered '" << args[1] << "'" << std::endl;
                std::exit(1);
            }

        } else if (!oneArgFuncs.contains(args[0])) {
            std::cerr << rm.getCounter() + 1 << " | Fatal error: Function '" << args[0] << "' requires an argument, but wasn't provided one" << std::endl;
            std::exit(1);
        }

        Registermachine::matchFunctions(args[0], val, 0);
    }

    f.close();
    return 0;
}
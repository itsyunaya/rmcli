//
// Created by ashley on 02.12.25.
//

#include "Fileinput.h"

#include <fstream>
#include <vector>

#include "../registermachine.h"
#include "../util/Util.h"

extern Registermachine rm;

int fileinput(const std::string& filepath) {
    running = true;
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

    while (running) {
        std::vector<std::string> args = splitString(lines[rm.getCounter()], ' ');
        int val {};

        // empty line handling
        if (args.empty()) {
            rm.incCounter();
            std::cerr << rm.getCounter() << ": Empty line read, will be treated as instruction." << std::endl;
            continue;
        }

        if (args.size() > 1) {
            try {
                val = std::stoi(args[1]);
            } catch (const std::invalid_argument&) {
                rm.incCounter();
                std::cerr << rm.getCounter() << ": Invalid argument entered '" << args[1] << "', ignoring instruction." << std::endl;
                continue;
            }
        }

        Registermachine::matchFunctions(args[0], val);
    }

    f.close();
    return 0;
}
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
        fprintf(stderr, "Could not open file '%s'\n", filepath.c_str());
        return 1;
    }

    std::string s;
    std::vector<std::string> lines;
    while (std::getline(f, s)) {
        lines.push_back(s);
    }

    while (running) {
        std::vector<std::string> args = splitString(lines[rm.getCounter()], ' ');
        int val = -1;

        // empty line handling
        // TODO: think about how to handle empty lines: if allowed will be considered as instruction
        if (args.empty()) {
            rm.incCounter();
            fprintf(stderr, "Empty line read: Will be treated as instruction.\n");
            continue;
        }

        if (args.size() > 1) {
            try {
                // TODO: if non-integer is entered stoi will silently fail and the function returns -1
                //  this is ok for instructions without second arg, but can cause weird behaviour otherwise
                val = std::stoi(args[1]);
            } catch (const std::invalid_argument&) {} // catch by doing nothing here as to make commenting instructions easier
        }

        Registermachine::matchFunctions(args[0], val);
    }

    return 0;
}
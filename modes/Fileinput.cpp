//
// Created by ashley on 02.12.25.
//

#include "Fileinput.h"

#include <fstream>
#include <iosfwd>
#include <vector>

#include "../registermachine.h"
#include "../util/Util.h"

extern Registermachine rm;

int fileinput(const std::string& filepath) {
    std::ifstream f(filepath);
    if (!f.is_open()) {
        fprintf(stderr, "Could not open file '%s'\n", filepath.c_str());
        return 1;
    }

    // TODO: any actual cpp dev would KILL me for this entire thing, eventually find a better implementation

    std::string s;
    std::vector<std::string> lines;
    while (std::getline(f, s)) {
        lines.push_back(s);
    }

    // TODO: infinite loop :(
    while (true) {
        for (int i = 0; i < lines.size(); i++) {
            if (i == rm.getCounter()) {
                std::vector<std::string> args = splitString(lines[i], ' ');
                int val = std::stoi(args[1]);
                rm.matchFunctions(args[0], val);
            }
        }
    }

    return 0;
}
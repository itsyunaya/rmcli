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

    // TODO: terrible and error prone, replace later
    std::string s;
    while (getline(f, s)) {
        std::vector<std::string> args = splitString(s, ' ');
        int val = stoi(args[1]);
        rm.matchFunctions(args[0], val);
    }
}

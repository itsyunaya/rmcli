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

    std::string s;
    std::size_t lineNum = 0;

    while (std::getline(f, s)) {
        std::vector<std::string> args = splitString(s, ' ');
        if (args.size() < 2) {
            fprintf(stderr, "Malformed line %zu: '%s'\n", lineNum, s.c_str());
            ++lineNum;
            continue;
        }

        // Check the counter at the moment we read this line.
        if (static_cast<std::size_t>(rm.getCounter()) == lineNum) {
            try {
                int val = std::stoi(args[1]);
                rm.matchFunctions(args[0], val);
            } catch (const std::exception& e) {
                fprintf(stderr, "Invalid integer on line %zu: %s\n", lineNum, e.what());
                return 1;
            }
        }

        ++lineNum;
    }

    return 0;
}

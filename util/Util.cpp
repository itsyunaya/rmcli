//
// Created by ashley on 02.12.25.
//

#include "Util.h"

#include <sstream>
#include <vector>
#include <tabulate/table.hpp>

std::vector<std::string> splitString(const std::string& input, const char delimiter) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int setupTable() {
    rm_outputs.format()
        .font_style({tabulate::FontStyle::bold})
        .border_top("─")
        .border_bottom("─")
        .border_left("│")
        .border_right("│")
        .corner("+")
        .width(11);

    rm_outputs.add_row({"AC", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10"});
    rm_outputs.add_row({});
    return 0;
}
//
// Created by ashley on 02.12.25.
//

#include "../include/Util.h"

#include <sstream>
#include <vector>
#include <tabulate/table.hpp>

#include "../include/registermachine.h"

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
    rm_outputs[1].format().multi_byte_characters(true);
    return 0;
}

void printTable(const int acc, const std::vector<int>& registers) {
    rm_outputs[1].cell(0).set_text(std::to_string(acc));

    for (int i = 1; i <= 10; i++) {
        if (registers[i] != 0) {
            std::string str = std::to_string(registers[i]);
            rm_outputs[1].cell(i).set_text(str);
        } else {
            rm_outputs[1].cell(i).set_text("undefined");
        }
    }

    const std::string out = rm_outputs.str();
    std::cout << out << std::endl;

    rm_outputs = tabulate::Table();
    setupTable();
}
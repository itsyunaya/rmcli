//
// Created by ashley on 02.12.25.
//

#include <sstream>
#include <vector>
#include "Util.h"

std::vector<std::string> splitString(const std::string& input, const char delimiter) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
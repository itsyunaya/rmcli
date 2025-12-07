//
// Created by ashley on 02.12.25.
//

#ifndef RMCLI_UTIL_H
#define RMCLI_UTIL_H

#include <string>
#include <vector>
#include <tabulate/table.hpp>

inline tabulate::Table rm_outputs;

std::vector<std::string> splitString(const std::string& input, char delimiter);

int setupTable();

#endif //RMCLI_UTIL_H
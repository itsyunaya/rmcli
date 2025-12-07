//
// Created by ashley on 12/1/25.
//

#include "InteractiveMode.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <readline/history.h>
#include <readline/readline.h>

#include "../registermachine.h"
#include "../util/Util.h"

extern Registermachine rm;

int interactive() {
    // TODO: while true is terrible, eventually replace with "while reading line"
    while (true) {
        char* raw = readline("rmcli> ");

        // exit if ctrl-d
        if (!raw) break;

        std::string line(raw);

        if (line.empty()) continue;

        if (!line.empty()) add_history(raw);
        free(raw);

        // TODO: add better exiting
        if (line == "quit" || line == "exit") break;

        std::vector<std::string> args = splitString(line, ' ');
        if (args.size() > 2) {
            std::cerr << "Too many arguments" << std::endl;
            args.clear();
            continue;
        }

        int val {};

        if (args.size() > 1) {
            try {
                val = std::stoi(args[1]);
            } catch (const std::invalid_argument&) {
                std::cerr << "Invalid argument entered '" << args[1] << "'" << std::endl;
                continue;
            }
        }

        Registermachine::matchFunctions(args[0], val);
    }

    return 0;
}

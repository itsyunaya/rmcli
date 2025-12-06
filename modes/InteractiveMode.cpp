//
// Created by ashley on 12/1/25.
//

#include "InteractiveMode.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>

#include "../registermachine.h"
#include "../util/Util.h"

extern Registermachine rm;

int interactive() {
    // while true is terrible, eventually replace with "while reading line"
    while (true) {
        char* raw = readline("rmcli> ");

        // exit if ctrl-d
        if (!raw) break;

        std::string line(raw);

        if (!line.empty()) add_history(raw);
        free(raw);

        // TODO: add better exiting, add output registers command
        if (line == "quit" || line == "exit") break;

        std::vector<std::string> args = splitString(line, ' ');
        if (args.size() > 2) {
            fprintf(stderr, "Too many arguments\n");
            args.clear();
        }

        // TODO: move input handling to a separate function maybe?
        //  so i dont have to write it TWICE
        try {
            const int val = std::stoi(args[1]);
            rm.matchFunctions(args[0], val);
        } catch (const std::exception& e) {
            // add actual error handling
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}

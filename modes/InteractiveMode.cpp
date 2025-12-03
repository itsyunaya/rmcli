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

        // exit when typing quit
        // TODO: add better exiting, like outputting all the registers
        if (line == "quit" || line == "exit") break;

        std::vector<std::string> args = splitString(line, ' ');
        if (args.size() > 2) {

            fprintf(stderr, "Too many arguments\n");
            args.clear();
        }

        // TODO: calling functions with just one parameter crashes this,
        //  because it always expects two, fix this
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

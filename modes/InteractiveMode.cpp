//
// Created by ashley on 12/1/25.
//

#include "InteractiveMode.h"

#include <iostream>
#include <string>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>

int InteractiveMode::run() {
    while (true) {
        char* raw = readline("rmcli> ");

        // exit if ctrl-d
        if (!raw) break;

        std::string line(raw);

        if (!line.empty()) add_history(raw);
        free(raw);

        // exit when typing quit
        // TODO: add better exiting, like outputting all the registers
        if (line == "quit") break;

        
    }

    return 0;
}

InteractiveMode::InteractiveMode() = default;

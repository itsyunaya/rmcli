#include "registermachine.h"
#include <getopt.h>
#include <iostream>

#include "modes/Fileinput.h"
#include "modes/InteractiveMode.h"
#include "util/Util.h"

Registermachine rm;

int main(const int argc, char *argv[]) {
    // TODO: this is slop, fix the headers so i can call functions normally

    int option;
    constexpr struct option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"interactive", no_argument, nullptr, 'i'},
        {"file", no_argument, nullptr, 'f'},
        {"debug", no_argument, nullptr, 'd'},
        {nullptr, 0, nullptr, 0}
    };

    while ((option = getopt_long(argc, argv, "hifd:", long_options, nullptr)) != -1) {
        switch (option) {
            case 'h': {
                printf("MEEP MAP\n");
                break;
            }

            case 'i': {
                std::cout << "interactive\n";
                interactive();
                break;
            }

            case 'f': {
                std::cout << "file\n";
                fileinput("input.txt");
                break;
            }

            case 'd': {
                setupTable();
            }

            default: {
                return 1;
            }
        }
    }

    return 0;
}

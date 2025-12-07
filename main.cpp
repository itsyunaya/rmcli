#include <cstring>
#include <getopt.h>
#include <iostream>

#include "registermachine.h"
#include "modes/Fileinput.h"
#include "modes/InteractiveMode.h"
#include "util/Util.h"

Registermachine rm;

int main(const int argc, char *argv[]) {
    const std::string ver = "1.0";

    int option;
    bool isInteractiveMode = false;
    bool isFileInputMode = false;
    const char* filepath = nullptr;

    if (argv[1] == nullptr) {
        std::cout
            << "rmcli - CLI Register Machine [version " << ver << "]\n\n"
            << "usage:      rmcli [options]\n\n"
            << "rmcli is a tool for simulating register machines in the commandline.\n"
            << "Hereby, two different modes can be used: interactive and file input.\n"
            << "For a listing of options, use rmcli --help.\n";
        return 0;
    }

    setupTable();

    constexpr struct option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"interactive", no_argument, nullptr, 'i'},
        {"file", required_argument, nullptr, 'f'},
        {"debug", no_argument, nullptr, 'd'},
        {nullptr, 0, nullptr, 0}
    };

    while ((option = getopt_long(argc, argv, "hif:d", long_options, nullptr)) != -1) {
        switch (option) {
            case 'h': {
                std::cout
                    << "rmcli - CLI Register Machine [version " << ver << "]\n\n"
                    << "options: \n"
                    << "    -i, --interactive       execute the tool in interactive mode\n"
                    << "    -f, --fileinput <path>  use a file as input for the register machine\n"
                    << "    -h, --help              prints this help menu\n\n"
                    << "register machine commands: \n"
                    // TODO: insert github link here
                    << "    for a full list with explanations, please consult the documentation under [insert github link]\n";
                break;
            }
            // TODO: the exclusivity logic here is slop, replace it eventually
            case 'i': {
                if (isFileInputMode) {
                    fprintf(stderr, "Error: -i/--interactive and -f/--fileinput are mutually exclusive.\n");
                    return 1;
                }
                isInteractiveMode = true;
                break;
            }

            case 'f': {
                if (isInteractiveMode) {
                    fprintf(stderr, "Error: -f/--fileinput and -i/--interactive are mutually exclusive");
                    return 1;
                }

                if (optarg == nullptr || std::strlen(optarg) == 0) {
                    fprintf(stderr, "Error: -f/--file requires a non-empty filepath\n");
                    return 1;
                }

                isFileInputMode = true;
                filepath = optarg;
                break;
            }

            #ifdef DEBUG
            case 'd': {
                setupTable();
                break;
            }
            #endif

            default: {
                return 1;
            }
        }
    }

    if (isInteractiveMode) {
        interactive();
    } else if (isFileInputMode) {
        fileinput(filepath);
    }

    return 0;
}
#include <cstring>
#include <getopt.h>
#include <iostream>

#include "registermachine.h"
#include "modes/Fileinput.h"
#include "modes/InteractiveMode.h"
#include "util/Util.h"

Registermachine rm;

int main(const int argc, char *argv[]) {
    int option;

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
                printf("MEEP MAP\n");
                break;
            }
            // TODO: make i and f mutually exclusive somehow
            case 'i': {
                interactive();
                break;
            }

            case 'f': {
                if (optarg == nullptr || std::strlen(optarg) == 0) {
                    fprintf(stderr, "Error: -f/--file requires a non-empty filepath\n");
                    return 1;
                }

                fileinput(optarg);
                break;
            }

            case 'd': {
                setupTable();
                break;
            }

            default: {
                return 1;
            }
        }
    }

    return 0;
}
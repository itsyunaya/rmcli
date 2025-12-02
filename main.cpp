#include "registermachine.h"
#include <getopt.h>
#include <iostream>

#include "modes/InteractiveMode.h"

int main(int argc, char *argv[]) {
    // Registermachine rm;
    // int state {1};
    // while (state == 1) {
    //     if (rm.getCounter() == 1) {rm.DLOAD(5);}
    //     if (rm.getCounter() == 2) {rm.STORE(1);}
    //     if (rm.getCounter() == 3) {rm.DLOAD(2);}
    //     if (rm.getCounter() == 4) {rm.ADD(1);}
    //     if (rm.getCounter() == 5) {rm.END(); state = 0;}
    // }

    // TODO: this is slop, fix the headers so i can call functions normally

    int option;
    constexpr struct option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"interactive", no_argument, nullptr, 'i'},
        {"file", no_argument, nullptr, 'f'},
        {nullptr, 0, nullptr, 0}
    };

    while ((option = getopt_long(argc, argv, "hif:", long_options, nullptr)) != -1) {
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
                break;
            }

            default: {
                return 1;
            }
        }
    }

    return 0;
}

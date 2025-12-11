//
// Created by ashley on 12/1/25.
//

// registermachine.cpp
#include "../include/registermachine.h"

#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <tabulate/table.hpp>

#include "../include/Util.h"

extern Registermachine rm;

Registermachine::Registermachine()
    : registers(50, 0), acc(0), counter(0) {
}

int Registermachine::getAcc() const {
    return acc;
}

int Registermachine::getCounter() const {
    return counter;
}

void Registermachine::incCounter() {
    counter++;
}

int Registermachine::resetRegistermachine() {
    acc = 0;
    counter = 1;
    registers.assign(50, 0);
    return 1;
}

void Registermachine::DLOAD(const int i) {
    acc = i;
    counter++;
}

void Registermachine::LOAD(const int i) {
    acc = registers[i];
    counter++;
}

void Registermachine::STORE(const int i) {
    registers[i] = acc;
    counter++;
}

void Registermachine::INC() {
    ++acc;
    counter++;
}

void Registermachine::DEC() {
    --acc;
    counter++;
}

void Registermachine::ADD(const int i) {
    acc += registers[i];
    counter++;
}

void Registermachine::ADDI(const int i) {
    acc += i;
    counter++;
}

void Registermachine::SUB(const int i) {
    acc -= registers[i];
    counter++;
}

void Registermachine::SUBI(const int i) {
    acc -= i;
    counter++;
}

void Registermachine::MUL(const int i) {
    acc *= registers[i];
    counter++;
}

void Registermachine::MULI(const int i) {
    acc *= i;
    counter++;
}

void Registermachine::DIV(const int i) {
    acc /= registers[i];
    counter++;
}

void Registermachine::DIVI(const int i) {
    acc /= i;
    counter++;
}

void Registermachine::MOD(const int i) {
    acc = acc % registers[i];
    counter++;
}

void Registermachine::JMP(const int i) {
    counter = i - 1;
}

void Registermachine::JEQ(const int i) {
    if (acc == 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JNE(const int i) {
    if (acc != 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JGE(const int i) {
    if (acc >= 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JGT(const int i) {
    if (acc > 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JLE(const int i) {
    if (acc <= 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JLT(const int i) {
    if (acc < 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

// TODO: let user execute printTable() in interactive mode

void Registermachine::END() {
    rmcli::g_running = false;

    /*rm_outputs[1].cell(0).set_text(std::to_string(acc));

    for (int i = 1; i <= 10; i++) {
        if (registers[i] != 0) {
            std::string str = std::to_string(registers[i]);
            rm_outputs[1].cell(i).set_text(str);
        } else {
            rm_outputs[1].cell(i).set_text("undefined");
        }
    }
    const std::string out = rm_outputs.str();
    std::cout << out << std::endl;

    // i need to regenerate the table upon every call of END, because otherwise it takes exponentially longer to process
    // every time. i do not know why this is the case, but its probably something related to tabular
    // this is awful and theres probably 10 billion better ways to do it, but this is the one that works rn so good enough
    rm_outputs = tabulate::Table();
    setupTable();*/

    printTable(acc, registers);

    resetRegistermachine();
}

// oh great heavens
std::unordered_map<std::string, std::function<void(int)>> functionMap = {
    {"DLOAD", [](const int x){ rm.DLOAD(x); }},
    {"LOAD", [](const int x){ rm.LOAD(x); }},
    {"STORE", [](const int x){ rm.STORE(x); }},
    // since the map *only* accepts goobers with ints as their params,
    // i have to input one here and just ignore it
    {"INC", [](int){ rm.INC(); }},
    {"DEC", [](int){ rm.DEC(); }},
    {"ADD", [](const int x){ rm.ADD(x); }},
    {"ADDI", [](const int x){ rm.ADDI(x); }},
    {"SUB", [](const int x){ rm.SUB(x); }},
    {"SUBI", [](const int x){ rm.SUBI(x); }},
    {"MUL", [](const int x){ rm.MUL(x); }},
    {"MULI", [](const int x){ rm.MULI(x); }},
    {"DIV", [](const int x){ rm.DIV(x); }},
    {"DIVI", [](const int x){ rm.DIVI(x); }},
    {"MOD", [](const int x){ rm.MOD(x); }},
    {"JMP", [](const int x){ rm.JMP(x); }},
    {"JEQ", [](const int x){ rm.JEQ(x); }},
    {"JNE", [](const int x){ rm.JNE(x); }},
    {"JGE", [](const int x){ rm.JGE(x); }},
    {"JGT", [](const int x){ rm.JGT(x); }},
    {"JLE", [](const int x){ rm.JLE(x); }},
    {"JLT", [](const int x){ rm.JLT(x); }},
    {"END", [](int){ rm.END(); }},
};

bool Registermachine::doesFunctionExist(const std::string &func) {
    return functionMap.contains(func);
}

// TODO: refactor this so checking if the syntax is valid is done in like an util function
void Registermachine::matchFunctions(const std::string& func, const int val) {
    //try {
        functionMap.at(func)(val);
    // } catch (...) {
    //     // a switch statement might seem a little silly here, but i might add more modes later so it's fine
    //     switch (mode) {
    //         // file mode
    //         case 0: {
    //             std::cerr << rm.getCounter() + 1 << " | Fatal error: unknown function '" << func << "'" << std::endl;
    //             std::exit(1);
    //         }
    //
    //         // interactive mode
    //         case 1: {
    //             rm.incCounter();
    //             std::cerr << "Unknown function '" << func << "', ignoring." << std::endl;
    //             break;
    //         }
    //
    //         // you shouldn't get to this point, what the fuck did you do
    //         default: {
    //             std::cout << "An unknown error occured";
    //             std::exit(1);
    //         }
    //     }
    // }
}

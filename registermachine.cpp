//
// Created by ashley on 12/1/25.
//

// registermachine.cpp
#include "registermachine.h"

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

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

void Registermachine::DLOAD(int i) {
    acc = i;
    counter++;
}

void Registermachine::LOAD(int i) {
    acc = registers[i];
    counter++;
}

void Registermachine::STORE(int i) {
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

void Registermachine::ADD(int i) {
    acc += registers[i];
    counter++;
}

void Registermachine::ADDI(int i) {
    acc += i;
    counter++;
}

void Registermachine::SUB(int i) {
    acc -= registers[i];
    counter++;
}

void Registermachine::SUBI(int i) {
    acc -= i;
    counter++;
}

void Registermachine::MUL(int i) {
    acc *= registers[i];
    counter++;
}

void Registermachine::MULI(int i) {
    acc *= i;
    counter++;
}

void Registermachine::DIV(int i) {
    acc /= registers[i];
    counter++;
}

void Registermachine::DIVI(int i) {
    acc /= i;
    counter++;
}

void Registermachine::MOD(int i) {
    acc = acc % registers[i];
    counter++;
}

void Registermachine::JMP(int i) {
    counter = i - 1;
}

void Registermachine::JEQ(int i) {
    if (acc == 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JNE(int i) {
    if (acc != 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JGE(int i) {
    if (acc >= 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JGT(int i) {
    if (acc > 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JLE(int i) {
    if (acc <= 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

void Registermachine::JLT(int i) {
    if (acc < 0) {
        counter = i - 1;
    } else {
        counter++;
    }
}

// TODO: implement register output via tabulate lib instead of just printing numbers
void Registermachine::END() {
    running = false;
    for (int v: registers) {
        if (v != 0) {
            std::cout << v << '\n';
        }
    }
    std::cout << acc << '\n';
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

void Registermachine::matchFunctions(const std::string& func, const int val) {
    functionMap.at(func)(val);
}

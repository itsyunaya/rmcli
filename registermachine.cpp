//
// Created by ashley on 12/1/25.
//

// registermachine.cpp
#include "registermachine.h"
#include <iostream>

Registermachine::Registermachine()
    : registers(50, 0), acc(0), counter(1) {
}

int Registermachine::getAcc() const {
    return acc;
}

int Registermachine::getCounter() const {
    return counter;
}

// Operations
int Registermachine::resetRegistermachine() {
    acc = 0;
    counter = 1;
    registers.assign(50, 0);
    return 1;
}

void Registermachine::DLOAD(int i) {
    acc = i;
    ++counter;
}

void Registermachine::LOAD(int i) {
    acc = registers[i];
    ++counter;
}

void Registermachine::STORE(int i) {
    registers[i] = acc;
    ++counter;
}

void Registermachine::ADD(int i) {
    acc += registers[i];
    ++counter;
}

void Registermachine::SUB(int i) {
    acc -= registers[i];
    ++counter;
}

void Registermachine::END() {
    for (int v: registers) {
        if (v != 0) {
            std::cout << v << '\n';
        }
    }
    std::cout << acc << '\n';
    resetRegistermachine();
}

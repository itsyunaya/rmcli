//
// Created by ashley on 12/1/25.
//

// registermachine.cpp
#include "registermachine.h"
#include <iostream>

Registermachine::Registermachine()
    : registers(50, 0), acc(0), counter(1) {
}

void matchFunctions(const std::string& func, const int val) {
    std::cout << func << " " << val << std::endl;
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

void Registermachine::INC() {
    ++acc;
    ++counter;
}

void Registermachine::DEC() {
    --acc;
    ++counter;
}

void Registermachine::ADD(int i) {
    acc += registers[i];
    ++counter;
}

void Registermachine::ADDI(int i) {
    acc += i;
    ++counter;
}

void Registermachine::SUB(int i) {
    acc -= registers[i];
    ++counter;
}

void Registermachine::SUBI(int i) {
    acc -= i;
    ++counter;
}

void Registermachine::MUL(int i) {
    acc *= registers[i];
    ++counter;
}

void Registermachine::MULI(int i) {
    acc *= i;
    ++counter;
}

void Registermachine::DIV(int i) {
    acc /= registers[i];
    ++counter;
}

void Registermachine::DIVI(int i) {
    acc /= i;
    ++counter;
}

void Registermachine::MOD(int i) {
    acc %= registers[i];
    ++counter;
}

void Registermachine::JMP(int i) {
    counter = i - 1;
}

void Registermachine::JEQ(int i) {
    if (acc == 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

void Registermachine::JNE(int i) {
    if (acc != 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

void Registermachine::JGE(int i) {
    if (acc >= 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

void Registermachine::JGT(int i) {
    if (acc > 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

void Registermachine::JLE(int i) {
    if (acc <= 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

void Registermachine::JLT(int i) {
    if (acc < 0) {
        counter = i - 1;
    } else {
        ++counter;
    }
}

enum functions {
    DLOAD,
    LOAD,
    STORE,
    INC,
    DEC,
    ADD,
    ADDI,
    SUB,
    SUBI,
    MUL,
    MULI,
    DIV,
    DIVI,
    MOD,
    JMP,
    JEQ,
    JNE,
    JGE,
    JGT,
    JLE,
    JLT
};

// TODO: make decent
void Registermachine::END() {
    for (int v: registers) {
        if (v != 0) {
            std::cout << v << '\n';
        }
    }
    std::cout << acc << '\n';
    resetRegistermachine();
}

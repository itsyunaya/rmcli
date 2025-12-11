//
// Created by ashley on 12/1/25.
//

// registermachine.h
#ifndef REGISTERMACHINE_H
#define REGISTERMACHINE_H

#include <functional>
#include <string>
#include <vector>

namespace rmcli {
    inline bool g_running;
}

class Registermachine {
public:
    Registermachine();

    [[nodiscard]] int getAcc() const;
    [[nodiscard]] int getCounter() const;
    void incCounter();

    int resetRegistermachine();
    void DLOAD(int i);
    void LOAD(int i);
    void STORE(int i);
    void INC();
    void DEC();
    void ADD(int i);
    void ADDI(int i);
    void SUB(int i);
    void SUBI(int i);
    void MUL(int i);
    void MULI(int i);
    void DIV(int i);
    void DIVI(int i);
    void MOD(int i);
    void JMP(int i);
    void JEQ(int i);
    void JNE(int i);
    void JGE(int i);
    void JGT(int i);
    void JLE(int i);
    void JLT(int i);
    void END();

    static void matchFunctions(const std::string &func, int val, int mode);

private:
    std::vector<int> registers;
    int acc;
    int counter;
};

#endif // REGISTERMACHINE_H

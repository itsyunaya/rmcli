//
// Created by ashley on 12/1/25.
//

// registermachine.h
#ifndef REGISTERMACHINE_H
#define REGISTERMACHINE_H

#include <vector>

class Registermachine {
public:
    Registermachine();

    [[nodiscard]] int getAcc() const;
    [[nodiscard]] int getCounter() const;

    // Operations
    int resetRegistermachine();
    void DLOAD(int i);
    void LOAD(int i);
    void STORE(int i);
    void ADD(int i);
    void SUB(int i);
    void END();

private:
    std::vector<int> registers;
    int acc;
    int counter;
};

#endif // REGISTERMACHINE_H

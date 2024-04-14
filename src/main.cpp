// Copyright 2022 UNN-IASR
#include "Automata.h"

int main() {
    Automata beverageAutomaton;
    beverageAutomaton.powerOn();
    beverageAutomaton.insertCoin(800);
    try {
        beverageAutomaton.selectOption(4);
        if (beverageAutomaton.isPurchasePossible()) {
            beverageAutomaton.brewBeverage();
            beverageAutomaton.concludeTransaction();
        } else {
            beverageAutomaton.reclaimCash();
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    beverageAutomaton.powerOff();
    return 0;
}

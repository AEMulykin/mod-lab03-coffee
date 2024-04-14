// Copyright 2022 UNN-IASR
#include "Automata.h"

int main() {
    Automata beverageAutomaton;  // Create an Automata instance
    beverageAutomaton.powerOn();  // Power on the beverage machine
    beverageAutomaton.insertCoin(800);  // Insert money into the machine

    try {
        beverageAutomaton.selectOption(4);  // Make a selection for the beverage
        if (beverageAutomaton.isPurchasePossible()) {
            beverageAutomaton.brewBeverage();  // Start brewing the beverage
            beverageAutomaton.concludeTransaction();  // Finish transaction once done
        } else {
            beverageAutomaton.reclaimCash();  // Reclaim the cash if not enough
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;  // Handle any exceptions that may arise
    }

    beverageAutomaton.powerOff();  // Turn the machine off when done
    return 0;  // Exit the program
}

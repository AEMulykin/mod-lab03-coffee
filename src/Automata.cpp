// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"
namespace std_io = std;  // Alias namespace for cleaner code
Automata::Automata() : state(OFF), cash(0), option(0) {
    displayState();
}
void Automata::presentMenu() {
    for (std::size_t i = 0; i < 10; ++i) {
        std_io::cout << i+1 << ": " << menu[i] << " - " << prices[i] << std_io::endl;
    }
}
void Automata::powerOn() {
    if (state == OFF) {
        state = WAIT;
        std_io::cout << "The beverage machine is now active." << std_io::endl;
        presentMenu();
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}
void Automata::powerOff() {
    if (state == WAIT) {
        state = OFF;
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}
void Automata::insertCoin(int amount) {
    if (state == WAIT || state == ACCEPT) {
        if (amount < 0) {
            throw std::invalid_argument("Error: Invalid amount.");
        }
        state = ACCEPT;
        cash += amount;
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}

void Automata::reclaimCash() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        std_io::cout << "Please add more coins to proceed with the purchase." << std_io::endl;
        revealCash();
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}

void Automata::selectOption(int choice) {
    if (state == ACCEPT) {
        if (std::size(menu) <= choice || choice <= 0) {
            throw std::invalid_argument("Error: Invalid selection.");
        }
        state = CHECK;
        option = choice;
        std_io::cout << "Selection made: " << menu[option - 1] << std_io::endl;
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}

bool Automata::isPurchasePossible() {
    if (state == CHECK) {
        bool isAffordable = cash >= prices[option - 1];
        displayState();
        return isAffordable;
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}

void Automata::brewBeverage() {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[option - 1];
        revealCash();
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}

void Automata::concludeTransaction() {
    if (state == COOK) {
        state = WAIT;
        revealCash();
        displayState();
    } else {
        throw std::domain_error("Error: Invalid operation.");
    }
}
int Automata::revealCash() {
    std_io::cout << "Remaining Balance: " << cash << std_io::endl;
    return cash;
}
void Automata::displayState() {
    using std_io::cout;
    using std_io::endl;

    const char* stateMessages[] = {
        "Beverage machine is deactivated.",
        "Beverage machine awaits transaction.",
        "Please deposit coins.",
        "Verifying transaction...",
        "Preparing your beverage..."
    };

    cout << stateMessages[state] << endl;
}

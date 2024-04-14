// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

using namespace std;

Automata::Automata() : state(OFF), cash(0), option(0) {
    DisplayState();
}

void Automata::DisplayMenu() const {
    for (int i = 0; i < sizeof(menu)/sizeof(menu[0]); i++) {
        cout << i + 1 << ": " << menu[i] << " - " << prices[i] << "₽" << endl;
    }
}

void Automata::PowerOn() {
    if (state != OFF) {
        throw domain_error("Machine is already running.");
    }
    
    state = WAIT;
    cout << "Machine activated." << endl;
    DisplayMenu();
    DisplayState();
}

void Automata::PowerOff() {
    if (state != WAIT) {
        throw domain_error("Machine is not in a wait state.");
    }
    
    state = OFF;
    DisplayState();
}

void Automata::InsertCoin(int amount) {
    if (state != WAIT && state != ACCEPT) {
        throw domain_error("Machine is not ready to accept money.");
    }

    if (amount < 0) {
        throw invalid_argument("Inserted amount cannot be negative.");
    }

    state = ACCEPT;
    cash += amount;
    DisplayState();
}

void Automata::CancelTransaction() {
    if (state != ACCEPT && state != CHECK) {
        throw domain_error("Cannot cancel at the current stage.");
    }

    cout << "Transaction cancelled. Please, take your money back: " << cash << "₽" << endl;
    cash = 0;
    state = WAIT;
    DisplayState();
}

void Automata::SelectOption(int choice) {
    if (state != ACCEPT) {
        throw domain_error("Machine is not ready to make a selection.");
    }

    if (choice < 0 || choice >= sizeof(menu)/sizeof(menu[0])) {
        throw invalid_argument("Selected option is not valid.");
    }

    state = CHECK;
    option = choice;
    cout << "You selected: " << menu[option] << endl;
    DisplayState();
}

bool Automata::IsPaymentSufficient() {
    if (state != CHECK) {
        throw domain_error("Payment can only be checked in CHECK state.");
    }

    DisplayState();
    return cash >= prices[option];
}

void Automata::MakeDrink() {
    if (state != CHECK) {
        throw domain_error("Machine is not in a proper state to make a drink.");
    }

    state = COOK;
    cout << "Preparing: " << menu[option] << endl;
    cash -= prices[option];
    DisplayState();
}

void Automata::CompleteTransaction() {
    if (state != COOK) {
        throw domain_error("Machine has not completed drink preparation.");
    }

    if (cash > 0) {
        cout << "Please, take your change: " << cash << "₽" << endl;
    }

    cash = 0;
    state = WAIT;
    DisplayState();
}

void Automata::DisplayState() const {
    static const char* StateMessages[] = {
        "The machine is idle.",
        "The machine is ready to accept money.",
        "The machine has received money.",
        "The machine is checking the inserted coins.",
        "The machine is preparing your drink."
    };

    cout << StateMessages[state] << endl;
}

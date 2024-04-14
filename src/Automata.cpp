// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include <stdexcept>
#include "Automata.h"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::domain_error;

Automata::Automata() : state_(States::OFF), cash_(0), option_(0) {
    DisplayState();
}

void Automata::DisplayMenu() const {
    for (size_t i = 0; i < menu_.size(); ++i) {
        cout << i + 1 << ": " << menu_[i] << " - " << prices_[i] << " RUB" << endl;
    }
}

void Automata::TurnOn() {
    if (state_ == States::OFF) {
        state_ = States::WAIT;
        cout << "The drink machine is on." << endl;
        DisplayMenu();
        DisplayState();
    } else {
        throw domain_error("Error: The machine is already on.");
    }
}

void Automata::TurnOff() {
    if (state_ == States::WAIT) {
        state_ = States::OFF;
        DisplayState();
    } else {
        throw domain_error("Error: The machine is not in a waiting state.");
    }
}

void Automata::InsertCoins(int amount) {
    if (state_ == States::WAIT || state_ == States::ACCEPT) {
        if (amount < 0) {
            throw invalid_argument("Error: The inserted amount cannot be negative.");
        }
        state_ = States::ACCEPT;
        cash_ += amount;
        DisplayState();
    } else {
        throw domain_error("Error: The machine is not ready to accept money.");
    }
}

void Automata::CancelTransaction() {
    if (state_ == States::ACCEPT || state_ == States::CHECK) {
        state_ = States::WAIT;
        cout << "The transaction has been canceled." << endl;
        ReturnChange();
        DisplayState();
    } else {
        throw domain_error("Error: The machine is not in a cancellable state.");
    }
}

void Automata::SelectOption(int option) {
    if (state_ == States::ACCEPT) {
        if (option <= 0 || option > static_cast<int>(menu_.size())) {
            throw invalid_argument("Error: The selected option is not valid.");
        }
        state_ = States::CHECK;
        option_ = option - 1;
        cout << "You have selected: " << menu_[option_] << endl;
        DisplayState();
    } else {
        throw domain_error("Error: The machine is not ready to make a selection.");
    }
}

bool Automata::ConfirmSelection() const {
    if (state_ == States::CHECK) {
        if (cash_ >= prices_[option_]) {
            return true;
        }
        DisplayState();
        return false;
    } else {
        throw domain_error("Error: The selection cannot be confirmed at this state.");
    }
}

void Automata::PrepareDrink() {
    if (state_ == States::CHECK && ConfirmSelection()) {
        state_ = States::COOK;
        cash_ -= prices_[option_];
        cout << "Your drink " << menu_[option_] << " is being prepared..." << endl;
        DisplayState();
    } else {
        throw domain_error("Error: Insufficient funds or wrong machine state.");
    }
}

void Automata::CompleteService() {
    if (state_ == States::COOK) {
        state_ = States::WAIT;
        ReturnChange();
        cout << "Your drink is ready. Please, take your drink." << endl;
        DisplayState();
    } else {
        throw domain_error("Error: The drink is not ready yet.");
    }
}

int Automata::ReturnChange() {
    cout << "Your change is " << cash_ << " RUB" << endl;
    int change = cash_;
    cash_ = 0;
    return change;
}

void Automata::DisplayState() const {
    static const char* state_messages[] = {
        "The drink machine is off.",
        "The drink machine is waiting for your action.",
        "Please insert money.",
        "Select your drink or check your balance.",
        "Your drink is being prepared. Please, wait..."
    };

    cout << state_messages[static_cast<int>(state_)] << endl;
}

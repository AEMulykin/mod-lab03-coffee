// Copyright 2022 UNN-IASR
#pragma once
#include <array>
#include <string>

enum AutomatonStates { OFF, WAIT, ACCEPT, CHECK, COOK };

using std::array;
using std::string;

class Automata {
 private:
        AutomatonStates state; // Current state of the automaton
        int cash; // Current cash balance
        array<string, 10> menu {{
            "Espresso",
            "Americano",
            "Cappuccino",
            "Latte",
            "FlatWhite",
            "Macchiato",
            "BlackTea",
            "GreenTea",
            "Cacao",
            "HotChocolate"
        }};
        int option; // Selected drink option
        array<int, 10> prices {{
            80, 100, 150, 180, 160, 190, 120, 120, 140, 170
        }};

 public:
        Automata(); // Constructor that initializes the automaton state
        void presentMenu(); // Display the beverage menu to the user
        void powerOn();  // Activate the machine
        void powerOff();  // Deactivate the machine
        void insertCoin(int amount);  // Accept money deposited by the user
        void reclaimCash();  // Refund the money to the user
        void selectOption(int choice);  // User makes a beverage choice
        bool isPurchasePossible();  // Verify if the user has provided enough money
        void brewBeverage();  // Begin preparing the selected beverage
        void concludeTransaction();  // Finish the current user session
        int revealCash();  // Show current cash balance and return change if applicable
        void displayState();  // Show current state of the automaton to the user
};

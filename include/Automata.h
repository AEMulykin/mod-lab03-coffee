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
Automata();
    void powerOn(); // replaced on()
    void powerOff(); // replaced off()
    void insertCoin(int amount); // replaced coin(int)
    void presentMenu(); // replaced getMenu()
    void displayState(); // replaced getState()
    void selectOption(int choice); // replaced choice(int)
    bool isPurchasePossible(); // replaced check()
    int revealCash(); // replaced getCash()
    void reclaimCash(); // new function to replace cancel()
    void brewBeverage(); // replaces cook()
    void concludeTransaction(); // replaces finish()
};

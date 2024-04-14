// Copyright 2022 UNN-IASR
#pragma once
#include <vector>
#include <array>

enum MachineStates {
    StateOff, StateWait, StateAccept, StateCheck, StateCook
};

using std::vector;
using std::array;
using std::string;

class BeverageAutomata {
 private:
        MachineStates currentState;  // Current state of the machine
        int currentCash;  // Current amount of money held
        array<string, 10> beverageOptions {{
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
        int selectedOption;  // User's beverage selection
        array<int, 10> beveragePrices {{
            60, 80, 130, 140, 110, 290, 120, 100, 120, 150
        }};

 public:
        BeverageAutomata();
        void activateMachine();  // Turn the machine on
        void deactivateMachine();  // Turn the machine off
        void insertCoins(int amount);  // User deposits money
        void displayMenu();  // Display menu to user
        void displayCurrentState();  // Show current state to the user
        void makeSelection(int choice);  // User makes a beverage selection
        bool validateSelection();  // Check if enough money has been provided
        int returnChange();  // Return change/money to the user
        void abortTransaction();  // User cancels the transaction
        void initiateBrewing();  // Simulate beverage preparation
        void completeService();  // End user service
};

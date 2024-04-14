// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
#include <array>

// Определение возможных состояний автомата
enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

// Автомат для продажи напитков
class Automata {
private:
    STATES currentState;  // Текущее состояние
    int totalCash;        // Текущая сумма денег
    int beverageChoice;   // Выбранный напиток

    // Меню напитков с соответствующими ценами
    const std::array<std::string, 10> beverages = {
        "Espresso", "Americano", "Cappuccino",
        "Latte", "FlatWhite", "Macchiato",
        "BlackTea", "GreenTea", "Cacao", "HotChocolate"};
    const std::array<int, 10> prices = {
        80, 100, 150, 180, 160, 190, 120, 120, 140, 170};

    void displayMenu();     // Вывод меню напитков
    void showState();       // Отображение текущего состояния автомата

public:
    Automata();  // Конструктор
    void switchOn();   // Включение автомата
    void switchOff();  // Выключение автомата
    void insertCash(int amount);    // Внесение денег
    void selectBeverage(int choice);  // Выбор напитка
    bool isEnoughCash();   // Проверка достаточности средств
    int returnChange();    // Возврат сдачи
    void abort();          // Отмена операции
    void prepare();        // Приготовление напитка
    void completeService(); // Завершение обслуживания
};

Automata::Automata() : currentState(OFF), totalCash(0), beverageChoice(0) {}

void Automata::displayMenu() {
    for (size_t i = 0; i < beverages.size(); ++i) {
        std::cout << i + 1 << ". " << beverages[i] << " - " << prices[i] << '\n';
    }
}

void Automata::showState() {
    const char* stateDescriptions[] = {
        "Offline", "Waiting for action", "Accepting cash",
        "Checking selection", "Preparing beverage"
    };
    std::cout << "Current state: " << stateDescriptions[currentState] << '\n';
}

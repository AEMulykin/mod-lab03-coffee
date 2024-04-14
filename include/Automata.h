// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <vector>
#include <string>

// Использование enum class для обеспечения типобезопасности
enum class State {
    Off,
    Wait,
    Accept,
    Check,
    Cook
};

class Automata {
 private:
    State currentState_;  // Текущее состояние автомата
    int cash_;            // Текущая сумма денег
    std::vector<std::string> menu_ = {
        "Ristretto",
        "Lungo",
        "Doppio",
        "Corretto",
        "Affogato",
        "IrishCoffee",
        "Frappe",
        "EspressoConPanna",
        "Mochaccino",
        "Bicerin"
    };  // Измененные названия кофе
    int selection_;       // Выбор напитка
    std::vector<int> prices_ = {
        70, 90, 110, 130, 120, 200, 160, 150, 180, 160
    };  // Обновленная структура с новыми ценами

 public:
    Automata();
    void TurnOn();             // Включение автомата
    void TurnOff();            // Выключение автомата
    void InsertCoin(int cash); // Занесение денег на счет пользователем
    void DisplayMenu();        // Отображение меню
    std::string GetState() const;         // Получение текущего состояния для пользователя
    void SelectDrink(int option); // Выбор напитка пользователем
    bool IsPaymentSufficient();   // Проверка наличия необходимой суммы
    int ReturnCash();             // Возврат сдачи/денег
    void CancelService();         // Отмена услуги пользователем
    void PrepareDrink();          // Приготовление напитка
    void FinishService();         // Завершение обслуживания
};

// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
#include <array>
// Перечисление для представления возможных состояний автомата
enum class States {
    Off,   // Выключено
    Wait,  // Ожидание
    Accept, // Прием денег
    Check,  // Проверка суммы
    Cook    // Приготовление
};
class Automata {
 private:
    States state_;  // Текущее состояние автомата
    int cash_;      // Текущая сумма денег в автомате
    int option_;    // Выбор напитка пользователем
    static constexpr std::array<std::string, 10> menu_ = {
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
    };
    static constexpr std::array<int, 10> prices_ = {
        80, 100, 150, 180, 160, 190, 120, 120, 140, 170
    };
  public:
    Automata();//Конструктор
void On();
//Включение автомата
void Off();
//Выключение автомата
    void InsertCoin(int amount);
//Внесение денег
    void DisplayMenu() const;
//Отображение меню
    std::string GetCurrentState() const;
//Получение описания текущего состояния
    void SelectDrink(int option);
//Выбор напитка пользователем
    bool IsSufficientAmount() const;
//Проверка достаточности внесенной суммы
int ReturnChange();
//Возврат сдачи/денег
    void Cancel();
// Отмена сессии
    void PrepareDrink();
// Имитация процесса приготовления напитка
    void CompleteService();
// Завершение обслуживания
};

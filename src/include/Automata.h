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
        Automata();
        void on();  // - включение автомата
        void off();  // - выключение автомата
        void coin(int x);  // - занесение денег на счёт пользователем
        void getMenu();  // - считывание меню
        void getState();  // - считывание текущего состояния для пользователя
        void choice(int x);  // - выбор напитка пользователем
        bool check();  // - проверка наличия необходимой суммы
        int getCash();  // - возвращает сдачу/деньги
        void cancel();  // - отмена сеанса обслуживания пользователем
        void cook();  // - имитация процесса приготовления напитка
        void finish();  // - завершение обслуживания пользователя
};

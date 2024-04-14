// Copyright 2022 UNN-IASR

#include <iostream>
#include <string>
#include "Automata.h"

int main() {
    // Создание объекта automat типа Automata
    Automata automat;

    // Запуск автомата
    automat.PowerOn();

    // Внесение суммы денег в автомат
    automat.InsertCoin(1000);

    // Выбор напитка (предположим, что FlatWhite - это позиция 5)
    const int flatWhiteOption = 5;
    automat.SelectOption(flatWhiteOption);

    // Проверка наличия достаточной суммы денег
    if (automat.IsPaymentSufficient()) {
        // Приготовление напитка
        automat.MakeDrink();

        // Завершение транзакции
        automat.CompleteTransaction();
    } else {
        // Отмена операции в случае недостаточной суммы
        automat.CancelTransaction();
    }

    // Выключение автомата
    automat.PowerOff();

    return 0;
}

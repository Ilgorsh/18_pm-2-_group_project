#include "object.h"
#include <iostream>

#ifndef FACTORY_H
#define FACTORY_H

//Класс "Завод" для переработки мусора
class Plant:protected Object{
protected:
    int distance_cost; //Стоимость единицы расстояния для вывоза мусора

public:
    friend std::ostream& operator<<(std::ostream& out, const Plant& plant); //Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& in, const Plant& plant); //Перегрузка оператора ввода

};

#endif // FACTORY_H

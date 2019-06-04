#include "object.h"
#include <iostream>

#ifndef CONTAINER_H
#define CONTAINER_H

//Контейнер с мусором
class Container:protected Object{
public:
    friend std::ostream& operator<<(std::ostream& out, const Container& plant); //Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& in, const Container& plant); //Перегрузка оператора вводаыыафа
};

#endif // CONTAINER_H

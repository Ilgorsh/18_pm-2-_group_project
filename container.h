#ifndef CONTAINER_H
#define CONTAINER_H
#include "object.h"

class Container:protected Object
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Container& plant); //Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& in, const Container& plant); //Перегрузка оператора ввода
    Container();//Конструктор бы сделать
};

#endif // CONTAINER_H

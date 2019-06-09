#ifndef CONTAINER_H
#define CONTAINER_H
#include "object.h"

class Container:protected Object
{
public:
    friend std::ostream& operator<<(std::ostream& out, const Container& plant); //Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& in, const Container& plant); //Перегрузка оператора ввода
    Container();//Конструктор бы сделать
    int getid();
    bool getmaterial(bool a);
    int getcoordx();
    int getcoordy();
    void setid(int id);
    void setx(int x);
    void sety(int y);
    void setmat_metal(bool a);
    void setmat_organic(bool a);
    void setmat_glass(bool a);
    void setmat_plastic(bool a);
    void setmat_paper(bool a);
};

#endif // CONTAINER_H

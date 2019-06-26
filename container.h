/*!
    \file container.h
     \brief Файл контейнера
 */
#ifndef CONTAINER_H
#define CONTAINER_H
#include "object.h"

class Container:public Object
{
protected:

public:
    friend std::ostream& operator<<(std::ostream& out, const Container& plant); //Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& in, const Container& plant); //Перегрузка оператора ввода
    int getid();
    /*!
     \brief Конструктор для контейнера
 */
      Container();
    bool getmaterial(bool a);
    int getcoordx();
    int getcoordy();
    bool getmetal();
    bool getpaper();
    bool getorganic();
    bool getplastic();
    bool getglass();
    void setid(int id);
    void setx(int x);
    void sety(int y);
    void setmat_metal(bool a);
    void setmat_organic(bool a);
    void setmat_glass(bool a);
    void setmat_plastic(bool a);
    void setmat_paper(bool a);
    Container operator = (const Container& equal);
    bool operator==(const Container &rightObj) const
    {
        return (id == rightObj.id);
    }
    bool operator < (const Container & plant) const
    {
        return(id<plant.id);
    }

};

#endif // CONTAINER_H

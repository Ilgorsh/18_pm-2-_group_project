/*!
\file object.h
\b лбьект
*/
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
using namespace std;


class Object{
    protected:
        int id;
        int x, y; //Координаты по x и y, отвечающие за местополжение объекта
        bool metal, paper, glass, plastic, organic;//Массив булов для материалов
       // char *name; //назвоние
    public:
        /*!
         * \brief Метод определения числа типов мусора
         * \return число типов мусора
         */
        int get_number_of_types();
        //  void setname(char* h);
        Object();
        //char * getname();

};

#endif // OBJECT_H

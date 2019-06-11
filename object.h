#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <map>
using namespace std;


class Object{
    protected:
        int encounters;//Сколько раз обьект встречается в разных списках (техническая переменная)
        int id;
        int x, y; //Координаты по x и y, отвечающие за местополжение объекта
        bool metal, paper, glass, plastic, organic;//Массив булов для материалов
        map<string, string> Service_list;
        float volume; //Объем объекта (ПОКА НЕ ДЕЛАЕМ! СНАЧАЛА СДЕЛАЕМ ДРУГОЕ ВСЕ!)
    public:
        int get_encounters();
        int get_number_of_types();
        void set_encounters(int encounters);
        Object();
};

#endif // OBJECT_H

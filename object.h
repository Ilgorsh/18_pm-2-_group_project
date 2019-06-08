#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
using namespace std;


class Object{
    protected:
        int x, y; //Координаты по x и y, отвечающие за местополжение объекта
        bool materials[5];//Массив булов для материалов
        map<string, string> Service_list;

        float volume; //Объем объекта (ПОКА НЕ ДЕЛАЕМ! СНАЧАЛА СДЕЛАЕМ ДРУГОЕ ВСЕ!)
    public:
        Object();
};

#endif // OBJECT_H

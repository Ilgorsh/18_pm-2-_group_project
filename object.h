#ifndef OBJECT_H
#define OBJECT_H

//Класс "Object", который одновременно подходит под класс Контейнера и класс Завода
class Object{//Пора уже сделать сеттеры и геттеры хотя бы, и для map-а тоже!
protected:
    int x, y; //Координаты по x и y, отвечающие за местополжение объекта
    bool materials[5];//Массив булов для материалов
    map<string, string> Service_list;

    float volume; //Объем объекта (ПОКА НЕ ДЕЛАЕМ! СНАЧАЛА СДЕЛАЕМ ДРУГОЕ ВСЕ!)

public:
    Object();
};

#endif // OBJECT_H

#ifndef OBJECT_H
#define OBJECT_H

//Класс "Object", который одновременно подходит под класс Контейнера и класс Завода
class Object{
protected:
    int x, y; //Координаты по x и y, отвечающие за местополжение объекта
    int id; //ID объекта: для поиска, для мапов
    bool materials[5];//Массив булов для материалов

    float volume; //Объем объекта (ПОКА НЕ ДЕЛАЕМ! СНАЧАЛА СДЕЛАЕМ ДРУГОЕ ВСЕ!)

public:
    Object();
};

#endif // OBJECT_H

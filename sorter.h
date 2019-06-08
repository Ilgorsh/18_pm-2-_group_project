#ifndef SORTER_H
#define SORTER_H
#include "plant.h"
#include "container.h"
#include <set>
#include <map>

class Sorter
{
private:
    map<int, Plant> Plants_map;//Возможно потом будет карта итн-ссылка или инт-указатель
    map<int, Container> Containers_map;//Возможно потом будет карта итн-ссылка или инт-указатель
    string password_plant, password_cont;
protected://Кто ответственный за бывший класс сортер (ныне manager), проверьте все методы, чтоб там было все, что нужно (и не больше)
                //для работы с переменными и контейнерами в private, т.е. методы для добавления, удаления, редактирования, 
                //Метод-Геттер (Возвращающий ССЫЛКУ!!!!(или указатель)) на контейнер контейнеров или на контейнер заводов
                //вывода/ввода в/из файлов, метод, проверяющий верность пороля и возвращающий 1, если пароль верный, иначе 1. 
                //Но только не напишите лишнего 
    
    void read_list(set<Plant> plant_list);//Метод считывания списка заводов из файла
    void read_list(set<Container> container_list);//Метод считывания списка контейнеров из файла
    void initilize () //Метод, создающий и заполняющий два списка: список Заводов и список Контейнеров
    {
        set<Container> containers_list; //Создаётся список контейнеров
        set<Plant> plants_list; //Создаётся список завлдлв
        map<Plant , set<Container>> All_list;//Создание общего списка с сопоставлеными заводами и списком контейнеров
        read_list(containers_list); //Заполнение списка Контейнеров
        read_list(plants_list); //Заполнение списка Заводов
    }

    set<Plant> compare(Container _container, set<int> Plants_id_list); //Функция, подбирающая каждому контейнеру список из подходящих заводов
    void optimizer(Container _container, set<int> Plant_id_list); //Метод, который находит оптимальные заводы для контейнера

    map<int, set<int> > mapp_container_to_plant(set<Container> containers_list, set<Plant> plants_list); //Метод, сопоставляющий каждой фабрике список из контейнеров
    map<int, set<int> > mapper_plant_to_container(set<Plant> plants_list, set<Container> containers_list); //Функция, привязывающая контейнер к списку заводов

};

#endif // SORTER_H

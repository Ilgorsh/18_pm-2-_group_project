#include "container.h"
#include "plant.h"
#include <set>
#include <map>

using namespace std;

#ifndef SORTER_H
#define SORTER_H

//Сортировщик сопоставляющий контейнеры и заводы
class Sorter:protected Plant, protected Container
{
private:
    void read_list(set<Plant> plant_list);//Метод считывания списка заводов из файла
    void read_list(set<Container> container_list);//Метод считывания списка контейнеров из файла
public:
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

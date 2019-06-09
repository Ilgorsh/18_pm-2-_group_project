#ifndef SORTER_H
#define SORTER_H
#include "plant.h"
#include "container.h"
#include <set>
#include <map>

class Sorter
{
private:

protected:
    Sorter();
    double cost(Container container,Plant plant);
    set<Container> read_Containers();
    set<Plant> read_Plants();
    map<int, set<int> > mapp_container_to_plant(set<Container> containers_list, set<Plant> plants_list); //Метод, сопоставляющий каждой фабрике список из контейнеров
    map<int, set<int> > mapper_plant_to_container(set<Plant> plants_list, set<Container> containers_list); //Функция, привязывающая контейнер к списку заводов

};

#endif // SORTER_H

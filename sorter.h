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
    void remap(map<Container,set<Plant>> inmap);

    void sorter();
    void sorter_container_to_plant(set<Container>,set<Plant>);
    map<int, set<int> > mapp_container_to_plant(set<Container> containers_list, set<Plant> plants_list); //Метод, сопоставляющий каждой фабрике список из контейнеров
    map<int, set<int> > mapper_plant_to_container(set<Plant> plants_list, set<Container> containers_list); //Функция, привязывающая контейнер к списку заводов
public:
    static set<Container> read_Containers();
     static double cost(Container container,Plant plant);
    static set<Plant> read_Plants();
};

#endif // SORTER_H

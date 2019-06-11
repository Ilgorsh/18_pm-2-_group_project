#ifndef MENU_H
#define MENU_H
#include "sorter.h"

    class Menu:protected Sorter{
    private:

    public:
        void add_plant();//Функция добавления завода, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
        void add_container();//Функция добавления контейнера, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
        void print_list();//Выводит список заводов с прикреплёнными контейнерами
        void delete_plant(set<Plant> plants_set, int id); //Функция, удаляющая завод
        void delete_container(set<Container> containers_set, int id); //Функция, удаляющая контейнер
        void change(int id); //Позволяет редактировать информацию
        void check_password();
        Menu();
};

#endif // MENU_H

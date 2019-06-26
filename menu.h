/*!
    \file menu.h
     \brief меню
 */
#ifndef MENU_H
#define MENU_H
#include "sorter.h"

class Menu:protected Sorter{
private:

public:
    /*!
     * \brief Добавление завода
     * \param айди
     * \param координата по x
     * \param координата по y
     * \param железо
     * \param стекло
     * \param бумага
     * \param органика
     * \param пластик
     * \param стоимость за нденицу расстояния
     * \return
     */
    int add_plant(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic, int cost);//Функция добавления завода, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
    int add_container(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic);//Функция добавления контейнера, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
    int delete_plant(int id); //Функция, удаляющая завод
    int delete_container(int id); //Функция, удаляющая контейнер
    int edit_plant(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic, int cost); //Позволяет редактировать информацию
    int edit_container(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic);
    void print_in_file_plant(set<Plant> plants);
    void print_in_file_container(set<Container> containers);
    int check_password(bool user_state, int pass);

    map<Container, set<Plant>> get_map_container_to_plant();
    map<Plant, set<Container>> get_map_plant_to_container();

    void menu_realiz();

};

#endif // MENU_H

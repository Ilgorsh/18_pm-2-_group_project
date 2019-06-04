#include <sorter.h>
/* Должны подключиться: #include <QWidget>
 *                      #include <QLabel>
 *                      #include <QKeyEvent>
 * и другие для работы с кнопочками и прочим. Надо пересоздать проект в QT Widget
 */

#ifndef MENU_H
#define MENU_H
class Menu:protected Sorter{
private:

public:
    void add_plant();//Функция добавления завода, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
    void add_container();//Функция добавления контейнера, внутри в конце запускается Sorter с новыми данными (прогоняет всё по-новой)
    void print_list();//Выводит список заводов с прикреплёнными контейнерами
    void delete_plant(set<Plant> plants_set, int id); //Функция, удаляющая завод
    void delete_container(set<Container> containers_set, int id); //Функция, удаляющая контейнер
    void start_menu(); //Запускает графическое приложение с основным меню
    void change(int id); //Позволяет редактировать информацию какого-либо объекта по его ID

/* Вся работа с кнопочками, окошками, графикой будет вызываться внутри start_menu()
 * Сами эти функции будут описаны в "mainwindow.cpp" (файл создастся при создании проекта Qt Widget)
 * Объявлены будут в "mainwindow.h" (так же создатся при создании проекта)
 */

    Menu();
};

#endif // MENU_H

//Если останется время, то сделать графическую оболочку

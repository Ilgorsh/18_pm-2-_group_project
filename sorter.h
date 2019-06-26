/*!
*\file Сортер
*\brief Файл сортировщика
*/
#ifndef SORTER_H
#define SORTER_H
#include "plant.h"
#include "container.h"
#include <set>
#include <map>

class Sorter :protected Container , protected Plant
{
private:

protected:
    Sorter();
public:
    /*!
     * \brief Считывание контейнера
     * \return сет контейнеров
     */
    static set<Container> read_Containers();
    /*!
     * \brief подсчёт стоимости перевозки от контейнера ло завода
     * \param контейнер
     * \param завод
     * \return
     */
    static int cost(Container container,Plant plant);
    /*!
     * \brief Считывание заводов из файла
     * \return Сет заводов
     */
    static set<Plant> read_Plants();
    /*!
     * \brief переводит привязку контейнер-> заводы в завод -> контейнеры
     * \param  контейнер-> заводы
     * \return завод -> контейнеры
     */
    static map<Plant,set<Container>> remap(map<Container,set<Plant>> const inmap);
    /*!
     * \brief привязка заводов к контейнерам согласно стоимости перевозки
     * \param Вводимые контейнеры
     * \param Вводимые заводы
     * \return
     */
    static map<Container,set<Plant>> Map(set<Container> Containers,set<Plant> Plants);
};

#endif // SORTER_H

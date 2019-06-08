#ifndef PLANT_H
#define PLANT_H
#include "object.h"

class Plant : protected Object
{
public:
  int distance_cost; //Стоимость единицы расстояния для вывоза мусора
  string 
  Plant();
  friend std::ostream& operator<<(std::ostream& out, const Plant& plant); //Перегрузка оператора вывода
  friend std::istream& operator>>(std::istream& in, const Plant& plant); //Перегрузка оператора ввода
};

#endif // PLANT_H

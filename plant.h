#ifndef PLANT_H
#define PLANT_H
#include "object.h"

class Plant : public Object
{
public:
  int distance_cost; //Стоимость единицы расстояния для вывоза мусора
  Plant();
  friend std::ostream& operator<<(std::ostream& out, const Plant& plant); //Перегрузка оператора вывода
  friend std::istream& operator>>(std::istream& in, const Plant& plant); //Перегрузка оператора ввода
  int getid();
  bool getmaterial(bool a);
  int getcoordx();
  int getcoordy();
  int get_distance_cost();
  bool getmetal();
  bool getpaper();
  bool getorganic();
  bool getplastic();
  bool getglass();
  void setid(int id);
  void setx(int x);
  void sety(int y);
  void setmat(bool a);
  void set_distance_cost(int cost);
  void setmat_metal(bool a);
  void setmat_organic(bool a);
  void setmat_glass(bool a);
  void setmat_plastic(bool a);
  void setmat_paper(bool a);
};

#endif // PLANT_H

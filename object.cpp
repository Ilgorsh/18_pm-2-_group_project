/*!
\file object.cpp
\b реализация функций обьекта
*/
#include "object.h"
#include <string>


Object::Object()
{

}
int Object::get_number_of_types()
{
    return (metal + paper + organic + plastic + glass);
}
//void Object::setname(char * h)
//{
//    name=h;
//}
//char* Object::getname(){
//    return(name);
//}

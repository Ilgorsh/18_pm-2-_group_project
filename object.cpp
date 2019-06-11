#include "object.h"

Object::Object()
{

}
int Object::get_number_of_types()
{
    return (metal + paper + organic + plastic + glass);
}

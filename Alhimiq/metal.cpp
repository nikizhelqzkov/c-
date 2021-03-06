#include "metal.h"
Metal::Metal() : Earth(), Fire()
{
    reactWith = Earth::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Fire::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < size; j++)
        {
            if (reactWith[j] == Fire::reactWith[i])
            {
                isIn = true;
            }
        }
        if (!isIn)
        {
            reactWith.push_back(Fire::reactWith[i]);
        }
    }
}

Metal::~Metal()
{
}
std::vector<std::string> Metal::getReactings() const
{
    return this->reactWith;
}
std::string Metal::getName() const
{
    return this->name;
}
void Metal::print() const
{
    for (auto m : this->reactWith)
    {
        std::cout << m << "  ";
    }
}
Elements *Metal::clone() const
{
    return new Metal(*this);
}
std::vector<std::string> Metal::getFathers() const
{
    return this->father;
}
Metal *Metal::read(std::istream &in)
{
    return new Metal;
}
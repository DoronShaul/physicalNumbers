#include <iostream>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;
using std::ostream, std::istream;

PhysicalNumber::PhysicalNumber(double k, Unit u)
{
    value = k;
    measurement = u;
}

PhysicalNumber::~PhysicalNumber()
{
    value = NULL;
}
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber &pn)
{
    PhysicalNumber ans(0, Unit::CM);
    ans.measurement = this->measurement;
    ans.value = this->value + pn.value;
    return ans;
}
PhysicalNumber PhysicalNumber::operator-(PhysicalNumber &pn)
{
    PhysicalNumber ans(0, Unit::CM);
    ans.measurement = this->measurement;
    ans.value = this->value - pn.value;
    return ans;
}
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pn)
{
    this->value = this->value + pn.value;
    return *this;
}
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &pn)
{
    this->value = this->value - pn.value;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator+()
{
    return *this;
}
PhysicalNumber &PhysicalNumber::operator-()
{
    this->value = this->value * (-1);
    return *this;
}
PhysicalNumber &PhysicalNumber::operator++()
{
    this->value = this->value + 1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--()
{
    this->value = this->value - 1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator++(int)
{
    this->value = this->value + 1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--(int)
{
    this->value = this->value - 1;
    return *this;
}

bool PhysicalNumber::operator>(const PhysicalNumber pn)
{
    return true;
}
bool PhysicalNumber::operator<(const PhysicalNumber pn)
{
    return true;
}
bool PhysicalNumber::operator<=(const PhysicalNumber pn)
{
    return true;
}
bool PhysicalNumber::operator>=(const PhysicalNumber pn)
{
    return true;
}
bool PhysicalNumber::operator==(const PhysicalNumber pn)
{
    return true;
}
bool PhysicalNumber::operator!=(const PhysicalNumber pn)
{
    return true;
}

ostream &operator<<(ostream &os, const PhysicalNumber &pn)
{
    os << pn.getValue() << "[" << pn.getUnit() << "]";
    return os;
}

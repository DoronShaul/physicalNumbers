#include <iostream>
#include "Unit.h"

using std::ostream, std::istream, std::string, ariel::Unit;

#pragma once

namespace ariel
{
class PhysicalNumber
{
  private:
    double value;
    Unit measurement;

  public:
    PhysicalNumber(double value, Unit measurement);
    ~PhysicalNumber();
    double getValue() const { return this->value; }
    Unit getUnit() const { return this->measurement; }
    PhysicalNumber operator+(PhysicalNumber &pn);
    PhysicalNumber operator-(PhysicalNumber &pn);
    PhysicalNumber &operator+=(const PhysicalNumber &pn);
    PhysicalNumber &operator-=(const PhysicalNumber &pn);
    PhysicalNumber &operator+();
    PhysicalNumber &operator-();
    PhysicalNumber &operator++();
    PhysicalNumber &operator--();
    PhysicalNumber &operator++(int);
    PhysicalNumber &operator--(int);

    bool operator<(const PhysicalNumber pn);
    bool operator>(const PhysicalNumber pn);
    bool operator<=(const PhysicalNumber pn);
    bool operator>=(const PhysicalNumber pn);
    bool operator==(const PhysicalNumber pn);
    bool operator!=(const PhysicalNumber pn);

    friend ostream &operator<<(ostream &os, const PhysicalNumber &pn);
    friend istream &operator>>(istream &is, PhysicalNumber pn);
};

ostream &operator<<(ostream &os, const PhysicalNumber &pn)
{
    os << pn.value << "[" << pn.measurement << "]";
    return os;
}

istream &operator>>(istream &is, PhysicalNumber pn)
{
    is >> pn.value >> pn.measurement;
    return is;
}

} // namespace ariel
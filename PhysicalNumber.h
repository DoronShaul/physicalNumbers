#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H

#include "Unit.h"
#include <iostream>
#include <sstream>

using std::ostream, std::istream, std::string, ariel::Unit;

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
  void setValue(double val) { this->value = val; }
  void setUnit(Unit u) { this->measurement = u; }
  PhysicalNumber operator+(const PhysicalNumber &pn);
  PhysicalNumber operator-(const PhysicalNumber &pn);
  PhysicalNumber &operator+=(const PhysicalNumber &pn);
  PhysicalNumber &operator-=(const PhysicalNumber &pn);
  PhysicalNumber &operator+();
  PhysicalNumber &operator-();
  PhysicalNumber &operator++();
  PhysicalNumber &operator--();
  PhysicalNumber &operator++(int);
  PhysicalNumber &operator--(int);
  bool operator<(const PhysicalNumber &pn);
  bool operator>(const PhysicalNumber &pn);
  bool operator<=(const PhysicalNumber &pn);
  bool operator>=(const PhysicalNumber &pn);
  bool operator==(const PhysicalNumber &pn);
  bool operator!=(const PhysicalNumber &pn);
  friend ostream &operator<<(ostream &os, const PhysicalNumber&);
  friend istream &operator>>(istream &is, PhysicalNumber&);
};

ostream &operator<<(ostream &os, const PhysicalNumber&);
istream &operator>>(istream &is, PhysicalNumber&);

} // namespace ariel

#endif
#include <iostream>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;
using std::ostream, std::istream;

double rightPnConverted(const PhysicalNumber &pn, const PhysicalNumber &pn1)
{
    double right = pn1.getValue();
    switch (pn.getUnit())
    {
    case Unit::CM:
        if (pn1.getUnit() == Unit::CM)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::M)
        {
            return right * 100;
        }
        else if (pn1.getUnit() == Unit::KM)
        {
            return right * 100000;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in cm, the right isn't a length unit");
        }

    case Unit::M:
        if (pn1.getUnit() == Unit::CM)
        {
            return right / 100;
        }
        else if (pn1.getUnit() == Unit::M)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::KM)
        {
            return right * 1000;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in meters, the right isn't a length unit");
        }

    case Unit::KM:
        if (pn1.getUnit() == Unit::CM)
        {
            return right / 100000;
        }
        else if (pn1.getUnit() == Unit::M)
        {
            return right / 1000;
        }
        else if (pn1.getUnit() == Unit::KM)
        {
            return right;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in km, the right isn't a length unit");
        }

    case Unit::G:
        if (pn1.getUnit() == Unit::G)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::KG)
        {
            return right * 1000;
        }
        else if (pn1.getUnit() == Unit::TON)
        {
            return right * 1000000;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in grams, the right isn't a weight unit");
        }

    case Unit::KG:
        if (pn1.getUnit() == Unit::G)
        {
            return right / 1000;
        }
        else if (pn1.getUnit() == Unit::KG)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::TON)
        {
            return right * 1000;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in kg, the right isn't a weight unit");
        }

    case Unit::TON:
        if (pn1.getUnit() == Unit::G)
        {
            return right / 1000000;
        }
        else if (pn1.getUnit() == Unit::KG)
        {
            return right / 1000;
        }
        else if (pn1.getUnit() == Unit::TON)
        {
            return right;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in tons, the right isn't a weight unit");
        }

    case Unit::SEC:
        if (pn1.getUnit() == Unit::SEC)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::MIN)
        {
            return right * 60;
        }
        else if (pn1.getUnit() == Unit::HOUR)
        {
            return right * 3600;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in seconds, the right isn't a time unit");
        }

    case Unit::MIN:
        if (pn1.getUnit() == Unit::SEC)
        {
            return right / 60;
        }
        else if (pn1.getUnit() == Unit::MIN)
        {
            return right;
        }
        else if (pn1.getUnit() == Unit::HOUR)
        {
            return right * 60;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in minutes, the right isn't a time unit");
        }

    case Unit::HOUR:
        if (pn1.getUnit() == Unit::SEC)
        {
            return right / 3600;
        }
        else if (pn1.getUnit() == Unit::MIN)
        {
            return right / 60;
        }
        else if (pn1.getUnit() == Unit::HOUR)
        {
            return right;
        }
        else
        {
            throw std::invalid_argument("the left physical number is in hours, the right isn't a time unit");
        }
    }
    return 0;
}

PhysicalNumber::PhysicalNumber(double k, Unit u)
{
    value = k;
    measurement = u;
}

PhysicalNumber::~PhysicalNumber()
{
    value = NULL;
}
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    PhysicalNumber ans(this->getValue() + right, this->getUnit());
    return ans;
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    PhysicalNumber ans(this->getValue() - right, this->getUnit());
    return ans;
}
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    this->setValue(this->getValue() + right);
    return *this;
}
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    this->setValue(this->getValue() - right);
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

bool PhysicalNumber::operator>(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value > right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PhysicalNumber::operator<(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value < right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PhysicalNumber::operator<=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value <= right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PhysicalNumber::operator>=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value >= right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PhysicalNumber::operator==(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value == right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PhysicalNumber::operator!=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    if (this->value != right)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &ariel::operator<<(ostream &os, const PhysicalNumber &pn)
{
    os << pn.getValue() << "[" << pn.getUnit() << "]";
    return os;
}

istream &ariel::operator>>(istream &is, PhysicalNumber &pn)
{

    return is;
}

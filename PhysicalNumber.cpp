#include <iostream>
#include <string>
#include "PhysicalNumber.h"
#include "Unit.h"
#include <sstream>

using namespace ariel;
using std::ostream, std::istream, std::string, std::cout;

//this method converts the right physical number's value to the measurement unit of the left one.
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

//this method is a constructor.
PhysicalNumber::PhysicalNumber(double k, Unit u)
{
    value = k;
    measurement = u;
}

//this method is a destructor.
PhysicalNumber::~PhysicalNumber()
{
    value = NULL;
}

//this method overloads the operator+ (binary).
//adds the right value and the left value if their units are of the same category.
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    PhysicalNumber ans(this->getValue() + right, this->getUnit());
    return ans;
}

//this method overloads the operator- (binary).
//subtructs the right value from the left value if their units are of the same category.
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    PhysicalNumber ans(this->getValue() - right, this->getUnit());
    return ans;
}
//this method overloads the operator+= (binary).
//adds the right value to the left value if their units are of the same category.
PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    this->setValue(this->getValue() + right);
    return *this;
}

//this method overloads the operator-= (binary).
//subtructs the right value from the left value if their units are of the same category.
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &pn)
{
    double right = rightPnConverted(*this, pn);
    this->setValue(this->getValue() - right);
    return *this;
}

//this method overloads the operator+ (unary).
PhysicalNumber PhysicalNumber::operator+()
{
    return PhysicalNumber(this->value, this->measurement);
}

//this method overloads the operator- (unary).
PhysicalNumber PhysicalNumber::operator-()
{
    return PhysicalNumber(this->value*(-1), this->measurement);
}

//this method overloads the operator++ (prefix).
PhysicalNumber &PhysicalNumber::operator++()
{
    this->value = this->value + 1;
    return *this;
}

//this method overloads the operator-- (prefix).
PhysicalNumber &PhysicalNumber::operator--()
{
    this->value = this->value - 1;
    return *this;
}

//this method overloads the operator++ (postfix).
PhysicalNumber PhysicalNumber::operator++(int)
{
    PhysicalNumber res(*this);
    ++(*this);
    return res;
}

//this method overloads the operator-- (postfix).
PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber res(*this);
    --(*this);
    return res;
}

//this method overloads the operator>.
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

//this method overloads the operator<.
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

//this method overloads the operator<=.
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

//this method overloads the operator>=.
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

//this method overloads the operator==.
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

//this method overloads the operator!=.
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
//this method overloads the operator<<. the output is "value[unit]".
ostream &ariel::operator<<(ostream &os, const PhysicalNumber &pn)
{
    os << pn.getValue() << "[" << pn.getUnit() << "]";
    return os;
}

//this method overloads the operator>>.
istream &ariel::operator>>(istream &is, PhysicalNumber &pn)
{
    string input, valueStr, unitStr;
    string::size_type sz;
    getline(is, input);                    //inserts the input stream (is) to the input string (input).
    std::size_t pos = input.find("[");     //finds the position of the char '[' in the input string.
    valueStr = input.substr(0, pos);       //substring the input string from the first char to pos(that's the value).
    double val = std::stod(valueStr, &sz); //converts the valueStr to a double and puts it in val parameter.
    unitStr = input.substr(pos);           //substring the input string from the char '[' to the end(that's the unit).
    pn.value = val;

    if (unitStr == "[kg]" || unitStr == "[KG]")
    {
        pn.measurement = Unit::KG;
    }
    else if (unitStr == "[g]" || unitStr == "[G]")
    {
        pn.measurement = Unit::G;
    }
    else if (unitStr == "[ton]" || unitStr == "[TON]")
    {
        pn.measurement = Unit::TON;
    }
    else if (unitStr == "[sec]" || unitStr == "[SEC]")
    {
        pn.measurement = Unit::SEC;
    }
    else if (unitStr == "[min]" || unitStr == "[MIN]")
    {
        pn.measurement = Unit::MIN;
    }
    else if (unitStr == "[hour]" || unitStr == "[HOUR]")
    {
        pn.measurement = Unit::HOUR;
    }
    else if (unitStr == "[cm]" || unitStr == "[CM]")
    {
        pn.measurement = Unit::CM;
    }
    else if (unitStr == "[m]" || unitStr == "[M]")
    {
        pn.measurement = Unit::M;
    }
    else if (unitStr == "[km]" || unitStr == "[KM]")
    {
        pn.measurement = Unit::KM;
    }
    else
    {
        throw std::invalid_argument("unknown unit");
    }

    return is;
}

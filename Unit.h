#include <iostream>

#pragma once

namespace ariel
{
enum class Unit
{
    CM,
    M,
    KM,
    G,
    KG,
    TON,
    SEC,
    MIN,
    HOUR

};

std::ostream &operator<<(std::ostream &os, Unit u)
{
    switch (u)
    {
    case Unit::CM:
        os << "cm";
        break;
    case Unit::M:
        os << "m";
        break;
    case Unit::KM:
        os << "km";
        break;
    case Unit::G:
        os << "g";
        break;
    case Unit::KG:
        os << "kg";
        break;
    case Unit::TON:
        os << "ton";
        break;
    case Unit::SEC:
        os << "sec";
        break;
    case Unit::MIN:
        os << "min";
        break;
    case Unit::HOUR:
        os << "hour";
        break;
    default:
        os << "none";
        break;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Unit &u)
{
    is >> u;
    return is;
}
} // namespace ariel

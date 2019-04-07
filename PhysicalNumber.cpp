#include <iostream>
#include <string.h>
#include "PhysicalNumber.h"

using namespace ariel;

/*
A constructor that get a number and a unit.
*/
PhysicalNumber::PhysicalNumber(double data, Unit unit)
{
    data = data;
    unit = unit;
}

PhysicalNumber PhysicalNumber::operator+(PhysicalNumber& other)
{
    return PhysicalNumber(0, Unit::M);
}

const PhysicalNumber PhysicalNumber::operator+()
{
    return PhysicalNumber(0, Unit::M);
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
{
    return *this;
}

// Negativ function.
PhysicalNumber PhysicalNumber::operator-(PhysicalNumber& other)
{
    return PhysicalNumber(0, Unit::M);
}

const PhysicalNumber PhysicalNumber::operator-()
{
    return PhysicalNumber(0, Unit::M);
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator++()
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator--()
{
    return *this;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& other)
{
    return false;
}

const bool PhysicalNumber::operator<(const PhysicalNumber& other)
{
    return false;
}

const bool PhysicalNumber::operator<=(const PhysicalNumber& other)
{
    return false;
}

const bool PhysicalNumber::operator>=(const PhysicalNumber& other)
{
    return false;
}

const bool PhysicalNumber::operator==(const PhysicalNumber& other)
{
    return false;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber& other)
{
    return false;
}

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& pn)
{
    return os;
}

istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
    return is;
}





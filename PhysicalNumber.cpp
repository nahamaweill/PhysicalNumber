#include <iostream>
#include <string.h>
#include <sstream>
#include <stdexcept>
#include "PhysicalNumber.h"

using namespace ariel;

/*
A constructor that gets a number and a unit.
*/
PhysicalNumber::PhysicalNumber(double data, Unit unit)
{
    this->data = data;
    this->unit = unit;
}

PhysicalNumber::~PhysicalNumber(){

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
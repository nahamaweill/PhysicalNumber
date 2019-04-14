#include <iostream>
#include <string.h>
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

/*
This function helps to know if 2 PhysicalNumber are on the same units group.
*/
bool PhysicalNumber::sameGroup(PhysicalNumber& num1, PhysicalNumber& num2)
{
    //If they have the same unit.
    if(num1.getUnit == num2.getUnit)
    {
        return true;
    }

    //If they both are time unit.
    else if((num1.getUnit == SEC || num1.getUnit == MIN || num1.getUnit == HOUR)
    && (num2.getUnit == SEC || num2.getUnit == MIN || num2.getUnit == HOUR))
    {
        return true;
    }

    //If they both are size unit.
    else if((num1.getUnit == CM || num1.getUnit == M || num1.getUnit == KM)
    && (num2.getUnit == CM || num2.getUnit == M || num2.getUnit == KM))
    {
        return true;
    }
    
    //If they both are weight unit.
    else if((num1.getUnit == G || num1.getUnit == KG || num1.getUnit == TON)
    && (num2.getUnit == G || num2.getUnit == KG || num2.getUnit == TON))
    {
        return true;
    }

    return false;
}

/*
This function sums 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger.
It gets help from sameGroup function
and convertIfSameGroup function.
*/
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber& other)
{
    //If they are not on the same group.
    if(sameGroup(*this, other) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(this->getUnit == other.getUnit)
    {
        return PhysicalNumber(this->data + other.data, this->unit);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(*this, other);
    }
    return PhysicalNumber(this->data + other.data, this->unit);
}

////////////////////////////////////////////////
const PhysicalNumber PhysicalNumber::operator+()
{
    return PhysicalNumber(0, Unit::M);
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
{
    this->operator+(other);
    return *this;
}

/*
This function subtracts 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger.
It gets help from sameGroup function
and convertIfSameGroup function.
*/
PhysicalNumber PhysicalNumber::operator-(PhysicalNumber& other)
{
    //If they are not on the same group.
    if(sameGroup(*this, other) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(this->getUnit == other.getUnit)
    {
        return PhysicalNumber(this->data - other.data, this->unit);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(*this, other);
    }
    return PhysicalNumber(this->data - other.data, this->unit);
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
    return os << "";
}

istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
    return is;
}
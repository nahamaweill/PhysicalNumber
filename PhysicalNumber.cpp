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

void PhysicalNumber::convertIfSameGroup(PhysicalNumber& num1, PhysicalNumber& num2)
{
    // Check if numbers are in the Length group.
    if((num1.getUnit == M) || (num1.getUnit == CM) || (num1.getUnit == KM)) 
    {
        if (((num1.getUnit == KM) && (num2.getUnit == M)) || ((num1.getUnit == M) && (num2.getUnit == KM))) // Checking if the numbers are from type 'km' and 'm'.
        {
            if (num1.getUnit == KM) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/1000);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/1000);
            }
        }
        else if (((num1.getUnit == KM) && (num2.getUnit == CM)) || ((num1.getUnit == CM) && (num2.getUnit == KM)))// Checking if the numbers are from type 'km' and 'cm'.
        {
            if (num1.getUnit == KM) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/100000);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/100000);
            }
        }
        else if (((num1.getUnit == M) && (num2.getUnit == CM)) || ((num1.getUnit == CM) && (num2.getUnit == M)))// Checking if the numbers are from type 'm' and 'cm'.
        {
            if (num1.getUnit == M) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/100);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/100);
            }
        }
    }
    // Check if the numbers are in the Time group.
    else if ((num1.getUnit == HOUR) || (num1.getUnit == MIN) || (num1.getData == SEC)) 
    {
        if (((num1.getUnit == HOUR) && (num2.getUnit == MIN)) || ((num1.getUnit == MIN) && (num2.getUnit == HOUR))) // Checking if the numbers are from type 'hour' and 'min'.
        {
            if (num1.getUnit == HOUR) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/60);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/60);
            }
        }
        else if (((num1.getUnit == HOUR) && (num2.getUnit == SEC)) || ((num1.getUnit == SEC) && (num2.getUnit == HOUR))) // Checking if the numbers are from type 'hour' and 'sec'.
        {
            if (num1.getUnit == HOUR) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/3600);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/3600);
            }
        }
        else if (((num1.getUnit == MIN) && (num2.getUnit == SEC)) || ((num1.getUnit == SEC) && (num2.getUnit == MIN))) // Checking if the numbers are from type 'min' and 'sec'.
        {
            if (num1.getUnit == MIN) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/60);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/60);
            }
        }
    }
    // Check if the numbers are in the weight group.
    else if ((num1.getUnit == TON) || (num1.getUnit == KG) || (num1.getData == G)) 
    {
        if (((num1.getUnit == TON) && (num2.getUnit == KG)) || ((num1.getUnit == KG) && (num2.getUnit == TON))) // Checking if the numbers are from type 'ton' and 'kg'.
        {
            if (num1.getUnit == TON) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/1000);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/1000);
            }
        }
        else if (((num1.getUnit == TON) && (num2.getUnit == G)) || ((num1.getUnit == G) && (num2.getUnit == TON))) // Checking if the numbers are from type 'ton' and 'g'.
        {
            if (num1.getUnit == TON) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/1000000);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/1000000);
            }
        }
        else if (((num1.getUnit == KG) && (num2.getUnit == G)) || ((num1.getUnit == G) && (num2.getUnit == KG))) // Checking if the numbers are from type 'kg' and 'g'.
        {
            if (num1.getUnit == KG) // Check if num1 is the bigger number.
            {
                num2.setData(num2.getData/1000);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.getData/1000);
            }
        }
    }
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
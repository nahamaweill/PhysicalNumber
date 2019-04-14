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
    if(num1.unit == num2.unit)
    {
        return true;
    }

    //If they both are time unit.
    else if((num1.unit == SEC || num1.unit == MIN || num1.unit == HOUR)
    && (num2.unit == SEC || num2.unit == MIN || num2.unit == HOUR))
    {
        return true;
    }

    //If they both are size unit.
    else if((num1.unit == CM || num1.unit == M || num1.unit == KM)
    && (num2.unit == CM || num2.unit == M || num2.unit == KM))
    {
        return true;
    }
    
    //If they both are weight unit.
    else if((num1.unit == G || num1.unit == KG || num1.unit == TON)
    && (num2.unit == G || num2.unit == KG || num2.unit == TON))
    {
        return true;
    }

    return false;
}

void PhysicalNumber::convertIfSameGroup(PhysicalNumber& num1, PhysicalNumber& num2)
{

    // Check if numbers are in the Length group.
    if((num1.unit == M) || (num1.unit == CM) || (num1.unit == KM)) 
    {
        if (((num1.unit == KM) && (num2.unit == M)) || ((num1.unit == M) && (num2.unit == KM))) // Checking if the numbers are from type 'km' and 'm'.
        {
            if (num1.unit == KM) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/1000);
                num2.setUnit(KM);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/1000);
                num1.setUnit(KM);
            }
        }
        else if (((num1.unit == KM) && (num2.unit == CM)) || ((num1.unit == CM) && (num2.unit == KM)))// Checking if the numbers are from type 'km' and 'cm'.
        {
            if (num1.unit == KM) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/100000);
                num2.setUnit(KM);

            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/100000);
                num1.setUnit(KM);

            }
        }
        else if (((num1.unit == M) && (num2.unit == CM)) || ((num1.unit == CM) && (num2.unit == M)))// Checking if the numbers are from type 'm' and 'cm'.
        {
            if (num1.unit == M) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/100);
                num2.setUnit(M);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/100);
                num1.setUnit(M);
            }
        }
    }
    // Check if the numbers are in the Time group.
    else if ((num1.unit == HOUR) || (num1.unit == MIN) || (num1.data == SEC)) 
    {
        if (((num1.unit == HOUR) && (num2.unit == MIN)) || ((num1.unit == MIN) && (num2.unit == HOUR))) // Checking if the numbers are from type 'hour' and 'min'.
        {
            if (num1.unit == HOUR) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/60);
                num2.setUnit(HOUR);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/60);
                num1.setUnit(HOUR);
            }
        }
        else if (((num1.unit == HOUR) && (num2.unit == SEC)) || ((num1.unit == SEC) && (num2.unit == HOUR))) // Checking if the numbers are from type 'hour' and 'sec'.
        {
            if (num1.unit == HOUR) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/3600);
                num2.setUnit(HOUR);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/3600);
                num1.setUnit(HOUR);
            }
        }
        else if (((num1.unit == MIN) && (num2.unit == SEC)) || ((num1.unit == SEC) && (num2.unit == MIN))) // Checking if the numbers are from type 'min' and 'sec'.
        {
            if (num1.unit == MIN) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/60);
                num2.setUnit(MIN);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/60);
                num1.setUnit(MIN);
            }
        }
    }
    // Check if the numbers are in the weight group.
    else if ((num1.unit == TON) || (num1.unit == KG) || (num1.data == G)) 
    {
        if (((num1.unit == TON) && (num2.unit == KG)) || ((num1.unit == KG) && (num2.unit == TON))) // Checking if the numbers are from type 'ton' and 'kg'.
        {
            if (num1.unit == TON) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/1000);
                num2.setUnit(TON);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/1000);
                num1.setUnit(TON);
            }
        }
        else if (((num1.unit == TON) && (num2.unit == G)) || ((num1.unit == G) && (num2.unit == TON))) // Checking if the numbers are from type 'ton' and 'g'.
        {
            if (num1.unit == TON) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/1000000);
                num2.setUnit(TON);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/1000000);
                num1.setUnit(TON);
            }
        }
        else if (((num1.unit == KG) && (num2.unit == G)) || ((num1.unit == G) && (num2.unit == KG))) // Checking if the numbers are from type 'kg' and 'g'.
        {
            if (num1.unit == KG) // Check if num1 is the bigger number.
            {
                num2.setData(num2.data/1000);
                num2.setUnit(KG);
            }   
            else // Else num2 is the bigger number.
            {
                num1.setData(num1.data/1000);
                num1.setUnit(KG);
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
    else if(this->unit == other.unit)
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
    else if(this->unit == other.unit)
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
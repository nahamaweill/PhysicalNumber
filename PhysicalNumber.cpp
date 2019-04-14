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
    //Checks if the numbers are in the size group.
    if((num1.unit == M) || (num1.unit == CM) || (num1.unit == KM)) 
    {
        if (((num1.unit == KM) && (num2.unit == M)) || ((num1.unit == M) && (num2.unit == KM))) //Checks if the numbers are from type 'km' and 'm'.
        {
            if (num1.unit == KM) //Checks if num1 is in 'km'.
            {
                num2.setData(num2.data / 1000);
                num2.setUnit(KM);
            }   
            else //Else - num1 is in 'm'.
            {
                num2.setData(num2.data * 1000);
                num2.setUnit(M);
            }
        }
        else if (((num1.unit == KM) && (num2.unit == CM)) || ((num1.unit == CM) && (num2.unit == KM))) //Checks if the numbers are from type 'km' and 'cm'.
        {
            if (num1.unit == KM) //Checks if num1 is in 'km'.
            {
                num2.setData(num2.data / 100000);
                num2.setUnit(KM);
            }   
            else //Else - num1 is in 'cm'.
            {
                num2.setData(num2.data * 100000);
                num2.setUnit(CM);
            }
        }
        else if (((num1.unit == M) && (num2.unit == CM)) || ((num1.unit == CM) && (num2.unit == M))) //Checks if the numbers are from type 'm' and 'cm'.
        {
            if (num1.unit == M) //Checks if num1 is in 'm'.
            {
                num2.setData(num2.data / 100);
                num2.setUnit(M);
            }   
            else // Else - num1 is in 'cm'.
            {
                num2.setData(num2.data * 100);
                num2.setUnit(CM);
            }
        }
    }
    //Checks if the numbers are in the time group.
    else if ((num1.unit == HOUR) || (num1.unit == MIN) || (num1.data == SEC)) 
    {
        if (((num1.unit == HOUR) && (num2.unit == MIN)) || ((num1.unit == MIN) && (num2.unit == HOUR))) //Checks if the numbers are from type 'hour' and 'min'.
        {
            if (num1.unit == HOUR) //Checks if num1 is in 'hour'.
            {
                num2.setData(num2.data / 60);
                num2.setUnit(HOUR);
            }   
            else //Else - num1 is in 'min'
            {
                num2.setData(num2.data * 60);
                num2.setUnit(MIN);
            }
        }
        else if (((num1.unit == HOUR) && (num2.unit == SEC)) || ((num1.unit == SEC) && (num2.unit == HOUR))) //Checks if the numbers are from type 'hour' and 'sec'.
        {
            if (num1.unit == HOUR) //Checks if num1 is in 'hour'.
            {
                num2.setData(num2.data / 3600);
                num2.setUnit(HOUR);
            }   
            else //Else - num1 is in 'sec'.
            {
                num2.setData(num2.data * 3600);
                num2.setUnit(SEC);
            }
        }
        else if (((num1.unit == MIN) && (num2.unit == SEC)) || ((num1.unit == SEC) && (num2.unit == MIN))) //Checks if the numbers are from type 'min' and 'sec'.
        {
            if (num1.unit == MIN) //Checks if num1 is in 'min'.
            {
                num2.setData(num2.data / 60);
                num2.setUnit(MIN);
            }   
            else //Else - num1 is in 'sec'.
            {
                num2.setData(num2.data * 60);
                num2.setUnit(SEC);
            }
        }
    }
    //Checks if the numbers are in the weight group.
    else if ((num1.unit == TON) || (num1.unit == KG) || (num1.data == G)) 
    {
        if (((num1.unit == TON) && (num2.unit == KG)) || ((num1.unit == KG) && (num2.unit == TON))) //Checks if the numbers are from type 'ton' and 'kg'.
        {
            if (num1.unit == TON) //Checks if num1 is in 'ton'.
            {
                num2.setData(num2.data / 1000);
                num2.setUnit(TON);
            }   
            else //Else - num1 is in 'kg'.
            {
                num2.setData(num2.data * 1000);
                num2.setUnit(KG);
            }
        }
        else if (((num1.unit == TON) && (num2.unit == G)) || ((num1.unit == G) && (num2.unit == TON))) //Checks if the numbers are from type 'ton' and 'g'.
        {
            if (num1.unit == TON) //Checks if num1 is in 'ton'.
            {
                num2.setData(num2.data / 1000000);
                num2.setUnit(TON);
            }   
            else //Else - num1 is in 'g'.
            {
                num2.setData(num2.data * 1000000);
                num2.setUnit(G);
            }
        }
        else if (((num1.unit == KG) && (num2.unit == G)) || ((num1.unit == G) && (num2.unit == KG))) //Checks if the numbers are from type 'kg' and 'g'.
        {
            if (num1.unit == KG) //Checks if num1 is in 'kg'.
            {
                num2.setData(num2.data / 1000);
                num2.setUnit(KG);
            }   
            else //Else - num1 is in 'g'.
            {
                num2.setData(num2.data * 1000);
                num2.setUnit(G);
            }
        }
    }
}

/*
This function sums 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger.
It gets help from sameGroup function
and convertIfSameGroup function.
*/
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other)
{
    PhysicalNumber tempThis = PhysicalNumber(this->data, this->unit); //temp for this.
    PhysicalNumber tempOther = PhysicalNumber(other.data, other.unit); //temp for other.

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(tempThis.unit == tempOther.unit)
    {
        return PhysicalNumber(tempThis.data + tempOther.data, tempThis.unit);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return PhysicalNumber(tempThis.data + tempOther.data, tempThis.unit);
}

/*
This function changes the data of the unit to the it's positive number.
*/
const PhysicalNumber PhysicalNumber::operator+()
{

    if (this->data <0)
    {
       return PhysicalNumber ((-1)*(this->data), this->unit);
    }
    else
    {
      return  PhysicalNumber (this->data, this->unit);
    }
}

/*
This function sums 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger,
and put it in the first number.
It gets help from operator+ function.
*/
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
{
    PhysicalNumber tempOther(other.data, other.unit);  //temp PhysicalNumber.
    *this = (*this).operator+(tempOther);
    return *this;
}

/*
This function subtracts 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger.
It gets help from sameGroup function
and convertIfSameGroup function.
*/
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other)
{
    PhysicalNumber tempThis = PhysicalNumber(this->data, this->unit);
    PhysicalNumber tempOther = PhysicalNumber(other.data, other.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(tempThis.unit == tempOther.unit)
    {
        return PhysicalNumber(tempThis.data - tempOther.data, tempThis.unit);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return PhysicalNumber(tempThis.data - tempOther.data, tempThis.unit);
}

/*
This function changes the data of the unit to the it's negative number.
*/
const PhysicalNumber PhysicalNumber::operator-()
{
    PhysicalNumber tempThis(this->data, this->unit);
    tempThis.setData((this->data) * (-1));
    return tempThis;
}

/*
This function subtracts 2 PhysicalNumbers if they on the same units group by convert the smaller to the bigger,
and put it in the first number.
It gets help from operator- function.
*/
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
{
    PhysicalNumber tempOther(other.data, other.unit); //temp PhysicalNumber.
    *this = (*this).operator-(tempOther);
    return *this;
}

/*
This function adds 1 to the data.
*/
PhysicalNumber& PhysicalNumber::operator++()
{
    this->setData(this->data + 1);
    return *this;
}

/*
This function subtracts 1 to the data.
*/
PhysicalNumber& PhysicalNumber::operator--()
{
    if(this->data < 1) //Checks if the data is smaller than 1.
    {
        __throw_runtime_error("The number is smaller than 1.");
    }

    this->setData(this->data - 1);
    return *this;
}

bool PhysicalNumber::operator>(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data > num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data > tempOther.data);
    
};

bool PhysicalNumber::operator<(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data < num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data < tempOther.data);
};

bool PhysicalNumber::operator<=(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data <= num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data <= tempOther.data);
};

bool PhysicalNumber::operator>=(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data >= num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data >= tempOther.data);
};

bool PhysicalNumber::operator==(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        __throw_runtime_error("They are not on the same group.");
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data == num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data == tempOther.data);
};

bool PhysicalNumber::operator!=(const PhysicalNumber& num1, const PhysicalNumber& num2)
{
    PhysicalNumber tempThis(num1.data, num1.unit);
    PhysicalNumber tempOther(num2.data, num2.unit);

    //If they are not on the same group.
    if(sameGroup(tempThis, tempOther) == false)
    {
        return true;
    }
    //If they have the same unit.
    else if(num1.unit == num2.unit)
    {
        return (num1.data != num2.data);
    }
    //If they don't have the same unit but they are on the same group.
    else
    {
        convertIfSameGroup(tempThis, tempOther);
    }
    return (tempThis.data != tempOther.data);
};

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& pn)
{
    string type = " ";
    switch(pn.unit)
    {
        case KM:
        type = "km";
        break;

        case M:
        type = "m";
        break;

        case CM:
        type = "cm";
        break;

        case HOUR:
        type = "hour";
        break;

        case MIN:
        type = "min";
        break;

        case SEC:
        type = "sec";
        break;

        case TON:
        type = "ton";
        break;

        case KG:
        type = "kg";
        break;

        case G:
        type = "g";
        break;

        default:
        cout << "ERROR";
    }

    return (os << pn.data << '[' << type << ']') ;
}

istream& ariel::operator>>(istream& is, PhysicalNumber& pn)
{
    string temp1, value1;
    int posStart=0;
    int posEnd=0;
    is>>temp1;
    posStart=temp1.find('[');
    posEnd=temp1.find(']');
    if((posStart<=0) || (posEnd!=temp1.length()-1) || (posStart+1==posEnd)|| (posEnd<0))
        return is;
    else 
    {
        value1 = temp1.substr(0, posStart);
        
        temp1 = temp1.substr(posStart + 1, temp1.length() - 2 - posStart);
        if ((temp1 == "cm") || (temp1 == "CM"))
            pn.setUnit(CM);
        else if ((temp1 == "m") || (temp1 == "M"))
            pn.setUnit(M);
        else if ((temp1 == "km") || (temp1 == "KM"))
            pn.setUnit(KM);
        else if ((temp1 == "sec") || (temp1 == "SEC"))
            pn.setUnit(SEC);
        else if ((temp1 == "min") || (temp1 == "MIN"))
            pn.setUnit(MIN);
        else if ((temp1 == "hour") || (temp1 == "HOUR"))
            pn.setUnit(HOUR);
        else if ((temp1 == "g") || (temp1 == "G"))
            pn.setUnit(G);
        else if ((temp1 == "kg") || (temp1 == "KG"))
            pn.setUnit(KG);
        else if ((temp1 == "ton") || (temp1 == "TON"))
            pn.setUnit(TON);
        else
            return is;
    }
    pn.setData(stod(value1));
    return is;
}
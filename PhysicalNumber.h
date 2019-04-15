#include <iostream>
#include "Unit.h"

namespace ariel
{
using namespace std;
    class PhysicalNumber
    {
        private: //Private functions.

        Unit unit; //Kinds of units size which explains what is the data before.
        double data; //A number of unit size.

        //Help functions:
        bool sameGroup(PhysicalNumber& num1, PhysicalNumber& num2);
        void convertIfSameGroup(PhysicalNumber& num1, PhysicalNumber& num2);

        public: //Public functions.

        PhysicalNumber(double data, Unit unit); //A constructor.
        
        //Setters:
        void setUnit(Unit un)
        {
            this->unit = un;
        }

        void setData(double data)
        {
            this->data = data;
        }

        //Positive:
        PhysicalNumber operator+(const PhysicalNumber& other);
        const PhysicalNumber operator+(); //onary
        PhysicalNumber& operator+=(const PhysicalNumber& other);

        //Negative:
        PhysicalNumber operator-(const PhysicalNumber& other);
        const PhysicalNumber operator-(); //onary
        PhysicalNumber& operator-=(const PhysicalNumber& other);

        bool operator>(const PhysicalNumber& num2);
        bool operator<(const PhysicalNumber& num2);
        bool operator<=(const PhysicalNumber& num2);
        bool operator>=(const PhysicalNumber& num2);
        bool operator==(const PhysicalNumber& num2);
        bool operator!=(const PhysicalNumber& num2);


        PhysicalNumber& operator++();
        PhysicalNumber& operator--();
        PhysicalNumber operator++(int);
        PhysicalNumber operator--(int);

        friend ostream& operator<<(ostream& os, const PhysicalNumber& pn);
        friend istream& operator>>(istream& is, PhysicalNumber& pn);
    };
    
    ostream& operator<<(ostream& os, const PhysicalNumber& pn);
    istream& operator>>(istream& is, PhysicalNumber& pn);
}

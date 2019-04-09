#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

namespace ariel
{
using namespace std;
    class PhysicalNumber
    {
        private: //Private functions.

        Unit unit; //Kinds of units size which explains what is the data before.
        double data; //A number of unit size.

        public: //Public functions.

        PhysicalNumber(double data, Unit unit); //A constructor.
        ~PhysicalNumber(); //Destructor

        //Positive:
        PhysicalNumber operator+(PhysicalNumber& other);
        const PhysicalNumber operator+(); //onary
        PhysicalNumber& operator+=(const PhysicalNumber& other);

        //Negative:
        PhysicalNumber operator-(PhysicalNumber& other);
        const PhysicalNumber operator-(); //onary
        PhysicalNumber& operator-=(const PhysicalNumber& other);

        const bool operator>(const PhysicalNumber& other);
        const bool operator<(const PhysicalNumber& other);
        const bool operator<=(const PhysicalNumber& other);
        const bool operator>=(const PhysicalNumber& other);
        const bool operator==(const PhysicalNumber& other);
        const bool operator!=(const PhysicalNumber& other);


        PhysicalNumber& operator++();
        PhysicalNumber& operator--();

        friend ostream& operator<<(ostream& os, const PhysicalNumber& pn);
        friend istream& operator>>(istream& is, PhysicalNumber& pn);
    };
    ostream& operator<<(ostream& os, const PhysicalNumber& pn);
    istream& operator>>(istream& is, PhysicalNumber& pn);
}

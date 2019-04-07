#include <iostream>
#include "Unit.h"

namespace ariel {

using namespace std;

    class PhysicalNumber {

        private: //All the private functions.

        Unit unit;
        double data;

        public:  //All the public functions.

        PhysicalNumber(double data, Unit unit);

        //Positive
        PhysicalNumber operator+(PhysicalNumber& other);
        const PhysicalNumber operator+(); //onary
        PhysicalNumber& operator+=(const PhysicalNumber& other);

        //Negative
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
}

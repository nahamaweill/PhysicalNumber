/**
 * Examples of automatic tests for the exercise on physical numbers.
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main()
{
  badkan::TestCase testcase;
  int grade = 0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber e(60, Unit::SEC);
    PhysicalNumber f(200, Unit::G);
    PhysicalNumber g(1, Unit::TON);
    PhysicalNumber h(20, Unit::MIN);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
    
    .setname("MyTest")
    .CHECK_OK(istringstream("30[min]") >> d)
    .CHECK_OK(istringstream("20[min]") >> h)
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(h, "20[min]")
    .CHECK_OUTPUT(d+h-h, "30[min]") //Checks if the output is right.
    .CHECK_THROWS(d+g) //Checks if METER + GRAM throws exception.
    .CHECK_OUTPUT(g, "1[ton]")
    .CHECK_OUTPUT(f, "200[g]")
    .CHECK_OUTPUT(g+f, "[1000200]") //Checks if it converts the TON to Gram and sums them.
    .CHECK_OUTPUT(-(g+f), "[1000200]") //Checks if the negative onary operator works(after sum).
    .CHECK_OUTPUT(+(g+f), "[1000200]") //Checks if the positive onary operator works(after sum).
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(-b, "-300[m]") //Checks if the negative onary operator works.
    .CHECK_OUTPUT(+b, "300[m]") //Checks if the positive onary operator works.
    .CHECK_OUTPUT(+b, "300[m]") //Checks if nothing has changed.
    .CHECK_OUTPUT((d>h), "true")
    .CHECK_THROWS(d>g) //Checks if METER > GRAM throws exaption.
    .CHECK_OUTPUT((h<d), "true")
    .CHECK_THROWS(h<g) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(h==g) //Checks if MINUTE == GRAM throws exception.
    .CHECK_THROWS(h<=g) //Checks if MINUTE <= GRAM throws exception.
    .CHECK_THROWS(h>=g) //Checks if MINUTE >= GRAM throws exception.
    .CHECK_THROWS(h+=g) //Checks if MINUTE += GRAM throws exception.
    .CHECK_THROWS(h-=g) //Checks if MINUTE -= GRAM throws exception.
    .CHECK_OUTPUT((c<=d), "false")
    .CHECK_OUTPUT(h, "30[min]") //Checks if the change worked well.
    .CHECK_OUTPUT((h==d), "true")
    .CHECK_OUTPUT(++c, "3[hour]")
    .CHECK_OUTPUT(c, "3[hour]") //Checks if the change worked well.
    .CHECK_OUTPUT(--g, "0[ton]")
    .CHECK_OUTPUT(g, "0[ton]") //Checks if the change worked well.
    .CHECK_OUTPUT((c<h), "false")
    .CHECK_THROWS(c>a) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(c<a) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(c==a) //Checks if MINUTE == GRAM throws exception.
    .CHECK_THROWS(c<=a) //Checks if MINUTE <= GRAM throws exception.
    .CHECK_THROWS(c>=a) //Checks if MINUTE >= GRAM throws exception.
    .CHECK_THROWS(c+=a) //Checks if MINUTE += GRAM throws exception.
    .CHECK_THROWS(c-=a) //Checks if MINUTE -= GRAM throws exception.
    .CHECK_OUTPUT((c-=h), "2.5[hour]")
    .CHECK_OUTPUT(c, "2.5[hour]") //Checks if the change worked well.
    .CHECK_OK(istringstream("2[km]") >> a)
    .CHECK_OK(istringstream("2.5[hour]") >> c)
    .CHECK_OUTPUT(a-b, "1.7[km]")
    .CHECK_THROWS(a!=e) //Checks if KILOMETER -= SECOND throws exception.
    .CHECK_OUTPUT((a!=b), "false")

    .print(cout, /*show_grade=*/false);
    grade = testcase.grade();
    }
    else
    {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "* Grade: " << grade << " *" << endl;
    return grade;
}
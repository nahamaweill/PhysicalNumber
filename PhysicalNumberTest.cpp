/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
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
      .CHECK_OUTPUT(d, "30[min]")
      .CHECK_OUTPUT(h, "20[min]")
      .CHECK_OUTPUT(d+h-h, "30[min]")
      .CHECK_THROWS(d+g)
      .CHECK_OUTPUT(g, "1[ton]")
      .CHECK_OUTPUT(f, "200[g]")
      .CHECK_OUTPUT(g+f, "[]")
      .CHECK_OUTPUT(b, "300[m]")
      .CHECK_OUTPUT(b-, "-300[m]")
      .CHECK_OUTPUT(b+, "300[m]")
      .CHECK_OUTPUT(d>h, true)
      .CHECK_OUTPUT(c<=d, false)
      .CHECK_OUTPUT(h+=10, "30[min]")
      .CHECK_OUTPUT(h==d,true)
      .CHECK_OUTPUT(c++, "3[hour]")
      .CHECK_OUTPUT(g--, "0[ton]")
      .CHECK_THROWS(c-=f)
      .CHECK_OK(istringstream("2[km]") >> a)
      .CHECK_OUTPUT(a-b, "1.7[km]")
      .CHECK_THROWS(a!=e)
      .CHECK_OUTPUT(a!=b, false)



      .print(cout, /show_grade=/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "* Grade: " << grade << " *" << endl;
    return grade;
}

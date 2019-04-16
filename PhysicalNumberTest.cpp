#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

/**
 * Examples of automatic tests for the exercise on physical numbers.
 */
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
    PhysicalNumber i(2.3, Unit::KM);
    PhysicalNumber j(2.7, Unit::HOUR);
    PhysicalNumber k(1.1, Unit::HOUR);
    PhysicalNumber l(100, Unit::CM);
    PhysicalNumber mi(110, Unit::MIN);
    PhysicalNumber se(600, Unit::SEC);

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
    
    //Checks all the exceptions options:
    .CHECK_OUTPUT(a, "1700[kg]") //Checks if the output is right.
    .CHECK_THROWS(a+b) //Checks if KILOGRAM + METER throws exception.
    .CHECK_THROWS(a+c) //Checks if KILOGRAM + HOUR throws exception.
    .CHECK_THROWS(a+d) //Checks if KILOGRAM + MINUTE throws exception.
    .CHECK_THROWS(a+e) //Checks if KILOGRAM + SECOND throws exception.
    .CHECK_THROWS(a+i) //Checks if KILOGRAM + KILOMETER throws exception.
    .CHECK_THROWS(a+l) //Checks if KILOGRAM + CENTIMETER throws exception.
    .CHECK_THROWS(a+=b) //Checks if KILOGRAM += METER throws exception.
    .CHECK_THROWS(a+=c) //Checks if KILOGRAM + =HOUR throws exception.
    .CHECK_THROWS(a+=d) //Checks if KILOGRAM += MINUTE throws exception.
    .CHECK_THROWS(a+=e) //Checks if KILOGRAM += SECOND throws exception.
    .CHECK_THROWS(a+=i) //Checks if KILOGRAM += KILOMETER throws exception.
    .CHECK_THROWS(a+=l) //Checks if KILOGRAM += CENTIMETER throws exception.
    .CHECK_THROWS(a-b) //Checks if KILOGRAM - METER throws exception.
    .CHECK_THROWS(a-c) //Checks if KILOGRAM - HOUR throws exception.
    .CHECK_THROWS(a-d) //Checks if KILOGRAM - MINUTE throws exception.
    .CHECK_THROWS(a-e) //Checks if KILOGRAM - SECOND throws exception.
    .CHECK_THROWS(a-i) //Checks if KILOGRAM - KILOMETER throws exception.
    .CHECK_THROWS(a-l) //Checks if KILOGRAM - CENTIMETER throws exception.
    .CHECK_THROWS(a-=b) //Checks if KILOGRAM -= METER throws exception.
    .CHECK_THROWS(a-=c) //Checks if KILOGRAM -= HOUR throws exception.
    .CHECK_THROWS(a-=d) //Checks if KILOGRAM -= MINUTE throws exception.
    .CHECK_THROWS(a-=e) //Checks if KILOGRAM -= SECOND throws exception.
    .CHECK_THROWS(a-=i) //Checks if KILOGRAM -= KILOMETER throws exception.
    .CHECK_THROWS(a-=l) //Checks if KILOGRAM -= CENTIMETER throws exception.
    .CHECK_THROWS(a>b) //Checks if KILOGRAM > METER throws exception.
    .CHECK_THROWS(a>c) //Checks if KILOGRAM > HOUR throws exception.
    .CHECK_THROWS(a>d) //Checks if KILOGRAM > MINUTE throws exception.
    .CHECK_THROWS(a>e) //Checks if KILOGRAM > SECOND throws exception.
    .CHECK_THROWS(a>i) //Checks if KILOGRAM > KILOMETER throws exception.
    .CHECK_THROWS(a>l) //Checks if KILOGRAM > CENTIMETER throws exception.
    .CHECK_THROWS(a>=b) //Checks if KILOGRAM >= METER throws exception.
    .CHECK_THROWS(a>=c) //Checks if KILOGRAM >= HOUR throws exception.
    .CHECK_THROWS(a>=d) //Checks if KILOGRAM >= MINUTE throws exception.
    .CHECK_THROWS(a>=e) //Checks if KILOGRAM >= SECOND throws exception.
    .CHECK_THROWS(a>=i) //Checks if KILOGRAM >= KILOMETER throws exception.
    .CHECK_THROWS(a>=l) //Checks if KILOGRAM >= CENTIMETER throws exception.
    .CHECK_THROWS(a<b) //Checks if KILOGRAM < METER throws exception.
    .CHECK_THROWS(a<c) //Checks if KILOGRAM < HOUR throws exception.
    .CHECK_THROWS(a<d) //Checks if KILOGRAM < MINUTE throws exception.
    .CHECK_THROWS(a<e) //Checks if KILOGRAM < SECOND throws exception.
    .CHECK_THROWS(a<i) //Checks if KILOGRAM < KILOMETER throws exception.
    .CHECK_THROWS(a<l) //Checks if KILOGRAM < CENTIMETER throws exception.
    .CHECK_THROWS(a<=b) //Checks if KILOGRAM <= METER throws exception.
    .CHECK_THROWS(a<=c) //Checks if KILOGRAM <= HOUR throws exception.
    .CHECK_THROWS(a<=d) //Checks if KILOGRAM <= MINUTE throws exception.
    .CHECK_THROWS(a<=e) //Checks if KILOGRAM <= SECOND throws exception.
    .CHECK_THROWS(a<=i) //Checks if KILOGRAM <= KILOMETER throws exception.
    .CHECK_THROWS(a<=l) //Checks if KILOGRAM <= CENTIMETER throws exception.

    .CHECK_THROWS(f+b) //Checks if GRAM + METER throws exception.
    .CHECK_THROWS(f+c) //Checks if GRAM + HOUR throws exception.
    .CHECK_THROWS(f+d) //Checks if GRAM + MINUTE throws exception.
    .CHECK_THROWS(f+e) //Checks if GRAM + SECOND throws exception.
    .CHECK_THROWS(f+i) //Checks if GRAM + KILOMETER throws exception.
    .CHECK_THROWS(f+l) //Checks if GRAM + CENTIMETER throws exception.
    .CHECK_THROWS(f+=b) //Checks if GRAM += METER throws exception.
    .CHECK_THROWS(f+=c) //Checks if GRAM + =HOUR throws exception.
    .CHECK_THROWS(f+=d) //Checks if GRAM += MINUTE throws exception.
    .CHECK_THROWS(f+=e) //Checks if GRAM += SECOND throws exception.
    .CHECK_THROWS(f+=i) //Checks if GRAM += KILOMETER throws exception.
    .CHECK_THROWS(f+=l) //Checks if GRAM += CENTIMETER throws exception.
    .CHECK_THROWS(f-b) //Checks if GRAM - METER throws exception.
    .CHECK_THROWS(f-c) //Checks if GRAM - HOUR throws exception.
    .CHECK_THROWS(f-d) //Checks if GRAM - MINUTE throws exception.
    .CHECK_THROWS(f-e) //Checks if GRAM - SECOND throws exception.
    .CHECK_THROWS(f-i) //Checks if GRAM - KILOMETER throws exception.
    .CHECK_THROWS(f-l) //Checks if GRAM - CENTIMETER throws exception.
    .CHECK_THROWS(f-=b) //Checks if GRAM -= METER throws exception.
    .CHECK_THROWS(f-=c) //Checks if GRAM -= HOUR throws exception.
    .CHECK_THROWS(f-=d) //Checks if GRAM -= MINUTE throws exception.
    .CHECK_THROWS(f-=e) //Checks if GRAM -= SECOND throws exception.
    .CHECK_THROWS(f-=i) //Checks if GRAM -= KILOMETER throws exception.
    .CHECK_THROWS(f-=l) //Checks if GRAM -= CENTIMETER throws exception.
    .CHECK_THROWS(f>b) //Checks if GRAM > METER throws exception.
    .CHECK_THROWS(f>c) //Checks if GRAM > HOUR throws exception.
    .CHECK_THROWS(f>d) //Checks if GRAM > MINUTE throws exception.
    .CHECK_THROWS(f>e) //Checks if GRAM > SECOND throws exception.
    .CHECK_THROWS(f>i) //Checks if GRAM > KILOMETER throws exception.
    .CHECK_THROWS(f>l) //Checks if GRAM > CENTIMETER throws exception.
    .CHECK_THROWS(f>=b) //Checks if GRAM >= METER throws exception.
    .CHECK_THROWS(f>=c) //Checks if GRAM >= HOUR throws exception.
    .CHECK_THROWS(f>=d) //Checks if GRAM >= MINUTE throws exception.
    .CHECK_THROWS(f>=e) //Checks if GRAM >= SECOND throws exception.
    .CHECK_THROWS(f>=i) //Checks if GRAM >= KILOMETER throws exception.
    .CHECK_THROWS(f>=l) //Checks if GRAM >= CENTIMETER throws exception.
    .CHECK_THROWS(f<b) //Checks if GRAM < METER throws exception.
    .CHECK_THROWS(f<c) //Checks if GRAM < HOUR throws exception.
    .CHECK_THROWS(f<d) //Checks if GRAM < MINUTE throws exception.
    .CHECK_THROWS(f<e) //Checks if GRAM < SECOND throws exception.
    .CHECK_THROWS(f<i) //Checks if GRAM < KILOMETER throws exception.
    .CHECK_THROWS(f<l) //Checks if GRAM < CENTIMETER throws exception.
    .CHECK_THROWS(f<=b) //Checks if GRAM <= METER throws exception.
    .CHECK_THROWS(f<=c) //Checks if GRAM <= HOUR throws exception.
    .CHECK_THROWS(f<=d) //Checks if GRAM <= MINUTE throws exception.
    .CHECK_THROWS(f<=e) //Checks if GRAM <= SECOND throws exception.
    .CHECK_THROWS(f<=i) //Checks if GRAM <= KILOMETER throws exception.
    .CHECK_THROWS(f<=l) //Checks if GRAM <= CENTIMETER throws exception.

    .CHECK_THROWS(g+b) //Checks if TON + METER throws exception.
    .CHECK_THROWS(g+c) //Checks if TON + HOUR throws exception.
    .CHECK_THROWS(g+d) //Checks if TON + MINUTE throws exception.
    .CHECK_THROWS(g+e) //Checks if TON + SECOND throws exception.
    .CHECK_THROWS(g+i) //Checks if TON + KILOMETER throws exception.
    .CHECK_THROWS(g+l) //Checks if TON + CENTIMETER throws exception.
    .CHECK_THROWS(g+=b) //Checks if TON += METER throws exception.
    .CHECK_THROWS(g+=c) //Checks if TON + =HOUR throws exception.
    .CHECK_THROWS(g+=d) //Checks if TON += MINUTE throws exception.
    .CHECK_THROWS(g+=e) //Checks if TON += SECOND throws exception.
    .CHECK_THROWS(g+=i) //Checks if TON += KILOMETER throws exception.
    .CHECK_THROWS(g+=l) //Checks if TON += CENTIMETER throws exception.
    .CHECK_THROWS(g-b) //Checks if TON - METER throws exception.
    .CHECK_THROWS(g-c) //Checks if TON - HOUR throws exception.
    .CHECK_THROWS(g-d) //Checks if TON - MINUTE throws exception.
    .CHECK_THROWS(g-e) //Checks if TON - SECOND throws exception.
    .CHECK_THROWS(g-i) //Checks if TON - KILOMETER throws exception.
    .CHECK_THROWS(g-l) //Checks if TON - CENTIMETER throws exception.
    .CHECK_THROWS(g-=b) //Checks if TON -= METER throws exception.
    .CHECK_THROWS(g-=c) //Checks if TON -= HOUR throws exception.
    .CHECK_THROWS(g-=d) //Checks if TON -= MINUTE throws exception.
    .CHECK_THROWS(g-=e) //Checks if TON -= SECOND throws exception.
    .CHECK_THROWS(g-=i) //Checks if TON -= KILOMETER throws exception.
    .CHECK_THROWS(g-=l) //Checks if TON -= CENTIMETER throws exception.
    .CHECK_THROWS(g>b) //Checks if TON > METER throws exception.
    .CHECK_THROWS(g>c) //Checks if TON > HOUR throws exception.
    .CHECK_THROWS(g>d) //Checks if TON > MINUTE throws exception.
    .CHECK_THROWS(g>e) //Checks if TON > SECOND throws exception.
    .CHECK_THROWS(g>i) //Checks if TON > KILOMETER throws exception.
    .CHECK_THROWS(g>l) //Checks if TON > CENTIMETER throws exception.
    .CHECK_THROWS(g>=b) //Checks if TON >= METER throws exception.
    .CHECK_THROWS(g>=c) //Checks if TON >= HOUR throws exception.
    .CHECK_THROWS(g>=d) //Checks if TON >= MINUTE throws exception.
    .CHECK_THROWS(g>=e) //Checks if TON >= SECOND throws exception.
    .CHECK_THROWS(g>=i) //Checks if TON >= KILOMETER throws exception.
    .CHECK_THROWS(g>=l) //Checks if TON >= CENTIMETER throws exception.
    .CHECK_THROWS(g<b) //Checks if TON < METER throws exception.
    .CHECK_THROWS(g<c) //Checks if TON < HOUR throws exception.
    .CHECK_THROWS(g<d) //Checks if TON < MINUTE throws exception.
    .CHECK_THROWS(g<e) //Checks if TON < SECOND throws exception.
    .CHECK_THROWS(g<i) //Checks if TON < KILOMETER throws exception.
    .CHECK_THROWS(g<l) //Checks if TON < CENTIMETER throws exception.
    .CHECK_THROWS(g<=b) //Checks if TON <= METER throws exception.
    .CHECK_THROWS(g<=c) //Checks if TON <= HOUR throws exception.
    .CHECK_THROWS(g<=d) //Checks if TON <= MINUTE throws exception.
    .CHECK_THROWS(g<=e) //Checks if TON <= SECOND throws exception.
    .CHECK_THROWS(g<=i) //Checks if TON <= KILOMETER throws exception.
    .CHECK_THROWS(g<=l) //Checks if TON <= CENTIMETER throws exception.

    .CHECK_OUTPUT(--g, "0[ton]")
    .CHECK_THROWS(--g) //Checks if it throws exception for a negative number.
    .CHECK_OUTPUT(++g, "1[ton]")

    .CHECK_OUTPUT(g--, "1[ton]")
    .CHECK_THROWS(g--) //Checks if it throws exception for a negative number.
    .CHECK_OUTPUT(g++, "0[ton]")
    .CHECK_OUTPUT(g, "1[ton]")

    //All the other tests:
    .CHECK_OK(istringstream("30[min]") >> d)
    .CHECK_OK(istringstream("20[min]") >> h)
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(h, "20[min]")
    .CHECK_OUTPUT(d+h-h, "30[min]") //Checks if the output is right.
    .CHECK_THROWS(d+g) //Checks if METER + GRAM throws exception.

    .CHECK_OUTPUT(g, "1[ton]")
    .CHECK_OUTPUT(f, "200[g]")
    .CHECK_OUTPUT(g+f, "1.0002[ton]") //Checks if it converts the TON to Gram and sums them.
    .CHECK_OUTPUT(-(g+f), "-1.0002[ton]") //Checks if the negative onary operator works(after sum).
    .CHECK_OUTPUT(+(g+f), "1.0002[ton]") //Checks if the positive onary operator works(after sum).

    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(-b, "-300[m]") //Checks if the negative onary operator works.
    .CHECK_OUTPUT(+b, "300[m]") //Checks if the positive onary operator works.
    .CHECK_OUTPUT(+b, "300[m]") //Checks if nothing has changed.

    .CHECK_OUTPUT((d>h), "1")
    .CHECK_THROWS(d>g) //Checks if METER > GRAM throws exception.

    .CHECK_OUTPUT((h<d), "1")
    .CHECK_THROWS(h<g) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(h==g) //Checks if MINUTE == GRAM throws exception.
    .CHECK_THROWS(h<=g) //Checks if MINUTE <= GRAM throws exception.
    .CHECK_THROWS(h>=g) //Checks if MINUTE >= GRAM throws exception.
    .CHECK_THROWS(h+=g) //Checks if MINUTE += GRAM throws exception.
    .CHECK_THROWS(h-=g) //Checks if MINUTE -= GRAM throws exception.

    .CHECK_OUTPUT((c<=d), "0")
    .CHECK_OUTPUT(h, "20[min]") //Checks if the change worked well.
    .CHECK_OUTPUT((h==d), "0")

    .CHECK_OUTPUT(++c, "3[hour]")
    .CHECK_OUTPUT(c, "3[hour]") //Checks if the change worked well.

    .CHECK_OUTPUT(--g, "0[ton]")
    .CHECK_OUTPUT(g, "0[ton]") //Checks if the change worked well.

    .CHECK_OUTPUT((c<h), "0")
    .CHECK_THROWS(c>i) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(c<i) //Checks if MINUTE > GRAM throws exception.
    .CHECK_THROWS(c==i) //Checks if MINUTE == GRAM throws exception.
    .CHECK_THROWS(c<=i) //Checks if MINUTE <= GRAM throws exception.
    .CHECK_THROWS(c>=i) //Checks if MINUTE >= GRAM throws exception.
    .CHECK_THROWS(c+=i) //Checks if MINUTE += GRAM throws exception.
    .CHECK_THROWS(c-=i) //Checks if MINUTE -= GRAM throws exception.
    .CHECK_OUTPUT((h+=(h+h)), "60[min]")
    .CHECK_OUTPUT((c-=h), "2[hour]")
    .CHECK_OUTPUT(c, "2[hour]") //Checks if the change worked well.

    .CHECK_OK(istringstream("2[km]") >> a)
    .CHECK_OK(istringstream("2.5[hour]") >> c)
    .CHECK_OUTPUT(i-b, "2[km]")
    .CHECK_THROWS((i!=e))
    .CHECK_OUTPUT((i!=b), "1")
    .CHECK_OUTPUT(mi+se, "120[min]")
    .CHECK_OUTPUT(se+mi, "7200[sec]")
    .CHECK_OUTPUT(j-k, "1.6[hour]")

    .CHECK_OK(istringstream("60[sec]") >> j)
    .CHECK_OK(istringstream("1[min]") >> k)
    .CHECK_OUTPUT((j!=k), "0")
    .CHECK_OUTPUT((j==k), "1")

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
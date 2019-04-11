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
#include "Unit.h"
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

    PhysicalNumber km(4, Unit::KM);
    PhysicalNumber m(30, Unit::M);
    PhysicalNumber cm(21, Unit::CM);
    PhysicalNumber sec(1800, Unit::SEC);
    PhysicalNumber min(15, Unit::MIN);
    PhysicalNumber hour(2, Unit::HOUR);
    PhysicalNumber g(858, Unit::G);
    PhysicalNumber kg(74, Unit::KG);
    PhysicalNumber ton(8, Unit::TON);
    

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
    .CHECK_OUTPUT(km-cm, "3.99979[km]")
    .CHECK_OUTPUT(m+km, "4030[m]")
    .CHECK_OUTPUT((cm+=m), "3021[cm]")
    .CHECK_OUTPUT((cm--), "3020[cm]")
    
    .CHECK_OUTPUT((hour-=sec), "1.5[hour]")
    .CHECK_OUTPUT(min++, "16[min]")
    .CHECK_OUTPUT(sec+min, "2760[sec]")
    .CHECK_OUTPUT(min-hour, "-74[min]")   //negative result
    .CHECK_OUTPUT(hour-hour, "0[hour]")
    
    .CHECK_OUTPUT(kg-g, "73.142[kg]")
    .CHECK_OUTPUT(g+kg, "74858[g]")
    .CHECK_OUTPUT((ton+=kg), "8.074[ton]")
    .CHECK_EQUAL(cm!=m, true)
    .CHECK_EQUAL(km<=m, false)
    .CHECK_EQUAL(m>m, false)
    .CHECK_EQUAL(sec==sec, true)
    .CHECK_EQUAL(hour<sec, false)
    .CHECK_EQUAL(g>ton, false)
    .CHECK_EQUAL(ton>=kg, true)
    .CHECK_EQUAL(kg<ton, true)

    .CHECK_THROWS(min-km)
    .CHECK_THROWS(hour+ton)
    .CHECK_THROWS(g+=sec)
    .CHECK_THROWS(cm-kg)
    .CHECK_THROWS(ton>sec)
    .CHECK_THROWS(kg==m)
    .CHECK_THROWS(sec!=cm)
    .CHECK_THROWS(min<ton)
    .CHECK_THROWS(m<=g)
    .CHECK_THROWS(cm>=min)




      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
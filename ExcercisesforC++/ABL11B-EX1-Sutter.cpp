/*
================================================================================================#=
wk11B-Exer1.cpp

The Greatest Common Divisor of A and B is
the largest positive integer that is a factor of both A and B.
The GCD is also known as the Greatest Common Factor and the Highest Common Factor (HCF).

The GCD is used, for example,
to reduce fractions to their lowest terms,
and to factor polynomials,
and to find the least common multiple (LCM).

ASSIGNMENT:
Design, code, and test a function named: gcd().

This function accepts two integer values: A and B,
returns the greatest common divisor of these two inputs.
The GCD shall be computed using Euclid's method as described below.

from Wikipedia...
The method introduced by Euclid for computing greatest common divisors is based on
the fact that, given two positive integers a and b such that a > b,
the common divisors of a and b are the same as the common divisors of a � b and b.
So, Euclid's method for computing the greatest common divisor of two positive integers
consists of replacing the larger number by the difference of the numbers,
and repeating this until the two numbers are equal: that is their greatest common divisor.

MOODLE ASSIGNMENT - ABL11B
    Turn this in before the end of the day.
    Your file must be named ABL11B-EX1-YourLastName.cpp
================================================================================================#=
*/

// We must include any libraries referenced within this file.
#include <ctime>
#include <cassert>
#include <cstdlib>

#include <iostream>
#include <stdexcept>
#include <numeric>

// The following "using" statement saves us a little bit of typing,
// but costs us some ambiguity in our code.
using namespace std;


// ---------------------------------------------------------------------+-
// Function Prototypes go here.
// ---------------------------------------------------------------------+-
int gcd(int, int);



// =====================================================================================#=
// TEST CODE
// =====================================================================================#=

// Each Test-Case consists of:
//     Two integers: the inputs,
//     and a third integer: the expected output.
//
struct GCD_TestCase {
    int  input_a;
    int  input_b;
    int  expected_output;
};

// -----------------------------------------------------+-
// This function exercises the "gcd()" function.
// This is driven by randomly generated test-case data.
// After calling gcd(), this function will validate
// the actual result against the expected integer result.
// -----------------------------------------------------+-
void test_gcd_function(void)
{
    const int  NUM_TEST_CASES = 256;

    // ---------------------------------------------+-
    // Define the test cases
    // by generating random input values.
    // ---------------------------------------------+-
    static GCD_TestCase test_cases[NUM_TEST_CASES];

    for(int count=0; count<NUM_TEST_CASES; count++) {

        // random number range: 1..1000
        int a = 1 + (rand()%1000);
        int b = 1 + (rand()%1000);

        test_cases[count].input_a = a;
        test_cases[count].input_b = b;

        // Note: we use the standard numeric library gcd() function
        // to compute the expected value.
        test_cases[count].expected_output = std::gcd(a, b);
    }

    // For each test case...
    for (auto test : test_cases) {

        // ---------------------------------------------+-
        // Print out the test case information
        // so we can know what we are testing.
        // ---------------------------------------------+-
        cout << "Testing: " << test.expected_output << " = gcd(";
        cout << test.input_a << ", ";
        cout << test.input_b << ")" << std::endl;

        // ---------------------------------------------+-
        // Call the Function Under Test
        // ---------------------------------------------+-
        int actual_result = gcd( test.input_a, test.input_b);

        // ---------------------------------------------+-
        // Compare Actual vs Expected
        // and print the results.
        // ---------------------------------------------+-
        if(actual_result == test.expected_output) {
            cout << "    Passed. " << std::endl;
        }
        else {
            cout << "    Expected: " << test.expected_output << std::endl;
            cout << "    Actual:   " << actual_result << std::endl;
            throw std::runtime_error("Test Failed!");
        }
    }
    return;
};


// =====================================================================================#=
// Function Under Test.
// =====================================================================================#=
int gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a-b;
            cout << " a = " << a << " b = " << b;
        }
        else
        {
            b = b-a;
            cout << " a = " << a << " b = " << b;
        }
    }
    return a;
}


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    printf("Main starting... \n");

    // Seed the PRNG.
    srand(time(0));

    test_gcd_function();

    printf("Main Finished! \n");
    return 0;
};

#if 0
// =============================================================#=
// Parking Lot
// =============================================================#=

// -------------------------------------------------------------+-
// Alternate GCD algorithm using the Euclidean Algorithm
// -------------------------------------------------------------+-
int gcd(int a, int b)
{
    int t; // temp

    while(b > 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
};

// =============================================================#=
#endif
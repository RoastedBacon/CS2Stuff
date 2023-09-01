
/*
================================================================================================#=
wk11B-Exer2.cpp

The least common multiple of A and B
is the smallest positive integer that is divisible by both A and B.

The LCM is the lowest common denominator that can be used
to compare, add, or subtract two fractions.

The LCM of A and B is (A * B)/GCD(A, B).
This applies only for two given numbers.

To find the LCM of N numbers...
we must deal with the numbers two at a time,
and use the LCM result of one pair, to then compute
the LCM of that result and the next number in the sequence.

ASSIGNMENT:
Design, code, and test two functions named: lcm().

The first computes the LCM of two integers.
The second computes the LCM of a list of integers.

MOODLE ASSIGNMENT - ABL11B
    Turn this in before the end of the day.
    Your file must be named ABL11B-EX2-YourLastName.cpp
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
int lcm(int, int);
int lcm(int numbers[], int len);



// =====================================================================================#=
// TEST CODE
// =====================================================================================#=
const int MAX_ARRAY_LEN = 16;

// Each Test-Case consists of:
//     An array of integers: the inputs,
//     the length of that array,
//     and the expected LCM result.
//
struct LCM_TestCase {
    int  numbers[MAX_ARRAY_LEN];
    int  len;
    int  expected_result;
};

void helper_print_array( int given_array[], int given_len)
{
    cout << "[";
    for(size_t idx=0; idx<given_len; idx++) {
        cout << given_array[idx];
        if(idx<given_len-1) {
            cout << ", ";
        }
    };
    cout << "]";
};

// -----------------------------------------------------+-
// This function exercises the "lcm()" function.
// After calling lcm(), this function will validate
// the actual result against the expected result.
// -----------------------------------------------------+-
void test_lcm_function(void)
{
    // ---------------------------------------------+-
    // Define the test cases
    // ---------------------------------------------+-
    static LCM_TestCase test_cases[] = {
        { {12, 61, 23},             3,  16836 },
        { {10, 51},                 2,  510 },
        { {61, 8, 13, 63, 26, 37},  6,  14787864},
        { {9, 4},                   2,  36},
        { {12, 39},                 2,  156},
        { {4, 27, 62, 10, 57},      5,  318060},
        { {32, 30},                 2,  480},
        { {12, 61, 23},             3,  16836},
        { {6, 60, 20, 14, 10, 11},  6,  4620},
        { {47, 1, 57, 55, 62},      5,  9135390},
        { {10, 51},                 2,  510},
        { {1, 39, 17, 44, 5},       5,  145860},
        { {56, 51, 60, 34, 35, 55}, 6,  157080},
        { {18, 30, 34, 12, 32},     5,  24480},
        { {1, 63, 6, 26},           4,  1638},
        { {40, 23, 64},             3,  7360},
        { {24, 10},                 2,  120},
        { {64, 42, 16},             3,  1344},
        { {14, 18},                 2,  126},
        { {30, 29},                 2,  870},
        { {51, 51, 39, 30, 49},     5,  324870},
        { {13, 53, 22},             3,  15158},
        { {53, 13, 16},             3,  11024},
        { {30, 43, 38, 1},          4,  24510},
        { {44, 57},                 2,  2508},
        { {63, 60, 6, 22},          4,  13860},
        { {60, 52},                 2,  780},
        { {50, 6},                  2,  150},
        { {42, 22, 57},             3,  8778},
        { {43, 5, 23, 52, 15, 26},  6,  771420},
        { {41, 55},                 2,  2255},
        { {23, 60},                 2,  1380},
        { {41, 15, 12, 54},         4,  22140},
        { {33, 26, 62, 24, 40, 11}, 6,  531960},
        { {55, 46, 17},             3,  43010},
        { {10, 14, 41, 21, 10},     5,  8610},
        { {8, 24, 13, 48, 50, 22},  6,  171600},
        { {27, 22},                 2,  594},
        { {28, 34, 1, 63, 42, 41},  6,  175644},
    };

    // For each test case...
    for(auto test : test_cases) {

        // ---------------------------------------------+-
        // Print out the test case information
        // so we can know what we are testing.
        // ---------------------------------------------+-
        cout << "Testing: ";
        helper_print_array( test.numbers, test.len);
        cout << " => " << test.expected_result << endl;

        // ---------------------------------------------+-
        // Call the Function Under Test
        // ---------------------------------------------+-
        int actual_result = lcm(test.numbers, test.len);

        // ---------------------------------------------+-
        // Compare Actual vs Expected
        // and print the results.
        // ---------------------------------------------+-
        if(actual_result == test.expected_result) {
            cout << "    Passed. " << std::endl;
        }
        else {
            cout << "    Expected: " << test.expected_result << std::endl;
            cout << "    Actual:   " << actual_result << std::endl;
            throw std::runtime_error("Test Failed!");
        }
    }
    return;
};


// =====================================================================================#=
// Functions Under Test.
// =====================================================================================#=
int gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
    }
    return a;
}

int lcm(int a, int b)
{
    return((a*b)/(gcd(a, b)));
}

int lcm(int numbers[], int len)
{
    int next_lcm = numbers[0];

    for (int N = 1; N < len; N++)
    {
        next_lcm = lcm(next_lcm, numbers[N]);
    }
    return next_lcm; 
}

// -----------------------------------------------------+-
// Euclid's algorithm to compute the GCD of two numbers.
// -----------------------------------------------------+-


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    printf("Main starting... \n");

    test_lcm_function();

    printf("Main Finished! \n");
    return 0;
};



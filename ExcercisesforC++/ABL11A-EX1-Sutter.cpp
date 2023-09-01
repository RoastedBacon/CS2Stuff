
/*
================================================================================================#=
Unit-3/CODE/wk11A-Exer1-Starter.cpp

ASSIGNMENT:
Design, code, and test a function named: accumulate().

This function receives an array of integers as input.
It's output is an array containing a sequence of 'accumulating sums' based upon
the values in the input array. For example:

    INPUT                  OUTPUT
    -----                  ------
    [100, 30, 7]        => [100, 130, 137]
    [10, 10, 10, 10, 2] => [10, 20, 30, 40, 42]

MOODLE ASSIGNMENT - 11A
    Turn this in before the end of the day.
    Your file must be named ABL11A-EX1-YourLastName.cpp
================================================================================================#=
*/

// We must include any libraries referenced within this file.
#include <iostream>

// The following "using" statement saves us a little bit of typing,
// but costs us some ambiguity in our code.
using namespace std;


// ---------------------------------------------------------------------+-
// Function Prototypes go here.
// ---------------------------------------------------------------------+-
void accumulate(int input[], int output[], int len);

// =====================================================================================#=
// TEST CODE
// =====================================================================================#=


// Each Test-Case consists of:
//     An array of integers (the input);
//     The array length (number of elements in the array);
//     An array of integers containing the expected output;
//     We assume the expected output array and the input array are the same length.
//
const int MAX_ARRAY_LEN = 32;
struct AccumulateTestCase {
    int  input[MAX_ARRAY_LEN];
    int  len;
    int  expected_output[MAX_ARRAY_LEN];
};

// This is a helper function that prints
// the given_array of integers to the standard output stream.
// The given_len specifies the number of elements in the array.
//
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

// -------------------------------------------------------------+-
// This function exercises the "accumulate()" function.
// The tests are driven by test-case data stored in a list.
// After calling accumulate(), this function will validate
// the actual result against the expected result.
// -------------------------------------------------------------+-
void test_accumulate_function(void)
{
    // ---------------------------------------------+-
    // Define the test cases.
    // ---------------------------------------------+-
    static AccumulateTestCase test_cases[] = {
        {   { 0, 1, 2, 3,  4,  5,  6}, 7,
            { 0, 1, 3, 6, 10, 15, 21},
        },
        {   { }, 0,
            { },
        },
        {   { 42 }, 1,
            { 42 },
        },
        {   { 10,  8 }, 2,
            { 10, 18 },
        },
        {   { 100,  30,   7 }, 3,
            { 100, 130, 137 },
        },
        {   { 100,  30,   7 }, 3,
            { 100, 130, 137 },
        },
    };

    // For each test case...
    for (auto test : test_cases) {

        // ---------------------------------------------+-
        // Print out the test case information
        // so we can know what we are testing.
        // ---------------------------------------------+-
        cout << "Testing: ";
        helper_print_array( test.input, test.len);
        cout << endl;

        // This is the array where the function output goes.
        int actual_array[MAX_ARRAY_LEN];

        // ---------------------------------------------+-
        // Call Function Under Test
        // ---------------------------------------------+-
        accumulate(test.input, actual_array, test.len);

        // ---------------------------------------------+-
        // Compare Actual vs Expected
        // by looking at each element in both arrays.
        // ---------------------------------------------+-
        bool match = true; // assume the best;
        for(size_t idx=0; idx<test.len; idx++) {
            if(actual_array[idx] != test.expected_output[idx]) {
                match = false;  // found mismatch;
            }
        }

        // Print Test Results
        if(match) {
            // SUCCESS!
            printf("    Passed. \n");
        }
        else {
            // FAILURE, print the details.
            cout << "    Expected: ";
            helper_print_array( test.expected_output, test.len);
            cout << endl;
            cout << "    Actual:   ";
            helper_print_array( actual_array, test.len);
            cout << endl;
            throw std::runtime_error("Test Failed!");
        }
    }
    return;
};


// =====================================================================================#=
// Function Under Test.
// =====================================================================================#=

// Given an array of integer values and the number of elements in that array,
// compute an accumulating sum of the given values.
// After each value is added to the sum,
// write the current sum to the next position in the output array.

void accumulate(int input[], int output[], int len)
{
    int accumulater = 0;
    for (int i = 0; i < len; i++)
    {
        accumulater = accumulater + input[i];
        output[i] = accumulater;

    } 
}


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    printf("Main starting... \n");
    test_accumulate_function();
    printf("Main Finished! \n");

    int exit_code = 0; // success
    return exit_code;
};



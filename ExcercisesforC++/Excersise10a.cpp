/*
================================================================================#=
Unit-3/CODE/wk10A-Worksheet-ex1.cpp
================================================================================#=
*/

#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <string>
#include <stdexcept>

// ---------------------------------------------------------------------+-
// Function Prototypes
//
// Declare each function so all subsequent code in this file
// can know the function's name and type signature.
// ---------------------------------------------------------------------+-

// @@@ Add Prototypes Here @@@
bool is_digit(char);
bool is_hex_digit(char);


// ---------------------------------------------------------------------+-
// Test Digit Functions:
//     is_digit()
//     is_hex_digit()
// ---------------------------------------------------------------------+-
struct DigitTestCase {
    char c;
    bool expected_digit_result;      // true if c is a decimal digit
    bool expected_hex_digit_result;  // true if c is a hexadecimal digit
};

void test_digit_functions(void)
{
    static DigitTestCase test_cases[] = {
        {'a', false, true},
        {'b', false, true},
        {'c', false, true},
        {'d', false, true},
        {'e', false, true},
        {'f', false, true},
        {'A', false, true},
        {'B', false, true},
        {'C', false, true},
        {'D', false, true},
        {'E', false, true},
        {'F', false, true},
        {'0', true, true},
        {'1', true, true},
        {'2', true, true},
        {'3', true, true},
        {'4', true, true},
        {'5', true, true},
        {'6', true, true},
        {'7', true, true},
        {'8', true, true},
        {'9', true, true},
        {'x', false, false},
        {'y', false, false},
        {'z', false, false},
        {'X', false, false},
        {'Y', false, false},
        {'Z', false, false},
        {' ', false, false},
        {'/', false, false},
        {':', false, false},
        {'@', false, false},
    };

    // Run each test case against the
    // is_digit() and is_hex_digit() functions.
    for (auto test: test_cases) {
        printf("testing char: %c \n", test.c);
        assert(test.expected_digit_result == is_digit(test.c));
        assert(test.expected_hex_digit_result == is_hex_digit(test.c));
    }
};


// ---------------------------------------------------------------------+-
// Functions under test.
// ---------------------------------------------------------------------+-

// ---------------------------------------------------------------------+-
// Returns TRUE iff the given char is a decimal digit.
// ---------------------------------------------------------------------+-
bool is_digit(char given_char)
{
    unsigned int ascii_code = given_char;

    if(ascii_code >= 0x30 && ascii_code <= 0x39)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
};

// ---------------------------------------------------------------------+-
// Returns TRUE if the given char is a hexadecimal digit.
// ---------------------------------------------------------------------+-
bool is_hex_digit(char given_char)
{
    unsigned int ascii_code = given_char;

    if(ascii_code >= '0' && ascii_code <= '9')
        {
            return true;
        }
    else if(ascii_code >= 'A' && ascii_code <= 'F')
    {
        return true;
    }

    else if(ascii_code >= 'a' && ascii_code <= 'f')
    {
        return true;
    }

    else
    {
        return false;
    }
};
// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    printf("Main starting... \n");

    test_digit_functions();

    printf("Main Finished! \n");

    int exit_code = 0; // success
    return exit_code;
};
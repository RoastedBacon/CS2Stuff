/*
================================================================================================#=
Unit-3/CODE/wk10A-Worksheet-ex2.cpp
================================================================================================#=
*/

#include <cstdio>
#include <cctype>
#include <cstring>
#include <cassert>
#include <string>
#include <stdexcept>

// ---------------------------------------------------------------------+-
// Function Prototypes
// ---------------------------------------------------------------------+-

// @@@ Add Prototypes Here @@@
void test_convert_functions(void);
const char *int_to_hex_string(std::string &str, int given_val);
char int_to_hex_char(int);
int hex_string_to_int(char);
int hex_char_to_int(char);

// ---------------------------------------------------------------------+-
// Test Conversion Functions...
// ---------------------------------------------------------------------+-
struct ConvertTestCase {
    char  hex_string[24];
    int   hex_val;
};

void test_convert_functions(void)
{
    static ConvertTestCase test_cases[] = {
        {"0",   0x0},
        {"9",   0x9},
        {"A",   0xA},
        {"F",   0xF},
        {"a",   0xa},
        {"f",   0xf},
        {"2A",  0x2A},
        {"123", 0x123},
        {"456", 0x456},
        {"789", 0x789},
        {"ABC", 0xABC},
        {"def", 0xdef},
        {"100", 0x100},
    };
    // Create a string object for use later
    std::string str;

    for (auto test : test_cases) {
        printf("testing: %s \n", test.hex_string);


        // @@@ UNCOMMENT TO TEST @@@
        // ---------------------------------------------+-
        // Call Function Under Test: Ex2Prt1
        // ---------------------------------------------+-
        const char * actual_str = int_to_hex_string(str, test.hex_val);

        // Note: the conversion above returns a string with all upper case chars.
        // The given expected string could use lower case chars.
        // So we convert the expected string to all uppercase for the comparison below.
        char *s = test.hex_string;
        while(*s) {
            *s = toupper(*s);
            s++;
        };
        if(0 == strcmp(test.hex_string, actual_str)) {
            printf("    Passed: int to str. \n");
        }
        else {
            printf("    Expected: \"%s\", Actual: \"%s\" \n", test.hex_string, actual_str);
            throw std::runtime_error("Test Failed!");
        }

        // @@@ UNCOMMENT TO TEST @@@
        // ---------------------------------------------+-
        // Call Function Under Test: Ex2Prt2
        // ---------------------------------------------+-
        int actual_val = hex_string_to_int(test.hex_string);
        if( test.hex_val == actual_val) {
            printf("    Passed: str to int. \n");
        }
        else {
            printf("    Expected: %d, Actual: %d \n", test.hex_val, actual_val);
            throw std::runtime_error("Test Failed!");
        }
    }
    return;
};


// ---------------------------------------------------------------------+-
// Given an integer value, this function returns a C string
// containing the hexadecimal representation of that value.
// Requires a std::string object to use as a scratch pad.
// ---------------------------------------------------------------------+-
const char *int_to_hex_string(std::string &str, int given_val)
{
    const int base = 0x10;

    //Start with an empty strig.
    //Note: str is just working memory for use by this function.
    str.clear();

    do 
    {
        // Remainder after dividing by the base
        int next_digit = given_val % base;

        // Add an ASCII ''0' yo convert this to character.
        char digit_as_char = int_to_hex_char(next_digit);

        // This algorithm works by first computing the one's digit
        // then the ten's digit, then the hundred's digit, and so on.
        // This means we have to insert the characters at
        // the beginning of the string.
        str.insert(str.begin(), digit_as_char);

        // Continue to convert the remaining digits by
        // dividing by the base and throwing aay the remainder.
        given_val = given_val / base;
    }
    while(given_val > 0);
    
    return str.c_str();
};

// ---------------------------------------------------------------------+-
// Given an integer value in the range: 0..15, this function returns
// the corresponding ASCII encoded character value.
// ---------------------------------------------------------------------+-
char int_to_hex_char(int given_val)
{
    if (given_val >= 0 && given_val <= 9)
    {
        return(given_val + 0x30);
    }

    else if (given_val >= 10 && given_val <= 15)
    {
        return(given_val - 10 + 0x41);
    }

    else 
    {
        throw std::invalid_argument("not in hex range");
    }
};


// ---------------------------------------------------------------------+-
// Given a string containing hexadecimal digits,
// this function returns the corresponding integer value.
// ---------------------------------------------------------------------+-
int hex_string_to_int(char *given_string)
{
    return 0;
};


// ---------------------------------------------------------------------+-
// Given a hexadecimal digit character,
// this function returns the corresponding integer value.
// ---------------------------------------------------------------------+-
int hex_char_to_int(char given_hex_char)
{
    unsigned int ascii_code = given_hex_char;

        if(ascii_code >= '0' && ascii_code <= '9')
            {
                return given_hex_char + 48;
            }
        else if(ascii_code >= 'A' && ascii_code <= 'F')
        {
            return given_hex_char + 0x65;
        }

        else if(ascii_code >= 'a' && ascii_code <= 'f')
        {
            return given_hex_char + 0x65;;
        }

        else
        {
            return false;
        }
};


// ---------------------------------------------------------------------+-
// Returns TRUE iff the given char is a hexadecimal digit.
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

    test_convert_functions();

    printf("Main Finished! \n");

    int exit_code = 0; // success
    return exit_code;
};


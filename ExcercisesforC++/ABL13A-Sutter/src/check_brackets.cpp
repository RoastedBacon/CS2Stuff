
/*
================================================================================================#=
ABL13A-LastName
check_brackets.cpp
================================================================================================#=
*/

#include <iostream>
#include <string>

#include <cassert>
#include "check_brackets.hpp"



// =====================================================================================#=
// Check Brackets
// =====================================================================================#=

bool check_brackets(const std::string str, Stack& given_stack)
{
    for (char c : str)
    {
        if (c == '(' || c == '[' || c == '{' || c == '<')
        {
            stack_push(given_stack, c);
        }
        else if (c == ')' || c == ']' || c == '}' || c == '>')
        {
            if (stack_is_empty(given_stack))
            {
                return false;
            }
            char left = stack_peek(given_stack);
            stack_pop(given_stack);
            if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{') || (c == '>' && left != '<'))
            {
                return false;
            }
        }
    }
    return stack_is_empty(given_stack);
}



// =====================================================================================#=
// TEST CODE: Test Brackets Function
// =====================================================================================#=

// ---------------------------------------------------------------------+-
// Helper Function: string-to-string
// Receives a given string and a given index value.
// It returns a new string formatted like this:
//
//     (+41) "{2+((foo-7)/(a**2 + b**2) * (1/sqrt(2))) }"
//
// ---------------------------------------------------------------------+-
static std::string  string_to_string(int given_idx, std::string given_string)
{
    std::string  return_str;  // this is the string object we return to the caller
    char buffer[32];          // buffer for formatted output - be careful!

    sprintf(buffer, "%+03d", given_idx);

    return_str += "(";
    return_str += buffer;
    return_str += ") ";

    return_str += "\"";
    return_str += given_string;
    return_str += "\"";

    return return_str;
};


// -----------------------------------------------------+-
// Each Test-Case consists of:
//     A string to be tested.
//     The exepected boolean result: all brackets properly match?
// -----------------------------------------------------+-
struct Bracket_TestCase {
    std::string  test_str;
    bool         expected_result;
};

// -----------------------------------------------------+-
// This function tests the "check_brackets()" function.
// After calling check_brackets(), this function will validate
// the actual result against the expected result.
// -----------------------------------------------------+-
void test_brackets_function(void)
{
    static Bracket_TestCase test_cases[] = {
        { "()", true },
        { "<>", true },
        { "[]", true },
        { "{}", true },
        { "(", false },
        { "<", false },
        { "[", false },
        { "{", false },
        { "{ do while(true) { block statement } }", true },
        { "{2+((foo-7)/(a**2 + b**2) * (1/sqrt(2)) }", false },
        { "{2+((foo-7)/(a**2 + b**2) * (1/sqrt(2))) }", true },
    };

    // -----------------------------------------------------+-
    // Create an empty stack for use by
    // the brackets function. Must be initialized here.
    // -----------------------------------------------------+-
    Stack bracket_stack;
    bracket_stack.top_idx = -1;
    bracket_stack.max_len = 0;

    // For each test case...
    for(auto test : test_cases) {

        stack_clear(bracket_stack);

        std::cout << std::endl;
        std::cout << "Testing: \"" << test.test_str << "\"" << std::endl;
        bool actual_result = check_brackets(test.test_str, bracket_stack);

        if(actual_result == test.expected_result) {
            std::cout << "    Passed. " << std::endl;
        }
        else {
            std::cout << "    Expected: " << (test.expected_result?"True":"False") << std::endl;
            std::cout << "    Actual:   " << (actual_result?"True":"False") << std::endl;
            throw std::runtime_error("Test Failed!");
        }
    }

    return;
};



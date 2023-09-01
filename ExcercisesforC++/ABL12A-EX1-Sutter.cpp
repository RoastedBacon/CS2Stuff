
/*
================================================================================================#=
ABL12A-EX1-Starter.cpp

ASSIGNMENT:
Design, code, and test a function named: check_brackets().

For each parameter in each function you create,
identify whether that parameter is being passed by value, reference, or pointer.

DEPENDENCY:
The check_brackets() function needs a data structure to support the checking algorithm.
Develop a "Stack" data structure.

    Design and code a struct to hold the Stack data.

    Design, code, and test the following functions:

        bool  stack_is_empty(Stack& given_stack)
        bool  stack_is_not_empty(Stack& given_stack)
        bool  stack_is_full(Stack& given_stack)
        bool  stack_is_not_full(Stack& given_stack)

        void           stack_push(Stack& given_stack, char given_char)
        unsigned char  stack_peek(Stack& given_stack)
        unsigned char  stack_pop(Stack& given_stack)
        void           stack_clear(Stack& given_stack)
        std::string    stack_to_string(Stack& given_stack)

    The strings returned from stack_to_string() should look something like this:
        [+00] (-01) ||
        [+00] (+00) | 0|
        [+01] (+01) | 0,  1|
        [+02] (+02) | 0,  1,  2|

You are finished with this part when test_stack_functions()
runs to completion without throwing any exceptions.

CHECK BRACKETS
    Design, code, and test the check_brackets() function.
    This function receives two parameters:
        A std::string  containing the input string.
        A Stack        object to be used for processing the input.

    The input string is an expression containing "brackets".
    The valid brackets are: (, <, [, {, }, ], >, and )
    For example:
        { "{2+((foo-7)/(a**2 + b**2) * (1/sqrt(2))) }", true },

    The check_brackets() function will return True, if and only if
    the given string contains brackets that are properly matched.
================================================================================================#=
*/

// We must include any libraries referenced within this file.
#include <ctime>
#include <cassert>
#include <cstdlib>

#include <iostream>
#include <string>
#include <stdexcept>
#include <numeric>

using namespace std;


// Note: because of the order in which we are structuring our functions below,
// you won't have to create the prototypes in this file.


// =====================================================================================#=
// Code Under Test: Char Stack
// =====================================================================================#=
const int MAX_STACK_LEN = 32;


struct Stack 
{
    unsigned char stk[MAX_STACK_LEN];
    int top_idx;
    int max_len;
};

bool stack_is_empty(Stack& given_stack)
{
    if (given_stack.top_idx >= 0) return false;
   return true;
}

bool stack_is_not_empty(Stack& given_stack)
{
    return !stack_is_empty(given_stack);
}

bool stack_is_full(Stack& given_stack)
{
    if (given_stack.top_idx == MAX_STACK_LEN)
    {
        return true;
    }
    else 
    {
        return false;
    }

}

bool  stack_is_not_full(Stack& given_stack)
{
    if (given_stack.top_idx != MAX_STACK_LEN)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void stack_push(Stack& given_stack, char given_char)
{
    if (stack_is_not_full)
    {
        given_stack.stk[++given_stack.top_idx] = given_char;
    }
    else
    {
        cout << "Stack was actually full ";
    }
}

unsigned char  stack_peek(Stack& given_stack)
{
    return given_stack.stk[given_stack.top_idx];
}

unsigned char  stack_pop(Stack& given_stack)
{
    return given_stack.stk[given_stack.top_idx--];

}

void stack_clear(Stack& given_stack)
{
    given_stack.top_idx = -1;
}

std::string stack_to_string(Stack& given_stack)
{
    std::string return_str;
    char buffer[32];

    sprintf(buffer, "%+03d", given_stack.max_len);
    return_str += "[";
    return_str += buffer;
    return_str += "] ";

    int top= given_stack.top_idx;
    sprintf(buffer, "%+03d", top);
    return_str += "(";
    return_str += std::to_string(top);
    return_str += ") ";

    return_str += "|";
    for(int idx = 0; idx <= top; idx++)
    {
        return_str += " ";
        return_str += given_stack.stk[idx];
        
        if(idx < top)
        {
            return_str += ", ";
        }
    }
    return_str += "|";

    return return_str;
}

// =====================================================================================#=
// Code Under Test: Check Brackets
// =====================================================================================#=

bool check_brackets(const std::string str, Stack& given_stack)
{
    for (char c : str) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            stk.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (stk.empty()) 
            {
                return false;
            }
            char left = stk.top();
            stk.pop();
            if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{')) 
            {
                return false;
            }
        }
    }
    return stk.empty();
}


// =====================================================================================#=
// TEST CODE: Test Stack Functions
// =====================================================================================#=
void test_stack_functions(void)
{
    // -----------------------------------------------------+-
    // Create an Empty Stack.
    // We are responsible to initialize it properly.
    // -----------------------------------------------------+-
    Stack stack_under_test;
    stack_under_test.top_idx = -1;
    stack_under_test.max_len = 0;

    if(stack_is_empty(stack_under_test)) {
        cout << "Empty Stack: " << endl;
        cout << "    " << stack_to_string(stack_under_test) << endl;
    } else {
        throw std::runtime_error("Test Failed!");
    }

    // -----------------------------------------------------+-
    // Push chars until it's full.
    // -----------------------------------------------------+-
    char next_char_to_push = '0';
    char expected_char_at_top;

    cout << std::endl;
    cout << "Pushing onto stack... " << std::endl;
    while(stack_is_not_full(stack_under_test))
    {
        stack_push(stack_under_test, next_char_to_push);
        expected_char_at_top = next_char_to_push;

        char peek_elem = stack_peek(stack_under_test);
        assert(peek_elem == expected_char_at_top);

        cout << "    " << stack_to_string(stack_under_test);
        cout << " <= " << next_char_to_push << endl;
        next_char_to_push += 1;
    }

    // -----------------------------------------------------+-
    // Pop elements from stack until empty.
    // -----------------------------------------------------+-
    cout << std::endl;
    cout << "Popping from stack... " << std::endl;
    while(stack_is_not_empty(stack_under_test))
    {
        char peek_elem = stack_peek(stack_under_test);
        assert(peek_elem == expected_char_at_top);

        char pop_elem  = stack_pop(stack_under_test);
        assert(pop_elem == peek_elem);

        cout << "    " << stack_to_string(stack_under_test);
        cout << " => " << pop_elem << endl;
        expected_char_at_top -= 1;
    }
    return;
};


// =====================================================================================#=
// TEST CODE: Test Brackets Function
// =====================================================================================#=

// Each Test-Case consists of:
//     A string to be tested.
//     The exepected boolean result: all brackets match?
//
struct Bracket_TestCase {
    std::string  test_str;
    bool         expected_result;
};

// -----------------------------------------------------+-
// This function tests the "check_brackets()" function.
// After calling check_brackets(), this function will validate
// the actual result against the expected result.
// -----------------------------------------------------+-
#if 0
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
    // Create an empty stack for use
    // by the brackets function.
    // -----------------------------------------------------+-
    Stack bracket_stack;
    bracket_stack.top_idx = -1;
    bracket_stack.max_len = 0;

    // For each test case...
    for(auto test : test_cases) {

        stack_clear(bracket_stack);

        cout << endl;
        cout << "Testing: \"" << test.test_str << "\"" << std::endl;
        bool actual_result = check_brackets(test.test_str, bracket_stack);

        if(actual_result == test.expected_result) {
            cout << "    Passed. " << std::endl;
        }
        else {
            cout << "    Expected: " << (test.expected_result?"True":"False") << std::endl;
            cout << "    Actual:   " << (actual_result?"True":"False") << std::endl;
            throw std::runtime_error("Test Failed!");
        }
    }

    return;
};

#endif
// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    cout << "Main starting..." << endl;
    cout << "Date: " << __DATE__ << endl;
    cout << "Time: " << __TIME__ << endl;

    cout << endl;
    cout << "TESTING STACK FUNCTIONS..." << endl;
    test_stack_functions();

    // cout << endl;
    // cout << "TESTING BRACKETS FUNCTION..." << endl;
    // test_brackets_function();

    cout << endl << endl;
    cout << "MAIN FINISHED!  [" << __TIME__ << "]" << endl;
    cout << endl << endl;
    return 0;
};



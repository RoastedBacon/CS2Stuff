
/*
================================================================================================#=
ABL13A-LastName
main.cpp
================================================================================================#=
*/

#include "stack_data_structure.hpp"
#include "check_brackets.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>



// ---------------------------------------------------------------------+-
// A Helper Function.
// Returns the current time as a string.
// ---------------------------------------------------------------------+-
std::string get_curr_time_string(void)
{
    time_t now = time(NULL);
    tm *ltm    = localtime(&now);

    std::ostringstream buffer_stream;
    buffer_stream << std::setfill('0');
    buffer_stream << std::setw(2) << ltm->tm_hour << ":";
    buffer_stream << std::setw(2) << ltm->tm_min  << ":";
    buffer_stream << std::setw(2) << ltm->tm_sec;

    return buffer_stream.str();
}
// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    std::cout << std::endl << std::endl;
    std::cout << "Program Build Date & Time: " << __DATE__ << " " << __TIME__ << std::endl;
    std::cout << "Main Starting... [" << get_curr_time_string() << "]" << std::endl;

    // std::cout << std::endl;
    // std::cout << "TESTING STACK FUNCTIONS... " << std::endl;
    // test_stack_functions();

    // std::cout << std::endl;
    // std::cout << "TESTING BRACKETS FUNCTION... " << std::endl;
    // test_brackets_function();


    std::cout << std::endl << std::endl;
    std::cout << "MAIN FINISHED!   [" << get_curr_time_string() << "]" << std::endl;
    std::cout << std::endl << std::endl;

    return 0;
};



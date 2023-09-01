
/*
================================================================================================#=
main.cpp
================================================================================================#=
*/

#include "intersection.hpp"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>





// ---------------------------------------------------------------------+-
// A helper function that returns the current time as a string.
// ---------------------------------------------------------------------+-
static std::string get_curr_time_string(void)
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
// A helper function that sleeps for the given number of seconds.
// ---------------------------------------------------------------------+-
static void sleep(float time_to_sleep_in_seconds)
{
    int time_to_sleep_in_msec = time_to_sleep_in_seconds * 1000;
    std::this_thread::sleep_for(
        std::chrono::milliseconds(time_to_sleep_in_msec)
    );
    return;
}

// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main(void) {

    std::cout << "Program Build Date & Time: " << __DATE__ << " " << __TIME__ << std::endl;
    std::cout << "Main Starting... [" << get_curr_time_string() << "]" << std::endl;

    std::string time_stamp;
    SignalColor direction_a;
    SignalColor direction_b;

    // -----------------------------------------------------+-
    // Simulation parameters
    // -----------------------------------------------------+-
    const float  sleep_interval_seconds = 0.3;
    const int    simulation_seconds = 100;
    const int    max_ticks = static_cast<int>(simulation_seconds/sleep_interval_seconds);

    float ylw = 3;
    float a_grn = 6;
    float b_grn = 9;

    // -----------------------------------------------------+-
    // Create the Object-Under-Test: the Intersection
    //
    // Test both the default constructor as well as
    // the parameterized constructor.
    // -----------------------------------------------------+-
    //Intersection obj_under_test;
    Intersection obj_under_test(ylw, a_grn, b_grn);


    for(auto count = 0; count < max_ticks; count++)
    {
        // -----------------------------------------------------+-
        // Get and print the current state of the intersection.
        // -----------------------------------------------------+-
        obj_under_test.get_status(time_stamp, direction_a, direction_b);
        if(0 == count % 24) {
            std::cout << std::endl;
            std::cout << "  Time          DirA      DirB"<< std::endl;
        }
        std::cout << std::setw(10) << time_stamp;
        std::cout << std::setw(10) << direction_a;
        std::cout << std::setw(10) << direction_b;
        std::cout << std::endl;

        // -----------------------------------------------------+-
        // Tick the intersection after a sleep interval.
        // -----------------------------------------------------+-
        sleep(sleep_interval_seconds);
        obj_under_test.tick(sleep_interval_seconds);
    }

    std::cout << std::endl << std::endl;
    std::cout << "MAIN FINISHED!   [" << get_curr_time_string() << "]" << std::endl;
    std::cout << std::endl << std::endl;

    return 0;
};



/*
================================================================================#=
intersection.hpp

This class models a basic two way intersection controlled by a traffic light.
The traffic light displays Green, Yellow, Red in each of the four directions.
================================================================================#=
*/

// Using pragma once will prevent multiple includes of this header file and
// is more convenient than having to write include guards in every header file.
// See: https://en.wikipedia.org/wiki/Pragma_once
// and: https://en.wikipedia.org/wiki/Include_guard
#pragma once

#include <iostream>
#include <cstdint>


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
// SignalColor represents the current state
// of one direction through the intersection.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
enum class SignalColor : uint8_t {
    Red,
    Yellow,
    Green,
};

// Overload the insertion operator for easier console output.
std::ostream& operator << (std::ostream& lhs, const SignalColor& rhs);


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
// TrafficDirection represents one direction through the intersection.
// For example, the East-West Street or the North-South Avenue.
// We'll just call them A and B to keep it simple.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
enum class TrafficDirection : uint8_t {
    A,
    B,
};

// Overload the insertion operator for easier console output.
std::ostream& operator << (std::ostream& lhs, const TrafficDirection& rhs);


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
// This class models a simple, two-way intersection.
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
class Intersection {

    private:
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
        // State of the Intersection
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~

        // The number of seconds since this object has been initialized.
        // This provides our time-base for keeping track of time.
        float on_time;
        int greenA_sec;
        int greenB_sec;
        int yellow_sec;

        bool Status_0;
        bool Status_1;
        bool Status_2;
        bool Status_3;
        bool Status_4;

        SignalColor a_status;
        SignalColor b_status;

        float current_time;

        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
        // Private helper functions.
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~
        // Convert on_time to a string with format: HH:MM:SS.S
        std::string get_on_time_in_hhmmss(void);

        // Function to do default object initialization.
        void default_obj_init(void);

    public:
        Intersection();
        Intersection(
                int ylw_sec,
                int a_grn_sec,
                int b_grn_sec
        )
        {

            Status_0 = true;
            Status_1 = false;
            Status_2 = false;
            Status_3 = false; 
            Status_4 = false;

            greenA_sec = b_grn_sec;
            greenB_sec = a_grn_sec;
            yellow_sec = ylw_sec;

            current_time = on_time;

        };
        ~Intersection();

        void tick(float seconds_elapsed);

        void get_status(
            std::string& time_stamp,
            SignalColor& direction_a_status,
            SignalColor& direction_b_status
        );
};



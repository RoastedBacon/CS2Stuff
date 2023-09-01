
// =====================================================================#=
// FILE: intersection.hpp
// =====================================================================#=

#include "intersection.hpp"

#include <iostream>


// =====================================================================================#=
// SignalColor
// =====================================================================================#=
// A helper function to map the enum value to a string for printing.
const char* SignalColorToString(SignalColor col)
{
    switch(col)
    {
        case SignalColor::Red:     return "red";
        case SignalColor::Yellow:  return "yellow";
        case SignalColor::Green:   return "green";
    }
    return "invalid-signal-color";
};

// Overload << so we can more easily print the signal color.
std::ostream& operator << (std::ostream& lhs, const SignalColor& rhs)
{
    lhs << SignalColorToString(rhs);
    return lhs;
};


// =====================================================================================#=
// =====================================================================================#=
const char* TrafficDirectionToString(TrafficDirection dir)
{
    switch(dir)
    {
        case TrafficDirection::A:  return "A";
        case TrafficDirection::B:  return "B";
    }
    return "invalid-traffic-direction";
};

// Overload << so we can more easily print the signal color.
std::ostream& operator << (std::ostream& lhs, const TrafficDirection& rhs)
{
    lhs << TrafficDirectionToString(rhs);
    return lhs;
};


// =====================================================================================#=
// Constructors & Destructor
// =====================================================================================#=
void Intersection::default_obj_init(void)
{
    on_time = 0.0;
};

Intersection::Intersection()
{
    default_obj_init();
};

Intersection::~Intersection() {
    // Nothing to do because this class
    // does not allocate any new resources.
};


// =====================================================================================#=
// Accessors
// =====================================================================================#=
void Intersection::get_status(
    std::string& output_time_stamp,
    SignalColor& output_direction_a_status,
    SignalColor& output_direction_b_status)
{
    // Current On-Time
    int   hours, mins;
    float secs;

    secs  = on_time;
    hours = static_cast<int>(secs / (60*60));

    secs  = secs - (hours * (60*60));
    mins  = static_cast<int>(secs / 60);

    secs  = secs - (mins * 60);

    // Write formatted time to buffer.
    char buffer[32];
    sprintf(buffer, "%02d:%02d:%04.1f", hours, mins, secs);
    output_time_stamp = buffer;



    output_direction_a_status = a_status;
    output_direction_b_status = b_status;

    



    
};


// =====================================================================================#=
// Mutators
// =====================================================================================#=
void Intersection::tick(float elapsed_seconds)
{
    on_time += elapsed_seconds;

    if (Status_0 == true)
    {
        a_status = SignalColor::Red;
        b_status = SignalColor::Red;

        Status_0 = false;
        Status_1 = true;
        current_time = on_time + greenB_sec;
    }

    if (Status_1 == true)
    {
        a_status = SignalColor::Red;
        b_status = SignalColor::Green;

        if (on_time >= current_time)
        {
            Status_2 = true;
            Status_1 = false;
            current_time = on_time + yellow_sec;
        }
    }

    if (Status_2 == true)
    {
        a_status = SignalColor::Red;
        b_status = SignalColor::Yellow;

        if (on_time >= current_time)
        {
            Status_3 = true;
            Status_2 = false;
            current_time = on_time + greenA_sec; 
        }
    }

    if (Status_3 == true)
    {
        a_status = SignalColor::Green;
        b_status = SignalColor::Red;

        if (on_time >= current_time)
        {
            Status_4 = true;
            Status_3 = false;
            current_time = on_time + yellow_sec;
        }
    }

    if (Status_4 == true)
    {
        a_status = SignalColor::Yellow;
        b_status = SignalColor::Red;

        if (on_time >= current_time)
        {
            Status_1 = true;
            Status_4 = false;
            current_time = on_time + greenB_sec;
        }
    }
};
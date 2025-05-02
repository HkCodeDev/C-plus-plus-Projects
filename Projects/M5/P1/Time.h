/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  file: Time.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: March 28 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {

    class Time {
        // Stores time in minutes
        unsigned int minutes;

    public:
        // Constructor with default argument,
        //  initializes Time object with given minutes or zero
        Time(unsigned int min = 0u);
        // Resets the Time object's
        //  minutes (assumedly to a current or default value)
        Time& reset();
        // Decreases the Time object's
        //  minutes by the minutes of another Time object
        Time& operator-=(const Time& D);
        // Returns a new Time object that
        //  represents the difference in minutes between two Time objects
        Time operator-(const Time& T) const;
        // Multiplies the Time object's 
        // minutes by an integer value
        Time& operator*=(int val);
        // Cast operator to allow a Time
        //  object to be treated as an unsigned integer of minutes
        operator unsigned int() const;
        // Friend function to insert a Time object into an output stream
        friend std::ostream& operator<<(std::ostream& out, const Time& T);
        // Friend function to extract a Time object from an input stream
        friend std::istream& operator>>(std::istream& in, Time& T);
    };
}

#endif // SENECA_TIME_H

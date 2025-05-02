/*****************************************************************************
 Citation and Sources:
                  Milestone 3
                  File: Time.cpp
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: March 24 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#include "Time.h"
#include "Utils.h"
#include <iomanip>

namespace seneca {
    // Constructor initializes a Time 
    // object with a specified number of minutes
    Time::Time(unsigned int min) : minutes(min) {}
    // Resets the Time object's minutes 
    // based on an external source, presumably current time
    Time& Time::reset() {
        minutes = U.getTime();//returning current time in minutes
        return *this;// Allows chaining of operations
    }
    // Subtracts the minutes of 
    // another Time object from this object, adjusting for overflow
    Time& Time::operator-=(const Time& D) {
        if (minutes < D.minutes) {// If subtraction would go negative,
            minutes += 24 * 60; // add 24 hours worth of minutes
        }
        minutes -= D.minutes;// Perform the subtraction
        return *this;// Enables chaining
    }
    // Subtracts the minutes of another 
    // Time object from a copy of this object, returns the result
    Time Time::operator-(const Time& T) const {
        // Create a temporary Time object as a copy of this object
        Time temp(*this);
        temp -= T;// Use operator-= to subtract Time object T from temp
        return temp;
    }
    // Multiplies the minutes of this Time object by a specified value
    Time& Time::operator*=(int val) {
        minutes *= val;// Perform the multiplication
        return *this;
    }
    // Cast operator to allow a Time 
    // object to be used as an unsigned int of minutes
    Time::operator unsigned int() const {
        return minutes;
    }
    // Overloads the insertion (<<) operator 
    // to output Time objects in HH:MM format
    std::ostream& operator<<(std::ostream& out, const Time& T) {
        unsigned hours = T.minutes / 60;
        unsigned mins = T.minutes % 60;
        // Format and output the time in HH:MM format
        out << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << mins;
        return out;

    }
    // Overloads the extraction (>>) 
    // operator to input Time objects in HH:MM format
    std::istream& operator>>(std::istream& in, Time& T) {
        unsigned hours, mins;
        char colon;

        if (!(in >> hours)) {
            // Set failbit manually if input fails
            in.clear(std::ios::failbit);
        }
        else {
            // Check for the colon character between hours and minutes
            if (in.peek() != ':') {
                in.setstate(std::ios::failbit);// Set failbit if colon is missing
            }
            else {

                in >> colon >> mins;
                if (in.fail()) {
                    // Set failbit manually if input fails
                    in.clear(std::ios::failbit);
                }
                else {
                    // Calculate total minutes and assign to Time object
                    T.minutes = hours * 60 + mins;
                }
            }
        }

        return in;
    }

}

/*****************************************************************************
                  Workshop - #5 (Part - 2)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"
#include <iostream>

namespace seneca {

    const int MAX_NAME_LEN = 50;
    // The Hero class represents a superhero
    //  with various powers and attributes
    class Hero {
        char name[MAX_NAME_LEN + 1];
        Power* powers;
        int numPowers;
        int powerLevel;

        void calculatePowerLevel();

    public:
        // Constructors
        Hero();// Default constructor
        // Parameterized constructor
        Hero(const char* name, Power* powers, int numPowers);
        // Copy constructor for deep copying a hero
        Hero(const Hero& hero); // Copy constructor (if needed)
        Hero& operator=(const Hero& hero); // Assignment operator (if needed)
        ~Hero(); // Destructor
        // Adds a Power to the hero and recalculates power level
        Hero& operator+=(const Power& power);
        // Decreases the hero's power level by a specified amount.
        Hero& operator-=(int powerLevelDecrease);
        // Method to display hero information
        std::ostream& display(std::ostream& ostr = std::cout) const;
        // Friend functions for comparison and I/O operations
        // Compares two heroes based on power level
        friend bool operator<(const Hero& a, const Hero& b);
        // Compares two heroes based on power level
        friend bool operator>(const Hero& a, const Hero& b);
        // Adds a power to the hero
        friend void operator<<(Hero& hero, const Power& power);
        // Custom operation, typically for input but used differently here
        friend void operator>>(const Power& power, Hero& hero);
    };
    // Non-member operator overloads for comparison
    // Compares two heroes based on power level
    bool operator<(const Hero& a, const Hero& b);
    // Compares two heroes based on power level
    bool operator>(const Hero& a, const Hero& b);
    // Adds a power to the hero
    void operator<<(Hero& hero, const Power& power);
    // Custom operation, typically for input but used differently here
    void operator>>(const Power& power, Hero& hero);
}

#endif // SENECA_HERO_H

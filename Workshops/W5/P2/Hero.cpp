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
#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <cstring>
#include <iostream>

using namespace std;
namespace seneca {
    // Constructor with parameters to initialize a Hero object
       // Takes the hero's name, an array of powers, and the number of powers
   Hero::Hero(const char* name, Power* powers, int numPowers) : 
        numPowers(numPowers), powerLevel(0) {
        // Copy the name, ensuring not to exceed MAX_NAME_LEN characters
        strncpy(this->name, name, MAX_NAME_LEN);
        this->name[MAX_NAME_LEN] = '\0'; // Ensure null termination

        // Allocate memory for the powers array
        this->powers = new Power[numPowers];

        // Copy the powers into the new array
        for (int i = 0; i < numPowers; ++i) {
            this->powers[i] = powers[i];
        }

        // Calculate the initial power level
        calculatePowerLevel();
    }

   // Copy constructor for creating a new Hero object as a copy of another
    Hero::Hero(const Hero& other) : name(), 
        powers(new Power[other.numPowers]), 
        numPowers(other.numPowers), 
        powerLevel(other.powerLevel) {
        strncpy(name, other.name, MAX_NAME_LEN);
        name[MAX_NAME_LEN] = '\0'; // Ensure null termination
        for (int i = 0; i < numPowers; ++i) {
            powers[i] = other.powers[i];
        }
    }

    // Copy assignment operator to assign one Hero object to another
    Hero& Hero::operator=(const Hero& other) {
        if (this != &other) { // Check for self-assignment
            delete[] powers; // Free existing resources
            numPowers = other.numPowers;
            powerLevel = other.powerLevel;
            strncpy(name, other.name, MAX_NAME_LEN);
            powers = new Power[numPowers];
            for (int i = 0; i < numPowers; ++i) {
                powers[i] = other.powers[i];
            }
        }
        return *this;
    }
    // Destructor to clean up dynamically allocated memory
    Hero::~Hero() {
        delete[] powers;
    }
    // Method to recalculate the hero's power level
    void Hero::calculatePowerLevel() {
        powerLevel = 0;
        // Sum up the rarity of each power and multiply by the number of powers
        for (int i = 0; i < numPowers; ++i) {
            powerLevel += powers[i].checkRarity();
        }
        powerLevel *= numPowers;
    }
    // Operator overloads to modify the hero's powers and power level
    Hero& Hero::operator+=(const Power& power) {
        // Add a new power to the hero and recalculate the power level
        Power* temp = new Power[numPowers + 1];
        for (int i = 0; i < numPowers; ++i) {
            temp[i] = powers[i];
        }
        temp[numPowers] = power;
        ++numPowers;
        delete[] powers;
        powers = temp;
        calculatePowerLevel();// Recalculate power level
        return *this;
    }




    Hero& Hero::operator-=(int powerLevelDecrease) {
      // Decrease the hero's power level and ensure it doesn't drop below zero
        powerLevel -= powerLevelDecrease;
        if (powerLevel < 0) powerLevel = 0;
        return *this;
    }
    // Display method to output the hero's details to an ostream
    std::ostream& Hero::display(std::ostream& ostr) const {
        ostr << "Name: " << name << std::endl;
        ostr << "List of available powers: " << std::endl;
        for (int i = 0; i < numPowers; ++i) {
            ostr << "  Name: " << powers[i].checkName() << ", Rarity: " 
                << powers[i].checkRarity() << std::endl;
        }
        ostr << "Power Level: " << powerLevel;
        return ostr;// Allow chaining of ostream operations
    }
   // Operator overloads for adding a power to a hero 
    void operator<<(Hero& hero, const Power& power) {
       // Assuming Hero::operator+= is correctly implemented for this operation
        hero += power;  
    }

    void operator>>(const Power& power, Hero& hero) {
        hero += power;
    }

    // Comparison operators to compare heroes based on their power levels
    bool operator<(const Hero& a, const Hero& b) {
        return a.powerLevel < b.powerLevel;
    }

    bool operator>(const Hero& a, const Hero& b) {
        return a.powerLevel > b.powerLevel;
    }
}

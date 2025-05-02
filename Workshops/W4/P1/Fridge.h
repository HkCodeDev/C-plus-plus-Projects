/*****************************************************************************
                  Workshop - #4 (Part - 1)>
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
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

namespace seneca {

    const int NAME_LEN = 20; // Adjusted as per the corrected information
    const int FRIDGE_CAP = 3;  // Maximum capacity of Fridge

    class Food {
        char m_name[NAME_LEN]{};
        int m_weight{};
    public:
        Food(); // Default constructor
        Food(const char* nm, int wei); // Parameterized constructor
        const char* name()const; // Getter for name
        int weight()const; // Getter for weight
    };

    class Fridge {
    private:
        Food m_foods[FRIDGE_CAP]; // Statically allocated array of Food items
        int m_numFoods; // Number of Food items currently in the Fridge
        char* m_model; // Dynamic C-style string for the model name

    public:
        Fridge(); // Default constructor
        // Constructor with parameters
        Fridge(Food farr[], int nf, const char* mod = "Ice Age");
        ~Fridge(); // Destructor

        bool addFood(const Food& f); // Add a Food item to the Fridge
        void changeModel(const char* m); // Change the model name of the Fridge
        bool fullFridge() const; // Check if the Fridge is full
        bool findFood(const char* f) const; // Find a Food item by name
        // Display the Fridge details
        std::ostream& display(std::ostream& os = std::cout) const; 
    };

} // namespace seneca

#endif // SENECA_FRIDGE_H

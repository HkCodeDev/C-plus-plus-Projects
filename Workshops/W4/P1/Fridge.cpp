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
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Fridge.h"
using namespace std;

namespace seneca {
    // Default constructor
    Food::Food() {
        // You can initialize the member variables to default values here
        // For instance, setting weight to 0 and name to an empty string
        m_weight = 0;
        m_name[0] = '\0'; // Represents an empty string
    }
    // Parameterized constructor
    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN - 1);
        m_name[NAME_LEN - 1] = '\0'; // Ensure null-termination
        m_weight = wei;
    }
    // Getter for name
    const char* Food::name() const {
        return m_name;
    }
    // Getter for weight
    int Food::weight() const {
        return m_weight;
    }

    // Default constructor
    Fridge::Fridge() : m_numFoods(0), m_model(nullptr) {
        // Initialize Fridge in an empty state
    }
    // Utilizing delegating constructors
    Fridge::Fridge(Food farr[], int nf, const char* mod) : Fridge() { 
        if (nf > 0 && mod && *mod != '\0') { // Validate parameters
            // Ensure we do not exceed FRIDGE_CAP
            m_numFoods = nf < FRIDGE_CAP ? nf : FRIDGE_CAP; 
            m_model = new char[strlen(mod) + 1];
            strcpy(m_model, mod);
            for (int i = 0; i < m_numFoods; ++i) {
                // Shallow copy is sufficient here due to Food's handling
                m_foods[i] = farr[i]; 
            }
        }
    }
    // Destructor
    Fridge::~Fridge() {
        delete[] m_model; // Deallocate dynamic memory
    }
    // Add a Food item to the Fridge
    bool Fridge::addFood(const Food& f) {
        if (m_numFoods < FRIDGE_CAP) {
            m_foods[m_numFoods++] = f; // Add food and increment food count
            return true;
        }
        return false; // Fridge is full
    }
    // Change the model name of the Fridge
    void Fridge::changeModel(const char* m) {
        if (m && *m != '\0') { // Validate parameter
            delete[] m_model; // Deallocate existing model
            m_model = new char[strlen(m) + 1];
            strcpy(m_model, m); // Copy new model name
        }
    }
    // Check if the Fridge is full
    bool Fridge::fullFridge() const {
        // Fridge is full if it holds FRIDGE_CAP items
        return m_numFoods == FRIDGE_CAP; 
    }
    // Find a Food item by name
    bool Fridge::findFood(const char* f) const {
        for (int i = 0; i < m_numFoods; ++i) {
            if (strcmp(m_foods[i].name(), f) == 0) {
                return true; // Found matching food
            }
        }
        return false; // No matching food found
    }
    // Display the Fridge details
    std::ostream& Fridge::display(std::ostream& os) const {
        // Do nothing if model is in an empty state
        if (m_model == nullptr || *m_model == '\0') return os; 

        os << "Fridge Model: " << m_model << std::endl;
        os << "Food count: " << m_numFoods << " Capacity: " <<
            FRIDGE_CAP << std::endl;
        if (m_numFoods > 0) {
            os << "List of Foods" << std::endl;
            for (int i = 0; i < m_numFoods; ++i) {
                os << std::right << std::setw(20) << m_foods[i].name(); 
                os << " | " << m_foods[i].weight() << std::endl;
            }
        }
        return os;
    }


}
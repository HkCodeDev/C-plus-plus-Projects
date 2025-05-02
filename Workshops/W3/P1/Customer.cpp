/*****************************************************************************
                  Workshop - #3 (Part - 1)>
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
#include "Customer.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace seneca {
    // Constructor: Initializes a Customer object with default values.
    // Initializes 'm_id' to 0, 'm_name' pointer to nullptr, and 'm_car' 
    // pointer to nullptr, indicating an empty or uninitialized state.
    Customer::Customer() : m_id(0), m_name(nullptr), m_car(nullptr) {}
    // Destructor: Responsible for cleaning up resources to prevent memory leaks.
    Customer::~Customer() {
        deallocateMemory();
    }
    // Checks if the Customer object is in an empty state.
    bool Customer::isEmpty() const {
        return m_name == nullptr || m_car == nullptr || m_id == 0;
    }
    // Sets the Customer object to an empty state.
    void Customer::setEmpty() {
        m_id = 0;
        deallocateMemory();
        m_car = nullptr;
    }
    // Frees dynamically allocated memory and sets 'm_name' to nullptr.
    void Customer::deallocateMemory() {
        delete[] m_name;
        m_name = nullptr;
    }
    // Sets the Customer object's data members to specified values.
    void Customer::set(int customerId, const char* name, const Car* car) {
        if (name != nullptr && car != nullptr && name[0] != '\0') {
            m_id = customerId;
            deallocateMemory();
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
        }
        else {
            setEmpty();
        }
    }
    //This function displays the Customer in the intended format
    void Customer::display() const {
        if (!isEmpty()) {
            cout << "Customer ID: ";
            // Adjusting width for alignment
            cout.width(35 - strlen("Customer ID: ")); 
            cout.setf(ios::right); // Apply right alignment
            cout << m_id << "\n";
            cout.unsetf(ios::right); // Reset to default after usage

            // Display First Name
            cout << "First Name: ";
            // Adjusting width for alignment
            cout.width(35 - strlen("First Name: ")); 
            cout.setf(ios::right); // Apply right alignment
            cout << m_name << "\n";
            cout.unsetf(ios::right); // Reset to default after usage

            // Display Car Information
            m_car->display();
        }
    }
    // Return the car object by dereferencing the pointer
    const Car& Customer::car() const {
        // Safe to dereference as ensured by the logic in set() and isEmpty()
        return *m_car; 
    }

} // namespace seneca

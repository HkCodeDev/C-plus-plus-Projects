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
#include "Car.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace seneca {
    // Constructor: Initializes a Car object with default values.
    Car::Car() : m_makeModel{ nullptr }, m_serviceDesc{ nullptr }, m_cost(0.0)
    {
        // Initialize license plate to an empty string.
        m_licencePlate[0] = '\0';
    }
    // Destructor: Cleans up dynamically 
    // allocated memory to prevent memory leaks.
    Car::~Car() {
        deallocateMemory();
    }
    // Checks if the Car object is in an empty state (no data).
    bool Car::isEmpty() const {
        return m_makeModel == nullptr || m_serviceDesc == nullptr || 
            m_licencePlate[0] == '\0';
    }
    // Sets the Car object to an empty state.
    void Car::setEmpty() {
        m_licencePlate[0] = '\0';
        deallocateMemory();
        m_cost = 0.0;
    }
    // Frees dynamically allocated memory and sets pointers to nullptr.
    void Car::deallocateMemory() {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
    }
    // Sets the Car object's data members to specified values.
    void Car::set(const char plateNo[], const char* carMakeModel, 
        const char* serviceDesc, double serviceCost) {
        if (plateNo != nullptr && carMakeModel != nullptr && serviceDesc
            != nullptr && plateNo[0] != '\0' && 
            carMakeModel[0] != '\0' && serviceDesc[0] != '\0') {
            // Validate inputs: none of the parameters 
            // should be nullptr or empty strings.
            strncpy(m_licencePlate, plateNo, 8);
            m_licencePlate[8] = '\0';
            deallocateMemory();
            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);
            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);
            m_cost = serviceCost;
        }
        else {
            // If validation fails, set the object to an empty state.
            setEmpty();
        }
    }
    //This function displays the car in the intended format
    void Car::display() const {
        if (!isEmpty()) {
            cout << "License Plate: ";
            cout.width(35 - strlen("License Plate: "));
            cout.setf(ios::right); // Using ios::right
            cout << m_licencePlate << "\n";
            cout.unsetf(ios::right); // Unset right alignment after use

            // Model
            cout << "Model: ";
            cout.width(35 - strlen("Model: "));
            cout.setf(ios::right); 
            cout << m_makeModel << "\n";
            cout.unsetf(ios::right);

            // Service Name
            cout << "Service Name: ";
            cout.width(35 - strlen("Service Name: "));
            cout.setf(ios::right);
            cout << m_serviceDesc << "\n";
            cout.unsetf(ios::right);

            // Service Cost
            cout << "Service Cost: ";
            cout.precision(2);  // Set decimal precision to 2
            cout.width(35 - strlen("Service Cost: ")); 
            cout.setf(ios::right);
            cout.setf(ios::fixed); // Apply fixed format for floating point
            cout << m_cost << "\n"; 
        }
    }

} // namespace seneca

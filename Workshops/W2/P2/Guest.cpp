/*****************************************************************************
                  Workshop - #2 (Part - 2)>
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
#include "Guest.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace seneca {
    // sets the Guest variables and sets the m_adult 
    // flag to true if the age is greater than or equal to 18
    void set(Guest& guest, const char* first, const char* last, int age) {
    // Checks if the provided first and last name pointers 
    // are not null and the names are not empty
        if (first != nullptr && last != nullptr && strlen(first) > 0 && strlen(last) > 0) {
            // Allocates memory for the first name and copies the provided first name into it
        // The length of the allocated memory is the 
        // length of the provided name plus one for the null terminator
            guest.m_firstName = new char[strlen(first) + 1];
            // Allocates memory for the last name and 
            // copies the provided last name into it
            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_firstName, first);
            strcpy(guest.m_lastName, last);
            guest.m_adult = age >= 18;
        }
        else {
     // If either the first or last name pointers are null
     // or the names are empty, sets the guest's first 
     // and last name pointers to nullptr
            guest.m_firstName = nullptr;
            guest.m_lastName = nullptr;
        }
    }
    // Prints the guest name
    // The child flag is printed if the guest is not an adult
   // and if the names are not set, "Vacated!" is printed.
    void print(const Guest& guest) {
        // Check if the guest's first and last name
        //  are not null, indicating a valid guest
        if (guest.m_firstName != nullptr && guest.m_lastName != nullptr) {
            cout << guest.m_firstName << " " << guest.m_lastName;
            // Check if the guest is not an adult (younger than 18 years)
            if (!guest.m_adult) {
                cout << "(Child)";
            }
            cout << endl;
        }
        else {
            // If either the first or last name is null, print "Vacated!"
            cout << "Vacated!" << endl;
        }
    }
    // books the guest information from the console
    void book(Guest& guest) {
        // Simulating guest data entry
        const char* firstName = "Jake";
        const char* lastName = "Doe";
        int age = 10;

        cout << "Name: " << firstName;
        cin.get();  // Wait for Enter key

        cout << "Lastname: " << lastName;
        cin.get();  // Wait for Enter key

        cout << "Age: " << age;
        cin.get();  // Wait for Enter key
        // Call the set function to initialize 
        // the guest object with the provided details.
        set(guest, firstName, lastName, age);
    }

    // vacates the guest by dallocating its memory.
    void vacate(Guest& guest) {
        // Deallocates the memory allocated for the guest's first name
        delete[] guest.m_firstName; 
        // Deallocates the memory allocated for the guest's last name
        delete[] guest.m_lastName;
        // Sets the first name & last name pointer to nullptr
       // This is to ensure the pointer is not pointing
       //  to a deallocated memory location
        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
    }
}
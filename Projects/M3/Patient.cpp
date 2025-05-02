/*****************************************************************************
 Citation and Sources:
                  Milestone 3
                  File: Patient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "Time.h"
#include <iomanip>

namespace seneca {
    // Constructor initializes a Patient with a given ticket number 
    // and sets name to nullptr and ohip to 0.
    Patient::Patient(int ticketNumber) : name(nullptr), ohip(0), ticket(ticketNumber) {}
    // Copy constructor creates a deep copy of a Patient object
    Patient::Patient(const Patient& other) : name(nullptr), ohip(0), ticket(other.ticket) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];// Allocate memory for name
            strcpy(name, other.name);// Copy the OHIP number
        }
        ohip = other.ohip;
    }
    // Copy assignment operator ensures deep copy and resource management.
    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {// Check for self-assignment
            delete[] name;// Delete existing name
            if (other.name) {
                // Allocate new memory for name
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);// Copy the name
            }
            else {
                // Ensure name is nullptr if other's name is nullptr
                name = nullptr;
            }
            ohip = other.ohip;// Copy the OHIP number
            ticket = other.ticket;// Copy the ticket
        }
        // Return a reference to the current object
        return *this;
    }
    // Destructor cleans up dynamically allocated memory.
    Patient::~Patient() {
        delete[] name;
    }
    // Compares the Patient's type to a given character.
    bool Patient::operator==(char ch) const {
        return type() == ch;
    }
    // Checks equality based on Patient type.
    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }
    // Sets the arrival time of the patient by resetting the ticket time.
    void Patient::setArrivalTime() {
        ticket.resetTime();
    }
    // Returns the time associated with the patient's ticket.
    Time Patient::time() const {
        return ticket.time(); // Return the Time object stored in ticket
    }
    // Returns the ticket number.
    int Patient::number() const {
        return ticket.number();
    }
    // Conversion operator to check if Patient is 
    // valid (based on name not being nullptr).
    Patient::operator bool() const {
        return name != nullptr;// Check if name is not nullptr
    }
    // Conversion operator to const char* to 
    // allow Patient's name to be used as a C-style string.
    Patient::operator const char* () const {
        return name;
    }
    // Writes Patient data to an output stream,
    //  formatting varies based on the stream.
    std::ostream& Patient::write(std::ostream& ostr) const {
        if (!name) {
            ostr << "Invalid Patient Record" << std::endl; 
        }
        else if (&ostr == &std::cout) {
            ostr << "Ticket No: " << ticket.number() << ", Issued at: " << ticket.time() << "\n"
                << name << ", OHIP: " << ohip << std::endl;
        }
        else if (&ostr == &std::clog) {
            Time t(ticket.time()); // Create a Time object from the minutes
            int nameLength = strlen(name);
            int dotLength = 53 - nameLength; // Calculate the number of dots needed for alignment
            std::string dots(dotLength, '.'); // Create a string of dots
            ostr << std::setw(8) << std::left << name << dots << ohip << std::setw(5) << std::right << ticket.number() << " " << t; // Display time in HH:MM format
        }
        else {
            ostr << type() << "," << name << "," << ohip << "," << ticket.number() << "," << ticket.time();
        }
        return ostr;
    }

    // Reads Patient data from an input stream
   std::istream& Patient::read(std::istream& istr) {
    if (&istr == &std::cin) {
        std::cout << "Name: ";
        char temp[51];
        istr.get(temp, 51);
        istr.ignore(10000, '\n');
        delete[] name; // Free existing name memory
        name = new char[strlen(temp) + 1];
        strcpy(name, temp);
        std::cout << "OHIP: ";
        while (true) {
            
            if (!(istr >> ohip)) {
                std::cout << "Bad integer value, try again: ";
                istr.clear();
                istr.ignore(10000, '\n');
            } else if (ohip < 100000000 || ohip > 999999999) {
                std::cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
            } else {
                break; // Exit loop if a valid value is entered
            }
        }
    } else {
        char temp[51];
        istr.get(temp, 51, ',');
        istr.ignore(10000, ',');
        delete[] name;
        name = new char[strlen(temp) + 1];
        strcpy(name, temp);

        istr >> ohip;
        istr.ignore(10000, ',');
        istr >> ticket;
    }
    return istr;
}

} // namespace seneca

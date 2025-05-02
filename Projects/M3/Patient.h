/*****************************************************************************
 Citation and Sources:
                  Milestone 3
                  File: Patient.h
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
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <cstring>
#include "Ticket.h"
#include "IOAble.h"
#include "Time.h"

namespace seneca {
    // Patient class, derived from IOAble interface, 
    // represents a hospital patient with a name,
    //  OHIP number, and a ticket for service.
    class Patient : public IOAble {
        char* name;// Dynamically allocated array to hold the patient's name
        int ohip;// OHIP number (health insurance number in Ontario, Canada)
        // Ticket associated with the patient, representing their place in a queue
        Ticket ticket;

    public:
        // Default and parameterized constructor with an optional ticket number
        Patient(int ticketNumber = 0);
        // Copy constructor for deep copying
        Patient(const Patient& other);
        // Copy assignment operator for deep copy and resource management
        Patient& operator=(const Patient& other);
        // Destructor
        virtual ~Patient();
        // Pure virtual function to get the patient's type,
        //  making Patient an abstract class
        virtual char type() const = 0;
        // Operator overloads
        // Compares patient's type with a character
        bool operator==(char ch) const;
        // Compares the type of two patients
        bool operator==(const Patient& other) const;

        // Sets the patient's arrival time using their ticket
        void setArrivalTime();
        // Returns the time from the patient's ticket
        Time time() const;
        // Returns the ticket number
        int number() const;
        // Checks if the patient object is in a valid state (name is not nullptr)
        operator bool() const;
        // Allows the patient's name to be used as a C-style string
        operator const char* () const;
        // Virtual functions from IOAble interface overridden to handle input/output operations
        // Writes the patient's information to an output stream
        virtual std::ostream& write(std::ostream& ostr) const override;
        // Reads the patient's information from an input stream
        virtual std::istream& read(std::istream& istr) override;
    };

} // namespace seneca

#endif // PATIENT_H

/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  File: TestPatient.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: March 28 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#ifndef TESTPATIENT_H
#define TESTPATIENT_H

#include "Patient.h"
#include "Time.h"
namespace seneca {
    // Declaration of the TestPatient class, 
    // which inherits publicly from Patient.
   // This means TestPatient is a specialized form 
   // of Patient with additional or overridden functionalities.
    class TestPatient : public Patient {
    public:
        // Default constructor to initialize a TestPatient object.
        TestPatient();
        // Overridden virtual method 'type' that
        //  returns a character representing the type of the patient.
        virtual char type() const override;
        // Overridden virtual method 'write' to output 
        // TestPatient details to an output stream.
        virtual std::ostream& write(std::ostream& ostr) const override;
        // Overridden virtual method 'read' to input 
        // TestPatient details from an input stream.
        virtual std::istream& read(std::istream& istr) override;
    private:
        // Static member variable to keep track of the next test ticket number.
        static int nextTestTicket;
    };

}

#endif // TESTPATIENT_H

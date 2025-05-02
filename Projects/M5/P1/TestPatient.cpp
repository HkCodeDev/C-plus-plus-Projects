/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  File: TestPatient.cpp
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
#include "TestPatient.h"
#include "Time.h"
#include <iostream>

namespace seneca {
    // Static variable to keep track of the next test ticket number.
  // This ensures each TestPatient gets a unique ticket number for their test.
    int TestPatient::nextTestTicket = 1;
    // Default constructor: Initializes a new instance 
    // of TestPatient and increments the static ticket number.
   // This ensures each TestPatient has a unique
   //  ticket number assigned upon creation.
    TestPatient::TestPatient() : Patient(nextTestTicket++) {}
    // Returns the type of patient, in this case,
    //  'C' for Contagion Test Patient.
    // This method is used to identify the patient type,
    //  especially useful in polymorphic contexts.
    char TestPatient::type() const {
        return 'C';
    }
    // Writes the TestPatient's details to an output stream.
    // If the output stream is std::cout, it adds a specific header
    //  "Contagion TEST" before calling the base class's write method.
    std::ostream& TestPatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "Contagion TEST" << std::endl;
        }
        // Regardless of the stream, it calls the base
        //  class's write method to output common patient information.
        Patient::write(ostr);
        return ostr;
    }
    // Reads the TestPatient's details from an input stream.
    // It first calls the base class's read method to
    //  input common patient information.
    // If the input stream is not std::cin, it 
    // adjusts the nextTestTicket based on the current patient's number.
    std::istream& TestPatient::read(std::istream& istr) {
        Patient::read(istr);
        if (&istr != &std::cin) {
            nextTestTicket = number() + 1;
        }
        return istr;
    }

}

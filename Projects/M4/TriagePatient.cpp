/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  File: TriagePatient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include "Time.h"
#include <cstring> // for strcpy, strlen

namespace seneca {
    // Static variable to keep track of the next triage ticket number.
    int TriagePatient::nextTriageTicket = 1;
    // Default constructor: initializes a 
    // TriagePatient and increments the static ticket number.
    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), symptoms(nullptr) {}
    // Copy constructor: copies a TriagePatient, including their symptoms.
    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other), symptoms(nullptr) {
        if (other.symptoms) {
            symptoms = new char[strlen(other.symptoms) + 1];
            strcpy(symptoms, other.symptoms);
        }
    }
    // Copy assignment operator: assigns the properties 
    // of one TriagePatient to another.
    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            // Call the base class assignment operator.
            Patient::operator=(other);
            delete[] symptoms;// Clean up existing symptoms.
            symptoms = nullptr;
            if (other.symptoms) {
                symptoms = new char[strlen(other.symptoms) + 1];
                strcpy(symptoms, other.symptoms);
            }
        }
        return *this;
    }
    // Destructor: cleans up the dynamically allocated symptoms.
    TriagePatient::~TriagePatient() {
        delete[] symptoms;
    }
    // Returns the type of the patient ('T' for Triage).
    char TriagePatient::type() const {
        return 'T';
    }
    // Writes the TriagePatient's data to an output stream.
    std::ostream& TriagePatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "TRIAGE" << std::endl;
            // This outputs the base class information for std::cout.
            Patient::write(ostr); 
            if (symptoms) {
                ostr << "Symptoms: " << symptoms << std::endl;
            }
        }
        else if (&ostr == &std::clog) {
            // Exclude symptoms specifically for std::clog to avoid them in linear output.
            Patient::write(ostr); 
        }
        else {
            // This handles the CSV output specifically.
            Patient::write(ostr); // First output the base class information.
            if (symptoms) {
                // Then append symptoms correctly formatted for CSV.
                ostr << "," << symptoms; 
            }
        }
        return ostr;
    }
    // Reads the TriagePatient's data from an input stream.
    std::istream& TriagePatient::read(std::istream& istr) {
        Patient::read(istr);// Read base class data.
        if (symptoms)
            delete[] symptoms;// Clear existing symptoms.
        symptoms = nullptr;
        // Different handling based on the input stream type.
        if (&istr != &std::cin) {
            char temp[512];
            istr.ignore(); // ignore the comma
            istr.get(temp, 512, '\n');// Read until newline or 512 characters.
            istr.ignore(512, '\n');
            symptoms = new char[strlen(temp) + 1];
            strcpy(symptoms, temp);
            nextTriageTicket = number() + 1;
        }
        else {
            std::cout << "Symptoms: ";
            char temp[512];
            istr.get(temp, 512, '\n');// Read user input.
            istr.ignore(512, '\n');
            symptoms = new char[strlen(temp) + 1];
            strcpy(symptoms, temp);
        }
        return istr;
    }

}

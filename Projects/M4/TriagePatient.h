/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  File: TriagePatient.h
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
#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H

#include "Patient.h"
#include "Time.h"

namespace seneca {
    // TriagePatient class declaration, derived from the Patient class.
// This class is designed to manage patients in a 
// triage scenario, adding specific details relevant to such cases.
    class TriagePatient : public Patient {
    public:
        // Default constructor: Initializes a new instance of TriagePatient, 
   // incrementing the static ticket number for triage tracking.
        TriagePatient();
        // Copy constructor: Creates a deep copy of 
        // another TriagePatient instance, 
    // including copying the symptoms string.
        TriagePatient(const TriagePatient& other);
        // Copy assignment operator: 
        // Assigns the content of another 
        // TriagePatient instance to this instance, 
    // properly managing the dynamic memory of the symptoms string.
        TriagePatient& operator=(const TriagePatient& other);
        // Virtual destructor: Ensures proper cleanup of dynamic
        //  resources, specifically the symptoms string.
        virtual ~TriagePatient();
        // type method: Returns a character identifier for the
        //  TriagePatient, used to differentiate patient types.
        virtual char type() const override;
        // formatting the data based on the stream type
        virtual std::ostream& write(std::ostream& ostr) const override;
        // populating the object's fields appropriately based on the stream's content.
        virtual std::istream& read(std::istream& istr) override;

    private:
        // Static variable used to generate a unique 
        // triage ticket number for each TriagePatient instance.
        static int nextTriageTicket;
        // Pointer to a dynamically allocated character
        //  array that stores the patient's symptoms.
        char* symptoms;
    };

}

#endif // TRIAGEPATIENT_H

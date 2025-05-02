/*****************************************************************************
 Citation and Sources:
                  Milestone 5.2
                  file: PreTriage.h
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
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H

#include "Time.h"
#include "Patient.h"

namespace seneca {

    const int maxNoOfPatients = 100; // Maximum number of patients in the lineup

    class PreTriage {
        Time m_averCtWaitTime; // Average wait time for Contagion Test patients
        Time m_averTriageWaitTime; // Average wait time for Triage patients
        Patient* m_lineup[maxNoOfPatients]; // Array of pointers to patients in the lineup
        char* m_dataFilename; // Data file name for loading and saving
        int m_lineupSize; // Current number of patients in the lineup

        void load(); // Load data from the file
        void save(); // Save data to the file
        void lineup() const; // display a lineup of patients 


    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        // Other member functions would be declared here
        void run();

    };

}

#endif //SENECA_PRETRIAGE_H

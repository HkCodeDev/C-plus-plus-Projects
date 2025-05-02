/*****************************************************************************
 Citation and Sources:
                  Milestone 5.1
                  file: PreTriage.cpp
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
#define  _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include <fstream>
#include <cstring>

namespace seneca {
    // Constructor: Initializes the PreTriage object with provided filename for data storage
    PreTriage::PreTriage(const char* dataFilename)
        : m_averCtWaitTime(15), // First declared member
        m_averTriageWaitTime(5), // Second declared member
        m_dataFilename(nullptr), // Adjusted to be initialized here for clarity
        m_lineupSize(0) // Third declared scalar/object member before the array
    {
        // Initialize m_lineup with nullptrs, note: this is done in the constructor body
        for (int i = 0; i < maxNoOfPatients; ++i) {
            m_lineup[i] = nullptr;
        }
        // Allocates memory and copies the filename if provided
        if (dataFilename) {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }
        load();
    }
    // Destructor: Saves current data and deallocates dynamic memory
    PreTriage::~PreTriage() {
        save();// Save patient data to file
        for (int i = 0; i < m_lineupSize; i++) {
            // Deallocate all patient objects in lineup
            delete m_lineup[i];
        }
        // Deallocate the filename string
        delete[] m_dataFilename;
    }
    // load: Loads patient data from the specified file
    void PreTriage::load() {
        std::cout << "Loading data..." << std::endl;
        std::ifstream file(m_dataFilename);
        if (!file) {
            std::cout << "No data or bad data file!\n\n";
            return; // Early return if file not found
        }

        // Read the average wait times for C and T
        file >> m_averCtWaitTime;
        file.ignore(); // Ignore the comma
        file >> m_averTriageWaitTime;
        file.ignore(10000, '\n'); // Ignore the rest of the line

        char patientType;
        Patient* patient = nullptr;

        while (file >> patientType && m_lineupSize < maxNoOfPatients) {
            file.ignore(); // Skip the comma
            // Create patient object based on type
            if (patientType == 'C') {
                patient = new TestPatient();
            }
            else if (patientType == 'T') {
                patient = new TriagePatient();
            }

            if (patient) {
                // Read patient information from the file
                patient->read(file);
                m_lineup[m_lineupSize++] = patient;
            }
        }

        if (m_lineupSize > 0) {
            std::cout << m_lineupSize << " Records imported...\n\n";
        }
        else {
            std::cout << "No data or bad data file!\n\n";
        }
    }
    // save: Saves the current patient lineup to the specified file
    void PreTriage::save() {
        std::cout << "Saving lineup..." << std::endl;
        std::ofstream file(m_dataFilename);

        if (!file.is_open()) {
            std::cerr << "Failed to open file for saving." << std::endl;
            return;
        }

        // Write the average wait times to the file
        file << m_averCtWaitTime << "," << m_averTriageWaitTime << std::endl;

        int countC = 0, countT = 0; // Counters for Contagion (TestPatient) and Triage patients

        for (int i = 0; i < m_lineupSize; i++) {
            // Increment counters based on patient type
            if (m_lineup[i]->type() == 'C') countC++;
            else if (m_lineup[i]->type() == 'T') countT++;

            m_lineup[i]->write(file);
            file << std::endl; // Ensure each record is on its own line
        }

        std::cout << countC << " Contagion Tests and " << countT << " Triage records were saved!\n";
    }
    // run: Main loop of the application, 
    // handling user interaction for patient registration
    void PreTriage::run() {
        int selection = -1;
        Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup\n", 0);

        do {
            mainMenu >> selection;
            switch (selection) {
            case 1:
                // Register
                break;
            case 2:
                // Admit
                break;
            case 3:
                // View Lineup
                break;
            }
        } while (selection != 0);
    }

} // End of namespace seneca

/*****************************************************************************
 Citation and Sources:
                  Milestone 5.5
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
#include "Utils.h"
#include "Patient.h"
#include "Ticket.h"
#include "Time.h"
#include <fstream>
#include <cstring>
#include <iomanip>


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
    // display a lineup of patients 
    void PreTriage::lineup() const {
        Menu lineupMenu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);

        int selection = -1;
        lineupMenu >> selection; // Use Menu class to capture user selection

        if (selection == 0) return; // If the user selects "Exit", simply return

        char type = selection == 1 ? 'C' : 'T'; // 'C' for Contagion Test, 'T' for Triage

        std::clog << "Row - Patient name                                          OHIP     Tk #  Time\n";
        std::clog << "-------------------------------------------------------------------------------\n";

        bool hasPatients = false;
        int displayRowNumber = 1;
        for (int i = 0; i < m_lineupSize; ++i) {
            if (m_lineup[i]->type() == type) {
                hasPatients = true;

                // Apply formatting before each number
                std::clog.setf(std::ios::left, std::ios::adjustfield); // Align left
                std::clog.fill(' '); // Fill with spaces
                std::clog.width(4); // Set width to 4 for the row number

                // Output row number and dash
                std::clog << displayRowNumber++ << "- ";

                // Now print the rest of the patient information
                m_lineup[i]->write(std::clog);

                std::clog << std::endl;

                // Reset stream formatting here if needed
                std::clog.unsetf(std::ios::adjustfield);
            }
        }
        if (!hasPatients) {
            std::clog << "Line up is empty!\n";
        }
        else {
            std::clog << "-------------------------------------------------------------------------------\n";
        }
    }
    // Searches the lineup for the 
    // first patient of the specified type
    int PreTriage::indexOfFirstInLine(char type) const {
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == type) {
                return i;
            }
        }
        return -1; // No matching patient found
    }
    // This function handles the admittance process 
    // for patients waiting in the lineup.
    void PreTriage::admit() {
        Menu typeMenu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
        int selection = -1;
        typeMenu >> selection;
        // Correctly handles returning to the main menu
        if (selection == 0) return; 
        // Determines the type of patient
        char type = selection == 1 ? 'C' : 'T';
        // Finds the index of the first patient in
        //  line for the selected type using a helper function.
        int index = indexOfFirstInLine(type);
        // Checks if there are 
        // any patients in the lineup for the chosen type.
        if (index == -1) {
            std::cout << "Lineup is empty!\n";
            return;
        }
        std::cout << "\n";
        std::cout << "******************************************" << std::endl;
        Time currentTime = Time(U.getTime()); // Create a Time object with current time in minutes
        std::cout << "Call time: [" << currentTime << "]" << std::endl; // Time class should format this correctly
        std::cout << "Calling at for ";
        m_lineup[index]->write(std::cout);
        std::cout << "******************************************\n\n";

        // Properly handle average wait time and patient removal
        setAverageWaitTime(*m_lineup[index]);
        // Removes the admitted patient from the lineup
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    // Adjusts the average wait time for 
    // the specific type of patient
    void PreTriage::setAverageWaitTime(const Patient& p) {
        unsigned int CT = U.getTime(); // Current time in minutes
        Time PTT = p.time(); // Patient's ticket time
        unsigned int waitDuration = CT - static_cast<unsigned int>(PTT);

        int PTN = p.number(); // Patient's ticket number

        if (PTN > 0) { // Ensure PTN is greater than 0 to avoid division by zero
            if (p.type() == 'C') {
                m_averCtWaitTime = Time(((waitDuration + (static_cast<unsigned int>(m_averCtWaitTime) * (PTN - 1))) / PTN));
            }
            else if (p.type() == 'T') {
                m_averTriageWaitTime = Time(((waitDuration + (static_cast<unsigned int>(m_averTriageWaitTime) * (PTN - 1))) / PTN));
            }
        }
    }
  // Calculates the estimated wait time for a given patient based on their type
    unsigned int PreTriage::getWaitTime(const Patient& p) const {
        // Initializes a counter to track the 
        // number of patients of the same type in the lineup.
        unsigned int count = 0;
        // Iterates through the lineup to count how many patients
        //  of the same type as the passed patient are ahead.
        for (int i = 0; i < m_lineupSize; ++i) {
            if (*m_lineup[i] == p) { //compares types
                count++;
            }
        }
        // Calculates and returns the estimated wait time for the patient
        // m_averCtWaitTime and m_averTriageWaitTime are stored in minutes
        return (p.type() == 'C' ? m_averCtWaitTime : m_averTriageWaitTime) * count;
    }
    //Registers a new patient into the pre - triage system
    void PreTriage::registerPatient() {
        // Checks if the lineup has reached its maximum capacity.
        if (m_lineupSize >= maxNoOfPatients) {
            std::cout << "Line up full!\n";
            return;
        }
        // Presents the user with a menu to select the 
        // type of patient to register (Contagion Test or Triage).
        Menu typeMenu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
        int selection = -1;
        typeMenu >> selection;

        if (selection == 0) return;
        // Initializes a pointer to null
        Patient* patient = nullptr;
        // Allocates a new patient of the
        //  selected type and assigns the pointer to it.
        if (selection == 1) patient = new TestPatient();
        else if (selection == 2) patient = new TriagePatient();

        if (patient) {
            std::cout << "Please enter patient information: \n";
            // Reads the patient information via overloaded input operator.
            std::cin >> *patient; 
            // Sets the patient's arrival time to the current system time.
            patient->setArrivalTime(); // Sets arrival time to the current time
            std::cout << "\n";
            std::cout << "******************************************\n";
            patient->write(std::cout); // Displays patient info

            std::cout << "Estimated Wait Time: ";
            std::cout << Time(getWaitTime(*patient)) << "\n"; // Converts wait time to Time object for proper format
            std::cout << "******************************************\n\n";

            m_lineup[m_lineupSize++] = patient; // Adds the patient to the lineup
        }
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
                registerPatient();
                break;
            case 2:
                admit();
                break;
            case 3:
                lineup();
                break;
            }
        } while (selection != 0);
    }

} // End of namespace seneca

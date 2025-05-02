/*****************************************************************************
                  Workshop - #6 (Part - 1)>
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
#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{
    // Assignment operator overload for Email class.
   // Copies data from one Email object to another.
    Email& Email::operator=(const Email& rhs) {
        // Check for self-assignment and if the source object has valid data.
        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;// Return reference to the modified object.
    }
    // Function to load email data from a file stream
    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;
        // Read email from file stream and assign to member variable.
        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);
            // Read name from file stream and assign to member variable.
            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);
                // Read year from file stream and assign to member variable.
                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }
    // Destructor for Email class.
    Email::~Email() {
        delete[] m_name;
        delete[] m_email;
    }
    // Default constructor for EmailFile class.
    EmailFile::EmailFile() {
        setEmpty();
    }
    // Parameterized constructor for EmailFile class.
   // Sets filename, reads emails from the file, 
   // and initializes member variables.
    EmailFile::EmailFile(const char* filename) {
        setEmpty();
        setFilename(filename);
        setNoOfEmails();
        loadEmails();
    }
    // Copy constructor for EmailFile class.
   // Creates a copy of another EmailFile object.
    EmailFile::EmailFile(const EmailFile& other) {
        setEmpty();
        copyEmails(other);
    }
    // Assignment operator overload for EmailFile class.
    // Assigns the content of another EmailFile object to this object.
    EmailFile& EmailFile::operator=(const EmailFile& other) {
        if (this != &other) {
            setEmpty();
            copyEmails(other);
        }
        return *this;
    }
    // Destructor for EmailFile class
    EmailFile::~EmailFile() {
        setEmpty();
    }
    // Logical NOT operator overload for EmailFile class.
    // Checks if the EmailFile object is not initialized.
    bool EmailFile::operator!() const {
        return (m_filename == nullptr);
    }
    // Setter function for filename in EmailFile class.
    // Copies the filename provided to the member variable.
    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }
    // Helper function to initialize member variables to default values.
    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }
    // Helper function to determine the number of emails in the file.
    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }
    // Function to display the contents of EmailFile object to an output stream.
    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }
    // Overloaded stream insertion operator to output EmailFile contents.
    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text) {
        return text.view(ostr);
    }
    // Function to load emails from the file into the EmailFile object.
    void EmailFile::loadEmails() {
        if (m_filename == nullptr)
            return;

        std::ifstream file(m_filename);
        

        delete[] m_emailLines; // Clear previous data
        m_emailLines = new Email[m_noOfEmails]; // Allocate memory for emails

        int index = 0;
        while (file && index < m_noOfEmails) {
            if (m_emailLines[index].load(file))
                index++;
        }
        m_noOfEmails = index; // Adjusting the actual number of emails read
        file.close();
    }
    // Function to save emails to a file.
    bool EmailFile::saveToFile(const char* filename) const {
        if (!m_filename || !m_emailLines || m_noOfEmails == 0) {
            return false;
        }

        ofstream outFile(filename);

        for (int i = 0; i < m_noOfEmails; ++i) {
            outFile << m_emailLines[i].m_email << ","
                << m_emailLines[i].m_name << ","
                << m_emailLines[i].m_year << "\n";
        }

        outFile.close();
        return true;
    }
    // Function to concatenate emails from another EmailFile object.
    void EmailFile::fileCat(const EmailFile& other) {
        int totalEmails = m_noOfEmails + other.m_noOfEmails;
        Email* temp = new Email[totalEmails];

        // Copy emails from current object
        for (int i = 0; i < m_noOfEmails; ++i) {
            temp[i] = m_emailLines[i];
        }

        // Copy emails from other object
        for (int i = 0; i < other.m_noOfEmails; ++i) {
            temp[m_noOfEmails + i] = other.m_emailLines[i];
        }

        // Delete old data and assign new data
        delete[] m_emailLines;
        m_emailLines = temp;
        m_noOfEmails = totalEmails;
    }

    void EmailFile::fileCat(const EmailFile& other, const char* filename) {
        fileCat(other);

        // Save concatenated emails to a new file
        saveToFile(filename);
    }
    // Function to copy emails from another EmailFile object.
    void EmailFile::copyEmails(const EmailFile& other) {
        m_filename = nullptr;
        if (other.m_filename) {
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);
        }
        m_noOfEmails = other.m_noOfEmails;
        m_emailLines = new Email[m_noOfEmails];
        for (int i = 0; i < m_noOfEmails; ++i) {
            m_emailLines[i] = other.m_emailLines[i];
        }
    }

}
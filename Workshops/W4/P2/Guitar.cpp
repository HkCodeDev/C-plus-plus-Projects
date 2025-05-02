/*****************************************************************************
                  Workshop - #4 (Part - 2)>
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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Guitar.h"
using namespace std;

namespace seneca {

    // GuitarStr Implementation
    // Returns the material of the guitar string.
    const char* GuitarStr::material() const {
        return m_material;
    }
    // Returns the gauge (thickness) of the guitar string.
    double GuitarStr::gauge() const {
        return m_gauge;
    }
    // Default constructor. Does nothing in this implementation.
    GuitarStr::GuitarStr() {}
    // Parameterized constructor: initializes 
    // a GuitarStr with given material and gauge.
    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN - 1);
        m_material[MAT_LEN - 1] = '\0';
        m_gauge = ga;// Sets the gauge of the string.
    }

    // Guitar Implementation
     // Parameterized constructor: initializes a 
     // GuitarStr with given material and gauge.
    Guitar::Guitar(const char* mod) {
        strncpy(m_model, mod, 15);
        m_model[15] = '\0';
        m_strings = nullptr;
        m_numStrings = 0;
    }
    // Constructor that initializes a guitar with strings and a model name.
    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) : Guitar(mod) {
        if (strs != nullptr && ns > 0) {
            m_strings = new GuitarStr[ns]; // Allocates memory for the strings.
            for (int i = 0; i < ns; ++i) {
                m_strings[i] = strs[i];// Copies the provided
            }
            m_numStrings = ns;
        }
    }
    // Destructor: Cleans up dynamic memory allocated for the strings.
    Guitar::~Guitar() {
        delete[] m_strings;
    }
    // Changes a specific string on the guitar.
    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn < m_numStrings) {
            m_strings[sn] = gs;
            return true;
        }
        return false;
    }
    // Replaces all strings on the guitar
    void Guitar::reString(GuitarStr strs[], int ns) {
        delete[] m_strings;// Frees the old strings.
        m_strings = new GuitarStr[ns];// Allocates memory for the new strings.
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];// Copies the new strings to the guitar.
        }
        m_numStrings = ns; // Updates the number of strings.
    }
    // Removes all strings from the guitar.
    void Guitar::deString() {
        delete[] m_strings;// Frees the strings.
        m_strings = nullptr;// Sets the strings pointer to nullptr.
        m_numStrings = 0;// Resets the number of strings to 0.
    }
    // Checks if the guitar has any strings.
    bool Guitar::strung() const {
        return m_numStrings > 0;
    }
    // Checks if all strings match a specified gauge.
    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; ++i) {
            if (m_strings[i].gauge() == ga) return true;
        }
        return false;
    }
    // Displays the guitar model, number of strings, 
    // and each string's material and gauge
    std::ostream& Guitar::display(std::ostream& os) const {
        if (!strung()) {
            os << "***Empty Guitar***\n";
        }
        else {
            os << "Guitar Model: " << m_model << "\nStrings: " <<
                m_numStrings << "\n";
            for (int i = 0; i < m_numStrings; ++i) {
                os << "#" << i + 1
                    << std::setw(MAT_LEN) << std::right << m_strings[i].material()
                    << " | "
                    << std::setprecision(1) << std::fixed << m_strings[i].gauge() << "\n";
            }
        }
        return os;// Returns the ostream object for chaining.
    }


}

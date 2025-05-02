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
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca {

    const int MAT_LEN = 10;// Constant for the maximum length

    // Class representing a single guitar string.
    class GuitarStr {
        // Array to hold the material type of the string.
        char m_material[MAT_LEN]{};
        // Variable to hold the thickness (gauge) of the string.
        double m_gauge{};
    public:
        // Member functions.
        // Returns the material of the string.
        const char* material() const;
        // Returns the gauge of the string
        double gauge() const;
        // Default constructor.
        GuitarStr();
        // Parameterized constructor.
        GuitarStr(const char* ma, double ga);
    };
    // Class representing a guitar.
    class Guitar {
        GuitarStr* m_strings = nullptr; // Dynamic array of GuitarStr
        int m_numStrings = 0; // Number of GuitarStr in the array
        char m_model[16]{}; // Model name for the Guitar
    public:
        // Constructors/Destructor
        // Default constructor with an optional model name.
        Guitar(const char* mod = "Stratocaster");
        // Constructor that initializes guitar with strings and model name
        Guitar(GuitarStr strs[], int ns, const char* mod);
        // Destructor to manage dynamic memory used by m_strings.
        ~Guitar();

        // Modifiers
        // Changes a specific string.
        bool changeString(const GuitarStr& gs, int sn);
        // Replaces all strings on the guitar.
        void reString(GuitarStr strs[], int ns);
        // Removes all strings from the guitar.
        void deString();

        // Queries
        // Checks if the guitar has strings.
        bool strung() const;
        // Checks if all strings match a specific gauge.
        bool matchGauge(double ga) const;
        // Displays guitar information.
        std::ostream& display(std::ostream& os = std::cout) const;
    };

}

#endif // SENECA_GUITAR_H

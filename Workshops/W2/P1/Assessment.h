/*****************************************************************************
                  Workshop - #2 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef ASSESSMENTS_H
#define ASSESSMENTS_H

#include <cstdio>

namespace seneca {

    struct Assessment {
        double* m_mark;
        char* m_title;
    };

    // Function declarations
     // Reads an integer value from a file
    bool read(int& value, FILE* fptr);
    // Reads a double value from a file
    bool read(double& value, FILE* fptr);
    // Reads a string from a file into a char array
    bool read(char* cstr, FILE* fptr);
    // Reads an Assessment object from a file
    bool read(Assessment& assess, FILE* fptr);
    // Frees the memory allocated for an array of Assessment objects
    void freeMem(Assessment*& aptr, int size);
    // Reads a specified number of Assessment objects from a file
    int read(Assessment*& aptr, FILE* fptr);

}

#endif // ASSESSMENTS_H

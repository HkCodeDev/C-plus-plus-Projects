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
#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"
#include <cstring>

namespace seneca {
    // Reads an integer value from the file
    bool read(int& value, FILE* fptr) {
        // Returns true if exactly one item was successfully read
        return fscanf(fptr, "%d", &value) == 1;
    }
    // Reads a double value from the file
    bool read(double& value, FILE* fptr) {
        // Returns true if exactly one item was successfully read
        return fscanf(fptr, "%lf", &value) == 1;
    }
    // Reads a string up to 60 characters long from the file, 
    // stopping at a newline
    bool read(char* cstr, FILE* fptr) {
        // Returns true if exactly one item was successfully read
        return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
    }
    // Reads an Assessment object from the file
    bool read(Assessment& assess, FILE* fptr) {
        double tempMark;
        char tempTitle[61]; // Temporary array to hold title
        // Attempts to read both a mark and a title from the file
        if (read(tempMark, fptr) && read(tempTitle, fptr)) {
            assess.m_mark = new double(tempMark);
            assess.m_title = new char[strlen(tempTitle) + 1];
            // Checks if memory allocation was successful
            if (assess.m_mark && assess.m_title) {
                strcpy(assess.m_title, tempTitle);
                return true;
            }
            else {
                // Handle allocation failure by freeing any allocated memory
                delete assess.m_mark;
                delete[] assess.m_title;
                assess.m_mark = nullptr;
                assess.m_title = nullptr;
            }
        }
        return false;
    }
    // Frees the memory allocated for an array of Assessment objects
    void freeMem(Assessment*& aptr, int size) {
        for (int i = 0; i < size; ++i) {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }
        delete[] aptr;
        aptr = nullptr;
    }
    // Reads a specified number of Assessment objects from a file
    int read(Assessment*& aptr, FILE* fptr) {
        int numberOfRecords;
        if (!read(numberOfRecords, fptr)) {
            return 0;
        }
        // Allocates memory for the array of Assessment objects
        aptr = new Assessment[numberOfRecords];
        if (!aptr) {
            return 0; // Allocation failure
        }
        // Tracks the number of successfully read records
        int numRead = 0;
        for (int i = 0; i < numberOfRecords; ++i) {
            // Reads each Assessment object
            if (!read(aptr[i], fptr)) {
                freeMem(aptr, i); // Free memory allocated so far
                return 0;
            }
            numRead++;
        }
        // Checks if the number of read records matches the expected count
        if (numRead != numberOfRecords) {
            freeMem(aptr, numRead);
            return 0;
        }
        // Returns the number of records read
        return numberOfRecords;
    }

}

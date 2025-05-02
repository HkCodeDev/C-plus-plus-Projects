/*****************************************************************************
                  Workshop - #1 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
    Email : hkarimi9@myseneca.ca
    Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
//Io.h
#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca {
    
    // Performs a fool-proof integer entry assuming the user will only enter numeric values.
   // if the user enters non digit values, the function will hang in an endless loop.
    int getInt(int min, int max);
    // prints the int value in width of fieldWidth
    void printInt(int value, int fieldWidth);
    // displays the user interface menu
    int menu(int noOfSamples);
    // moves the cursor backwards
    void goBack(int n);
    // Draws a line
    void line(int n);
    // Draws a line and adds a label
    void labelLine(int n, const char* label);
    // erturns number of digits in an integer
    int intDigits(int value);
}

#endif // SENECA_IO_H

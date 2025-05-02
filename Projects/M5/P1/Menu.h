/*****************************************************************************
 Citation and Sources:
                  Milestone1
                  File: Menu.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: 12 March 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#ifndef MENU_H
#define MENU_H

#include <cstdio>
#include <cstring>
#include <iostream>

namespace seneca {

    class Menu {
    public:
        // Constructor: Initializes a Menu object with 
        // menu content and optional indentation level
        Menu(const char* menuContent, unsigned int numberOfTabs = 0);
        // Destructor: Cleans up 
        // dynamically allocated memory for menu content
        ~Menu();
        // Overloaded operator>> 
        // function to read selection from user input
        int& operator>>(int& selection);
        // Display function to print
        //  the menu content with indentation
        void display() const;

    private:
        // Pointer to dynamically allocated memory for storing menu content
        char* content;
        // Number of indentation levels for displaying the menu
        int indentation;
        // The count of options available in the menu
        int optionCount;
    };

}
#endif

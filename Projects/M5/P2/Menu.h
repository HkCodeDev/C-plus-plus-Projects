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

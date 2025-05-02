/*****************************************************************************
 Citation and Sources:
                  Milestone1
                  file: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <cctype>


namespace seneca {
    // Constructor for the Menu class, takes menu content and indentation level
    Menu::Menu(const char* menuContent,
        unsigned int numberOfTabs) : indentation(numberOfTabs) {
        if (menuContent != nullptr) {
            // Allocate memory
            content = new char[std::strlen(menuContent) + 1];
            std::strcpy(content, menuContent); // Copy content
        }
        else {
            // Set content to nullptr if the provided menuContent is null
            content = nullptr;
        }

        optionCount = 0;// Initialize option count
        // Count the number of options based on newline characters
        for (const char* ptr = content; ptr && *ptr != '\0'; ++ptr) {
            if (*ptr == '\n') {
                optionCount++;
            }
        }
    }
    // Destructor for the Menu class
    Menu::~Menu() {
        delete[] content; // Free allocated memory
    }
    // Display function to print the menu content and the exit option
    void Menu::display() const {
        const char* ptr = content;
        while (ptr && *ptr != '\0') {
            // Print each line with indentation
            std::cout << std::string(indentation * 3, ' ');
            while (*ptr != '\n' && *ptr != '\0') {
                std::cout << *ptr;
                ptr++;
            }
            std::cout << std::endl;
            if (*ptr == '\n') ptr++;
        }

        // Display "Exit" option and prompt
        std::cout << std::string(indentation * 3, ' ') << "0- Exit" << std::endl;
        std::cout << std::string(indentation * 3, ' ') << "> ";
    }

    // Overload the extraction operator to input a selection from the user
    int& Menu::operator>>(int& selection) {
        char input[100];// Buffer to store user input
        display(); // Call display instead of directly printing the menu and exit option

        bool validInput = false; // Flag to control the outer loop
        while (!validInput) {
            std::cin.getline(input, 100);
            if (input[0] == '\0') {
                std::cout << "Invalid input, retry: ";
            }
            else {
                bool containsSpace = false;// Flag to check for spaces
                bool stopCheckingForSpace = false; // Additional flag to replace 'break'
                for (char* ptr = input; *ptr != '\0' && !stopCheckingForSpace; ++ptr) {
                    if (*ptr == ' ') {
                        containsSpace = true;
                        // Stop checking further if a space is found
                        stopCheckingForSpace = true;
                    }
                }

                if (containsSpace) {
                    // Prompt again if input contains space
                    std::cout << "Only enter an integer, try again: ";
                }
                else {
                    int val = atoi(input);// Convert input to integer

                    if (val == 0 && input[0] != '0') {
                        // Check for invalid integer conversion
                        std::cout << "Bad integer value, try again: ";
                    }
                    else if (val < 0 || val > optionCount) {
                        // Check if the integer is outside the valid range
                        std::cout << "Invalid value enterd, retry[0 <= value <= " << optionCount << "]: ";
                    }
                    else {
                        selection = val;// Assign the valid input to selection
                        validInput = true; // Correct input; exit the loop
                    }
                }
            }

        }

        return selection;// Return the valid selection by reference
    }

}

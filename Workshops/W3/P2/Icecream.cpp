/*****************************************************************************
                  Workshop - #3 (Part - 2)>
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
#include "Icecream.h"
#include <iomanip>
#include <cstring>
#include <cstdlib>

namespace seneca {
    // Default constructor: Initializes all 
    // member variables to their default values.
    Icecream::Icecream() : flavor(nullptr), scoops(0), 
        vanillaWafer(false), price(0.0) {
        setFlavor(""); // Initialize flavor with an empty string
    }

    Icecream::~Icecream() {
        delete[] flavor; // Properly deallocate memory
    }
    // Copy constructor: Creates a new Icecream object
    //  as a copy of another Icecream object.
    // Initializes scoops, vanillaWafer, and price directly 
    // from the other object.
    // The flavor string is deep copied using setFlavor to 
    // ensure independent memory management.
    Icecream::Icecream(const Icecream& other)
        : scoops(other.scoops), vanillaWafer(other.vanillaWafer), 
        price(other.price) {
        setFlavor(other.flavor);
    }
// Copy assignment operator: Assigns the state of 
// another Icecream object to this object.
// Checks for self-assignment to avoid unnecessary work and potential issues.
// Upon confirming the object is not being assigned to itself, it copies all properties
// from the other object, including making a deep copy of the flavor string.
    Icecream& Icecream::operator=(const Icecream& other) {
        if (this != &other) {
            setFlavor(other.flavor);
            scoops = other.scoops;
            vanillaWafer = other.vanillaWafer;
            price = other.price;
        }
        return *this;// Return a reference to this object
    }
    // setFlavor: Manages the dynamic memory for the flavor string.
    void Icecream::setFlavor(const char* name) {
        // Deallocate existing flavor
        delete[] flavor;
        // Allocate new memory for the new flavor name and copy it
        flavor = new char[std::strlen(name) + 1];
        std::strcpy(flavor, name);
    }
 // getFlavorName: Maps an integer choice to a specific flavor name.
// This function is used to translate user input into 
// a meaningful flavor string.
    const char* Icecream::getFlavorName(int choice) const {
        switch (choice) {
        case 1: return "Chocolate";
        case 2: return "Strawberry";
        case 3: return "Mango";
        case 4: return "Tutti fruit";
        case 5: return "Almond crunch";
        default: return "Invalid";
        }
    }
    // getOrder prompts the user to customize their 
    // ice cream order by selecting a flavor,
    // the number of scoops, and whether they want a vanilla wafer cone. 
    // It ensures that all
// inputs are valid and calculates the total price based on the selections.
    void Icecream::getOrder() {
        char inputBuffer[256];
        bool validInput = false; // Flag to control loop exit

        // Select Flavor
        std::cout << "Select flavour:\n----------------\n"
            << "1: Chocolate\n2: Strawberry\n3: Mango\n4: Tutti fruit\n5: Almond crunch\n----------------\n> ";
        int flavorChoice = 0;
        while (!validInput) {
            std::cin.getline(inputBuffer, 256);
            flavorChoice = atoi(inputBuffer); // Attempt to convert to integer

            if (flavorChoice >= 1 && flavorChoice <= 5) {
                validInput = true; // Valid choice, exit loop
            }
            // Check if the input is non-numeric and prompt for a retry.
            else if (inputBuffer[0] != '\0' && !isdigit(inputBuffer[0])) {
                std::cout << "Invalid entry, retry\n> ";
            }
            else {
                std::cout << "Invlid value(1<=val<=5)\n> ";
            }
        }
        // Update the flavor of the ice cream based on the user's choice
        const char* flavorName = getFlavorName(flavorChoice);
        // Set the flavor using the chosen option.
        setFlavor(flavorName);

        // Number of Scoops
        std::cout << "Number of Scoops (max 3)\n> ";
        validInput = false; // Reset flag for the next input
        while (!validInput) {
            std::cin.getline(inputBuffer, 256);
            scoops = atoi(inputBuffer);

            if (scoops >= 1 && scoops <= 3) {
                validInput = true; // Valid number of scoops, exit loop
            }
            // Check if the input is non-numeric and prompt for a retry.
            else if (inputBuffer[0] != '\0' && !isdigit(inputBuffer[0])) {
                std::cout << "Invalid entry, retry\n> ";
            }
            else {
                std::cout << "Invlid value(1<=val<=3)\n> ";
            }
        }

        // Vanilla Wafer Cone
        std::cout << "Vanilla wafer cone?\n(Y)es/(N)o > ";
        validInput = false; // Reset flag for the next input
        while (!validInput) {
            std::cin.getline(inputBuffer, 256);
            if ((inputBuffer[0] == 'Y' || inputBuffer[0] == 'y' 
                || inputBuffer[0] == 'N' || 
                inputBuffer[0] == 'n') && (inputBuffer[1] == '\0')) {
                vanillaWafer = (inputBuffer[0] == 'Y' || 
                    inputBuffer[0] == 'y');
                validInput = true; // Valid input, exit loop
            }
            else {
                std::cout << "Only Y or N are acceptable:\n> ";
            }
        }

        // Price calculation
        price = scoops * 5.0; // Base price per scoop
        if (strcmp(flavor, "Chocolate") == 0) {
            price += scoops; // Chocolate flavor costs $1 extra per scoop
        }
        if (vanillaWafer) {
            price += 5.0; // Vanilla wafer cone costs $5 extra
        }
    }

    // Captures an order from user input
    double Icecream::getPrice() const {
        return price; // Return the price of the ice cream order
    }
    // Prints the order details
    void Icecream::printOrder() const {
        std::cout << "Order details:                Price\n"
            << "-----------------------------------\n";

        // Number of scoops
        std::cout << std::left << "Number of scoops, " << scoops << " total: " << std::right << std::setw(8);
        std::cout << std::fixed << std::setprecision(2) << scoops * 5.0 << "\n";

        // Chocolate flavour or other flavours
        if (strcmp(flavor, "Chocolate") == 0) {
            std::cout << std::left << "Chocolate flavour: " << std::setw(20); // Adjusted for the text length
            std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(2) << scoops * 1.00 << "\n";
        }
        else {
            std::cout << std::left << flavor << " flavour" << std::endl;
        }

        // Vanilla Wafer
        std::cout << "Vanilla Wafer: ";
        std::cout.width(35 - std::strlen("Vanilla Wafer: "));
        std::cout.setf(std::ios::right);
        std::cout << (vanillaWafer ? "5.00" : "0.00") << "\n";
        std::cout.unsetf(std::ios::right);

        // Total Price
        std::cout << "Price: ";
        std::cout.width(35 - std::strlen("Price: "));
        std::cout.setf(std::ios::right);
        std::cout << std::fixed << std::setprecision(2) << price << "\n";
        std::cout.unsetf(std::ios::right);
    }
} // namespace seneca

#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include "Time.h"
#include <iomanip>

namespace seneca {

    Patient::Patient(int ticketNumber) : name(nullptr), ohip(0), ticket(ticketNumber) {}

    Patient::Patient(const Patient& other) : name(nullptr), ohip(0), ticket(other.ticket) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        ohip = other.ohip;
    }

    Patient& Patient::operator=(const Patient& other) {
        if (this != &other) {
            char* newName = nullptr;
            if (other.name) {
                newName = new char[strlen(other.name) + 1];
                strcpy(newName, other.name);
            }
            // Now delete the old name and assign the new one
            delete[] name;
            name = newName; // newName is nullptr if other.name was nullptr
            ohip = other.ohip;
            ticket = other.ticket;
        }
        return *this;
    }

    Patient::~Patient() {
        delete[] name;
    }

    bool Patient::operator==(char ch) const {
        return type() == ch;
    }

    bool Patient::operator==(const Patient& other) const {
        return type() == other.type();
    }

    void Patient::setArrivalTime() {
        ticket.resetTime();
    }

    Time Patient::time() const {
        return ticket.time(); // Return the Time object stored in ticket
    }

    int Patient::number() const {
        return ticket.number();
    }

    Patient::operator bool() const {
        return name != nullptr;
    }

    Patient::operator const char* () const {
        return name;
    }

    std::ostream& Patient::write(std::ostream& ostr) const {
        if (!name) {
            ostr << "Invalid Patient Record";
        }
        else if (&ostr == &std::cout) {
            ostr << "Ticket No: " << ticket.number() << ", Issued at: " << ticket.time() << "\n"
                << name << ", OHIP: " << ohip << std::endl;
        }
        else if (&ostr == &std::clog) {
            Time t(ticket.time()); // Create a Time object from the minutes
            size_t nameLength = strlen(name);
            size_t dotLength = 53 - nameLength; // Calculate the number of dots needed for alignment
            std::string dots(dotLength, '.'); // Create a string of dots
            ostr << std::setw(3) << std::left << name << dots << ohip << std::setfill(' ') << std::setw(5) << std::right << ticket.number() << " " << t;
        }
        else {
            ostr << type() << "," << name << "," << ohip << "," << ticket.number() << "," << ticket.time();
        }
        return ostr;
    }


    std::istream& Patient::read(std::istream& istr) {
        char temp[51];
        if (&istr == &std::cin) {
            std::cout << "Name: ";
            istr.get(temp, 51);
            istr.ignore(10000, '\n');
        }
        else {
            istr.get(temp, 51, ',');
            istr.ignore(10000, ',');
        }

        // Before allocating new memory, delete any existing memory to prevent leaks
        delete[] name;
        name = new char[strlen(temp) + 1];
        strcpy(name, temp);

        if (&istr == &std::cin) {
            while (true) {
                std::cout << "OHIP: ";
                if (!(istr >> ohip)) {
                    std::cout << "Bad integer value, try again: ";
                    istr.clear();
                    istr.ignore(10000, '\n');
                }
                else if (ohip < 100000000 || ohip > 999999999) {
                    std::cout << "Invalid value entered, retry [100000000 <= value <= 999999999]: ";
                }
                else {
                    break; // Exit loop if a valid value is entered
                }
            }
            istr.ignore(10000, '\n');
        }
        else {
            istr >> ohip;
            istr.ignore(10000, ',');
            istr >> ticket;
        }

        return istr;
    }

    // Remainder of Patient class implementation...

} // namespace seneca

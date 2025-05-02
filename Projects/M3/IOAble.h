/*****************************************************************************
 Citation and Sources:
                  Milestone 3
                  File: IOAble.h
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: March 24 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca {
    // Abstract base class for objects that can be input and output
    class IOAble {
    public:
        // Pure virtual function for outputting object data
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        // Pure virtual function for reading object data
        virtual std::istream& read(std::istream& istr) = 0;
        // Virtual destructor to ensure proper destruction of derived objects
        virtual ~IOAble() {}
    };

    // Operator overloads for IOAble interface
    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
    std::istream& operator>>(std::istream& istr, IOAble& obj);
}

#endif // SENECA_IOABLE_H

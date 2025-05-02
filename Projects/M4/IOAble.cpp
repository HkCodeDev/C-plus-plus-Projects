/*****************************************************************************
 Citation and Sources:
                  Milestone 4
                  File: IOAble.cpp
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
 Date: March 28 2024
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#include "IOAble.h"
namespace seneca {
    // Class definition for Box inheriting from IOAble
    class Box : public seneca::IOAble {
        int m_height, m_width;
    public:
        // Constructor with default arguments
        Box(int height = 0, int width = 0);
        // Overridden write function to output Box properties
        virtual std::ostream& write(std::ostream& ostr) const override;
        // Overridden read function to input Box properties
        virtual std::istream& read(std::istream& istr) override;
        // Destructor for Box
        virtual ~Box();
    };
    // Constructor definition for Box
    Box::Box(int height, int width) : m_height(height), m_width(width) {}
    // Overridden write function definition for Box
    std::ostream& Box::write(std::ostream& ostr) const {
        // Custom implementation for Box
        return ostr << "Box [Height: " << m_height << ", Width: " << m_width << "]";
    }
    // Overridden read function definition for Box
    std::istream& Box::read(std::istream& istr) {
        // Custom implementation for Box
        return istr >> m_height >> m_width;
    }
    // Destructor definition for Box
    Box::~Box() {}

    // Define the operator overloads within the global namespace
    std::ostream& operator<<(std::ostream& ostr, const seneca::IOAble& obj) {
        return obj.write(ostr);
    }
    // Overloaded >> operator to input IOAble object using read function
    std::istream& operator>>(std::istream& istr, seneca::IOAble& obj) {
        return obj.read(istr);
    }
}

#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca {
    class IOAble {
    public:
        virtual std::ostream& write(std::ostream& ostr) const = 0; // For ostream outputs
        virtual std::istream& read(std::istream& istr) = 0; // For istream inputs
        virtual ~IOAble() {} // Virtual destructor
    };

    // Operator overloads for IOAble interface
    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
    std::istream& operator>>(std::istream& istr, IOAble& obj);
}

#endif // SENECA_IOABLE_H

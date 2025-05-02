#ifndef SENECA_TIME_H
#define SENECA_TIME_H

#include <iostream>

namespace seneca {

    class Time {
        unsigned int minutes;

    public:
        Time(unsigned int min = 0u);
        Time& reset();
        Time& operator-=(const Time& D);
        Time operator-(const Time& T) const;
        Time& operator*=(int val);
        operator unsigned int() const;
        friend std::ostream& operator<<(std::ostream& out, const Time& T);
        friend std::istream& operator>>(std::istream& in, Time& T);
    };
}

#endif // SENECA_TIME_H

#include "Time.h"
#include "Utils.h"
#include <iomanip>

namespace seneca {

    Time::Time(unsigned int min) : minutes(min) {}

    Time& Time::reset() {
        minutes = U.getTime();
        return *this;
    }

    Time& Time::operator-=(const Time& D) {
        if (minutes < D.minutes) {
            minutes += 24 * 60;
        }
        minutes -= D.minutes;
        return *this;
    }

    Time Time::operator-(const Time& T) const {
        Time temp(*this);
        temp -= T;
        return temp;
    }

    Time& Time::operator*=(int val) {
        minutes *= val;
        return *this;
    }

    Time::operator unsigned int() const {
        return minutes;
    }

    std::ostream& operator<<(std::ostream& out, const Time& T) {
        unsigned hours = T.minutes / 60;
        unsigned mins = T.minutes % 60;
        out << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << mins;
        return out;

    }

    std::istream& operator>>(std::istream& in, Time& T) {
        unsigned hours, mins;
        char colon;

        if (!(in >> hours)) {
            in.clear(std::ios::failbit);
        }
        else {
            if (in.peek() != ':') {
                in.setstate(std::ios::failbit);
            }
            else {

                in >> colon >> mins;
                if (in.fail()) {
                    in.clear(std::ios::failbit);
                }
                else {
                    T.minutes = hours * 60 + mins;
                }
            }
        }

        return in;
    }

}

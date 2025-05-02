#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <cstring>
#include "Ticket.h"
#include "IOAble.h"
#include "Time.h"

namespace seneca {

    class Patient : public IOAble {
        char* name;
        int ohip;
        Ticket ticket;

    public:
        Patient(int ticketNumber = 0);
        Patient(const Patient& other);
        Patient& operator=(const Patient& other);
        virtual ~Patient();
        virtual char type() const = 0;
        // Pure virtual function

        bool operator==(char ch) const;
        bool operator==(const Patient& other) const;

        void setArrivalTime();
        Time time() const;
        int number() const;

        operator bool() const;
        operator const char* () const;

        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;
    };

} // namespace seneca

#endif // PATIENT_H

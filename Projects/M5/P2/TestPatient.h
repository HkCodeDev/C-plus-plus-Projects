#ifndef TESTPATIENT_H
#define TESTPATIENT_H

#include "Patient.h"
#include "Time.h"
namespace seneca {

    class TestPatient : public Patient {
    public:
        TestPatient();
        virtual char type() const override;
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;
    private:
        static int nextTestTicket;
    };

}

#endif // TESTPATIENT_H

#ifndef TRIAGEPATIENT_H
#define TRIAGEPATIENT_H

#include "Patient.h"
#include "Time.h"

namespace seneca {

    class TriagePatient : public Patient {
    public:
        TriagePatient();
        TriagePatient(const TriagePatient& other);
        TriagePatient& operator=(const TriagePatient& other);
        virtual ~TriagePatient();
        virtual char type() const override;
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;

    private:
        static int nextTriageTicket;
        char* symptoms;
    };

}

#endif // TRIAGEPATIENT_H

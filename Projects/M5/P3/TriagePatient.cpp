#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include "Time.h"
#include <cstring> // for strcpy, strlen

namespace seneca {

    int TriagePatient::nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket++), symptoms(nullptr) {}

    TriagePatient::TriagePatient(const TriagePatient& other) : Patient(other), symptoms(nullptr) {
        if (other.symptoms) {
            symptoms = new char[strlen(other.symptoms) + 1];
            strcpy(symptoms, other.symptoms);
        }
    }

    TriagePatient& TriagePatient::operator=(const TriagePatient& other) {
        if (this != &other) {
            Patient::operator=(other);
            delete[] symptoms;
            symptoms = nullptr;
            if (other.symptoms) {
                symptoms = new char[strlen(other.symptoms) + 1];
                strcpy(symptoms, other.symptoms);
            }
        }
        return *this;
    }

    TriagePatient::~TriagePatient() {
        delete[] symptoms;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::ostream& TriagePatient::write(std::ostream& ostr) const {
        if (&ostr == &std::cout) {
            ostr << "TRIAGE" << std::endl;
            Patient::write(ostr); // This outputs the base class information for std::cout.
            if (symptoms) {
                ostr << "Symptoms: " << symptoms << std::endl;
            }
        }
        else if (&ostr == &std::clog) {
            Patient::write(ostr); // Exclude symptoms specifically for std::clog to avoid them in linear output.
        }
        else {
            // This handles the CSV output specifically.
            Patient::write(ostr); // First output the base class information.
            if (symptoms) {
                ostr << "," << symptoms; // Then append symptoms correctly formatted for CSV.
            }
        }
        return ostr;
    }



    std::istream& TriagePatient::read(std::istream& istr) {
        Patient::read(istr);
        if (symptoms)
            delete[] symptoms;
        symptoms = nullptr;
        if (&istr != &std::cin) {
            char temp[512];
            istr.ignore(); // ignore the comma
            istr.get(temp, 512, '\n');
            istr.ignore(512, '\n');
            symptoms = new char[strlen(temp) + 1];
            strcpy(symptoms, temp);
            nextTriageTicket = number() + 1;
        }
        else {
            std::cout << "Symptoms: ";
            char temp[512];
            istr.get(temp, 512, '\n');
            istr.ignore(512, '\n');
            symptoms = new char[strlen(temp) + 1];
            strcpy(symptoms, temp);
        }
        return istr;
    }

}

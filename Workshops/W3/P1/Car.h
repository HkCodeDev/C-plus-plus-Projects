/*****************************************************************************
                  Workshop - #3 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef CAR_H
#define CAR_H

namespace seneca {
    class Car {
    private:
        char m_licencePlate[9]; // Max 8 characters + null terminator
        char* m_makeModel;
        char* m_serviceDesc;
        double m_cost;

    public:
        Car();
        ~Car();
    //Member function to check if the object is in a safe recognizable empty state.
    bool isEmpty() const;
    //Member function sets the object a safe recognizable empty state.
    void setEmpty();
    //Member function to deallocate dynamically allocated memory for 
    // "make and model" and "service description" member variables.
    void deallocateMemory();
    //Member function to Set car information and service details 
    void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
    //This function displays the car in the intended format
    void display() const;
    };
}

#endif // CAR_H

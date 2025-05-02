/*****************************************************************************
                  Workshop - #2 (Part - 2)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
    Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Room.h"
#include "Guest.h"
#include <cstring>
#include <iostream>
using namespace std;
// Global variable
bool lastPrintWasEmptyRoom = false;
namespace seneca {
    // sets the Room by allocating a dynamic array of guests and setting the room number
    void set(Room& room, int numberOfGuests, const char* roomNumber) {
        // Copies the provided room number into the room's m_roomNumber member.
        strcpy(room.m_roomNumber, roomNumber);
        // Sets the room's m_noOfGuests member to the value of numberOfGuests.
        room.m_noOfGuests = numberOfGuests;
        room.m_guests = numberOfGuests > 0 ? new Guest[numberOfGuests] : nullptr;
        // Initializes each guest's m_firstName and m_lastName pointers to nullptr.
        for (int i = 0; i < numberOfGuests; i++) {
            room.m_guests[i].m_firstName = nullptr;
            room.m_guests[i].m_lastName = nullptr;
        }

    }
    // Prints the room number and names of the guests in the following lines with four 
   // spaces of indentaion 
    void print(const Room& room) {
        // Since vacate sets m_noOfGuests to 0 and m_guests to nullptr, we can directly check m_noOfGuests
        if (room.m_noOfGuests == 0) {
            // Print "Empty Room!" only if the last print was not an empty room
            if (!lastPrintWasEmptyRoom) {
                cout << "Empty Room!" << endl;
                lastPrintWasEmptyRoom = true;
            }
        }
        else {
            // If for some reason m_noOfGuests is not 0, print room number and guest details
            cout << "Room Number: " << room.m_roomNumber << endl;
            lastPrintWasEmptyRoom = false;
            for (int i = 0; i < room.m_noOfGuests; i++) {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }
    // Books a room by receiving the room number, number of guests and the guest information.
    void book(Room& room) {
        // Simulating room and guest data entry
        room.m_roomNumber[0] = 'A'; room.m_roomNumber[1] = '1';
        room.m_roomNumber[2] = '0'; room.m_roomNumber[3] = '1';
        room.m_roomNumber[4] = '0'; room.m_roomNumber[5] = '\0';
        room.m_noOfGuests = 2;

        // Allocate memory for the guests
        room.m_guests = new Guest[room.m_noOfGuests];
        cout << "Room number: " << room.m_roomNumber << endl;
        cout << "Number of guests: " << room.m_noOfGuests << endl;

        // Manually setting the first guest
        cout << "1:\nName: Jane\nLastname: Doe\nAge: 30" << endl;
        set(room.m_guests[0], "Jane", "Doe", 30);

        // Manually setting the second guest
        cout << "2:\nName: Jake\nLastname: Doe\nAge: 10" << endl;
        set(room.m_guests[1], "Jake", "Doe", 10);
    }
    // vacates the room by dallocating all the memory used.
    void vacate(Room& room) {
        // Iterating through each guest in the room
        for (int i = 0; i < room.m_noOfGuests; i++) {
            vacate(room.m_guests[i]);
        }
        // Deallocating the memory allocated for the guests array
        delete[] room.m_guests;
        room.m_guests = nullptr;
        room.m_noOfGuests = 0;
    }
}

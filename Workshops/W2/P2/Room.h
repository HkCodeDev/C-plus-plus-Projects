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
#ifndef ROOM_H
#define ROOM_H

#include "Guest.h"

namespace seneca {

	struct Room {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};
	// sets the Room by allocating a dynamic array of guests and setting the room number 
	void set(Room& room, int numberOfGuests, const char* roomNumber);
	// Prints the room number and names of the guests in the following lines with four 
   // spaces of indentaion 
	void print(const Room& room);
	// Books a room by receiving the room number, number of guests and the guest information.
	void book(Room& room);
	// vacates the room by dallocating all the memory used.
	void vacate(Room& room);

} // namespace seneca

#endif // ROOM_H

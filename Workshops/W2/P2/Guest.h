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
#ifndef GUEST_H
#define GUEST_H

namespace seneca {

	struct Guest {
		char* m_firstName;
		char* m_lastName;
		bool m_adult;
	};
	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest& guest, const char* first, const char* last, int age);
	// Prints the guest name
	void print(const Guest& guest);
	// books the guest information from the console
	void book(Guest& guest);
	// vacates the guest by dallocating its memory.
	void vacate(Guest& guest);

} // namespace seneca

#endif // GUEST_H

/*****************************************************************************
				  Workshop - #6 (Part - 1)>
Full Name : Hoda Karimi
Student ID# : 138611223
 Email : hkarimi9@myseneca.ca
 Section : NII
	Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************/
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca {
	// Maximum possible size for all the fields of the Email record
	const int BUFFER_SIZE = 1024; 
	// Forward declaration of classes
	class EmailFile;
	class Email
	{
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{ '\0' };
		// Private constructor
		Email() {};
		// Private copy assignment operator
		Email& operator=(const Email&);
		// Private member functions
		bool load(std::ifstream& in);
		~Email();
		Email(const Email&); // Copy constructor declaration

		// Make EmailFile class a friend
		friend class EmailFile;
	};


	class EmailFile
	{
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 };
		// Private member functions
		void setFilename(const char* filename);// Sets the filename
		void setEmpty();// Resets the EmailFile object to an empty state
		// Determines the number of email records in the file
		bool setNoOfEmails();
		void loadEmails();// Loads email records from the file
		// Copies email records from another EmailFile object
		void copyEmails(const EmailFile& other); 

	public:
		// Default constructor
		EmailFile();
		// Parameterized constructor that takes a filename
		EmailFile(const char* filename);
		// Copy constructor
		EmailFile(const EmailFile& other);
		// Assignment operator overload
		EmailFile& operator=(const EmailFile& other);
		// Destructor
		~EmailFile();
		// Logical NOT operator overload
	// Checks if the EmailFile object is not initialized.
		bool operator!() const;
		// Function to save email records to a file
		bool saveToFile(const char* filename) const;
		// Function to concatenate email records from another EmailFile object
		void fileCat(const EmailFile& other);
		// Function to concatenate email records from
		//  another EmailFile object and save to a file
		void fileCat(const EmailFile& other, const char* filename);
		// Function to display the contents of 
		// the EmailFile object to an output stream
		std::ostream& view(std::ostream& ostr) const;
	};
	// Overloaded stream insertion operator to 
	// output the contents of an EmailFile object
	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}
#endif // !SENECA_EMAILFILE_H
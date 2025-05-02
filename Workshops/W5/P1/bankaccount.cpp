/*****************************************************************************
				  Workshop - #5 (Part - 1)>
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
#include "bankaccount.h"
#include <iostream>
#include<iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount& bankAccount::operator++() {
		if (this->isOpen() && m_funds > 0) {
			double interest = m_funds * (m_checking ? 0.005 : 0.025);
			m_funds += interest;
		}
		return *this;
	}
	// Decreases the account funds by the monthly fees
	//  based on account type (checking or savings)
	bankAccount& bankAccount::operator--() {
		if (this->isOpen()) {
			double fees = m_monthlyTransactions * (m_checking ? 1.25 : 3.5);
			m_funds -= fees;
		}
		return *this;
	}
	// Adds a specified amount to the account's 
	// funds and increments transaction count. Prints a deposit message.
	bool bankAccount::operator+=(double amount) {
		// Check if account is open and amount is valid
		if (!this->isOpen() || amount < 0) return false; 
		m_funds += amount;
		m_monthlyTransactions++;
		cout << "Deposit $" << std::fixed << std::setprecision(2) << amount << 
			" for " << m_userName << endl;
		return true;
	}
	// Subtracts a specified amount from the account's funds and 
	// increments transaction count. Prints a withdrawal message.
	bool bankAccount::operator-=(double amount) {
		m_funds -= amount; // Subtract the withdrawal amount from the funds
		m_monthlyTransactions++; // Increment transaction count
		cout << "Withdraw $" << std::fixed << std::setprecision(2) <<
			amount << " for " << m_userName << endl;
		return true;
	}
	// Compares this account to another account for equality. 
	// Accounts are considered equal if they have the same user name, funds (within a small tolerance), and account type.
    bool bankAccount::operator==(const bankAccount& other) const {
		return std::strcmp(m_userName, other.m_userName) == 0 &&
			((m_funds > other.m_funds) ? (m_funds - other.m_funds) : 
				(other.m_funds - m_funds)) < 0.001 &&
			m_checking == other.m_checking;
	}

	// Determines if the account's funds are greater than a specified value.
	bool bankAccount::operator>(double value) const {
		return this->isOpen() && m_funds > value;
	}
	// Determines if the account's 
	// funds are not greater than a specified value.
	bool bankAccount::operator<=(double value) const {
		return !(*this > value);
	}
	// Transfers all funds from one account to another if both accounts 
	// are open and the source account has funds.
	bool bankAccount::transfer(bankAccount& fromAccount) {
		if (!this->isOpen() || !fromAccount.isOpen() || 
			fromAccount.m_funds <= 0) return false;
		*this += fromAccount.m_funds;
		fromAccount -= fromAccount.m_funds;
		return true;
	}
	// Prints account details, dynamically adjusting the dashes
	//  based on the username length to maintain alignment.
	void bankAccount::display() const {
		// Adjust this based on the longest expected username
		const int baseLengthForDashes =16; 

		if (!this->isOpen()) {
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
		else {
			// Calculate needed dashes
			int dashLength = baseLengthForDashes - strlen(m_userName); 
			// Ensuring dashLength is never negative

			if (dashLength < 0) dashLength = 0; 

			cout << "Display Account -> User:" << string(dashLength, '-') << m_userName << " |"
				<< left << setw(10) << (m_checking ? " Checking" : "  Savings")
				<< "|" << std::right << std::setw(7) << " Balance: $" <<
				right << setw(8) << fixed << setprecision(2) << m_funds
				<< " | Transactions:" << setfill('0') << setw(3) <<
				m_monthlyTransactions << setfill(' ') << endl;
		}
	}

	// Defines a transfer operation from one bankAccount object to another.
	bool bankAccount::operator<<(bankAccount& source) {
		double transferAmount = source.m_funds;
		if (!this->isOpen() || !source.isOpen() || transferAmount <= 0) {
			return false;
		}

		// Print the "Transfer" message manually before executing operations.
		std::cout << "Transfer $" << std::fixed << std::setprecision(2) << transferAmount
			<< " from " << source.m_userName << " to " << m_userName << std::endl;

		// Perform the operations silently if possible, 
		// or accept the current message sequence.
		*this += transferAmount; // This will print the deposit message.
		source -= transferAmount; // This will print the withdraw message.

		return true;
	}

    // ADD: Global Helper Functions
	// Global function to compare a double value against
	//  the funds of a bankAccount object, determining if the value is greater.
	bool operator>(double lhs, const seneca::bankAccount& rhs) {
		return lhs > (double)rhs;
	}
	// Global function to compare a double 
	// value against the funds of a bankAccount object, 
	// determining if the value is not greater.
	bool operator<=(double lhs, const seneca::bankAccount& rhs) {
		return !(lhs > rhs);
	}

}
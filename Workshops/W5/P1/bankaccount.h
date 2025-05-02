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
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
    const int	 ACCT_MAXLEN_USER = 16;		// Max Length of user name
    const double TRANSACTION_FEE_CHECKING = 1.25;
    const double TRANSACTION_FEE_SAVINGS = 3.50;
    const double INTEREST_RATE_CHECKING = 0.005; // 0.5%
    const double INTEREST_RATE_SAVINGS = 0.025; // 2.5%

    // Class Definition
    class bankAccount
    {

    private:
        // Data Members
        char	m_userName[ACCT_MAXLEN_USER];
        double	m_funds;
        bool	m_checking;
        int		m_monthlyTransactions;

        bool isOpen() const;
    public:
        bankAccount(const char* name = nullptr, bool checking = false);
        bool setup(const char* name, bool checking);

        // ADD: Type Conversion, Unary, Binary Operators & Additional Methods
        // Conversion operator to bool, returns true if the account is open.
        operator bool() const { return isOpen(); }
        // Conversion operator to double, returns the account's fund balance.
        operator double() const { return m_funds; }
        // Prefix increment operator, applies interest to the account's funds.
        bankAccount& operator++();
        // Prefix decrement operator,
        //  applies transaction fees to the account's funds.
        bankAccount& operator--();
        // Overloads the '<<' operator for transferring
        //  funds from one account to another.
        bool operator<<(bankAccount& fromAccount);
        // Adds a specified amount to the account's funds,
        //  incrementing the transaction count.
        bool operator+=(double amount);
        // Subtracts a specified amount 
        // from the account's funds, incrementing the transaction count.
        bool operator-=(double amount);
        // Checks equality between two bank accounts based on user name,
        //  funds (with a tolerance for floating-point comparison),
        //  and account type.
        bool operator==(const bankAccount& other) const;
        // Checks if the account's funds are greater than a specified value.
        bool operator>(double value) const;
        // Checks if the account's funds are 
        // less than or equal to a specified value.
        bool operator<=(double value) const;
        // Initiates a transfer of all 
        // funds from the specified account to this account.
        bool transfer(bankAccount& fromAccount);
        // Displays account information in a formatted manner.
        void display() const;


    };

    // ADD: Global helpers
    // Global helper: Checks if a double value
    //  is greater than the funds in a bankAccount.
    bool operator>(double lhs, const seneca::bankAccount& rhs);
     // Global helper: Checks if a double value 
    // is less than or equal to the funds in a bankAccount.
    bool operator<=(double lhs, const seneca::bankAccount& rhs);
}
#endif
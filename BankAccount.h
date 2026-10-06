#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string> 
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
       
public: 
    // Constructors
    BankAccount();
    BankAccount(string accNum, string holderName, double bal);

    // the Rule of Three
    BankAccount(const BankAccount& other);  // copy constructor
    BankAccount& operator=(const BankAccount& other);  // copy assignment operator
    ~BankAccount(); // destructor

    // Getters
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;

    // Setter
    void setAccountHolderName(string holderName);

    // Transaction methods
    void deposit(double amount);
    bool withdraw(double amount);

    // Arithmetic operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparison operators
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static Utility Functions
    static void printAccount(const BankAccount& account); 
    static BankAccount createAccountFromInput();
};


#endif // BANKACCOUNT_H

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string> 
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
       
public: 
    BankAccount();
    BankAccount(string accNum, string holderName, double bal);
    string getAccountNumber() const;
    string getAccountHolderName() const;
    double getBalance() const;
    void setAccountHolderName(string holderName);
    void deposit(double amount);
    bool withdraw(double amount);
   
};


#endif // BANKACCOUNT_H

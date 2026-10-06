#include "BankAccount.h"

BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
}
BankAccount::BankAccount(string accNum, string holderName, double bal) {
    accountNumber = accNum;
    accountHolderName = holderName;
    balance = bal;
}
string BankAccount::getAccountNumber() const {
    return accountNumber; 
}
string BankAccount:: getAccountHolderName() const {
    return accountHolderName;
}
double BankAccount::getBalance() const{
    return balance; 
}
void BankAccount::setAccountHolderName(string holderName) {
    accountHolderName = holderName;
}
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true; 
    }
   
    return false; 
}

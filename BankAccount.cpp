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
// copy constructer 
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}
// copy assignment operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}
// destructor 
BankAccount::~BankAccount() {
    // no dynamic memory to free explicitly
}
// arithmetic operator 
BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    return *this; 
}
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount; 
    }
    return *this; 
}
// comparsion operators
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}
bool BankAccount::operator>(const BankAccount& other) const {
    return balance > other.balance;
}
// Static function 
void BankAccount::printAccount(const BankAccount& account) {
    cout << "\n Account Number: " << account.accountNumber << endl;
    cout << " Account Holder Name: " << account.accountHolderName << endl;
    cout << " Balance: $" << account.balance << endl;
}
BankAccount BankAccount::createAccountFromInput() {
    string accNum;
    string holderName;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin >> holderName;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    return BankAccount(accNum, holderName, bal);
}

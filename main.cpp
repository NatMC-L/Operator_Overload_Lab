#include <iostream>
#include <limits>
#include <vector>
#include "BankAccount.h"
using namespace std;

int findAccount(const vector<BankAccount>& accounts, 
    const string& accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    vector<BankAccount> accounts; 
    int choice;
    do {
        cout << "\n ====== Managemtn system of Bank ======\n";
        cout << "1. Create Account\n";
        cout << "2. View Accounts\n";
        cout << "3. Deposit the Money\n";
        cout << "4. Withdraw the Money\n";
        cout << "5. Update Account Holder Name\n";
        cout << "6. Compare Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cout << "Inalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        cin.ignore();
        switch (choice) {
            case 1: {
                accounts.push_back(BankAccount::createAccountFromInput());
                cout << "Account created suessfuly.\n";
                break;
            }
            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts found.\n";
                }
                else {
                    for (const auto& account : accounts) {
                        BankAccount::printAccount(account);
                    }
                }
                break;
            }
            case 3: {
                string accNum;
                double amount;
                
                cout <<"Enter Account Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);
                if(index == -1) {
                    cout << "Account not found.\n";
                    break; 
                }
                cout << "Enter Deposit Amount: ";
                while (!(cin >> amount)|| amount <=0) {
                    cout << "Invalid amount.Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();
                accounts[index] += amount; 
                cout << "Deposit sucessful.\n";
                break;
            }
            case 4: {
                string accNum;
                double amount;
                
                cout << "Enter Account Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);
                if (index == -1) {
                    cout << "Account not found.\n";
                    break;
                }

                cout << "Enter Withdrawal Amount: ";
                while (!(cin>> amount) || amount <= 0) {
                    cout << "Invaild amount. Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }

                cin.ignore();
                double oldBalance = accounts[index].getBalance();
                accounts[index] -= amount;
                if (accounts[index].getBalance() < oldBalance) {
                    cout << "Withdrawal successful.\n";
                }
                else {
                    cout << "Insufficient funds.\n";
                }
                break;
            }

            case 5: {
                string accNum;
                string newName;

                cout << "Enter Accout Number: ";
                getline(cin, accNum);

                int index = findAccount(accounts, accNum);

                if (index == -1) {
                    cout << "Acount not found.\n";
                    break;
                }
                cout <<"Enter New Account Holder Name: ";
                getline(cin, newName);

                accounts[index].setAccountHolderName(newName);
                cout << "Name updated successfully.\n";
                break;
            }

            case 6: {
                if (accounts.size() < 2) {
                    cout << "Need at least two account.\n";
                    break;
                }
                if (accounts[0] == accounts[1]) {
                    cout << "The accounts have the same accoount number.\n";
                }
                else {
                    cout << "The accounts have different account numbers.\n";
                }

                if (accounts[0] > accounts[1]) {
                    cout << "Account  1 has a greater balance.\n";
                }
                else if (accounts[0] < accounts[1]) {
                    cout << "Account 2 has a greater balance.\n";
                }
                else {
                    cout << "Both accounts have the same balance.\n";
                }
                break;
            }

            case 7: 
                cout << "Have a Good Day!\n";
                break;
            default:
                cout << "Invaild menu choice.\n";    
        }

    } while (choice != 7);

    return 0;
}

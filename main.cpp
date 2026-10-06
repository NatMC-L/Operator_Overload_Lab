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
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        while (!(cin >> choice)) {
            cout << "Inalid input. Enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        cin.ignore();
        switch (choice) {
            case 1: {
                string accNum;
                string holderName;
                double Balance;

                cout << "Enter Account Number: ";
                getline(cin, accNum);

                cout << "Enter Account Holer Name: ";
                getline(cin, holderName);

                cout << "Enter the Balance: ";

                while (!(cin >> Balance) || Balance < 0) {
                    cout << "Invalid amount. Try again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();
                accounts.push_back(BankAccount(accNum, holderName, Balance));
                cout << "Account created suessfuly.\n";
                break;
            }
            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts found.\n";
                }
                else {
                    for (const auto& account : accounts) {
                        cout << "\nAccount Number: " <<
                        account.getAccountNumber() << endl;
                        cout << "Account Holder: " <<
                        account.getAccountHolderName() << endl;
                        cout << "Balance: $" <<
                        account.getBalance() << endl; 
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
                accounts[index].deposit(amount);
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

                if (accounts[index].withdraw(amount)) {
                    cout << "Withdrawal successful.\n";
                }
                else {
                    cout << "Insuffiient funds.\n";
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

            case 6: 
                cout << "Have a Good Day!\n";
                break;
            default:
                cout << "Invaild menu choice.\n";
        }

    } while (choice != 6);

    return 0;
}

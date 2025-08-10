#include <iostream> 
#include <fstream>
#include <string>
#include "account.h" 
#include "User.h"
using namespace std;

int main() { 
    User user;
    if(!user.login())
    return 0;
    
    Account acc; 
    int choice;
    double amount;

    ifstream
    infile("account.txt");
    if(infile){
        int accNo;
        string name;
        double bal;
        infile>> accNo;
        infile.ignore();
        getline(infile, name);
        infile>> bal;
        acc = Account(accNo, name, bal);
        infile.close();
        cout<<"Account Loaded Succesfully\n";
    } else {
        cout<<"No Account found.Create new Account\n";
        acc.createAccount();

        ofstream
        outfile("account.txt");
        outfile<<acc.getAccountNumber()<<endl;
        outfile<<acc.getName()<<endl;
        outfile<<acc.getBalance()<<endl;
        outfile.close();
    }
    

while (true) {
    cout << "\n--- Bank Management Menu ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Show Account Details\n";
    cout << "5. Apply for Loan\n";
    cout << "6. Show Transaction History\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            acc.createAccount();
            break;
        case 2: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            acc.saveToFile();
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            acc.saveToFile();
            break;
        }
        case 4:
            acc.showAccount();
            break;
        case 5:
            acc.applyForLoan();
            acc.saveToFile();
            break;
        case 6:
            acc.showTransactions();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}

return 0;
}


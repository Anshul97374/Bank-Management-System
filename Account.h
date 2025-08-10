#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;
    double loanAmount;
    int pin;
    string accountType;
    string occupation;
    double salary;
    bool loanApplied = false;
    double interestRate;
    vector<string> transactions;

public:
    Account();
    Account(int accNo, const string& name, double balance);
 //   Account(int accNo, const string& accName, double initialBalance, int userPin,const string& type);
    void createAccount();
    void showAccount() const;
    void deposit(double);
    void withdraw(double);
    int getAccountNumber() const;
    string getName() const;
    double getBalance() const;
    void saveToFile() const;
   
    void applyForLoan();
    void showTransactions() const;
    void setAccountType(std::string type);
    std::string getAccountType() const;

    
   // void setPin(int);
   //bool validatePin(int) const;
    bool checkPIN(int enteredPIN) const;
};

#endif
 #include "account.h" 
 #include <iostream>
 #include <cmath> 
 #include <limits> 
 #include <string>
 #include <vector>
 #include <iomanip>
 #include <fstream>

 using namespace std;

Account::Account() { 
    accountNumber = 0; 
    name = "";
    balance = 0.0;
    pin = 0;
    accountType = ""; 
    occupation = ""; 
    salary = 0.0; 
    loanApplied = false; 
    loanAmount=0.0;
    interestRate=0.05;
}


void Account::createAccount() { 
    cout << "Enter Account Number : "; 
    cin >> accountNumber;
    cin.ignore();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Account Holder Name : ";
    getline(cin, name); 
    cout << "Enter Account Type (Saving/Current): ";
    cin>>accountType;
    getline(cin, accountType);
    
    cout << "Set Account PIN (4-digit): ";
    cin >> pin; cout << "Enter Initial Balance: "; 
    loanApplied=false;
    cin >> balance; cout << "Account Created Successfully!\n"; 
}

void Account::deposit(double amount) { 
    int enteredPIN;
    cout<<"Enter PIN: ";
    cin>> enteredPIN;
    if(!checkPIN(enteredPIN)){
        cout<<"Incorrect PIN\n";
        transactions.push_back("Failed Deposit Attempt(Incorrect PIN): Rs. "+to_string(amount));
        return;
    }
    balance += amount; 
    transactions.push_back("Deposited: Rs. " + to_string(amount)); 
    cout << "Deposited Successfully!\n"; 
}

void Account::withdraw(double amount) {
    int enteredPIN;
    cout<<"Enter PIN: ";
    cin>> enteredPIN;
    if(!checkPIN(enteredPIN)){
        cout<<"Incorrect PIN\n";
        transactions.push_back("Failed Withdrawal Attempt(Incorrect PIN): Rs. "+to_string(amount));
        return;
    }
     if (amount > balance) { cout << "Insufficient Balance.\n"; 
        transactions.push_back("Failed Withdrawal Attempt: Rs. " + to_string(amount));
     } else { balance -= amount; 
        transactions.push_back("Withdrawl: Rs. " + to_string(amount)); 
        cout << "Withdrawl Successfully!\n"; 
    } 
}

void Account::showAccount() const { 
    cout << "\nAccount Number: " << accountNumber << endl; 
    cout << "Account Holder: " << name << endl; cout << "Account Type: " << accountType << endl; 
    cout << "Balance: Rs. " << balance << endl; 
}

int Account::getAccountNumber() const { 
    return accountNumber;
 }

double Account::getBalance() const { 
    return balance; 
}

string Account::getName() const {
     return name; 
    }

void Account::applyForLoan() {
    if (loanApplied) {
        cout << "You have already applied for a loan.\n";
        return;
    }

    cout << "Enter Occupation: ";
    cin.ignore();
    getline(cin, occupation);

    cout << "Enter Monthly Salary: ";
    cin >> salary;

    double loanAmount;
    int tenure;

    cout << "Enter Loan Amount: ";
    cin >> loanAmount;

    
    cout << "Enter Tenure (in months): ";
    cin >> tenure;

    if (tenure <= 0) {
        cout << "Invalid tenure entered.\n";
        return;
    }

    double interestRate=0.05;
    double monthlyRate = interestRate/12;
    double  emi = (loanAmount * monthlyRate * pow(1 + monthlyRate,tenure))/(pow(1 + monthlyRate,tenure)-1);
    cout << "\nLoan Approved!\n";
    cout << "Monthly EMI: Rs." << emi << " for " << tenure << " months.\n";

    balance += loanAmount;
    loanApplied = true;

    transactions.push_back("Loan Approved: ₹" + to_string((int)loanAmount) +
                           ", EMI: ₹" + to_string((int)emi) +
                           " for " + to_string(tenure) + " months.");
}

void Account::showTransactions() const { 
    cout << "\nTransaction History:\n"; 
    for (const string& entry : transactions) { cout << "- " << entry << endl; 
    }
 }

 bool Account::checkPIN(int enteredPIN) const{
    return enteredPIN==pin;
 }
 Account::Account(int accNo,const string& name, double balance){
    accountNumber=accNo;
    this->name=name;
    this->balance=balance;
    
 }

 void Account::saveToFile() const {
    ofstream
    outfile("account.txt");
    if(outfile){
        outfile<<accountNumber<<endl;
        outfile<<name<<endl;
        outfile<<balance<<endl;
    }
 }

 void Account::setAccountType(string type){
    accountType = type;
 }
 string Account::getAccountType() const {
    return accountType;
 }

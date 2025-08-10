// src/User.cpp
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

User::User() {
    username = "";
    password = "";
}

bool User::login() {
    cout << "Login\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // For simplicity, hardcoded login
    if ((username == "admin" && password == "admin123") || 
        (username == "user" && password == "user123")) {
        cout << "Login Successful!\n";
        return true;
    } else {
        cout << "Invalid credentials.\n";
        return false;
    }
}
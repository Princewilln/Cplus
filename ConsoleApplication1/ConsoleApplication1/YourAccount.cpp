#include <iostream>
#include "YourAccount.h"

using namespace std;

// Default Constructor
//YourAccount::YourAccount() : balance(0.0f) {}
 YourAccount::YourAccount() { 
 balance = 0.0f; 
 }

// Constructor with a parameter
//YourAccount::YourAccount(float initialBalance) : balance(initialBalance) {}
YourAccount::YourAccount(float initialBalance) {
    balance = initialBalance;
}

// Function to deposit money
float YourAccount::deposit(float amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
    return balance;
}

// Function to withdraw money
float YourAccount::withdraw(float amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
    }
    return balance;
}

// Function to print the current balance
void YourAccount::printBalance()
{
    cout << "Current balance: $" << balance << endl;
}



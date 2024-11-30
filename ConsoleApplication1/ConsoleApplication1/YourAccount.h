#pragma once
#ifndef YOURACCOUNT_H
#define YOURACCOUNT_H

class YourAccount
{
public:
    YourAccount();                    // Default Constructor
    YourAccount(float initialBalance); // Constructor with a parameter
    float deposit(float amount);      // Function to deposit money
    float withdraw(float amount);     // Function to withdraw money
    void printBalance();              // Function to print the current balance

private:
    float balance; // Member variable for storing the balance
};

#endif // YOURACCOUNT_H

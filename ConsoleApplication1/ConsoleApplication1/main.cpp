#include <iostream>
#include "YourAccount.h"

using namespace std;

int main()
{
    YourAccount account; // Default constructor
    int choice;
    float amount;

    do
    {
        // Display menu
        cout << "1: Display balance\n";
        cout << "2: Deposit\n";
        cout << "3: Withdraw\n";
        cout << "4: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.printBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            account.deposit(amount);
            cout << "Deposited $" << amount << endl;
            break;
        case 3:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            if (account.withdraw(amount) >= 0)
            {
                cout << "Withdrew $" << amount << endl;
            }
            else
            {
                cout << "Insufficient funds or invalid amount" << endl;
            }
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
            break;
        }

    } while (choice != 4);

    return 0;
}

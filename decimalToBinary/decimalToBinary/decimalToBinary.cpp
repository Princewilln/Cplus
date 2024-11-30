#include <iostream>
#include "linkedStack.h"

using namespace std;

// Function to convert decimal to binary using a stack
void decimalToBinary(int decimal) {
    linkedStackType<int> stack; // Create a linked stack
    while (decimal > 0) {
        stack.push(decimal % 2); // Push the remainder onto the stack
        decimal /= 2; // Divide the decimal number by 2
    }

    // Display the binary number
    cout << "Binary representation: ";
    while (!stack.isEmptyStack()) {
        cout << stack.top(); // Print the top element of the stack
        stack.pop(); // Remove the top element
    }
    cout << endl;
}

// Move nth element to the front of the queue
void moveNthFront(int queue[], int& size, int n) {
    if (n < 1 || n > size) {
        cout << "Invalid position" << endl;
        return;
    }

    int nthElement = queue[n - 1]; // Get the nth element
    for (int i = n - 1; i > 0; --i) {
        queue[i] = queue[i - 1]; // Shift elements
    }
    queue[0] = nthElement; // Move nth element to front
}

int main() {
    // Question 4: Convert decimal to binary
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal; // User input for decimal number
    decimalToBinary(decimal); // Call the function to convert

    // Question 5: Move nth element to front in queue
    const int maxSize = 10; // Maximum size of the queue
    int queue[maxSize]; // Declare an array for the queue
    int size; // Actual size of the queue

    cout << "Enter the number of elements in the queue (max " << maxSize << "): ";
    cin >> size; // User input for size of the queue

    cout << "Enter the queue elements separated by spaces: ";
    for (int i = 0; i < size; i++) {
        cin >> queue[i]; // User input for each queue element
    }

    cout << "Queue before function call: ";
    for (int i = 0; i < size; i++) {
        cout << queue[i] << " "; // Display the queue
    }
    cout << endl;

    int n;
    cout << "Enter the position of the element to move to front: ";
    cin >> n; // User input for the position
    moveNthFront(queue, size, n); // Move nth element to front

    cout << "Queue after function call: ";
    for (int i = 0; i < size; i++) {
        cout << queue[i] << " "; // Display the updated queue
    }
    cout << endl;

    return 0;
}

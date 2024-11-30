//Header File: linkedStack.h
#ifndef H_StackType
#define H_StackType
#include <iostream>
#include <cassert>
#include "stackADT.h"
using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;
};

template <class Type>
class linkedStackType : public stackADT<Type>
{
public:
    const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
    //Overload the assignment operator.

    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.

    bool isFullStack() const;
    //Function to determine whether the stack is full.

    void initializeStack();
    //Function to initialize the stack to an empty state.

    void push(const Type& newItem);
    //Function to add newItem to the stack.

    Type top() const;
    //Function to return the top element of the stack.

    void pop();
    //Function to remove the top element of the stack.

    void pop_k(int k);
    //Function to remove the top k elements from the stack.

    linkedStackType();
    //Default constructor

    linkedStackType(const linkedStackType<Type>& otherStack);
    //Copy constructor

    ~linkedStackType();
    //Destructor

private:
    nodeType<Type>* stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack);
    //Function to make a copy of otherStack.
};

// Existing member function implementations...

template <class Type>
void linkedStackType<Type>::pop_k(int k)
{
    for (int i = 0; i < k; ++i) {
        if (isEmptyStack()) {
            cout << "Stack is empty. Cannot pop more elements." << endl;
            break;
        }
        pop(); // Calls the existing pop function
    }
}

// Existing constructors, destructor, and other methods...

#endif




#include <iostream>
#include "linkedStack.h"
using namespace std;

int main() {
    linkedStackType<int> stack; // Create a linked stack
    int value;

    // Ask user to enter 10 integer values
    cout << "Enter 10 integer values to be stored in the stack:" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> value;
        stack.push(value);
    }

    // Ask user to enter the number of values to pop
    int k;
    cout << "Enter the number of values to pop from the stack: ";
    cin >> k;

    // Pop k values from the stack
    stack.pop_k(k);

    // Display the top value in the stack
    if (!stack.isEmptyStack()) {
        cout << "The top value in the stack is: " << stack.top() << endl;
    }
    else {
        cout << "The stack is empty." << endl;
    }

    return 0;
}
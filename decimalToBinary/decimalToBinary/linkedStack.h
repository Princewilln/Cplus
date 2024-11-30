#ifndef H_LINKEDSTACK
#define H_LINKEDSTACK

#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;

// Definition of the node
template <class Type>
struct nodeType {
    Type info;                 // Data field
    nodeType<Type>* link;     // Pointer to the next node
};

template <class Type>
class linkedStackType : public stackADT<Type> {
public:
    linkedStackType();                         // Default constructor
    linkedStackType(const linkedStackType<Type>& otherStack); // Copy constructor
    ~linkedStackType();                        // Destructor

    void initializeStack();                    // Initialize the stack
    bool isEmptyStack() const;                 // Check if the stack is empty
    bool isFullStack() const;                  // Check if the stack is full
    void push(const Type& newElement);         // Push new element onto the stack
    Type top() const;                          // Return the top element
    void pop();                                 // Remove the top element
    const linkedStackType<Type>& operator=(const linkedStackType<Type>&); // Assignment operator

private:
    nodeType<Type>* stackTop;                  // Pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); // Copy stack
};

// Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType() {
    stackTop = nullptr;
}

// Check if stack is empty
template <class Type>
bool linkedStackType<Type>::isEmptyStack() const {
    return (stackTop == nullptr);
}

// Check if stack is full
template <class Type>
bool linkedStackType<Type>::isFullStack() const {
    return false; // Linked stack is never full
}

// Initialize the stack
template <class Type>
void linkedStackType<Type>::initializeStack() {
    nodeType<Type>* temp;
    while (stackTop != nullptr) {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}

// Push new element onto the stack
template <class Type>
void linkedStackType<Type>::push(const Type& newElement) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newElement;
    newNode->link = stackTop;
    stackTop = newNode;
}

// Return the top element of the stack
template <class Type>
Type linkedStackType<Type>::top() const {
    assert(stackTop != nullptr);
    return stackTop->info;
}

// Remove the top element of the stack
template <class Type>
void linkedStackType<Type>::pop() {
    if (stackTop != nullptr) {
        nodeType<Type>* temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    else {
        cout << "Cannot remove from an empty stack." << endl;
    }
}

// Copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack) {
    stackTop = nullptr;
    copyStack(otherStack);
}

// Destructor
template <class Type>
linkedStackType<Type>::~linkedStackType() {
    initializeStack();
}

// Assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack) {
    if (this != &otherStack) {
        copyStack(otherStack);
    }
    return *this;
}

// Copy stack
template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack) {
    nodeType<Type>* newNode, * current, * last;
    if (stackTop != nullptr) // If stack is nonempty, make it empty
        initializeStack();
    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else {
        current = otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;
        last = stackTop;
        current = current->link;
        while (current != nullptr) {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

#endif // H_LINKEDSTACK

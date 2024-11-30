#ifndef H_LinkedQueue
#define H_LinkedQueue
#include "stackADT.h"
#include <iostream>
#include <cassert>

using namespace std;

// Definition of the node structure for the queue
template <class Type>
struct nodeType {
    Type info;               // Data stored in the node
    nodeType<Type>* link;    // Pointer to the next node
};

// Class definition for the linked queue
template <class Type>
class linkedQueueType {
public:
    linkedQueueType();        // Default constructor
    ~linkedQueueType();       // Destructor
    bool isEmpty() const;     // Check if the queue is empty
    void initializeQueue();    // Initialize the queue
    void addQueue(const Type& newElement); // Add an element to the queue
    void deleteQueue();       // Remove an element from the queue
    Type front() const;       // Get the front element of the queue

private:
    nodeType<Type>* queueFront; // Pointer to the front of the queue
    nodeType<Type>* queueRear;  // Pointer to the rear of the queue
};

// Default constructor
template <class Type>
linkedQueueType<Type>::linkedQueueType() {
    queueFront = nullptr; // Initialize the front pointer to nullptr
    queueRear = nullptr;  // Initialize the rear pointer to nullptr
}

// Destructor
template <class Type>
linkedQueueType<Type>::~linkedQueueType() {
    initializeQueue(); // Clear the queue
}

// Function to initialize the queue
template <class Type>
void linkedQueueType<Type>::initializeQueue() {
    nodeType<Type>* temp; // Pointer to delete nodes
    while (queueFront != nullptr) { // While there are elements in the queue
        temp = queueFront;          // Set temp to point to the current front node
        queueFront = queueFront->link; // Move front to the next node
        delete temp;               // Delete the current node
    }
    queueRear = nullptr; // Set rear pointer to nullptr
}

// Function to check if the queue is empty
template <class Type>
bool linkedQueueType<Type>::isEmpty() const {
    return (queueFront == nullptr); // Returns true if the queue is empty
}

// Function to add an element to the queue
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement) {
    nodeType<Type>* newNode = new nodeType<Type>; // Create a new node
    newNode->info = newElement;                   // Store the new element
    newNode->link = nullptr;                      // Set link to nullptr

    if (queueRear == nullptr) { // If the queue is empty
        queueFront = newNode;   // Front and rear point to the new node
        queueRear = newNode;
    }
    else { // If the queue is not empty
        queueRear->link = newNode; // Link the old rear to the new node
        queueRear = newNode;        // Update the rear to the new node
    }
}

// Function to remove an element from the queue
template <class Type>
void linkedQueueType<Type>::deleteQueue() {
    nodeType<Type>* temp; // Pointer to deallocate memory
    if (queueFront != nullptr) {
        temp = queueFront;           // Set temp to point to the front node
        queueFront = queueFront->link; // Advance front to the next node
        delete temp;                // Delete the old front node
        if (queueFront == nullptr)  // If the queue is now empty
            queueRear = nullptr;     // Set rear to nullptr
    }
    else {
        cout << "Cannot remove from an empty queue." << endl;
    }
}

// Function to get the front element of the queue
template <class Type>
Type linkedQueueType<Type>::front() const {
    assert(queueFront != nullptr); // If the queue is empty, terminate the program
    return queueFront->info;       // Return the front element
}

#endif

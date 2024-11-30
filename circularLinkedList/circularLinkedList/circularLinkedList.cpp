// circularLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link; // Pointer to the next node
};

template <class Type>
class circularLinkedList {
public:
    circularLinkedList(); // Default constructor
    ~circularLinkedList(); // Destructor

    const circularLinkedList<Type>& operator= (const circularLinkedList<Type>&);
    void initializeList(); // Initializes the list to an empty state
    bool isEmptyList() const; // Determines whether the list is empty
    void print() const; // Displays the elements in the list
    int length() const; // Returns the number of nodes in the list
    void destroyList(); // Deletes all the nodes from the list
    Type front() const; // Returns the first element of the list
    Type back() const; // Returns the last element of the list
    bool search(const Type& searchItem) const; // Searches for an item in the list
    void insertLast(const Type& newItem); // Inserts an item at the end of the list
    void deleteNode(const Type& deleteItem); // Deletes a node from the list

protected:
    int count; // Number of elements in the list
    nodeType<Type>* first; // Pointer to the first node of the list
};

// Constructor
template <class Type>
circularLinkedList<Type>::circularLinkedList() {
    first = nullptr;
    count = 0;
}

// Destructor
template <class Type>
circularLinkedList<Type>::~circularLinkedList() {
    destroyList();
}

// Initializes the list to an empty state
template <class Type>
void circularLinkedList<Type>::initializeList() {
    destroyList();
}

// Checks if the list is empty
template <class Type>
bool circularLinkedList<Type>::isEmptyList() const {
    return (first == nullptr);
}

// Displays the elements in the list
template <class Type>
void circularLinkedList<Type>::print() const {
    if (isEmptyList()) {
        cout << "The list is empty." << endl;
        return;
    }
    nodeType<Type>* current = first;
    do {
        cout << current->info << " ";
        current = current->link;
    } while (current != first);
    cout << endl;
}

// Returns the number of nodes in the list
template <class Type>
int circularLinkedList<Type>::length() const {
    return count;
}

// Deletes all nodes from the list
template <class Type>
void circularLinkedList<Type>::destroyList() {
    if (isEmptyList()) return;
    nodeType<Type>* current = first;
    nodeType<Type>* temp;
    do {
        temp = current;
        current = current->link;
        delete temp;
    } while (current != first);
    first = nullptr;
    count = 0;
}

// Returns the first element of the list
template <class Type>
Type circularLinkedList<Type>::front() const {
    assert(first != nullptr);
    return first->info;
}

// Returns the last element of the list
template <class Type>
Type circularLinkedList<Type>::back() const {
    assert(first != nullptr);
    nodeType<Type>* current = first;
    while (current->link != first) {
        current = current->link;
    }
    return current->info;
}

// Searches for an item in the list
template <class Type>
bool circularLinkedList<Type>::search(const Type& searchItem) const {
    if (isEmptyList()) return false;
    nodeType<Type>* current = first;
    do {
        if (current->info == searchItem) return true;
        current = current->link;
    } while (current != first);
    return false;
}

// Inserts an item at the end of the list
template <class Type>
void circularLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;

    if (isEmptyList()) {
        first = newNode;
        newNode->link = first; // Link to itself
    }
    else {
        nodeType<Type>* current = first;
        while (current->link != first) {
            current = current->link;
        }
        current->link = newNode;
        newNode->link = first; // Link the new node to the first
    }
    count++;
}

// Deletes a node from the list
template <class Type>
void circularLinkedList<Type>::deleteNode(const Type& deleteItem) {
    if (isEmptyList()) {
        cout << "Cannot delete from an empty list." << endl;
        return;
    }

    nodeType<Type>* current = first;
    nodeType<Type>* trailCurrent = nullptr;

    // Check if the node to delete is the first node
    if (first->info == deleteItem) {
        if (first->link == first) { // Only one node in the list
            delete first;
            first = nullptr;
        }
        else {
            trailCurrent = first;
            while (trailCurrent->link != first) {
                trailCurrent = trailCurrent->link;
            }
            nodeType<Type>* temp = first;
            first = first->link;
            trailCurrent->link = first; // Link the last node to the new first
            delete temp;
        }
        count--;
        return;
    }

    // Search for the node to delete
    while (current->link != first && current->link->info != deleteItem) {
        current = current->link;
    }

    // If the item was found
    if (current->link->info == deleteItem) {
        nodeType<Type>* temp = current->link;
        current->link = temp->link; // Link the previous node to the next node
        delete temp;
        count--;
    }
    else {
        cout << "The item to be deleted is not in the list." << endl;
    }
}

// Main function to demonstrate circular linked list functionality
int main() {
    circularLinkedList<int> myList;
    int num;

    // Input integers to store in the circular linked list
    cout << "Enter integer values to store in the circular linked list (end with -999): " << endl;
    while (true) {
        cin >> num;
        if (num == -999) break; // End input when -999 is entered
        myList.insertLast(num); // Insert into circular linked list
    }

    // Display the elements in the list
    cout << "\nElements in the circular linked list: ";
    myList.print();

    // Input value to delete from the list
    cout << "\nEnter a value to delete from the list: ";
    cin >> num;
    myList.deleteNode(num); // Delete the specified node

    // Display the elements after deletion
    cout << "Elements in the circular linked list after deletion: ";
    myList.print();

    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

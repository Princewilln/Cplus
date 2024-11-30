#include <iostream>
using namespace std;

template <class elemType>
class arrayListType {
public:
    arrayListType(int size = 100) {
        maxSize = size;
        length = 0;
        list = new elemType[maxSize];
    }

    ~arrayListType() {
        delete[] list;
    }

    void insertEnd(const elemType& insertItem) {
        if (length < maxSize) {
            list[length] = insertItem; // Insert at the end
            length++;
        }
        else {
            cout << "List is full. Cannot insert " << insertItem << endl;
        }
    }

    void print() const {
        for (int i = 0; i < length; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    void revPrint() const {
        revPrintHelper(length - 1); // Start from the last index
    }

    int occur(const elemType& item) const {
        return occurHelper(item, 0); // Start from the first index
    }

private:
    elemType* list; // array to hold the list elements
    int length;     // to store the length of the list
    int maxSize;    // to store the maximum size of the list

    void revPrintHelper(int index) const {
        if (index < 0) {
            return; // Base case
        }
        cout << list[index] << " "; // Print current element
        revPrintHelper(index - 1); // Recursive call
    }

    int occurHelper(const elemType& item, int index) const {
        if (index >= length) {
            return 0; // Base case: reached the end of the list
        }
        int count = (list[index] == item) ? 1 : 0; // Check current item
        return count + occurHelper(item, index + 1); // Recursive call
    }
};

int main() {
    arrayListType<int> myList(10);

    // Adding elements to the list for demonstration
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(2);
    myList.insertEnd(4);

    cout << "Original list: ";
    myList.print(); // Display original list

    cout << "Reversed list: ";
    myList.revPrint(); // Display reversed list
    cout << endl;

    int item;
    cout << "Enter an item to count occurrences: ";
    cin >> item;
    int count = myList.occur(item); // Count occurrences
    cout << "Number of occurrences of " << item << ": " << count << endl;

    return 0;
}

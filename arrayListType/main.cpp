#include "arrayListType.h"

template <class elemType>
void testArrayListType() {
    int size;
    cout << "Enter the number of elements in the list: ";
    cin >> size;

    arrayListType<elemType> list(size);

    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; ++i) {
        elemType value;
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Number of elements in the list: " << list.listSize() << endl;

    cout << "Elements in the list: ";
    list.print();

    elemType smallest, secondSmallest;
    int smallestIndex, secondSmallestIndex;
    list.smallest(smallest, smallestIndex, secondSmallest, secondSmallestIndex);
    cout << "Smallest value: " << smallest << " at index " << smallestIndex << endl;
    cout << "Second smallest value: " << secondSmallest << " at index " << secondSmallestIndex << endl;

    elemType largest, secondLargest;
    int largestIndex, secondLargestIndex;
    list.largest(largest, largestIndex, secondLargest, secondLargestIndex);
    cout << "Largest value: " << largest << " at index " << largestIndex << endl;
    cout << "Second largest value: " << secondLargest << " at index " << secondLargestIndex << endl;
}

int main() {
    cout << "Testing with integer values:" << endl;
    testArrayListType<int>();

    cout << "Testing with double values:" << endl;
    testArrayListType<double>();

    return 0;
}

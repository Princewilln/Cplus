#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template <class elemType>
class arrayListType {
public:
    arrayListType(int size = 100);
    arrayListType(const arrayListType<elemType>& otherList);
    ~arrayListType();
    const arrayListType<elemType>& operator=(const arrayListType<elemType>& otherList);

    bool isEmpty() const;
    bool isFull() const;
    size_t listSize() const;
    size_t maxListSize() const;
    void print() const;
    void insertEnd(const elemType& insertItem);
    void removeAt(size_t location);
    void smallest(elemType& smallest, int& smallestIndex, elemType& secondSmallest, int& secondSmallestIndex) const;
    void largest(elemType& largest, int& largestIndex, elemType& secondLargest, int& secondLargestIndex) const;

private:
    vector<elemType> list;
    size_t maxSize;
};

// Implementation
template <class elemType>
arrayListType<elemType>::arrayListType(int size) : maxSize(size) {}

template <class elemType>
arrayListType<elemType>::arrayListType(const arrayListType<elemType>& otherList)
    : list(otherList.list), maxSize(otherList.maxSize) {}

template <class elemType>
arrayListType<elemType>::~arrayListType() {}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType>& otherList) {
    if (this != &otherList) {
        list = otherList.list;
        maxSize = otherList.maxSize;
    }
    return *this;
}

template <class elemType>
bool arrayListType<elemType>::isEmpty() const {
    return list.empty();
}

template <class elemType>
bool arrayListType<elemType>::isFull() const {
    return list.size() >= maxSize;
}

template <class elemType>
size_t arrayListType<elemType>::listSize() const {
    return list.size();
}

template <class elemType>
size_t arrayListType<elemType>::maxListSize() const {
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const {
    for (const auto& item : list) {
        cout << item << " ";
    }
    cout << endl;
}

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem) {
    if (isFull()) {
        cerr << "List is full." << endl;
        return;
    }
    list.push_back(insertItem);
}

template <class elemType>
void arrayListType<elemType>::removeAt(size_t location) {
    if (location >= list.size()) {
        cerr << "Location out of range." << endl;
        return;
    }
    list.erase(list.begin() + location);
}

template <class elemType>
void arrayListType<elemType>::smallest(elemType& smallest, int& smallestIndex, elemType& secondSmallest, int& secondSmallestIndex) const {
    if (list.size() < 2) {
        cerr << "List must contain at least two elements." << endl;
        return;
    }

    smallest = list[0];
    smallestIndex = 0;
    secondSmallest = numeric_limits<elemType>::max();
    secondSmallestIndex = -1;

    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] < smallest) {
            secondSmallest = smallest;
            secondSmallestIndex = smallestIndex;
            smallest = list[i];
            smallestIndex = i;
        }
        else if (list[i] < secondSmallest && list[i] != smallest) {
            secondSmallest = list[i];
            secondSmallestIndex = i;
        }
    }
}

template <class elemType>
void arrayListType<elemType>::largest(elemType& largest, int& largestIndex, elemType& secondLargest, int& secondLargestIndex) const {
    if (list.size() < 2) {
        cerr << "List must contain at least two elements." << endl;
        return;
    }

    largest = list[0];
    largestIndex = 0;
    secondLargest = numeric_limits<elemType>::min();
    secondLargestIndex = -1;

    for (size_t i = 1; i < list.size(); ++i) {
        if (list[i] > largest) {
            secondLargest = largest;
            secondLargestIndex = largestIndex;
            largest = list[i];
            largestIndex = i;
        }
        else if (list[i] > secondLargest && list[i] != largest) {
            secondLargest = list[i];
            secondLargestIndex = i;
        }
    }
}

// Explicitly instantiate templates for the types you want to use
template class arrayListType<int>;
template class arrayListType<double>;

#endif // ARRAYLISTTYPE_H

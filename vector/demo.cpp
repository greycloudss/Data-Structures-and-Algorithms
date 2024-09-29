#include "header.h"
#define INT_MAX 2147483630  //close enough to int_max

size_t ADT::getSize() const {
    return size;
}

size_t ADT::getMaxSize() const {
    return cap;
}

int ADT::get(const size_t pos) const {
    if (pos >= size) throw std::out_of_range("Position out of range");
    return data[pos];
}

size_t ADT::get(const int val) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == val)
            return i;
    }
    return -1;
}

int ADT::getFirst() const {
    if (size == 0) throw std::out_of_range("List is empty");
    return data[0];
}

int ADT::getLast() const {
    if (size == 0) throw std::out_of_range("List is empty");
    return data[size - 1];
}

void ADT::remove(const size_t pos) {
    if (pos >= size) throw std::out_of_range("Position out of range");

    for (size_t i = pos; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

void ADT::removeFirst() {
    if (size == 0) throw std::out_of_range("List is empty");
    remove(0);
}

void ADT::removeLast() {
    if (size == 0) throw std::out_of_range("List is empty");
    size--;
}

void ADT::remove(int val) {
    size_t pos = get(val);
    if (pos == static_cast<size_t>(-1)) throw std::out_of_range("Value not found");
    remove(pos);
}

ADT::ADT() : cap(4), size(0) {
    data = new int[cap];
}

ADT::ADT(int val) : cap(4), size(1) {
    data = new int[cap];
    data[0] = val;
}

void ADT::addLast(int val) {
    resize();
    data[size++] = val;
}

void ADT::add(int val) {
    addLast(val);
}

void ADT::add(size_t pos, int val) {
    if (pos > size) throw std::out_of_range("Position out of range");
    resize();
    for (size_t i = size; i > pos; --i) {
        data[i] = data[i - 1];
    }
    data[pos] = val;
    size++;
}

void ADT::addFirst(int val) {
    add(0, val);
}

void ADT::resize() {
    if (size >= cap) {
        size_t newCap = cap * 2;
        int* newBlock = new int[newCap];
        for (size_t i = 0; i < size; ++i) {
            newBlock[i] = data[i];
        }
        delete[] data;
        data = newBlock;
        cap = newCap;
    }
}

int main() {
    ADT RADavacius(1);
    RADavacius.add(0, 21);
    RADavacius.addLast(45);
    RADavacius.add(4);
    RADavacius.addFirst(5111);
    return 0;
}
#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>

class ADT {
private:
    size_t cap; // Current capacity
    int* data;   // Pointer to the data array
    size_t size;   // Current size

    void resize();

public:
    ADT();
    ADT(int val);

    size_t sizee() const { return this->size; }
    size_t getSize() const;
    size_t getMaxSize() const;

    void add(size_t pos, int val);
    void add(int val);
    void addFirst(int val);
    void addLast(int val);

    int get(const size_t pos) const;
    size_t get(const int val) const;
    int getFirst() const;
    int getLast() const;

    void remove(const size_t pos);
    void removeFirst();
    void removeLast();
    void remove(int val);

    ~ADT() {
        delete[] data;
    }
};

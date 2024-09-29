#pragma once

#include <iostream>
#include <stdexcept>

#include <iostream>
#include <stdexcept>

struct Node {
    Node* next;
    int val;
    Node* prev;

    Node() : next(nullptr), val(0), prev(nullptr) {}
    Node(Node* prv, int value, Node* nxt) : next(nxt), val(value), prev(prv) {}
};

class ADT {
private:
    Node* Head;
    Node* Footer;
    int length;

public:
    ADT();
    ~ADT();
    int getLength() const { return length; }
    void add(int pos, int val);
    void add(int val);
    void addLast(int val);
    void addFirst(int val);


    void edit(int pos, int val);
    void editFirst(int val);
    void editLast(int val);

    int get(int pos) const;
    int getFirst() const;
    int getLast() const;

    void remove(int pos);
    void removeFirst();
    void removeLast();
};


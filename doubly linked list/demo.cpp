#include "header.h"

ADT::ADT() {
    Head = new Node();
    Footer = new Node();
    
    Head->next = Footer;
    Footer->prev = Head;

    length = 0;
}

ADT::~ADT() {
    Node* current = Head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void ADT::add(int val) {
    Node* newNode = new Node(Footer->prev, val, Footer);
    Footer->prev->next = newNode;
    Footer->prev = newNode;
    length++;
}

void ADT::add(int pos, int val) {
    if (pos < 0 || pos > length)
        throw std::invalid_argument("Invalid position");

    Node* temp;
    if (pos < length / 2) {
        temp = Head->next;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
    } else {
        temp = Footer;
        for (int i = length; i > pos; --i) {
            temp = temp->prev;
        }
    }

    Node* newNode = new Node(temp->prev, val, temp);
    temp->prev->next = newNode;
    temp->prev = newNode;
    length++;
}

void ADT::addFirst(int val) {
    add(0, val);
}

void ADT::addLast(int val) {
    add(val);
}

int ADT::get(int pos) const {
    if (pos < 0 || pos >= length)
        throw std::invalid_argument("Invalid position");

    Node* temp;
    if (pos < length / 2) {
        temp = Head->next;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
    } else {
        temp = Footer->prev;
        for (int i = length - 1; i > pos; --i) {
            temp = temp->prev;
        }
    }

    return temp->val;
}

int ADT::getFirst() const{
    return get(0);
}

int ADT::getLast() const {
    return get(length - 1);
}

void ADT::edit(int pos, int val){
    if (pos < 0 || pos >= length)
        throw std::invalid_argument("Invalid position");

    Node* temp;
    if (pos < length / 2) {
        temp = Head->next;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
    } else {
        temp = Footer->prev;
        for (int i = length - 1; i > pos; --i) {
            temp = temp->prev;
        }
    }

    temp->val = val;
}

void ADT::editFirst(int val){
    edit(0, val);
}

void ADT::editLast(int val){
    edit(length - 1, val);
}

void ADT::remove(int pos) {
    if (pos < 0 || pos >= length || length == 0)
        throw std::invalid_argument("Invalid position");

    Node* temp;
    if (pos < length / 2) {
        temp = Head->next;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
    } else {
        temp = Footer->prev;
        for (int i = length - 1; i > pos; --i) {
            temp = temp->prev;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    length--;
}

void ADT::removeFirst() {
    remove(0);
}

void ADT::removeLast() {
    remove(length - 1);
}

int main() {
    ADT* list = new ADT();

    list->add(1);
    list->add(2);
    list->add(3);
    
    for (int i = 0; i < list->getLength(); ++i) {
        std::cout << list->get(i) << " ";
    }
    std::cout << std::endl;

    list->remove(1);
    list->editLast( 21);

    for (int i = 0; i < list->getLength(); ++i) {
        std::cout << list->get(i) << " ";
    }
    std::cout << std::endl;

    delete list;
    return 0;
}
#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>

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
        ADT() {
            Head = new Node();
            Footer = new Node();

            Head->next = Footer;
            Footer->prev = Head;

            length = 0;
        }

        ~ADT() {
            Node* current = Head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        int getLength() const {
            return length;
        }


        void add(int pos, int val) {
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

        void add(int val) {
            Node* newNode = new Node(Footer->prev, val, Footer);
            Footer->prev->next = newNode;
            Footer->prev = newNode;
            length++;
        }

        void addFirst(int val) {
            add(0, val);
        }

        void addLast(int val) {
            add(val);
        }

        void edit(int pos, int val){
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

        void editFirst(int val){
            edit(0, val);
        }

        void editLast(int val){
            edit(length - 1, val);
        }

        int get(int pos) const {
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

        int getFirst() const{
            return get(0);
        }

        int getLast() const {
            return get(length - 1);
        }

        void remove(int pos) {
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

        void removeFirst() {
            remove(0);
        }

        void removeLast() {
            remove(length - 1);
        }

        std::string printAsc() const {

            if (length == 0) return {};

            std::vector<int> elements;
            Node* temp = Head;

            while (temp) {
                elements.push_back(temp->val);
                temp = temp->next;
            }

            std::sort(elements.begin(), elements.end());

            std::stringstream ss;

            for (const auto& val : elements)
                ss << val << " ";
            

            ss << std::endl;
            return ss.str();
        }
};
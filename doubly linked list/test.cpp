#include <stdio.h>
#include <stdlib.h>
#include <iostream>


// other includes and definitions
#include <stdexcept>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
/* YOUR CODE HERE */

using namespace std;

// define your container here

struct Node {
    Node* next;
    int val;
    Node* prev;

    Node() : next(nullptr), val(0), prev(nullptr) {}
    Node(Node* prv, int value, Node* nxt) : next(nxt), val(value), prev(prv) {}
};

class tADT {
    private:
        Node* Head;
        Node* Footer;
        int length;

        Node* getNode(int pos) const {
            if (pos < 0 || pos >= length)
                throw std::out_of_range("Invalid position");

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
            return temp;
        }

    public:
        tADT() {
            Head = new Node();
            Footer = new Node();

            Head->next = Footer;
            Footer->prev = Head;

            length = 0;
        }

        ~tADT() {
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
                throw std::out_of_range("Invalid position");

            Node* temp = (pos == length) ? Footer : getNode(pos);

            Node* newNode = new Node(temp->prev, val, temp);
            temp->prev->next = newNode;
            temp->prev = newNode;
            length++;
        }

        void add(int val) {
            add(length, val);
        }

        void addFirst(int val) {
            add(0, val);
        }

        void addLast(int val) {
            add(length, val);
        }

        void edit(int pos, int val) {
            Node* temp = getNode(pos);
            temp->val = val;
        }

        void editFirst(int val) {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            edit(0, val);
        }

        void editLast(int val) {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            edit(length - 1, val);
        }

        int get(int pos) const {
            Node* temp = getNode(pos);
            return temp->val;
        }

        bool find(int val) const {
            Node* slow = Head->next;
            Node* fast = slow ? slow->next : nullptr;

            while (slow != Footer && fast != Footer) {
                if (slow->val == val || fast->val == val)
                    return true;
        

                slow = slow->next;

                (fast->next != Footer) ? fast = fast->next->next : fast = Footer;
            }


            if (slow != Footer && slow->val == val) {
                return true;
            }

            return false;
        }

        int getFirst() const {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            return get(0);
        }

        int getLast() const {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            return get(length - 1);
        }

        void remove(int pos) {
            if (pos < 0 || pos >= length || length == 0)
                throw std::out_of_range("Invalid position");

            Node* temp = getNode(pos);

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
            length--;
        }

        void removeByValue(int val) {
            Node* temp = Head->next;
            while (temp != Footer) {
                if (temp->val == val) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    length--;
                    return;
                }
                temp = temp->next;
            }
            throw std::invalid_argument("Value not found");
        }

        void removeFirst() {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            remove(0);
        }

        void removeLast() {
            if (length == 0)
                throw std::out_of_range("No elements in the array");
            remove(length - 1);
        }

        std::string printAsc() const {
            if (length == 0) return {};

            std::vector<int> elements;
            Node* temp = Head->next;
            while (temp != Footer) {
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

// define your value here		
typedef int/* YOUR CODE HERE */ tValue; 		


int errorCode;

// throw the following class if function is not implemented
class NotImplementedException {
};
// throw the following class if index/position out of bounds
class OutOfBoundsException {
};



void createADT(tADT &adt){
	
}
void destroyADT(tADT &adt){
	
}



void add(tADT &adt, tValue value, int pos){
    adt.add(pos, value);

	//throw NotImplementedException();
}
void addValue(tADT &adt, tValue value){
    adt.add(value);

	//throw NotImplementedException();
}
void addFirst(tADT &adt, tValue value){
    adt.addFirst(value);

	//throw NotImplementedException();
}
void addLast(tADT &adt, tValue value){
    adt.addLast(value);

	//throw NotImplementedException();
}



void remove(tADT &adt, int pos){
    adt.remove(pos);

	//throw NotImplementedException();
}
void removeValue(tADT &adt, tValue value){
	adt.removeByValue(value);
	//throw NotImplementedException();
}
void removeFirst(tADT &adt){
    adt.removeFirst();

	//throw NotImplementedException();
}
void removeLast(tADT &adt){
    adt.removeLast();

	//throw NotImplementedException();
}



tValue get(tADT &adt, int pos){
    return adt.get(pos);

	//throw NotImplementedException();
}
bool getValue(tADT &adt, tValue value){
	return adt.find(value);
	
	//throw NotImplementedException();
}
tValue getFirst(tADT &adt){

	return adt.getFirst();

	//throw NotImplementedException();
}
tValue getLast(tADT &adt){
    return adt.getLast();

	///throw NotImplementedException();
}



int getSize(tADT &adt){
	return adt.getLength();
}
int getMaxSize(tADT &adt){
    return std::numeric_limits<int>::max() / sizeof(Node);
}

// print all values of your ADT in ascending order
// all values should be in a single line separated by single spaces	
void printADT(tADT &adt) {
    std::cout << adt.printAsc();
}


/* DO NOT MODIFY CODE BELOW */
class ErrorCodeException {
};

int main(){	
	try {
		errorCode = 0;
		tADT adt;
		createADT(adt);
		
		int x = -1;
		while(1){
			cin >> x;
			if (x == 0){
				destroyADT(adt);
				break;
			} else {
					tValue val;
					int pos;
					switch(x){
						case 11:
							printADT(adt);
							break;
						case 12:
							cout << getSize(adt) << endl;
							break;
						case 13:
							cout << getMaxSize(adt) << endl;
							break;
						case 21:
							cout << getFirst(adt) << endl;
							break;
						case 22:
							cout << getLast(adt) << endl;
							break;
						case 23:
							cin >> pos;
							cout << get(adt, pos) << endl;
							break;
						case 24:
							cin >> val;
							cout << getValue(adt, val) << endl;
							break;
						case 31:
							cin >> val;
							addFirst(adt, val);
							break;
						case 32:
							cin >> val;
							addLast(adt, val);
							break;
						case 33:
							cin >> val >> pos;
							add(adt, val, pos);
							break;
						case 34:
							cin >> val;
							addValue(adt, val);
							break;
						case 41:
							removeFirst(adt);
							break;
						case 42:
							removeLast(adt);
							break;
						case 43:
							cin >> pos;
							remove(adt, pos);
							break;	
						case 44:
							cin >> val;
							removeValue(adt, val);
							break;				
					}		
			}		
		}
		if (errorCode){
			throw OutOfBoundsException();
		}
	} catch (NotImplementedException &e){
		return 2018;
	} catch (ErrorCodeException &e){
		return 1234;
	} catch (OutOfBoundsException &e){
		return 4321;
	} catch (...){
		return -1;
	}
	return 0;	
}
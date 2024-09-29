#include <stdio.h>
#include <stdlib.h>
#include <iostream>


// other includes and definitions

/* YOUR CODE HERE */

using namespace std;

// define your container here

#include <limits>
#include <stdexcept>
#include <cstring>

class tADT {
    private:
        int cap;   // Current capacity
        int* data; // Pointer to the data array
        int size;  // Current size

        void resize() {
            int newCap = cap * 2;
            int* newBlock = new int[newCap];
            for (int i = 0; i < size; ++i)
                newBlock[i] = data[i];
            delete[] data;
            data = newBlock;
            cap = newCap;
        }
        static constexpr int initialCapacity = 4;
    public:
        tADT() : cap(initialCapacity), data(new int[initialCapacity]), size(0) {}

        tADT(int val) : cap(initialCapacity), data(new int[initialCapacity]), size(1) {
            data[0] = val;
        }

        tADT(const tADT& other) : cap(other.cap), data(new int[other.cap]), size(other.size) {
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        tADT(tADT&& other) noexcept : cap(other.cap), data(other.data), size(other.size) {
            other.data = nullptr;
            other.size = 0;
            other.cap = 0;
        }

        tADT& operator=(const tADT& other) {
            if (this == &other) return *this;
            delete[] data;
            cap = other.cap;
            size = other.size;
            data = new int[cap];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            return *this;
        }

        tADT& operator=(tADT&& other) noexcept {
            if (this == &other) return *this;
            delete[] data;
            cap = other.cap;
            size = other.size;
            data = other.data;
            other.data = nullptr;
            other.size = 0;
            other.cap = 0;
            return *this;
        }

        ~tADT() {
            delete[] data;
        }

        int getSize() const {
            return size;
        }

        int getMaxSize() const {
            return cap;
        }

        void addLast(int val) {
            if (size >= cap)
                resize();

            data[size++] = val;
        }

        void add(int val) {
            addLast(val);
        }

        int* returnData() const {
            return data;
        }

        void add(int pos, int val) {
            if (pos > size || pos < 0)
                throw std::out_of_range("Position out of range");

            if (size == cap)
                resize();

            ++size;

            std::memmove(&data[pos + 1], &data[pos], (size - pos) * sizeof(int));

            data[pos] = std::move(val);
        }

        void addFirst(int val) {
            add(0, val);
        }

       inline int get(int pos) const {
            if (pos >= size || pos < 0)
                throw std::out_of_range("Position out of range");
            return data[pos];
        }

        bool getValue(int val) const {
            for (int i = 0; i < size; ++i)
                if (val == data[i])
                    return true;
            return false;
        }

        inline int getFirst() const {
            if (size == 0)
                throw std::out_of_range("No elements in the array");
            return data[0];
        }

        inline int getLast() const {
            if (size == 0)
                throw std::out_of_range("No elements in the array");
            return data[size - 1];
        }

        void remove(int pos) {
            if (pos >= size || pos < 0)
                throw std::out_of_range("Position out of range");

            std::memmove(&data[pos], &data[pos + 1], (size - pos - 1) * sizeof(int));
            
            size--;
        }

        void removeFirst() {
            remove(0);
        }

        void removeLast() {
            remove(size - 1);
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
	/* YOUR CODE HERE OR EMPTY */

}
void destroyADT(tADT &adt){
	/* YOUR CODE HERE OR EMPTY */
}



void add(tADT &adt, tValue value, int pos){
	adt.add(pos, value);
	//throw NotImplementedException();
}

void addValue(tADT &adt, tValue value){
	/* YOUR CODE HERE */
    adt.add(value);
	//throw NotImplementedException();
}
void addFirst(tADT &adt, tValue value){
	/* YOUR CODE HERE */
    adt.addFirst(value);
	//throw NotImplementedException();
}
void addLast(tADT &adt, tValue value){
	/* YOUR CODE HERE */
    adt.addLast(value);
	//throw NotImplementedException();
}



void remove(tADT &adt, int pos){
	/* YOUR CODE HERE */
    adt.remove(pos);
	//throw NotImplementedException();
}
void removeValue(tADT &adt, tValue value){
	/* YOUR CODE HERE */
     for (int i = 0; i < adt.getSize(); ++i) {
        if (adt.get(i) == value) {
            adt.remove(i);
            return;
        }
    }
	//throw NotImplementedException();
}
void removeFirst(tADT &adt){
	/* YOUR CODE HERE */
    adt.removeFirst();
	//throw NotImplementedException();
}
void removeLast(tADT &adt){
	/* YOUR CODE HERE */
    adt.removeLast();
	//throw NotImplementedException();
}



tValue get(tADT &adt, int pos){
	/* YOUR CODE HERE */
    return adt.get(pos);
	//throw NotImplementedException();
}
bool getValue(tADT &adt, tValue value){
	/* YOUR CODE HERE */
    return adt.getValue(value);
	//throw NotImplementedException();
}
tValue getFirst(tADT &adt){
	/* YOUR CODE HERE */
    return adt.getFirst();
	//throw NotImplementedException();
}
tValue getLast(tADT &adt){
	/* YOUR CODE HERE */
    return adt.getLast();
	//throw NotImplementedException();
}


int getSize(tADT &adt){
	/* YOUR CODE HERE */
    return adt.getSize();
}
int getMaxSize(tADT &adt){
	/* YOUR CODE HERE */
    return adt.getMaxSize();
}

// print all values of your ADT in ascending order
// all values should be in a single line separated by single spaces	
void printADT(tADT &adt){

	int* data = adt.returnData();
    int size = adt.getSize();
    int* sortedData = new int[size];

    for (int i = 0; i < size; ++i)
        sortedData[i] = data[i];
    

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (sortedData[j] > sortedData[j + 1]) {
                std::swap(sortedData[j], sortedData[j + 1]);
            }
        }
    }

    for (int i = 0; i < size; ++i)
        std::cout << sortedData[i] << " ";
    
    std::cout << std::endl;

    delete[] sortedData;



	/* YOUR CODE HERE */
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
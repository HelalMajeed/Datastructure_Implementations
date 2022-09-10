#include <iostream>
using namespace std;

const int maxSize = 10;

class queue {
    int first, last, length;
    int itmes[maxSize];

public:

    queue() {
        first = length = 0;
        last = maxSize -1;
    }

    bool empty() {
        return length == 0;
    }     

    bool full() {
        return length == maxSize -1;
    }
    
    void insert(int data) {
        if(full()) {
            cout << "queue full";
        }
        else {
            last = (last+1) % maxSize;
            itmes[last] = data;
        }
        length++;
    }

    void pop() {
        if(empty()) {
            cout << "empty queue";
        }
        else {
            first = (first+1) % maxSize;
        }
        length--;
    }
    
    void print() {
        for(int i=first; i<=last; i++) {
            cout << itmes[i] << " ";
        }
    }
};

int main() {
   queue myQueue;
   myQueue.insert(1); 
   myQueue.insert(4); 
   myQueue.insert(2); 
   myQueue.insert(3); 
   myQueue.pop();
   myQueue.print();
}

#include <iostream>
using namespace std;

template <class data_type>

class stackTypeArray {

    int top;
    data_type *item;
    int maxSize;

public:

    stackTypeArray(size_t size) {
        maxSize = size;
        item = new data_type[maxSize];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize;
    }

    void insert(data_type value) {
        if(isFull()) {
            cout << "full stack cannot insert" << endl;
            return;
        }
        else {
            top++;
            item[top] = value;
        }
    }

    void pop() {
        if(isEmpty()) {
            cout << "empty stack no thing to remove" << endl;
            return;
        }
        else {
            top--;
        }
    }

    void printLenght() {
        cout << "length is: " << top +1 << endl;
    }

    data_type getTop(data_type &element) {
        element = item[top];
        return element;
    }

    void printStack() {
        if(isEmpty()) {
            cout << "NO thing to pirnt " << endl;
            return;
        }
        else {
            cout << "[";
            for(int i=top; i>=0; i--) {
                cout << "'" << item[i] << "'" << " ";
            }
            cout << "]";
        }
        cout << endl;
    }
};

int main() {

    stackTypeArray<string> myStack(4);

    myStack.insert("School");
    myStack.insert("college");
    myStack.insert("Studying");
    myStack.insert("Video game");

    myStack.pop();

    myStack.printStack();
    
    string top;
    myStack.getTop(top);
    cout << "top is: " << top;
}

#include <iostream>
using namespace std;

template <class data_type>

class stackTypeList {

private:

    struct Node  {
        data_type data;
        Node *next;
    };

    Node *top;
    int length;

public:

    stackTypeList() {
        top = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insert(data_type value) {
        Node *newNode = new Node;
        newNode->data = value;
        if(isEmpty()) {
            top = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        length++;
    }

    void pop() {
        if(isEmpty()) {
            cout << "empty stack no thing to delete" << endl;
            return;
        }
        else {
            Node *ptr = top;
            top = top->next;
            delete ptr;
        }
        length--;
    }

    void printStack() {
        if(isEmpty()) {
            cout << "empty stack" << endl;
            return;
        }
        else {
            cout << "stack is: [";
            Node *ptr = top;
            for(int i=0; i<length; i++) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << "]" << endl;
        }
    }
};

int main() {

    stackTypeList<int> myStack;

    myStack.insert(9);
    myStack.insert(8);
    myStack.insert(7);
    myStack.insert(6);
    myStack.insert(5);
    myStack.insert(4);
    myStack.insert(3);
    myStack.insert(2);
    myStack.insert(1);
    myStack.insert(0);
    myStack.insert(0);

    myStack.pop();
    myStack.pop();

    myStack.printStack();

}

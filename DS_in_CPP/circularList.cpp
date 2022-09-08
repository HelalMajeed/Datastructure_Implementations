#include <iostream>
using namespace std;

template <class tmplt>

class circularList {

    struct Node {
        tmplt data;
        Node *next;
    };

    Node *first, *last;
    int length;

public:

    circularList() {
        first = last = NULL;
        length = 0;
    }

    bool empty() {
        return length == 0;
    }

    void insertFirst(tmplt value) {
        Node *newNode = new Node;
        newNode->data = value;
        if(empty()) {
            first = last = newNode;
            last->next = first;
        }
        else {
            newNode->next = first;
            first = newNode;
            last->next = first;
        }
        length++;
    }

    void insertLast(tmplt value) {
        Node *newNode = new Node;
        newNode->data = value;
        if(empty()) {
            first = last = newNode;
            last->next = first;
        }
        else {
            newNode->next = last;
            last->next = newNode;
            last = newNode;
            last->next = first;
        }
        length++;
    }
    
    void insertAtPos(tmplt value, int position) {
        if(position > length) {
            cout << "cant insert the position is out of range";
            return;
        }

        else if(empty() || position == 0 || position == 1)
            insertFirst(value);

        else if(position == length) 
            insertLast(value);

        else {
            Node *ptr = first;
            Node *newNode = new Node;
            newNode->data = value;
            for(int i=1; i<position-1; i++)
                ptr = ptr->next;
            newNode->next = ptr->next;
            ptr->next = newNode;
            length++;
        }

    }

    void deleteFirst() {
        if(empty()) {
            cout << "empty list";
            return;
        }
        else {
            Node *ptr = first;
            first = first->next;
            ptr->next = NULL;
            delete ptr; 
        }
        length--;
    }

    void deleteLast() {
        if(empty()) {
            cout <<"empty list";
            return;
        }
        else {
            Node *ptr, *tmp;
            ptr = tmp = first;
            for(int i=0; i<length-1; i++) {
                tmp = ptr;
                ptr = ptr->next;
            }
            last = tmp;
            last->next = first;
            ptr->next = NULL;
            delete ptr;
            length--;
        }
    }

    void printList() {
        if(empty()) {
            cout << "empty";
            return;
        }
        else {
            Node *ptr = first;
            for(int i=0; i<length; i++) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
    }
};

int main() {

    circularList<int> l;

    l.insertFirst(10);

    l.insertLast(20);
    l.insertLast(40);
    l.insertLast(50);

    l.insertFirst(10);
    l.deleteFirst();

    l.insertLast(50);
    l.deleteLast();

    l.insertAtPos(30, 3);
    l.printList();
}

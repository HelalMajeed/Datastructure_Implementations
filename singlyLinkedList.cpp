#include <iostream>
using namespace std;

class list {
    typedef struct Node {
        int item;
        struct Node *next;
    }Node;
    Node *first;
    Node *last;
    int length;
public:
    list() {
        first = last = NULL;
        length = 0;
    }
    bool isEmpty() {
        return length == 0;
    }
    void insertFirst(int data) {
        Node *newNode = new Node;
        newNode->item = data;
        if(isEmpty()) {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }
    void insertLast(int data) {
        Node *newNode = new Node;
        newNode->item = data;
        if(isEmpty()) {
            first = last = newNode;
            newNode = NULL;
        }
        else {
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }
    void addInPosition(int data, size_t position) {
        Node *ptr = first;
        Node *newNode = new Node;
        newNode->item = data;
        if(isEmpty()) {
            first = last = newNode;
            newNode->next = NULL;
        }
        else {
            for(int i=1; i<length; i++) 
                ptr = ptr->next;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        length++;
    }
    void replace(int data, size_t position) {
        if(isEmpty()) {
            Node *newNode = new Node;
            newNode->item = data;
            newNode->next = NULL;
            first = last = newNode;
        }
        else {
            Node *ptr = first;
            position--;
            while(position--) 
                ptr = ptr->next;
            ptr->item = data;
        }
    }
    void deleteFirst() {
        if(isEmpty()) {
            cout << "Node is empty\n";
            return;
        }
        else {
            Node *ptr = first;
            first = first->next;
            delete ptr;
            length--;
        }
    }
    void deleteLast() {
        if(isEmpty()) {
            cout << "Node is empty\n";
            return;
        }
        else {
            Node *ptr, *tmp;
            ptr = tmp = first;
            while(ptr != NULL) {
                tmp = ptr;
                ptr = ptr->next;
            }
            last = tmp;
            delete ptr;
           length--; 
        }
    }
    void deleteNode(int data) {
        if(isEmpty()) 
            cout << "Node is empty\n";
        else {
            Node *ptr, *tmp; 
            ptr = tmp = first;
            for(int i=1; i<length; i++) {
                tmp = ptr;
                ptr = ptr->next;
                if(ptr->item == data) {
                    tmp->next = ptr->next;
                    delete ptr;
                    return;
                }
            }
        }
    }
    void printList() {
        if(isEmpty()) 
            cout << "Node is empty\n";
        else {
            Node *ptr = first;
            while(ptr != NULL) {
                printf("%d ", ptr->item);
                ptr = ptr->next;
            }
        }
    }
};

int main() {
    list myList;
    myList.insertFirst(0);
    myList.insertFirst(1);
    myList.insertFirst(1);
    myList.insertLast(2);
    myList.insertLast(3);
    myList.insertLast(4);
    myList.insertLast(5);
    myList.insertLast(6);
    myList.insertLast(7);
    myList.insertLast(7);
    myList.insertLast(10);
    myList.replace(8, 10);
    myList.deleteLast();
    myList.addInPosition(9, 9);
    myList.deleteFirst();
    myList.deleteNode(0);
    myList.printList();
    //output should be: 1 2 3 4 5 6 7 8 9 10
    return 0;
}

#include <iostream>

using namespace std;

class doubleList {
private:

    struct Node {
        int data;
        Node *next;
        Node *prev;
    };

    Node *first, *last;
    int length;

public:

    doubleList() {

        first = last = NULL;
        length = 0;
    }

    bool isEmpty() {

        return length == 0;
    }

    void insertFirst(int value) {

        Node *newNode = new Node;
        newNode->data = value;

        if(isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        
        else {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;
        }

        length++;
    }

    void insertLast(int value) {

        Node *newNode = new Node;
        newNode->data = value;

        if(isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->next = NULL;
        }

        else {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }

        length++;
    }

    void addInPosition(int value, size_t position) {

        if(position > length || position < 0) {
            cout << "Out of range!\n";
            return;
        }

        else if(isEmpty() || position == 1 || position == 0) 
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
            newNode->prev = ptr;
            ptr->next = newNode;
            ptr->next->prev = newNode;
        }

        length++;
    }

    void deleteFirst() {

        if(isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        else {
            Node *ptr = first;
            first = first->next;
            first->prev = NULL;
            delete ptr;
        }

        length--;
    }

    void deleteLast() {

        if(isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        else {
            Node *ptr = last;
            last = last->prev;
            last->next = NULL;
            delete ptr;
        }

        length--;
    }

    void deleteNode(int value) {

        if(isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        else {
            Node *ptr, *tmp;
            ptr = tmp = first;

            while(ptr->data != value && ptr != NULL) {
                tmp = ptr;
                ptr = ptr->next;
            }

            if(ptr->data == value) {
                tmp->next = ptr->next;
                ptr->next->prev = tmp;
                delete ptr;                
                length--;
            }
            
            else {
                cout << "No such a node!" << endl;
                return;
            }
        }
    }

    void replace(int value, size_t position) {

        if(isEmpty() || position > length) {
            cout << "Fuck off!" << endl;
            return;
        }
        
        else {
            Node *ptr = first;
            for(int i=1; i<position-1; i++) 
                ptr = ptr->next;
            ptr->data = value;
        }
    }

    void searchPositionForward(int value) {

        int position(1);
        Node *ptr = first;
        while(ptr->data != value && ptr != NULL) {
            ptr = ptr->next;
            position++;
        }

        if(ptr->data = value) 
            cout << "The position for " << ptr->data << " forward is: " <<  position << endl;
        
        else 
            cout << "No such a node\n";
    }

    void searchPositionBackward(int value) {

        int position(1);
        Node *ptr = last;
        while(ptr->data != value && ptr != NULL) {
            ptr = ptr->prev;
            position++;
        }

        if(ptr->data == value) 
            cout << "The position for " << ptr->data << " backward is: " <<  position << endl;
    }

    void printForward() {

        if(isEmpty()) {
            puts("List is empty!");
            return;
        }

        else {
            cout << "List forward: ";
            Node *ptr = first;
            while(ptr != NULL) {
                cout << ptr->data;
                if(ptr->next != NULL)
                    cout <<"->";
                ptr = ptr->next;
            } 

            puts("");
        }
    }

    void printBackward() {

        if(isEmpty()) {
            cout << "List is empty\n";
            return;
        }

        else {
            printf("List backward: ");
            Node *ptr = last;
            while(ptr != NULL) {
                printf("%d", ptr->data);
                if(ptr->prev != NULL)
                    printf("->");
                ptr = ptr->prev; 
            }
            puts("");
        }
    }

    void printLength() {

        cout << "Length is: " << length << endl;
    }

};

int main() {

    doubleList myList;

    myList.insertFirst(1);

    myList.insertLast(2);
    myList.insertLast(3);
    myList.insertLast(4);
    myList.insertLast(5);
    myList.insertLast(6);
    myList.insertLast(7);
    myList.insertLast(8);
    myList.insertLast(9);
    myList.insertLast(10);

    myList.printForward();
    myList.searchPositionForward(9);

    myList.printBackward();
    myList.searchPositionBackward(9);

    myList.printLength();

    return 0;

}

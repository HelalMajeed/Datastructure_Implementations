#include <iostream>
using namespace std;

template <class data_type>

class queueList {
    
    struct Node {
        data_type data;
        Node *next;
    };

    Node *first, *last;
    int length;
    
public:

    queueList() {
        first = last = NULL;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insert(data_type value) {
        Node *newNode = new Node;
        newNode->data = value;
        if(isEmpty()) {
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

    void pop() {
        if(isEmpty()) {
            cout<< " empty queue";
            return;
        }
        else {
            Node *ptr = first;
            first = first->next;
            last->next = first;
            delete ptr;
            length--;
        }
    }

    void getFirst() {
        puts("");
        cout << "first is: " << first->data; 
        puts("");
    }

    void getLast() {
        puts("");
        cout << "last is: " << last->data;
        puts("");
    }

    void printQueue() {
        if(isEmpty()) {
            cout << "queue is empty";
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

int main(void) {
    
    queueList<int> queue;
    
    queue.insert(0);
    queue.insert(1);
    queue.insert(2);
    queue.insert(3);
    queue.insert(4);
    queue.insert(5);
    queue.insert(6);
    queue.insert(7);
    queue.insert(8);
    queue.insert(9); 

    queue.pop();

    queue.getFirst();
    queue.getLast();

    queue.printQueue();

}

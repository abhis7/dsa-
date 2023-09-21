#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

bool circularLinkedList(Node* head) {
    if (head == NULL) {
        return false; // Empty list is not circular.
    }

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    if (temp == head) {
        return true; // Circular linked list.
    }

    return false; // Not circular.
}

int main() {
    Node* node1 = new Node(5);
    Node* node2 = new Node(10);
    Node* node3 = new Node(15);

    // Creating a circular linked list: 5 -> 10 -> 15 -> 5
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    Node* head = node1;

    if (circularLinkedList(head)) {
        cout << "The linked list is circular." << endl;
    } else {
        cout << "The linked list is not circular." << endl;
    }

    return 0;
}

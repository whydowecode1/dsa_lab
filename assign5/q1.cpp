#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int A[], int n) {
    if (n == 0) return nullptr;

    Node *head = new Node{A[0], nullptr};
    Node *previous = head;

    for (int i = 1; i < n; i++) {
        Node *temp = new Node{A[i], nullptr};
        previous->next = temp;
        previous = temp;
    }
    return head;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void search(Node* head, int num) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != num)
        temp = temp->next;

    if (temp == nullptr)
        cout << "Element not found";
    else
        cout << "Element found";
}

Node* insertBeg(Node* head, int num) {
    Node* temp = new Node{num, head};
    return temp;
}

Node* deleteBeg(Node* head) {
    if (head == nullptr) {
        cout << "List is empty";
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    Node* head = create(A, 8);

    cout << "Linked list created: ";
    display(head);

    cout << "\nSearch for element: ";
    search(head, 80);

    cout << "\nInsert at beginning: ";
    head = insertBeg(head, 80);
    display(head);

    cout << "\nDelete from beginning: ";
    head = deleteBeg(head);
    display(head);

    cout << endl;
    return 0;
}

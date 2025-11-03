#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int A[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node{A[0], nullptr};
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node{A[i], nullptr};
        temp = temp->next;
    }
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverse(Node* head) {
    Node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int n = 4;

    Node* head = create(A, n);
    cout << "Original List: ";
    display(head);

    head = reverse(head);
    cout << "Reversed List: ";
    display(head);

    return 0;
}

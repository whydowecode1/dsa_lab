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
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteKey(Node* head, int key, int &count) {
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    int A[] = {1, 2, 1, 2, 1, 3, 1};
    int n = 7, key = 1, count = 0;

    Node* head = create(A, n);
    cout << "Original Linked List: ";
    display(head);

    head = deleteKey(head, key, count);

    cout << "Count: " << count << ", Updated Linked List: ";
    display(head);

    return 0;
}

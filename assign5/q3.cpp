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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    Node* head = create(A, n);
    cout << "Middle element: " << findMiddle(head) << endl;

    return 0;
}

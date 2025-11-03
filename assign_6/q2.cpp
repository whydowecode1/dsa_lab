#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* createCircular(int arr[], int n) {
    if (n == 0) return nullptr;
    Node *head = new Node{arr[0], nullptr};
    Node *last = head;
    for (int i = 1; i < n; i++) {
        Node *temp = new Node{arr[i], nullptr};
        last->next = temp;
        last = temp;
    }
    last->next = head;
    return head;
}

void display(Node *head) {
    if (!head) return;
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    Node *head = createCircular(arr, 5);
    display(head);
    return 0;
}

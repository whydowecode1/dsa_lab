#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* createDoubly(int arr[], int n) {
    if (n == 0) return nullptr;
    Node *head = new Node{arr[0], nullptr, nullptr};
    Node *last = head;
    for (int i = 1; i < n; i++) {
        Node *temp = new Node{arr[i], nullptr, last};
        last->next = temp;
        last = temp;
    }
    return head;
}

void display(Node *head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node *temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void search(Node *head, int key) {
    Node *temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            cout << "Element " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element " << key << " not found.\n";
}

Node* insertAtBeginning(Node *head, int data) {
    Node *temp = new Node{data, head, nullptr};
    if (head) head->prev = temp;
    return temp;
}

Node* insertAtEnd(Node *head, int data) {
    Node *temp = new Node{data, nullptr, nullptr};
    if (!head) return temp;
    Node *p = head;
    while (p->next) p = p->next;
    p->next = temp;
    temp->prev = p;
    return head;
}

Node* insertAfter(Node *head, int key, int data) {
    Node *p = head;
    while (p && p->data != key) p = p->next;
    if (!p) {
        cout << "Node " << key << " not found.\n";
        return head;
    }
    Node *temp = new Node{data, p->next, p};
    if (p->next) p->next->prev = temp;
    p->next = temp;
    return head;
}

Node* insertBefore(Node *head, int key, int data) {
    Node *p = head;
    while (p && p->data != key) p = p->next;
    if (!p) {
        cout << "Node " << key << " not found.\n";
        return head;
    }
    Node *temp = new Node{data, p, p->prev};
    if (p->prev) p->prev->next = temp;
    else head = temp;
    p->prev = temp;
    return head;
}

Node* deleteNode(Node *head, int key) {
    Node *p = head;
    while (p && p->data != key) p = p->next;
    if (!p) {
        cout << "Node not found.\n";
        return head;
    }
    if (p->prev) p->prev->next = p->next;
    else head = p->next;
    if (p->next) p->next->prev = p->prev;
    delete p;
    cout << "Node " << key << " deleted.\n";
    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    Node *head = createDoubly(arr, 5);
    int choice, val, key;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display\n";
        cout << "2. Search\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert After Node\n";
        cout << "6. Insert Before Node\n";
        cout << "7. Delete Node\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> val;
                search(head, val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                head = insertAtBeginning(head, val);
                break;
            case 4:
                cout << "Enter value: ";
                cin >> val;
                head = insertAtEnd(head, val);
                break;
            case 5:
                cout << "Enter node after which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                head = insertAfter(head, key, val);
                break;
            case 6:
                cout << "Enter node before which to insert: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> val;
                head = insertBefore(head, key, val);
                break;
            case 7:
                cout << "Enter node to delete: ";
                cin >> key;
                head = deleteNode(head, key);
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* insertBeg(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insertEnd(Node* head, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) return temp;

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = temp;
    return head;
}

Node* insertBefore(Node* head, int target, int val) {
    if (head == nullptr) return head;

    if (head->data == target)
        return insertBeg(head, val);

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return head;

    Node* temp = new Node(val);
    prev->next = temp;
    temp->next = curr;

    return head;
}

Node* insertAfter(Node* head, int target, int val) {
    Node* curr = head;

    while (curr != nullptr && curr->data != target)
        curr = curr->next;

    if (curr == nullptr) return head;

    Node* temp = new Node(val);
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

Node* deleteBeg(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;

    return head;
}

Node* deleteEnd(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        return nullptr;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    cout << "Deleted: " << curr->data << endl;
    prev->next = nullptr;
    delete curr;

    return head;
}

Node* deleteValue(Node* head, int val) {
    if (head == nullptr) return nullptr;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) return head;

    prev->next = curr->next;
    cout << "Deleted: " << curr->data << endl;
    delete curr;

    return head;
}

void search(Node* head, int val) {
    Node* curr = head;
    int pos = 1;

    while (curr != nullptr) {
        if (curr->data == val) {
            cout << val << " found at position " << pos << endl;
            return;
        }
        curr = curr->next;
        pos++;
    }

    cout << "Value not found.\n";
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, val, target;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert BEFORE a value\n";
        cout << "4. Insert AFTER a value\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific value\n";
        cout << "8. Search a value\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insertBeg(head, val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = insertEnd(head, val);
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                head = insertBefore(head, target, val);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> val;
                head = insertAfter(head, target, val);
                break;

            case 5:
                head = deleteBeg(head);
                break;

            case 6:
                head = deleteEnd(head);
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> val;
                head = deleteValue(head, val);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                search(head, val);
                break;

            case 9:
                display(head);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

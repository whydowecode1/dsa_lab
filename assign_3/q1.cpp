#include <iostream>
#define MAXLEN 100
using namespace std;

class Stack {
private:
    int element[MAXLEN];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAXLEN - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "OVERFLOW\n";
        } else {
            element[++top] = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "UNDERFLOW\n";
        } else {
            --top;
        }
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Empty stack\n";
            return -1;
        } else {
            return element[top];
        }
    }

    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << element[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack S;
    int choice = 0;

    cout << "********* Stack operations using array *********\n";
    cout << "----------------------------------------------\n";

    while (choice != 4) {
        cout << "Choose one from the below options...\n";
        cout << "1. Push\n2. Pop\n3. Show\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int el;
                cout << "Enter an element to push into stack: ";
                cin >> el;
                S.push(el);
                break;
            }
            case 2:
                S.pop();
                break;
            case 3:
                S.print();
                break;
            case 4:
                cout << "Exiting\n";
                break;
            default:
                cout << "Please enter a valid choice.\n";
        }
        cout << endl;
    }

    return 0;
}

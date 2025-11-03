#include <iostream>
#define MAXLEN 100
using namespace std;

class Queue {
private:
    int element[MAXLEN];
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = rearIndex = -1;
    }

    bool isEmpty() const {
        return (frontIndex == -1 || frontIndex > rearIndex);
    }

    bool isFull() const {
        return (rearIndex == MAXLEN - 1);
    }

    int size() const {
        if (isEmpty()) return 0;
        return (rearIndex - frontIndex + 1);
    }

    int front() const {
        if (isEmpty()) {
            cout << "Empty queue\n";
            return -1;
        }
        return element[frontIndex];
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "OVERFLOW\n";
        } 
        else if (isEmpty()) {
            frontIndex = rearIndex = 0;
            element[rearIndex] = x;
        } 
        else {
            rearIndex++;
            element[rearIndex] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "UNDERFLOW\n";
        } 
        else {
            frontIndex++;
        }
    }

    void print() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << element[i] << " ";
        }
    }
};

int main() {
    Queue Q;

    Q.enqueue(5);
    Q.enqueue(3);
    Q.dequeue();
    Q.enqueue(7);
    Q.dequeue();

    cout << "Current queue: ";
    Q.print();
    cout << " with front = " << Q.front() << endl;

    Q.enqueue(9);
    Q.enqueue(3);
    Q.enqueue(1);

    cout << "Current queue: ";
    Q.print();
    cout << " with front = " << Q.front() << endl;

    cout << "Size is " << Q.size() << "." << endl;

    return 0;
}

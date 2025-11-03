#include <queue>
#include <iostream>
using namespace std;

queue<int> q1, q2;

void push(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

void pop()
{
    if (q1.empty())
        return;
    q1.pop();
}

int top()
{
    return q1.empty() ? -1 : q1.front();
}

int size()
{
    return q1.size();
}

int main()
{
    push(1);
    push(2);
    push(3);
    cout << "current size: " << size() << endl;
    cout << top() << endl;
    pop();
    cout << top() << endl;
    pop();
    cout << top() << endl;
    cout << "current size: " << size() << endl;
    return 0;
}
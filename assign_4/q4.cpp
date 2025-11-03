#include <queue>
#include <iostream>
using namespace std;

queue<int> q;

void push(int data)
{
    q.push(data);

    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void pop()
{
    if (q.empty())
    {
        cout << "No elements\n";
    }
    else
    {
        q.pop();
    }
}

int top()
{
    return q.empty() ? -1 : q.front();
}

int size()
{
    return q.size();
}

bool empty()
{
    return q.empty();
}

int main()
{
    push(1);
    push(2);
    push(3);
    cout << "Current size: " << size() << "\n";
    cout << top() << "\n";
    pop();
    cout << top() << "\n";
    pop();
    cout << top() << "\n";
    cout << "Current size: " << size() << "\n";
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> s;

    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    for (int i = 0; i < length; i++)
    {
        s.push(str[i]);
    }

    string reversed = "";
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}

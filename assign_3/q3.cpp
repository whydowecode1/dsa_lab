#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    stack<char> s;
    bool balanced = true;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                balanced = false;
                break;
            }
            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                balanced = false;
                break;
            }
        }
    }

    if (!s.empty())
        balanced = false;

    if (balanced)
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}

#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    stack<int> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            int result;

            switch (ch)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            case '^':
                result = pow(val1, val2);
                break;
            default:
                result = 0;
            }

            s.push(result);
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}

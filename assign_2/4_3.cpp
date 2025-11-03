#include <iostream>
#include <string>
using namespace std;
int main() {
    string s = "beautiful";
    string r = "";
    for (char c : s)
        if (string("aeiouAEIOU").find(c) == string::npos)
            r += c;
    cout << r;
}

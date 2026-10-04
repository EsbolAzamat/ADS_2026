#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main () {
    stack<char> s;
    string a;

    cin >> a;

    for (char x: a) {
        if (s.empty()) {
            s.push(x);
        }
        else if (s.top() != x) {
            s.push(x);
        }
        else s.pop();
    }

    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
#include<iostream>
#include<stack>
#include<string>

using namespace std;




int main() {
    string a;
    cin >> a;
    
    stack<char> s;

    for (char x: a) {
        if (s.empty()) {
            s.push(x);
        }
        else if (s.top() != x) {
            s.push(x);
        }
        else s.pop();
    }

    // while (!s.empty()) {
    //     cout << s.top() << ' ';
    //     s.pop();
    // }
    
    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    // cout << a << endl;
    
    return 0;
}
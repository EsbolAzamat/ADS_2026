#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main () {
    stack<char> s1;
    stack<char> s2;
    
    string a, b;

    cin >> a;
    cin >> b;


    for (char x: a) {
        if (x == '#') {
            if (!s1.empty()) s1.pop();
        }
        else s1.push(x);
    }
    
    for (char x: b) {
        if (x == '#') {
            if (!s2.empty()) s2.pop();
        }
        else s2.push(x);
    }


    bool isSimilar = s1.size() == s2.size();
    while (!s1.empty() && !s2.empty()){
        if (s1.top() != s2.top()) {
            isSimilar = false;
            break;
        }
        s1.pop();
        s2.pop();
    } 

    if (isSimilar) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
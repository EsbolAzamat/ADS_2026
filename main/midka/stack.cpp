#include<iostream>
#include<stack>

using namespace std;

bool check(string line) {
    stack<char> st;

    for (char x: line) {
        if (x == '(' || x == '{' || x == '[') {
            st.push(x);
        }


        if (x == ')' || x == '}' || x == ']') {
            char top = st.top();
            
            if (top == '(' && x == ')' ||
            top == '{' && x == '}' ||
            top == '[' && x == ']') {
                st.pop();
            }
        }
        else st.push(x);
    }

    // while (!st.empty()) {
    //     cout << st.top() << ' ';
    //     st.pop();
    // }
    
    
    if (st.empty()) return true;
    else return false;
}


int main() {
    string line;
    cin >> line;

    if (check(line)) cout << "YES" << endl;
    else cout << "NO" << endl;


    
    return 0;
}
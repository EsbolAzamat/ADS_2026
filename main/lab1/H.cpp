#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main () {
    int N;
    stack<int> s;
    vector<int> res;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;

        while (!s.empty() && cur <= s.top()) s.pop();

        if (s.empty()) res.push_back(-1);
        else res.push_back(s.top());
        
        
        s.push(cur);
    }
   

    for (int x: res) cout << x << ' ';

    return 0;
}
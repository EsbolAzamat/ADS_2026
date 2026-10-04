#include<iostream>
#include<queue>
#include<vector>

using namespace std;


vector<string> func () {
    int freq[26] = {};
    queue<char> q;
    vector<string> res;
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char x;
        cin >> x;   
        
        q.push(x);
        freq[x - 'a']++;
        
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) res.push_back("-1");
        else res.push_back(string(1, q.front()));
    }  
    
    return res;
}


int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        vector<string> ans = func();
        for (string x: ans) cout << x << ' ';   
        cout << endl;
    }



    return 0;
}
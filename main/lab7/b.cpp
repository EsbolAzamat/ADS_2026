#include<iostream>
#include<vector>


using namespace std;


int main() {
    vector<int> res;
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
     
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            res.push_back(a[i]);
            i++;
        }
        else {  
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n) {
        res.push_back(a[i]);
        ++i;
    }
    while (j < m) {
        res.push_back(b[j]);
        j++;
    }

    for (int x: res) cout << x << ' ';
    cout << endl;    
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    vector<int> a1 = {5, 1, 12, 4, 9}, a2 = {3, 15, 6};

    int n = a1.size();
    int m = a2.size();
    
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    vector<int> res;

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a1[i] > a2[j]) {
            res.push_back(a2[j]);
            j++;
        }
        else {
            res.push_back(a1[i]);
            i++;
        }
    }

    cout << i << ' ' << j << endl;
    while (i < n) {
        res.push_back(a1[i]);
        i++;
    }
    while (j < m) {
        res.push_back(a2[j]);
        j++;
    }
    for (int x: res) cout << x << ' ';
    cout << endl;
    return 0;
}
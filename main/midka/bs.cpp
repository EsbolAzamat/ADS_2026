#include<iostream>
#include<vector>

using namespace std;

int lowerBoundCount(vector<int> v, int n, int x) {
    int l = -1;
    int r = n;


    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    
    return r;

}

int UpperBoundCount(vector<int> v, int n, int x) {
    int l = -1;
    int r = n;

    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return r;
}

int main() {
    int n, q;
    cin >> n;


    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;

        int count = UpperBoundCount(v, n, x) - lowerBoundCount(v, n, x);
        cout << count << endl; 
    }

    
    return 0;
}
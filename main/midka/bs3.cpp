#include<iostream>
#include<vector>

using namespace std;

int lowerBound(const vector<int> &v, int n, int L) {
    int l = -1;
    int r = n;

    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] < L) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return r;
}

int uppperBound(const vector<int> &v, int n, int R) {
    int l = -1;
    int r = n;

    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] <= R) {
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
    cin >> n ;ы

    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int count = uppperBound(v, n, r) - lowerBound(v, n, l);
        cout << count << endl;
    }
    
    return 0;
}
#include<iostream>
#include<vector>


using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

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

    if (v[r] == x) cout << r << endl;
    else cout << -1 << endl;

    return 0;
}
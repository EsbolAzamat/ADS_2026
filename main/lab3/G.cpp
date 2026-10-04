#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ropes(n);

    int maxrope = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ropes[i];
        maxrope = max(maxrope, ropes[i]);
    }

    double l = 0;
    double r = maxrope;

    for (int j = 0; j < 100; j++) {
        double m = l + (r - l) / 2;

        
        long long pieces = 0;
        for (int i = 0; i < n; ++i) {
            pieces += (long long)(ropes[i] / m);
        }   

        if (pieces >= k) {
            l = m;
        }
        else {
            r = m;
        }
    }

    cout << fixed << setprecision(9) << l;



    return 0;
}
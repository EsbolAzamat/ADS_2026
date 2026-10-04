#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prefix(n + 1);

    prefix[0] = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }

    int ans = n + 1;
    for (int i = 0; i < n; ++i) {
        int l = i;
        int r = n + 1;

        while (r - l > 1) {
            int m = l + (r - l) / 2;
            
            if (prefix[m] - prefix[i] >= k) {
                r = m;
            }
            else {
                l = m;
            }
        }

        if (r <= n) {
            ans = min(ans, r - i);
        }

    }

    cout << ans << endl;


    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N, target;
    cin >> N >> target;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int r = N;
    int l = -1;

    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] <= target) {
            l = m;
        }
        else {
            r = m;
        }
    }

    if (v[l] == target) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}
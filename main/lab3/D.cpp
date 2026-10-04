#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    vector<int> prefix(N);
    prefix[0] = v[0];
    for (int i = 1; i < N; ++i) {
        prefix[i] = prefix[i - 1] + v[i];
    }
    
    int P;
    cin >> P;

    for (int i = 0; i < P; i++) {
        int M;
        cin >> M;

        int l = -1;
        int r = N;

        while (r - l > 1) {
            int m = l + (r - l) / 2;

            if (v[m] <= M) l = m;
            else r = m;
        }

        if (l == -1) cout << 0 << ' ' <<  0 << endl;
        else cout << l + 1 << ' ' <<  prefix[l] << endl;
    }
    
    return 0;
}
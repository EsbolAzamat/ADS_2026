#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> need(N);

    long long maxNeed = 0;

    for (int i = 0; i < N; ++i) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        need[i] = max(x2, y2);
        maxNeed = max(maxNeed, need[i]);
    }

    long long l = 0;
    long long r = maxNeed;

    while (r - l > 1) {
        long long m = l + (r - l) / 2;

        int sheep = 0;

        for (int i = 0; i < N; ++i) {
            if (need[i] <= m) {
                sheep++;
            }
        }

        if (sheep >= K) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << r << endl;

    return 0;
}
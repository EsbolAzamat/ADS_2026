#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> prefix(N);


    cin >> prefix[0];
    for (int i = 1; i < N; ++i) {
        int x; 
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    for (int i = 0; i < M; ++i) {
        int line;
        cin >> line;

        int l = -1;
        int r = N;

        while(r - l > 1) {
            int m = l + (r - l) / 2;

            if (prefix[m] >= line) {
                r = m;
            }
            else {
                l = m;
            }
        }

        cout << r + 1 << endl;
    }


    return 0;
}
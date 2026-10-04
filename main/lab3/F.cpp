#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {    
    int N, H;
    cin >> N >> H;
    vector<int> v(N);

    int maxBag = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        maxBag = max(maxBag, v[i]);
    }

    int l = 0;
    int r = maxBag;

    while (r - l > 1) {
        int K = l + (r - l) / 2;
        
        int hourse = 0;
        for (int i = 0; i < N; ++i) {
            hourse += (v[i] + K - 1) / K;
        }

        if (hourse <= H) {
            r = K;
        }
        else {
            l = K;
        }
    }

    cout << r << endl;
    return 0;
}
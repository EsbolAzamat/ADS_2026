#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, target;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    cin >> target;
    
    int l = -1;
    int r = N;
    
    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (a[m] == target) {
            cout << "Yes" << endl;
            return 0;
        }
        
        if (a[m] > target) {
            r = m;
        }
        else {
            l = m;
        }
    }

    cout << "No" << endl;
    return 0;
}
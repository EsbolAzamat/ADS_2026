#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int func(vector<int>& v, int x) {
    int l = -1;
    int r = v.size();

    while (r - l > 1) {
        int m = l + (r - l) / 2;

        if (v[m] <= x) l = m;
        else r = m;
    }

    return l + 1;
}


int main() {
    int N, q;
    cin >> N >> q;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int count1 = func(v, r1) - func(v, l1 - 1);       
        int count2 = func(v, r2) - func(v, l2 - 1);
        int count = count1 + count2;

        int left = max(l1 , l2);
        int right = min(r1, r2);

        if (right >= left) {
            int both = func(v, right) - func(v, left - 1);
            count -= both;
        }

        cout << count << endl;
    }
    
    
    return 0;
}
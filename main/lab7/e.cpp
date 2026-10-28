#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;
    int k = n - 1;

    while (left <= right) {
        int l = arr[left] * arr[left];
        int r = arr[right] * arr[right];

        if (l > r) {
            res[k] = l;
            left++;
        }
        else {
            res[k] = r;
            right--;
        }
        k--;
    }

    for (int x: res) cout << x << ' ';
    cout << endl;
    return 0;
}
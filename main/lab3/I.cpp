#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);

    long long sum = 0;
    long long maxHouse = 0;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        maxHouse = max(maxHouse, v[i]);
    }

    long long r = sum;
    long long l = maxHouse - 1;

    while (r - l > 1) {
        long long m = l + (r - l) / 2;

        int blocks = 1;
        long long currentSum = 0;

        for (int i = 0; i < n; ++i) {
            if (currentSum + v[i] <= m) {
                currentSum += v[i];
            }
            else {
                blocks++;
                currentSum = v[i];
            }

        }

        if (blocks <= k) {
            r = m;
        }
        else {
            l = m;
        }
    }


    cout << r << endl;


    return 0;
}
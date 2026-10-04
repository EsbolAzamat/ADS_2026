#include <iostream>

using namespace std;

int main() {
    long long a, m, n;
    cin >> a >> m >> n;

    long long res = 1;
    a %= n;

    while (m > 0) {
        if (m % 2 == 0) {
            m /= 2;
            a = a * a % n;
        }
        else {
            res = res * a % n;
            m -= 1;
        }
    }

    cout << res % n << endl;
    return 0;
}
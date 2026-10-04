#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;

    bool IsPrime = true;
    for (int i = 2; a >= i * i; i++) {
        if (a % i == 0) {
            IsPrime = false; 
        }
    }

    if (!IsPrime || a == 1) cout << "NO" << endl;
    else cout << "YES" << endl;


    return 0;
}
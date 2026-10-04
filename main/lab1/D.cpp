#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int x) {
    bool isprime = x >= 2;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            isprime = false;
            break;
        }
    }
    return isprime;
}


int main () {
    int n;
    int counter = 0;

    cin >> n;
    
    int x = 2;   
    while (counter < n) {
        if (IsPrime(x)) {
            counter ++;
        }
        x++;
    }
    cout << x - 1 << endl;

    
    return 0;
}
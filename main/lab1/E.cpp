#include <iostream>
#include <vector>

using namespace std;

vector<long long> primeFactor (long long n) {
    vector<long long> factors;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}
   

int main () {
    long long n;
    cin >> n;

    vector<long long> factors= primeFactor(n);
    
    for (long long x : factors) {
        cout << x << " ";
    }

    
    return 0;
}
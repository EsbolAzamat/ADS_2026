#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main () {
    deque<int> d1;
    deque<int> d2;

    for (int i = 0; i < 5; i++) {
        int x; 
        cin >> x;
        d1.push_back(x);
    }

    for (int i = 0; i < 5; i++) {
        int x; 
        cin >> x;
        d2.push_back(x);
    }

    int count = 0;
    while (!d1.empty() && !d2.empty()) {
        int d1_f = d1.front();
        int d2_f = d2.front();

        d2.pop_front();
        d1.pop_front();

        if ((d1_f > d2_f && !(d1_f == 9 && d2_f == 0)) || (d1_f == 0 && d2_f == 9)) {
            d1.push_back(d1_f);
            d1.push_back(d2_f);
        }
        else { 
            d2.push_back(d1_f);
            d2.push_back(d2_f);
        }
        count++;
    }

    if (d1.empty()) cout << "Nursik" << " " << count << endl;
    else cout << "Boris" << " " << count << endl;
    return 0;
}

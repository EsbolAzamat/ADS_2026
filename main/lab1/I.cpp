#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> func(int N) {
    deque<int> deq;
    int i = 0;
    while (N != i) {
        deq.push_front(N-i);
        for (int j = 0; j < N-i; ++j) {
            int temp = deq.back();
            deq.pop_back();
            deq.push_front(temp);
        }
        i++;
    }
    return deq;
}

int main () {
    int T;
    deque<int> deq;
    cin >> T;
    
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        deq = func(N);
        while (!deq.empty()) {
            cout << deq.front() << ' ';
            deq.pop_front();
        }
    }

    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> arr) {
    for (int x: arr) cout << x << ' ';
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    vector<int> L(n), R(m);
    
    for (int i = 0; i < n; ++i)
        L[i] = arr[i + left];
    for (int i = 0; i < m; ++i)
        R[i] = arr[i + mid + 1];

    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        k++;
    }

    while (i < n) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < m) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    vector<int> arr = {7, 3, 8, 9, 2, 1, 11, 37, 34, 18, 84, 24, 81, 88, 66, 25, 72};
    int n = arr.size();
    
    mergeSort(arr, 0, n - 1);
    print(arr);

    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

long long merge(vector<int> &arr, int left, int mid, int right) {
    int n = mid - left + 1;
    int m = right - mid;

    vector<int> L(n), R(m);

    for (int i = 0; i < n; ++i) 
        L[i] = arr[i + left];
    for (int i = 0; i < m; ++i)
        R[i] = arr[mid + i + 1];


    int i = 0, j = 0;
    int k = left;

    long long count = 0;
    while (i < n && j < m) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            count += n - i;
            arr[k] = R[j];
            j++;
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

    return count;
}

long long mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;
    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
 
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << mergeSort(arr, 0, n - 1) << endl;
    return 0;
}
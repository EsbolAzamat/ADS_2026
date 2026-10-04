#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> targets(t);
    for (int i = 0; i < t; ++i) {
        cin >> targets[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int q = 0; q < t; ++q) {
        int target = targets[q];


        int l = -1;
        int r = n;

        while (r - l > 1) {
            int mid = l + (r - l) / 2;

            int rowMax;

            if (mid % 2 == 0) {
                rowMax = a[mid][0];
            }
            else {
                rowMax = a[mid][m - 1];
            }

            if (rowMax >= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }

        int row = l;

        if (row == -1) {
            cout << -1 << '\n';
            continue;
        }


        int rowMin, rowMax;

        if (row % 2 == 0) {
            rowMax = a[row][0];
            rowMin = a[row][m - 1];
        }
        else {
            rowMin = a[row][0];
            rowMax = a[row][m - 1];
        }

        if (target < rowMin || target > rowMax) {
            cout << -1 << '\n';
            continue;
        }


        int left = -1;
        int right = m;

        if (row % 2 == 0) {
            
            while (right - left > 1) {
                int mid = left + (right - left) / 2;

                if (a[row][mid] > target) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
        }
        else {

            while (right - left > 1) {
                int mid = left + (right - left) / 2;

                if (a[row][mid] < target) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
        }

        if (right < m && a[row][right] == target) {
            cout << row << ' ' << right << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
        }
    }
    int max_dia = INT_MIN;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            int s = arr[i][j];
            for (int k = 1;k < n;k++) {
                if (i + k < n && j + k < n) s += arr[i + k][j + k];
                if (max_dia < s) max_dia = s;
            }
        }
    }
    cout << max_dia;
}
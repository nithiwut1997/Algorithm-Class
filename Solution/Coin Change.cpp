#include <bits/stdc++.h>

using namespace std;

int coinChange(int arr[], int n, int m) {
    int c[n + 1][m + 1];
    for (int i = 1;i <= n;i++) c[i][1] = 1;
    for (int i = 1;i <= m;i++) c[1][i] = i;
    for (int i = 2;i <= n;i++) {
        for (int j = 2;j <= m;j++) {
            if (arr[i] == j) c[i][j] = 1;
            else if (arr[i] > j) c[i][j] = c[i - 1][j];
            else c[i][j] = min(c[i - 1][j], 1 + c[i][j - arr[i]]);
        }
    }
    return c[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    for (int i = n;i > 0;i--) cin >> arr[i];
    cout << coinChange(arr, n, m);
}
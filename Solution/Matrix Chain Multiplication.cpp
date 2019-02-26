#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 1], dp[n + 1][n + 1];
    for (int i = 0;i <= n;i++) cin >> arr[i];
    for (int i = 0;i <= n;i++) dp[i][i] = 0;
    for (int j = 2;j <= n;j++) {
        for (int i = j - 1;i >= 1;i--) {
            dp[i][j] = dp[i][i] + dp[i + 1][j] + arr[i - 1]*arr[i]*arr[j];
            for (int k = 1;k < j - i;k++) {
                dp[i][j] = min(dp[i][j], dp[i][i + k] + dp[i + k + 1][j] + arr[i - 1]*arr[i + k]*arr[j]);
            }
        }
    }
    cout<< dp[1][n];
}
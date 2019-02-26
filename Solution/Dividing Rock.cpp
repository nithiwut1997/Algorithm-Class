#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int dp[n + 1][k + 1];
    for (int i = 1;i <= n;i++) dp[i][1] = 1;
    for (int i = 2;i <= k;i++) dp[i][i] = 1;
    for (int i = 3;i <= n;i++) {
        for (int j = 2;j <= k && j < i;j++) {
            dp[i][j] = (dp[i - 1][j]*j) % 1997 + (dp[i - 1][j - 1]) % 1997;
        }
    }
    cout << dp[n][k] % 1997;
}
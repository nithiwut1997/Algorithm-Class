#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, ans = INT_MAX;
    cin >> n >> k;
    int arr[n + 1], dp[n + 1];
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        if (i <= k + 1) dp[i] = arr[i];
    }
    for (int i = k + 2;i <= n;i++) {
        dp[i] = dp[i - 1] + arr[i];
        for (int j = i - 2;j >= 1 && j >= i - 2*k - 1;j--) {
            dp[i] = min(dp[i], dp[j] + arr[i]);
        }
    }
    for (int i = n;i >= n - k && i >= 1;i--) {
        if (ans > dp[i]) ans = dp[i];
    }
    cout << ans;
}
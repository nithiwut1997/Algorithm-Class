#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int dp[4001];
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int A, B, C;
    for (int i = 2;i <= n;i++) {
        A = (i - a < 0) ? 0 : i - a;
        B = (i - b < 0) ? 0 : i - b;
        C = (i - c < 0) ? 0 : i - c;
        if (dp[A] > 0 || dp[B] > 0 || dp[C] > 0) dp[i] = max(dp[A], dp[B], dp[C]) + 1;
        else dp[i] = (i == a || i == b || i == c) ? 1 : 0;
    }
    cout << dp[n];
}
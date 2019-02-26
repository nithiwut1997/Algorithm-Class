#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m], s[n][m];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
            if (i == 0 && j == 0) s[i][j] = arr[i][j];
        }
    }
    for (int i = 1;i < n;i++) s[i][0] = s[i - 1][0] + arr[i][0];
    for (int i = 1;i < m;i++) s[0][i] = s[0][i - 1] + arr[0][i];
    for (int i = 1;i < n;i++) {
        for (int j = 1;j < m;j++) {
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + arr[i][j];
        }
    }
    for (int i = 0;i < k;i++) {
        int r1, c1, r2, c2, ans;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == 0 && c1 == 0) ans = s[r2][c2];
        else if (r1 == 0 && c1 != 0) ans = s[r2][c2] - s[r2][c1 - 1];
        else if (r1 != 0 && c1 == 0) ans = s[r2][c2] - s[r1 - 1][c2];
        else ans = s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1];
        cout << ans << "\n";
    }
}
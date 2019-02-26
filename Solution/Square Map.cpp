#include <bits/stdc++.h>

using namespace std;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {
    int r, c;
    cin >> r >> c;
    string arr[r + 1];
    int map[r + 1][c + 1];
    for (int i = 1;i <= r;i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0;i <= r;i++) map[i][0] = 0;
    for (int i = 1;i <= c;i++) map[0][i] = 0;
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            if (arr[i][j - 1] - '0' == 1) {
                map[i][j] = 1 + min(map[i - 1][j], map[i - 1][j - 1], map[i][j - 1]);
                if (map[i][j] > ans) ans = map[i][j];
            }
            else map[i][j] = 0;
        }
    }
    cout << ans;
}
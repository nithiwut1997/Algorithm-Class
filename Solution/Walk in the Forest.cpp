#include <bits/stdc++.h>

using namespace std;

int walk_int_forest(vector<vector<int>> &arr, int n, int m) {
    int s[n + 1][m + 1];
    s[1][1] = arr[0][0];
    for (int i = 2;i <= n;i++) s[i][1] = s[i - 1][1] + arr[i - 1][0];
    for (int i = 2;i <= m;i++) s[1][i] = s[1][i - 1] + arr[0][i - 1];
    for (int i = 2;i <= n;i++) {
        for (int j = 2;j <= m;j++) {
            int up_left = max(s[i - 1][j] + arr[i - 1][j - 1], s[i][j - 1] + arr[i - 1][j - 1]);
            int diagonal = s[i - 1][j - 1] + 2*arr[i - 1][j - 1];
            s[i][j] = max(up_left, diagonal);
        }
    }
    return s[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> forest;
    for (int i = 1;i <= n;i++) {
        vector<int> v;
        for (int j = 1;j <= m;j++) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        forest.push_back(v);
    }

    cout << walk_int_forest(forest, n, m);
}

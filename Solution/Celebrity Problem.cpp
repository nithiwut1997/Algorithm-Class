#include <bits/stdc++.h>

using namespace std;

int celeb(vector<vector<int>> &k, int left, int right) {
    if (left == right) return left;
    int b, s_a;
    if (k[left][right] == 1) {
        s_a = celeb(k, left + 1, right);
        b = left;
    }
    else {
        s_a = celeb(k, left, right - 1);
        b = right;
    }
    if (s_a > 0 && k[s_a][b] == 0 && k[b][s_a] == 1) return s_a;
    else return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> k;
    for (int i = 0;i < n;i++) {
        vector<int> temp;
        for (int j = 0;j < n;j++) {
            int t;
            scanf("%d", &t);
            temp.push_back(t);
        }
        k.push_back(temp);
    }
    int c = celeb(k, 0, n - 1);
    if (c < 0) cout << 0;
    else cout << c + 1;
}
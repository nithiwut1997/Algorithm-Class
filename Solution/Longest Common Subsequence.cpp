#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    string a, b;
    cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();
    int lcs[len_a + 1][len_b + 1];
    for (int i = 0;i <= len_a;i++) lcs[i][0] = 0;
    for (int i = 1;i <= len_b;i++) lcs[0][i] = 0;
    for (int i = 1;i <= len_a;i++) {
        for (int j = 1;j <= len_b;j++) {
            if (a.compare(i - 1, 1, b, j - 1, 1) == 0) lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else lcs[i][j] = max(max(lcs[i - 1][j], lcs[i][j - 1]), lcs[i - 1][j - 1]);
        }
    }
    cout << lcs[len_a][len_b];
}
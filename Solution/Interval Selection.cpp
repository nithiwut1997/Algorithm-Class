#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f, ans = 1;
    cin >> n;
    int s[n + 1];
    set<pair<int, int>> sortByFinal;
    for (int i = 1;i <= n;i++) cin >> s[i];
    for (int i = 1;i <= n;i++) {
        pair<int, int> temp;
        cin >> f;
        temp.first = f;
        temp.second = s[i];
        sortByFinal.insert(temp);
    }
    auto left = sortByFinal.begin();
    auto right = ++sortByFinal.begin();;
    while (right != sortByFinal.end()) {
        if ((*right).second >= (*left).first) {
            ans++;
            left = right;
        }
        right++;
    }
    cout << ans;
}
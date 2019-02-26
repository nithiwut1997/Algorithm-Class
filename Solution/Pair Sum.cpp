#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    unordered_set<int> s;
    for (int i = 0;i < n;i++) {
        int t;
        cin >> t;
        s.insert(t);
    }
    for (int i = 0;i < m;i++) {
        int q;
        cin >> q;
        bool found = false;
        for (auto it = s.begin();it != s.end();it++) {
            int diff = q - *it;
            if (diff >= 0 && s.find(diff) != s.end()) {
                cout << "YES\n";
                found = true;
                break;
            }
       }
        if (!found) cout << "NO\n";
    }
}
#include <bits/stdc++.h>

using namespace std;

int timeSubmit[101];
int main() {
    int n, m, temp;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 1;i <= m;i++) {
        cin >> temp;
        s.insert(temp);
    }
    int idx = 0;
    double sumTime = 0;
    for (int t : s) {
        timeSubmit[idx % n] += t;
        sumTime += timeSubmit[idx % n];
        idx++;
    }
    cout << fixed << setprecision(3) << sumTime / m;
}
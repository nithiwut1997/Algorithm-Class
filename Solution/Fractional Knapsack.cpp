#include <bits/stdc++.h>

using namespace std;

double v[100001], w[100001];
int main() {
    double weight;
    int n;
    cin >> weight >> n;
    for (int i = 1;i <= n;i++) cin >> v[i];
    for (int i = 1;i <= n;i++) cin >> w[i];
    priority_queue<pair<double, int>> a;
    double sumWeight = 0, ans = 0;
    for (int i = 1;i <= n;i++) {
        pair<double, int> t;
        t.first = v[i] / w[i];
        t.second = i;
        a.push(t);
    }
    for (int i = 1; i <= n; i++) {
         int idx = a.top().second;
        if (w[idx] + sumWeight < weight) {
            sumWeight += w[idx];
            ans += v[idx];
        }
        else {
            double use = weight - sumWeight;
            sumWeight += use;
            ans += (use * v[idx]) / w[idx];
        }
        a.pop();
    }
    cout << fixed << setprecision(4) << ans;
}
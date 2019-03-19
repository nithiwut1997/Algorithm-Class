#include <bits/stdc++.h>

using namespace std;

int n, e, k, a, b;
vector<int> graph[1001];
int state[1001], layer[1001];
queue<int> q;
int main() {
    cin >> n >> e >> k;
    for (int i = 1;i <= e;i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int front, count = 0;
    q.push(0);
    state[0] = 1;
    while (!q.empty()) {
        front = q.front();
        q.pop();
        for (int v : graph[front]) {
            if (state[v] == 0) {
                q.push(v);
                layer[v] = layer[front] + 1;
                state[v] = 1;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        if (layer[i] == k) count++;
    }
    cout << count;
}
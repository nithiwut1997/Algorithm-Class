#include <bits/stdc++.h>

using namespace std;

int n, x, y;
vector<int> graph[100000];
int state[100000], len[100000];

void dfs(int node, int parent) {
    state[node] = 1;
    for (int v : graph[node]) {
        if (state[v] == 0 && v != parent) {
            len[v] = len[node] + 1;
            dfs(v, node);
        }
        if (state[v] == 1 && v != parent) {
            x = v;
            y = node;
        }
    }
    state[node] = 2;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(0, -1);
    cout << len[y] - len[x] + 1;
}

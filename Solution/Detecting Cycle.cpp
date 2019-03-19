#include <bits/stdc++.h>

using namespace std;

int t, n, e, node1, node2;
vector<int> graph[1000];
int state[1000];

bool hasCycle(int node, int parent) {
    state[node] = 1;
    for (int v : graph[node]) {
        if (state[v] == 1 && parent != v) return true; 
        if (state[v] == 0) {
            if (hasCycle(v, node)) return true;
        }
    }
    state[node] = 2;
    return false;
}

bool hasCycle() {
    for (int i = 0;i < n;i++) state[i] = 0;
    for (int i = 0;i < n;i++) {
        if (hasCycle(i, -1)) return true;
    }
    return false;
}

int main() {
    cin >> t;
    for (int l = 1;l <= t;l++) {
        cin >> n >> e;
        for (int i = 1;i <= e;i++) {
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        if (hasCycle()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        for (int i = 0;i < n;i++) graph[i].clear();
    }
}
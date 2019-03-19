#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1000];
int state[1000];
stack<int> topological;

void dfs(int root, int state[]) {
    state[root] = 1;
    for (int v : graph[root]) {
        if (state[v] == 0) dfs(v, state);
    }
    topological.push(root);
}

void dfs(int &n) {
    for (int i = 0;i < n;i++) {
        if (state[i] == 0) {
            dfs(i, state);
        }
    }
}

int main() {
    int n, m, preRequire, root;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> m;
        for (int j = 1;j <= m;j++) {
            cin >> preRequire;
            graph[preRequire].push_back(i);
        }
    }
    dfs(n);
    for (int i = 0;i < n;i++) {
        cout << topological.top() << " ";
        topological.pop();
    }
}
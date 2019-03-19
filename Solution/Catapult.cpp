#include <bits/stdc++.h>

using namespace std;

int n, m, sendTo;
vector<int> graph[1000];
vector<int> graph_T[1000];
int state[1000];
stack<int> nodeStart;
vector<int> countNode;

void dfs(vector<int> G[], int node, int status) {
    state[node] = 1;
    for (int v : G[node]) {
        if (state[v] == 0) dfs(G, v, status);
    }
    if (status == 0) nodeStart.push(node);
    else countNode.push_back(node);
}

void dfs(vector<int> G[]) {
    for (int i = 0;i < n;i++) {
        if (state[i] == 0) dfs(G, i, 0);
    }
}

int main() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> m;
        for (int j = 1;j <= m;j++) {
            cin >> sendTo;
            graph[sendTo].push_back(i);
            graph_T[i].push_back(sendTo);
        }
    }
    dfs(graph);
    int start;
    multiset<int> ans;
    for (int i = 0;i < n;i++) state[i] = 0;
    for (int i = 0;i < n;i++) {
        start = nodeStart.top();
        nodeStart.pop();
        if (state[start] == 0) {
            dfs(graph_T, start, 1);
            ans.insert(countNode.size());
            countNode.clear();
        }
    }
    for (int a : ans) cout << a << " ";
}
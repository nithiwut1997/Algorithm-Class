#include <bits/stdc++.h>

using namespace std;

int n, e, a, b, plan;
vector<int> graph[1001];
bool usedToDo[1001];
queue<int> step;

bool success(int node) {
    for (int v : graph[node]) {
        if (!usedToDo[v]) return false;
    }
    return true;
}

int main() {
    cin >> n >> e;
    for (int i = 0;i < e;i++) {
        cin >> a >> b;
        graph[b].push_back(a);
    }
    for (int i = 1;i <= 5;i++) {
        bool isSuccess = true;
        for (int j = 1;j <= n;j++) {
            cin >> plan;
            step.push(plan);
        }
        while (!step.empty()) {
            plan = step.front();
            step.pop();
            if (success(plan)) usedToDo[plan] = true;
            else isSuccess = false;
        }
        for (int j = 1;j <= n;j++) usedToDo[j] = false;
        if (isSuccess) cout << "SUCCESS" << '\n';
        else cout << "FAIL" << '\n';
    }
}
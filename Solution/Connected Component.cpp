#include <bits/stdc++.h>

using namespace std;

int v, e, a, b;
vector<int> graph[10001];
int state[10001];
queue<int> q;
int main() {
    cin >> v >> e;
    for (int i = 1;i <= e;i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int front, count = 0;
    for (int i = 1;i <= v;i++) {
        if (state[i] == 0) {
            q.push(i);
            count++;
            state[i] = 1;
            while (!q.empty()) {
                front = q.front();
                q.pop();
                for (int vertex : graph[front]) {
                    if (state[vertex] == 0) {
                        q.push(vertex);
                        state[vertex] = 1;
                    }
                }
            }
        }
    }
    cout << count;
}
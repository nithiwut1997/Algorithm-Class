#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[100][100];
int main() {
    int r, c;
    cin >> r >> c;
    char grid[r][c];
    int layer[r][c];
    pair<int, int> temp;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> grid[i][j];
            if (j > 0 && grid[i][j] == '.' && grid[i][j - 1] == '.') {
                temp.first = i; temp.second = j - 1;
                graph[i][j].push_back(temp);
                temp.second = j;
                graph[i][j - 1].push_back(temp);
            }
            if (i > 0 && grid[i][j] == '.' && grid[i - 1][j] == '.') {
                temp.first = i - 1; temp.second = j;
                graph[i][j].push_back(temp);
                temp.first = i;
                graph[i - 1][j].push_back(temp);
            }
            if (grid[i][j] == '.') layer[i][j] = -1;
            else layer[i][j] = -2;
        }
    }
    queue<pair<int, int>> q;
    temp.first = 0; temp.second = 0;
    q.push(temp);
    layer[0][0] = 0;
    while (!q.empty()) {
        temp = q.front(); q.pop();
        for (auto p : graph[temp.first][temp.second]) {
            if (layer[p.first][p.second] == -1) {
                q.push(p);
                layer[p.first][p.second] = layer[temp.first][temp.second] + 1;
            }
        }
    }
    cout << layer[r - 1][c - 1];
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int v[n + 1], w[n + 1];
    int arr[n + 1][m + 1];
    for (int i = 1;i <= n;i++) cin >> v[i];
    for (int i = 1;i <= n;i++) cin >> w[i];
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= m;j++) {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    int ans[n];
    while(n > 0 && m > 0){
        if(m >= w[n] && arr[n][m] == v[n] + arr[n-1][m-w[n]]){
            ans[count++] = n;
            m -= w[n];
        }
        n--;
    }
    cout << count << "\n";
    for (int i = 0;i < count;i++) cout << ans[i] << " ";
}
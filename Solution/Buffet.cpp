#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int main() {
    int f, w, n, t;
    cin >> f >> w >> n;
    for (int i = 1;i <= f;i++) {
        int t;
        cin >> t;
        arr[t] = 1;
    }
    int i = 1, ans = 0;
    while (i <= n) {
        if (arr[i] == 1) {
            ans++;
            i += 2*w;
        }
        i++;
    } 
    cout << ans;
    for (int i = 1;i <= n;i++) cout << arr[i] << " ";
}
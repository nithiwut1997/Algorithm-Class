#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], lis[n];
    for (int i = 0;i < n;i++) cin >> arr[i];
    lis[0] = 1;
    int ans = 1;
    for (int i = 1;i < n;i++) {
        lis[i] = 1;
        for (int j = 0;j < i;j++) {
            if (arr[j] < arr[i] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                if (lis[i] > ans) ans = lis[i];
            }
        }
    }
    cout << ans;
}
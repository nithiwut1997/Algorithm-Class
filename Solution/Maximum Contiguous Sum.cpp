#include <bits/stdc++.h>

using namespace std;

int mcs(int arr[], int n) {
    int p[n + 1], s[n + 1];
    p[1] = arr[1];
    s[1] = arr[1];
    for (int i = 2;i <= n;i++) {
        p[i] = max(p[i - 1] + arr[i], arr[i]);
        s[i] = max(s[i - 1], p[i]);
    }
    return s[n];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    cout << mcs(arr, n);
}
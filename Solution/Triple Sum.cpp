#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    for (int i = 0;i < m;i++) {
        int q;
        cin >> q;
        bool found = false;
        for (int j = 0;j < n - 2;j++) {
            int left = j + 1;
            int right = n - 1;
            while (left < right) {
                if (arr[j] + arr[left] + arr[right] == q) {
                    cout << "YES\n";
                    found = true;
                    break;
                }
                else if (arr[j] + arr[left] + arr[right] < q) left++;
                else right--;
            }
            if (found) break;
        }
        if (!found) cout << "NO\n";
    }
}
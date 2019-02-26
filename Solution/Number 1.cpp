#include <bits/stdc++.h>

using namespace std;

int num, le, ri;

int scale(int n) {
    int t = log(n)/log(2) + 1;
    return pow(2, t) - 1;
}

int number_one(int n, int l, int r) {
    if (r < le || l > ri) return 0;
    if (n < 2) return n;
    int mid = (l + r) / 2;
    int one = number_one(n/2, l, mid - 1) + number_one(n/2, mid + 1, r);
    if (mid >= le && mid <= ri && n%2 == 1) one++;
    return one;
}

int main() {
    cin >> num >> le >> ri;
    cout << number_one(num, 1, scale(num));
}
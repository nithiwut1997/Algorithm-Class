#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> A;

vector<int> pareto(int l,int r) {
    //trivial case
    if (r - l <= 0) {
        vector<int> R;
        for (int i = l;i <= r;i++) R.push_back(i);
        return R;
    }

    //divide
    int m = (l + r) / 2;
    
    //recursive
    vector<int> R1,R2;
    R1 = pareto(l,m);
    R2 = pareto(m+1,r);

    //merge
    vector<int> R;
    for (auto i = R1.begin();i != R1.end();i++) {
        if (A[*i].second > A[*(R2.begin())].second) {
            R.push_back(*i);
        }
    }
    for (auto i = R2.begin();i != R2.end();i++) {
        R.push_back(*i);
    }

    //write your code here
    
    return R;
}

int main() {
    int n;
    scanf("%d",&n);
    A.resize(n);
    for (int i = 0;i < n;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        A[i].first = x;
        A[i].second = y;
    }

    sort(A.begin(),A.end());

    vector<int> result = pareto(0,n-1);

    printf("%d\n",(int)result.size());
}
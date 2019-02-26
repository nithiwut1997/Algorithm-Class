#include <iostream>

using namespace std;

int powerMod(long x,long n,long k){
    if(n == 0) return 1;
    int tmp = powerMod(x,n/2,k);
    if(n%2 == 0){
        return (tmp*tmp)%k;
    }
    return (x*tmp*tmp)%k;
}

int main()
{
    long x,n,k;
    cin>>x>>n>>k;
    cout<<powerMod(x,n,k);
}
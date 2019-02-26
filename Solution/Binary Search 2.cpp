#include <iostream>
#define endl "\n"

using namespace std;

int searchNear(int search[],int left,int right,int xi){
    if(xi < search[left]) return -1;
    if(xi > search[right]) return search[right];
    int mid = (left+right)/2;
    if(search[mid] == xi) return xi;
    else if(search[mid] < xi){
        if(search[mid+1] > xi){
            return search[mid];
        }
        return searchNear(search,mid+1,right,xi);
    }
    else{
        return searchNear(search,left,mid-1,xi);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int search[n];
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        search[i] = tmp;
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        int out = searchNear(search,0,n-1,tmp);
        cout<<out<<endl;
    }
}
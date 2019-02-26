#include <cstdio>

int n,m;
int arr[1000000];

int binarySearchNear(int left,int right,int value){
    if(arr[left] > value) return -1;
    if(arr[right] <= value) return right;
    int mid = (left+right)/2;
    if(arr[mid] == value){
        if(arr[mid+1] != value){
            return mid;
        }
        return binarySearchNear(mid+1,right,value);
    }
    if(arr[mid] > value){
        return binarySearchNear(left,mid-1,value);
    }
    else{
        if(arr[mid+1] > value){
            return mid;
        }
        return binarySearchNear(mid+1,right,value);
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        arr[i] = t;
    }
    for(int i=0;i<m;i++){
        int value;
        scanf("%d",&value);
        int ans = binarySearchNear(0,n-1,value);
        printf("%d\n",ans);
    }
}

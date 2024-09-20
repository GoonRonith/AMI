#include<stdio.h>
int max(int x,int y){
    if(x>y) return x;
    return y;
}
int main(){
    int a[]={1,4,2,4,6};
    int k=3;
    int n=5;
    int i,j=0;
    int preSum=0;
    int len=0;
    int map[1000]={-1};
    for(int i=1;i<1000;i++){
        map[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        preSum+=a[i];
        int mod=preSum%k;
        if(mod==0) len=i+1;
        if(map[mod]!=-1){
            len=max(len,i-map[mod]+1);
        }
        if(map[preSum]==-1){
            map[preSum]=i+1;
        }
        
    }
    printf("%d",len);
    
}
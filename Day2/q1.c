#include<stdio.h>
int max(int x,int y){
    if(x>y) return x;
    return y;
}
int main(){
    int a[]={1,4,2,6,4}; 
    int k=3;              
    int n=5;              
    int preSum=0;
    int len=0;
    int map[1000];        

    
    for(int i=0; i<1000; i++){
        map[i] = -1;
    }
    
    map[0] = 0;  

    for(int i=0; i<n; i++){
        preSum += a[i];
        int mod = preSum % k;

        if(map[mod] != -1){
            len = max(len, i - map[mod] + 1);
        } else {
            map[mod] = i + 1;  
        }
    }
    
    printf("%d\n", len);  
    return 0;
}

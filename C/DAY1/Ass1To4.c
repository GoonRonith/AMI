#include<stdio.h>
void func1(){
    int lower=0;
    int upper=5;
    int sum=0;
    for(int i=lower;i<=upper;i++){
        if(i%2!=0) sum+=i*i;
    }
    printf("\naddition from func1()->%d",sum);
}
int func2(){
    int lower=0;
    int upper=5;
    int sum=0;
    for(int i=lower;i<=upper;i++){
        if(i%2!=0) sum+=i*i;
    }
    return sum;
}
void func3(int l,int u){
    int sum=0;
    for(int i=l;i<=u;i++){
        if(i%2!=0) sum+=i*i;
    }
    printf("\naddition from func3()->->%d",sum);
}
int func4(int l,int u){
    int sum=0;
    for(int i=l;i<=u;i++){
        if(i%2!=0) sum+=i*i;
    }
    return sum;
}
int main(){
    int lower=0;
    int upper=20;
    func1();
    printf("\naddition from func2()->%d",func2());
    func3(10,20);
    printf("\naddition from func4()->%d",func4(10,20));
}
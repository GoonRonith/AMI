#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p,*q;
    p=(int *)malloc(4);
    *p=10;
    printf("\n%d %p",*p,p);
    // p=NULL;
    free(p);
    q=(int *)malloc(4);
    *q=20;
    printf("\n%d %p",*q,q);
    printf("\n%d %p",*p,p);
    *p=100;
    printf("\n%d %p",*p,p);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[],int size){
for(int i=0;i<size;i++){
    for(int j=0;j<size-i+1;j++){
        if(arr[j] > arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
}
int main(){
    int size;
    printf("\n enter the size->");
    scanf("%d",&size);
    int *arr=(int *)malloc(size);
    printf("\nEnter the array elements->");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
       printf("\nbefore sorting:");
    for(int i=0;i<size;i++){
        printf("\t%d",arr[i]);
    }
    bubbleSort(arr,5);
    printf("\nAfter sorting:");
    for(int i=0;i<size;i++){
        printf("\t%d",arr[i]);
    }
}
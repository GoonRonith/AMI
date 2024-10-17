#include<stdio.h>
#include<stdlib.h>
void replaceOldElmentsWithNew(int arr[],int size){
    printf("\nEnter new array elements");
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter new element at index %d->",i);
        scanf("%d",&arr[i]);
    } 
     printf("\n replace  is done");
}
void printAllElements(int arr[],int size){
    printf("\n All the array elements are->");
    for (int i = 0; i < size; i++)
    {
        printf("\t%d",arr[i]);
    }
    
}

void onlyOddNumbers(int arr[],int size){
    printf("\nOnly the odd elements of the array is->");
    for (int  i = 0; i < size; i++)
    {
        if(arr[i]%2!=0) printf("\t%d",arr[i]);
    }
    
}

void onlyEvenNumbers(int arr[],int size){
    printf("\nOnly the Even elements of the array is->");
    for (int  i = 0; i < size; i++)
    {
        if(arr[i]%2==0) printf("\t%d",arr[i]);
    }
    
}

void reverseArray(int arr[],int size){
    int i=0,j=size-1;
    while (i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
     printf("\n Reverse is done");
}

void sort(int arr[],int size,char order){
    if(order=='a'){
        for (int i = 0; i < size; i++)
        {
            for(int j=0;j<size-(i+1);j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    else{
        for (int i = 0; i < size; i++)
        {
            for(int j=0;j<size-(i+1);j++){
                if(arr[j]<arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    printf("\n Sort is done");
}

int main(){
    int size;
    printf("\nEnter no of array elenets->");
    scanf("%d",&size);
   int *arr=(int *)malloc(size);
    printf("\nEnter the array elements->");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
int choice;
while (1)
{
   
    printf("\n press 1 for replace all elements");
    printf("\npress 2 for print all elements");
    printf("\npress 3 for print only odd elenets");
    printf("\npress 4 for print only even elements");
    printf("\npress 5 for print reverse of the original array");
    printf("\npress 6 for sort in ascending order");
    printf("\npress 7 for sort in descending order");
    printf("\npress 8 or any number for exit");
     printf("\nenter your choice(only integer value is allowed)->");
    scanf("%d",&choice);
    if(choice==1){
        replaceOldElmentsWithNew(arr,size);
    }
    else if (choice==2)
    {
        printAllElements(arr,size);
    }
      else if (choice==3)
    {
        onlyOddNumbers(arr,size);
    }
      else if (choice==4)
    {
        onlyEvenNumbers(arr,size);
    }
      else if (choice==5)
    {
        reverseArray(arr,size);
    }
      else if (choice==6)
    {
        sort(arr,size,'a');
    }
      else if (choice==7)
    {
       sort(arr,size,'d');
    }
      else
    {
        break;
    }
    
}

}
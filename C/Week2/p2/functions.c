#include<stdio.h>
#define MAX_LIMIT 20
int readBit(int value,int pos){
    return ((value&(1<<pos)));
}
int setBit(int value,int pos){
    return ((value|(1<<pos)));
}
int resetBit(int value,int pos){
    return ((value&(~(1<<pos))));
}
int toggleBit(int value,int pos){
    return ((value^(1<<pos)));
}
int getSize(char *str){
    int len=0;
    while (*str!='\0')
    {
        len++;
        str++;
    }
    return len;
}

void reverse(char *source,char *dest){
    int len=getSize(source);
    int i=len-2;
    int j=0;
while (i>=0)
{
    *(dest+j)=*(source+i);
    i--;
    j++;
}
*(dest+j)='\0';
}

void intToString(int n,char *dest){
    while (n>0)
    {
        int rem=n%10;
        if (rem==0)
        {
           *dest='0'; 
        }
        else if (rem==1)
        {
            *dest='1'; 
        }
          else if (rem==2)
        {
            *dest='2'; 
        }
          else if (rem==3)
        {
            *dest='3'; 
        }
          else if (rem==4)
        {
            *dest='4'; 
        }
          else if (rem==5)
        {
            *dest='5'; 
        }
          else if (rem==6)
        {
            *dest='6'; 
        }
          else if (rem==7)
        {
            *dest='7'; 
        }
          else if (rem==8)
        {
            *dest='8'; 
        }
          else if (rem==9)
        {
            *dest='9'; 
        }
        
        n=n/10;
        dest++;
    }
    
}
int main(){
    char source[MAX_LIMIT];
    char dest[MAX_LIMIT];
    char temp[MAX_LIMIT];
    char IntString[MAX_LIMIT];
    int number;
    printf("\nEnter the source string->");
    fgets(source,MAX_LIMIT,stdin);
    reverse(source,dest);
    printf("\nReverse of source string is->");
    printf("%s",dest);
    printf("\n enter the number->");
    scanf("%d",&number);
    intToString(number,temp);
    printf("\nInteger to string is->");
    reverse(temp,IntString);
    printf("\n%s",IntString);

    printf("\n%d",readBit(15,3));
    printf("\n%d",setBit(15,3));
    printf("\n%d",resetBit(15,3));
    printf("\n%d",toggleBit(15,3));

    return 0;
}
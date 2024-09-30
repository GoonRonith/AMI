#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LIMIT 20

//function to copy one string to another
void copyOneStringToAnother(char* str,char *s2){
  while (*str!='\0')
  {
    *s2=*str;
    str++;
    s2++;
  }
  *s2='\0';
}
//function to get size of a string
int getSize(char *str){
    int len=0;
    while (*str!='\0')
    {
        len++;
        str++;
    }
    return len;
}
//function to compare 2 strings
bool compareTwoStrings(char* s1,char *s3){
    int l1=getSize(s1);
    int l2=getSize(s3);
    if(l1 != l2) return false;

    while (*s1 != '\0')
    {
        if(*s1!=*s3) return false;
        s1++;
        s3++;
    }
    return true;
}
//function to reverse a string
void reverse(char *s1,char *s4){
    int len=getSize(s1);
    int i=len-1;
    int j=0;
while (i>=0)
{
    *(s4+j)=*(s1+i);
    i--;
    j++;
}

}
//function to remove space
void removeSpace(char *s1,char *s5){
    int i=0;
    while (*s1!='\0')
    {
        if(*s1!=' ') {
            *(s5+i)=*s1;
            i++;
        }
        s1++;
        
    }
    
}

int main(){
char s1[MAX_LIMIT];
char s2[MAX_LIMIT];
char s3[MAX_LIMIT];
char s4[MAX_LIMIT];
char s5[MAX_LIMIT];
printf("\nenter 1st string");
fgets(s1,MAX_LIMIT,stdin);
printf("\nenter 3rd string");
fgets(s3,MAX_LIMIT,stdin);

copyOneStringToAnother(s1,s2);
printf("\nthe copied string is->");
printf("%s",s2);  

compareTwoStrings(s1,s2);

if(compareTwoStrings(s1,s3)){
    printf("\n s1 and s3 is equal");
}
else{
    printf("\n s1 and s3 is not equal");
}
reverse(s1,s4);
printf("\nReverse of s1 is->");
printf("\n%s",s4); 
printf("\nAfter removing of space string is->");
removeSpace(s1,s5);
printf("\n%s",s5);  

}
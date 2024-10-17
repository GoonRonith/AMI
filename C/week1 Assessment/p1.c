#include <stdio.h>
#include <math.h>
void main(){
int input;

printf("Enter a number between 1-9999 : ");
scanf("%d",&input);

int units = input % 10;
input/=10;
int tens = input % 10;
input/=10;
int hundred = input % 10;
input/=10;
int thousand = input % 10;
int val, flag=0;
for(int i=0;i<4;i++){
val = thousand;
thousand = hundred;
hundred = tens;
tens = units;
units = 0;
if(val == 0 && flag == 0){
continue;
}
flag = 1;

switch(val){
case 0:
printf("Zero ");
break;
case 1:
printf("One ");
break;
case 2:
printf("Two ");
break;
case 3:
printf("Three ");
break;
case 4:
printf("Four ");
break;
case 5:
printf("Five ");
break;
case 6:
printf("Six ");
break;
case 7:
printf("Seven ");
break;
case 8:
printf("Eight ");
break;
case 9:
printf("Nine ");
}
}
}

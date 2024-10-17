#include <stdio.h>
#define D0 (Input & 0x01) 
#define D1 ((Input >> 1) & 0x01) 
#define D2 ((Input >> 2) & 0x01) 
#define SET_D5_ON() (Input |= (1 << 5)) 

#define SET_D5_OFF() (Input &= ~(1 << 5))

#define SET_D6_ON() (Input |= (1 << 6)) 
#define SET_D6_OFF() (Input &= ~(1 << 6)) 
#define SET_D7_ON() (Input |= (1 << 7)) 

#define SET_D7_OFF() (Input &= ~(1 << 7)) 

int main()
{
unsigned char Input;

printf("Enter a number between 0 and 255: ");
scanf("%hhu", &Input);

if (D0)
{

SET_D6_ON();

if (D1)
{
SET_D5_ON();
}
else
{
SET_D5_OFF(); 
}
if (D2)
{
SET_D7_ON(); 
}
else
{
SET_D7_OFF(); 
}
}
else
{

SET_D6_OFF();
SET_D5_OFF(); 
SET_D7_OFF(); 
}

printf("Modified Input Value : %d\n", Input);
if (D0)
{
printf("IGNITION IS ON\n");
if (D1 && D2)
{
printf("PARKING IS ON\n");
}
else if (D1)
{
printf("Right Indicator IS ON\n");
}
else if (D2)
{
printf("Left Indicator IS ON\n");
}
}
else
{
printf("IGNITION IS OFF\n");
}
return 0;
}

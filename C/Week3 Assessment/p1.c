#include <stdio.h>
#include <stdlib.h>


void deposit(int *denom500, int *denom200, int *denom100, int *denom50, int *balance);
void withdraw(int *denom500, int *denom200, int *denom100, int *denom50, int *balance);
void balanceEnquiry(int denom500, int denom200, int denom100, int denom50, int balance);
int isValidWithdrawal(int amount);

int main()
{
    int denom500 = 0, denom200 = 0, denom100 = 0, denom50 = 0;
    int balance = 0;
    int choice;
    int deposited = 0;

    if (!deposited)
    {
        printf("Please deposit money into your account:\n");
        deposit(&denom500, &denom200, &denom100, &denom50, &balance);
        deposited = 1;
    }

  
    while (1)
    {
        printf("\nATM Menu:\n");
        printf("1. Withdraw Money\n");
        printf("2. Balance Enquiry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            withdraw(&denom500, &denom200, &denom100, &denom50, &balance);
            break;
        case 2:
            balanceEnquiry(denom500, denom200, denom100, denom50, balance);
            break;
        case 3:
            printf("Thanks for visiting!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void deposit(int *denom500, int *denom200, int *denom100, int *denom50, int *balance)
{
    int count500, count200, count100, count50;

    printf("Enter the number of 500 notes: ");
    scanf("%d", &count500);
    printf("Enter the number of 200 notes: ");
    scanf("%d", &count200);
    printf("Enter the number of 100 notes: ");
    scanf("%d", &count100);
    printf("Enter the number of 50 notes: ");
    scanf("%d", &count50);


    *denom500 += count500;
    *denom200 += count200;
    *denom100 += count100;
    *denom50 += count50;


    *balance = (*denom500 * 500) + (*denom200 * 200) + (*denom100 * 100) + (*denom50 * 50);


    printf("\nTotal Balance: %d\n", *balance);
    printf("Denominations available:\n");
    printf("500 notes: %d\n", *denom500);
    printf("200 notes: %d\n", *denom200);
    printf("100 notes: %d\n", *denom100);
    printf("50 notes: %d\n", *denom50);
}


void withdraw(int *denom500, int *denom200, int *denom100, int *denom50, int *balance)
{
    int amount;
    printf("Enter the amount to withdraw: ");
    scanf("%d", &amount);

 
    if (!isValidWithdrawal(amount))
    {
        printf("Invalid amount. Amount should be in multiples of 50.\n");
        return;
    }


    if (amount > *balance)
    {
        printf("Insufficient balance.\n");
        return;
    }

   
    int temp500 = *denom500, temp200 = *denom200, temp100 = *denom100, temp50 = *denom50;
    int originalAmount = amount;

    while (amount >= 500 && temp500 > 0)
    {
        amount -= 500;
        temp500--;
    }
    while (amount >= 200 && temp200 > 0)
    {
        amount -= 200;
        temp200--;
    }
    while (amount >= 100 && temp100 > 0)
    {
        amount -= 100;
        temp100--;
    }
    while (amount >= 50 && temp50 > 0)
    {
        amount -= 50;
        temp50--;
    }
    if (amount != 0)
    {
        printf("Unable to dispense the exact amount with available denominations.\n");
        return;
    }

  
    *denom500 = temp500;
    *denom200 = temp200;
    *denom100 = temp100;
    *denom50 = temp50;


    *balance -= originalAmount;

    printf("Withdrawal successful! Please collect your cash.\n");
    printf("Available balance: %d\n", *balance);
}


int isValidWithdrawal(int amount)
{
    return (amount % 50 == 0); 
}


void balanceEnquiry(int denom500, int denom200, int denom100, int denom50, int balance)
{
    printf("\nCurrent Balance: %d\n", balance);
    printf("Denominations available:\n");
    printf("500 notes: %d\n", denom500);
    printf("200 notes: %d\n", denom200);
    printf("100 notes: %d\n", denom100);
    printf("50 notes: %d\n", denom50);
}

#include <stdio.h>
#include <string.h> // Include string.h for strcspn

#define MAX_LIMIT 100

struct Library_management {
    char name[MAX_LIMIT];
    int id;
    float price; // Change to float if prices can have decimals
};

void add(struct Library_management *lm) {
    for (int i = 0; i < 5; i++) {
        printf("\nEnter the name of book %d -> ", (i + 1));
        fgets(lm[i].name, MAX_LIMIT, stdin);
        
        // Remove newline character from the end of the string
        lm[i].name[strcspn(lm[i].name, "\n")] = '\0';

        printf("Enter the ID of it (Integer value): ");
        scanf("%d", &lm[i].id);
        
        // Consume the newline left in the buffer
        while (getchar() != '\n');

        printf("Enter the price of it -> ");
        scanf("%f", &lm[i].price);
        
        // Consume the newline left in the buffer
        while (getchar() != '\n');
    } 
}

void printBookById(int id,struct Library_management *lm){
      for (int i = 0; i < 5; i++) {
       if(lm[i].id==id){
        printf("\n the book detials of id=%d",id);
        printf("\nBook %d: Name: %s, ID: %d, Price: %.2f\n", 
               i + 1, lm[i].name, lm[i].id, lm[i].price);
        break;
       }
    }
}

int main() {
    struct Library_management lm[MAX_LIMIT]; // Declare an array of 5 Library_management structs

    // Call the add function to populate the array
    add(lm);

    // Optionally, you can print the added books to verify
    printf("\nBooks added:\n");
    for (int i = 0; i < 5; i++) {
        printf("Book %d: Name: %s, ID: %d, Price: %.2f\n", 
               i + 1, lm[i].name, lm[i].id, lm[i].price);
    }

    printBookById(1,lm);

    return 0;
}

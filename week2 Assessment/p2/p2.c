#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month < 8) {
        return month % 2 == 0 ? 30 : 31;
    }
    return month % 2 == 0 ? 31 : 30;
}


int totalDays(struct Date date) {
    int total = date.year * 365;


    for (int i = 0; i < date.year; i++) {
        if (isLeapYear(i)) {
            total++;
        }
    }

  
    for (int i = 1; i < date.month; i++) {
        total += daysInMonth(i, date.year);
    }


    total += date.day;

    return total;
}


int calculateDaysBetween(struct Date date1, struct Date date2) {
    return abs(totalDays(date1) - totalDays(date2));
}

int main() {
    struct Date date1, date2;

   
    printf("Enter the first date (DD MM YYYY): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    
    printf("Enter the second date (DD MM YYYY): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    
    int daysBetween = calculateDaysBetween(date1, date2);
    printf("The number of days between %02d/%02d/%04d and %02d/%02d/%04d is: %d days.\n",
           date1.day, date1.month, date1.year, date2.day, date2.month, date2.year, daysBetween);

    return 0;
}


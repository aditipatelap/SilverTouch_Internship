#include <stdio.h>

int isLeapYear(int year) {
    // Leap year is divisible by 4
    // but not divisible by 100 unless it is divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // It is a leap year
    } else {
        return 0; // It is not a leap year
    }
}

int main() {
    // Get the year from the user
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // Check if it is a leap year
    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
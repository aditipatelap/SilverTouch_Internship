#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return daysInMonth[month];
    }
}

void printCalendar(int month, int year) {
    int totalDays, currentDay;
    
    // Calculate the total days in the month
    totalDays = getDaysInMonth(month, year);

    // Calculate the day of the week on which the month starts
    currentDay = 1;

    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Print leading spaces based on the starting day of the week
    for (int i = 0; i < currentDay - 1; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= totalDays; day++) {
        printf("%3d ", day);

        // Move to the next line if it's the last day of the week
        if ((currentDay + day - 1) % 7 == 0 || day == totalDays) {
            printf("\n");
        }
    }
}

int main() {
    int month, year;

    // Get input from the user
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    // Print the calendar
    printf("\n");
    printCalendar(month, year);

    return 0;
}
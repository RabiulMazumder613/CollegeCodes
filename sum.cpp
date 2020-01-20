/*
Author: Rabiul Mazumder
Course: CSCI-136
Instructor: Alvin Lam
Assignment: Lab1A
*/
/*
Asks the user to input an integer representing a year number (1999, 2016, etc.). If the input year is a leap year according to the modern Gregorian calendar, it should print Leap year, otherwise, print Common year.
*/
#include <iostream>
#include <stdio.h>
int main (int argCount, char *argVal[]) {
    int i;              // General purpose counter.
    int smallNum;       // Holds the smallest number.
    int numSum;         // Holds the sum of all numbers.
    int currentNum;     // Holds the current number.
    int numCount;       // Holds the count of numbers.

    // Get count of numbers and make sure it's in range 1 through 50.

    printf ("How many numbers will be entered (max 50)? ");
    scanf ("%d", &numCount);
    if ((numCount < 1) || (numCount > 50)) {
        printf ("Invalid count of %d.\n", numCount);
        return 1;
    }
    printf("\nEnter %d numbers then press enter after each entry:\n",
        numCount);

    // Set initial sum to zero, numbers will be added to this.

    numSum = 0;

    // Loop, getting and processing all numbers.

    for (i = 0; i < numCount; i++) {

        // Get the number.

        printf("%2d> ", i+1);
        scanf("%d", &currentNum);

        // Add the number to sum.
        numSum += currentNum;

        // First number entered is always lowest.

        if (i == 0) {
            smallNum = currentNum;
        } else {
            // Replace if current is smaller.

            if (currentNum < smallNum) {
                smallNum = currentNum;
            }
        }
    }

    // Output results.

    printf ("The sum of the numbers is: %d\n", numSum);
    printf ("The smallest number is:    %d\n", smallNum);

    return 0;
}


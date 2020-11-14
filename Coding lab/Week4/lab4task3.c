/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 4 (October 19th, 2020)
   Lab participants: Tara, Alex, & George
   Task 3
*/

// Include files

#include <stdio.h>

// Constant declaration

const int BASELINE = 120;   // baseline blood pressure

// Variable declarations

char name[13];   // user name
int age;         // user age
float max_sbp;   // maximum systolic blood pressure

// Function prototypes

void DisplayHeader(void);
void GetInfo(void);
void Report(void);

// MAIN FUNCTION

int main(void) {
   DisplayHeader();   // display header
   GetInfo();         // prompt user for information
   Report();          // calculate and display results
   
   return 0;
}

// The DisplayHeader function displays the header on the screen.

void DisplayHeader(void) {
   printf("Blood Pressure Program\n\n");

   printf("This is just a guideline program. Please consult your doctor\n");
   printf("for a more accurate analysis.\n\n");
}

// The GetInfo function promps the user for their first name and their age.

void GetInfo(void) {
   printf("Please enter your first name: ", name);
   gets(name);

   printf("Please enter your age: ", age);
   scanf("%d", &age);
}

// The Report function calculates the maximum systolic blood pressure and
// displays a warning on the screen

void Report(void) {
   /* Calculate maximum systolic blood pressure */

   max_sbp = BASELINE + (age / 2.);

   /* Display warning */

   printf("\nThank you, %s. ", name);
   printf("You indicated that you are %d years of age.\n", age);
   printf("Seek medical attention if your systolic blood pressure is %.1f mm Hg or higher.", max_sbp);
}

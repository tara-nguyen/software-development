/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 3 (October 12th, 2020)
   Lab participants: Tara, Judy, & Shi
   Task 4
*/

// Include files

#include <stdio.h>

// Constant declaration

const int BASELINE = 120;   // baseline blood pressure

// Variable declarations

char name[13];   // user name
int age;         // user age
float max_sbp;   // maximum systolic blood pressure

// Main Function

main() {
   printf("Blood Pressure Program\n\n");

   printf("This is just a guideline program. Please consult your doctor\n");
   printf("for a more accurate analysis.\n\n");

   /* Prompt user for information */

   printf("Please enter your first name: ", name);
   gets(name);

   printf("Please enter your age: ", age);
   scanf("%d", &age);

   /* Calculate maximum systolic blood pressure */

   max_sbp = BASELINE + (age / 2.);

   /* Display warning */

   printf("\nThank you, %s. ", name);
   printf("You indicated that you are %d years of age.\n", age);
   printf("Seek medical attention if your systolic blood pressure is %.1f "
                "mm Hg or higher.", max_sbp);

   return 0;
}

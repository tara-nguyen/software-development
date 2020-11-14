/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 4 (October 19th, 2020)
   Lab participants: Tara, Alex, & George
   Task 4
*/

// Include files

#include <stdio.h>

// Variable declarations

char name[13];   // user name
int age;         // user age
float max_sbp;   // maximum systolic blood pressure

// Function prototypes

float bpwarning(int);

// MAIN FUNCTION

int main(void) {
   printf("Blood Pressure Program\n\n");

   printf("This is just a guideline program. Please consult your doctor\n");
   printf("for a more accurate analysis.\n\n");

   /* Prompt user for information */

   printf("Please enter your first name: ", name);
   gets(name);

   printf("Please enter your age: ", age);
   scanf("%d", &age);

   /* Display warning */

   printf("\nThank you, %s. ", name);
   printf("You indicated that you are %d years of age.\n", age);
   printf("Seek medical attention if your systolic blood pressure is %.1f mm Hg or higher.",
      bpwarning(age));

   return 0;
}

// The bpwarning function takes in the user's age and returns the maximum systolic blood pressure.

float bpwarning(int user_age) {
   /* Constant and variable declarations */
   
   const int BASELINE = 120;   // baseline blood pressure
   float max_sbp;              // maximum systolic blood pressure
   
   /* Calculate maximum systolic blood pressure */
   
   max_sbp = BASELINE + (user_age / 2.);
   
   return(max_sbp);
}

/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 5 (October 26th, 2020)
   Lab participants: Tara, Judy, & Siva
   Task 1
*/

// Include files

#include <stdio.h>

// Constant declaration

const int BASELINE = 120;   // baseline blood pressure

// Variable declarations

char name[21];   // user name
int age;         // user age
float max_sbp;   // maximum systolic blood pressure
char repeat;     // user answer to the question about repeating process
int count = 0;   // number of patients

// Define clear() function to help with process repetitions

int clear() {
   while ((getchar())^'\n');
}

// Main Function

main() {
   printf("Blood Pressure Processing Program\n\n");
   printf("This is just a guideline program.\n");
   
   do {
      /* Prompt user for information */
      
      printf("\n-----\n");
      
      printf("Please enter patient name: ", name);
      gets(name);
      
      printf("Please enter your age: ", age);
      scanf("%d", &age);
      
      /* Calculate maximum systolic blood pressure and display warning*/

      max_sbp = BASELINE + (age / 2.);
      printf("\n%s, age %d -- Warning level is %.1f mm Hg or higher\n\n", name, age, max_sbp);
      
      /* Ask if user wants to continue*/
      
      printf("Are you finished with processing (y/n)? ", repeat);
      scanf("%s", &repeat);
      clear();   // clear for next patient
      
      count++;   // increment count of patients
   } while (repeat == 'n');
   
   printf("\nThank you. You processed %d patients.", count);
   
   return 0;
}

/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 5 (October 26th, 2020)
   Lab participants: Tara, Judy, & Siva
   Task 2
*/

// Include files

#include <stdio.h>

// Constant declaration

const int BASELINE = 120;   // baseline blood pressure

// Variable declarations

char name[21];         // user name
int age;               // user age
float max_sbp;         // maximum systolic blood pressure
char repeat;           // user answer to the question about repeating process
int count = 0;         // number of patients
float age_total = 0;   // total age of all patients
float sbp_total = 0;   // total maximum systolic blood pressure of all patients
float age_avg;         // average age of all patients
float sbp_avg;         // average maximum systolic blood pressure of all patients

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
      
      /* Calculate counts, total age, and total blood pressure */

      count++;   // increment count of patients
      age_total = age_total + age;
      sbp_total = sbp_total + max_sbp;
      
      /* Ask if user wants to continue*/

      printf("Are you finished with processing (y/n)? ", repeat);
      scanf("%s", &repeat);
      clear();   // clear for next patient

   } while (repeat == 'n');
   
   /* Calculate average age and average blood pressure */
   
   age_avg = age_total / count;
   sbp_avg = sbp_total / count;

   printf("\nThank you. You processed %d patients.", count);
   printf("\nAverage age: %.1f", age_avg);
   printf("\nAverage blood pressure warning level: %.1f", sbp_avg);
   
   return 0;
}

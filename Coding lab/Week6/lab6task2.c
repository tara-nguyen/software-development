/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 6 (November 2nd, 2020)
   Lab participants: Tara, Alex, & Anna
   Task 2
*/

// Include files

#include <stdio.h>

// Constant and variable declarations

const int LOWTHRESHOLD = 110;   // threshold for low blood pressure
const int NORMBASELINE = 120;   // baseline for high blood pressure

int age;               // user age
float bp;              // user's blood pressure
float normthreshold;   // threshold for high blood pressure
char repeat;           // user answer to the question about repeating process
int count = 0;         // number of patients

// Main Function

main() {
   printf("Blood Pressure Warning Program\n\n");
   printf("This is just a guideline program.\n");

   do {
      /* Prompt user for information and keep count */

      printf("\n-----\n");
      
      printf("Enter the patient's age: ", age);
      scanf("%d", &age);

      printf("Please enter a blood pressure reading: ", bp);
      scanf("%f", &bp);
      
      count++;

      /* Calculate threshold for high blood pressure */
      
      normthreshold = NORMBASELINE + age / 2.;

      /* Display warning */

      if (bp <= LOWTHRESHOLD) {
         printf("\nBLOOD PRESSURE IS LOW\n");
         printf("Please refer to the doctor.\n\n");
      }
      else if (bp <= normthreshold) {
         printf("\nBLOOD PRESSURE IS NORMAL\n\n");
      }
      else {
         printf("\nBLOOD PRESSURE IS HIGH\n");
         printf("Please refer to the doctor.\n\n");
      }

      /* Ask for another reading */

      printf("Do you have another to analyze (y/n)? ", repeat);
      scanf("%s", &repeat);
   } while (repeat == 'y' || repeat == 'Y');

   /* Display number of blood pressures processed */

   printf("\n%d blood pressures processed.", count);

   return 0;
}

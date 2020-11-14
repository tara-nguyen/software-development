/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 6 (November 2nd, 2020)
   Lab participants: Tara, Alex, & Anna
   Task 3
*/

// Include files

#include <stdio.h>

// Constant and variable declarations

const int LOWTHRESHOLD = 110;   // threshold for low blood pressure
const int NORMBASELINE = 120;   // baseline for high blood pressure
const int MINOR = 18;           // minimum adult age

int age;               // user age
float bp;              // user's blood pressure
float normthreshold;   // threshold for high blood pressure
char repeat;           // user answer to the question about repeating process
int count = 0;         // number of patients

// Function prototype

void CheckMinor(void);

// MAIN FUNCTION

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

      /* Display warnings about blood pressure and age */

      if (bp <= LOWTHRESHOLD) {
         printf("\nBLOOD PRESSURE IS LOW\n");
         printf("Please refer to the doctor.\n");
         
         CheckMinor();
      }
      else if (bp <= normthreshold) {
         printf("\nBLOOD PRESSURE IS NORMAL\n");
      }
      else {
         printf("\nBLOOD PRESSURE IS HIGH\n");
         printf("Please refer to the doctor.\n");

         CheckMinor();
      }
      
      /* Ask for another reading */

      printf("\nDo you have another to analyze (y/n)? ", repeat);
      scanf("%s", &repeat);
   } while (repeat == 'y' || repeat == 'Y');

   /* Display number of blood pressures processed */

   printf("\n%d blood pressures processed.", count);

   return 0;
}

// The CheckMinor() function checks if the patient is a minor (under 18 years old),
// in which case a message is displayed.

void CheckMinor(void) {
   if (age < MINOR) {
      printf("Patient is a minor. Advise to bring parent.\n");
   }
}

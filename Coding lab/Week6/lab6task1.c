/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 6 (November 2nd, 2020)
   Lab participants: Tara, Alex, & Anna
   Task 1
*/

// Include files

#include <stdio.h>

// Constant and variable declarations

const int THRESHOLD = 110;   // threshold for blood pressure warning

float bp;        // user's blood pressure
char repeat;     // user answer to the question about repeating process
int count = 0;   // number of patients

// Main Function

main() {
   printf("Blood Pressure Warning Program\n\n");
   printf("This is just a guideline program.\n");
   
   do {
      /* Prompt user for information and keep count */

      printf("\n-----\n");

      printf("Please enter a blood pressure reading: ", bp);
      scanf("%f", &bp);
      
      count++;
      
      /* Display warning */
      
      if (bp <= THRESHOLD) {
         printf("\nBLOOD PRESSURE IS LOW\n");
         printf("Please refer to the doctor.\n\n");
      }
      else {
         printf("\nBLOOD PRESSURE IS NORMAL/HIGH.\n\n");
      }
      
      /* Ask for another reading */
      
      printf("Do you have another to analyze (y/n)? ", repeat);
      scanf("%s", &repeat);
   } while (repeat == 'y' || repeat == 'Y');
   
   /* Display number of blood pressures processed */
   
   printf("\n%d blood pressures processed.", count);
   
   return 0;
}

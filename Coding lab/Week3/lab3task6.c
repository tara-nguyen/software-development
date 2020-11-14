/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 3 (October 12th, 2020)
   Lab participants: Tara, Judy, & Shi
   Task 6
*/

// Include files

#include <stdio.h>

// Constant declarations

const int FREEZEPOINT = 32;      // freezing point in degrees Fahrenheit
const float CONVFACTOR = 5./9;   // conversion factor

// Variable declarations

float tempF;   // temperature in degrees Fahrenheit
float tempC;   // temperature in degrees Celcius

FILE *diskfile;   // file where output will be displayed

// Main Function

main() {
   printf("Temperature Conversion App\n\n");

   /* Prompt user for information */

   printf("Please enter a temperature in degrees Fahrenheit: ", tempF);
   scanf("%f", &tempF);

   /* Calculate temperature in degrees Celcius */

   tempC = (tempF - FREEZEPOINT) * CONVFACTOR;

   /* Display result to the screen */

   printf("%.1f degrees F is equivalent to %.1f degrees Celcius.\n\n", tempF, tempC);
   printf("This information has been recorded in a log file called tempchange.txt");
   
   /* Write result to disk file */
   
   diskfile = fopen("c:\\class\\tempchange.txt", "w");   // create and open file
   
   fprintf(diskfile, "Group 1\n");
   fprintf(diskfile, "F %6.2f\n", tempF);
   fprintf(diskfile, "C %6.2f", tempC);
   
   fclose(diskfile);   // close file

   return 0;
}

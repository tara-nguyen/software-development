/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 3 (October 12th, 2020)
   Lab participants: Tara, Judy, & Shi
   Task 5
*/

// Include files

#include <stdio.h>

// Constant declarations

const int FREEZEPOINT = 32;      // freezing point in degrees Fahrenheit
const float CONVFACTOR = 5./9;   // conversion factor

// Variable declarations

float tempF;   // temperature in degrees Fahrenheit
float tempC;   // temperature in degrees Celcius

// Main Function

main() {
   printf("Temperature Conversion App\n\n");

   /* Prompt user for information */

   printf("Please enter a temperature in degrees Fahrenheit: ", tempF);
   scanf("%f", &tempF);

   /* Calculate temperature in degrees Celcius */

   tempC = (tempF - FREEZEPOINT) * CONVFACTOR;

   /* Display result */

   printf("%.1f degrees F is equivalent to %.1f degrees Celcius.", tempF, tempC);

   return 0;
}

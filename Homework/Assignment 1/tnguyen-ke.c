/* UCLA Extension
   Fundamentals of Software Development
   Assignment 1 - Currency exchange
   This program converts currency from Czech korunas to US dollars at two different exchange rates
   and calculates the difference in USD.
*/

// Include files

#include <stdio.h>
#include <math.h>

// Constant declarations

const int YEAR1RATE = 42;   // conversion rate in year 1
const int YEAR2RATE = 37;   // conversion rate in year 2

// Variable declarions

int user_korunas;   // number of korunas the user has
float year1_usd;    // USD value in year 1
float year2_usd;    // USD value in year 2
float diff;         // difference in USD between the two years

FILE *diskfile;     // file where output will be displayed

// Main Function

main() {
   printf("*** Koruna Exchange App ***\n\n");
   
   /* Prompt user for information */
   
   printf("How many korunas do you have in your savings account? ", user_korunas);
   scanf("%d", &user_korunas);
   
   /* Display message on the screen */
   
   printf("\nThe exchange information for %d korunas is now being recorded.", user_korunas);
   
   /* Calculate values in U.S. dollars */
   
   year1_usd = 1. * user_korunas / YEAR1RATE;
   year2_usd = 1. * user_korunas / YEAR2RATE;
   diff = fabs(year1_usd - year2_usd);
   
   /* Write results to disk file */
   
   diskfile = fopen("c:\\class\\tnguyen-ke.txt", "w");   // create and open file
   
   fprintf(diskfile, "For %d korunas:\n", user_korunas);
   fprintf(diskfile, "At the rate of %d korunas per U.S. dollar,\n", YEAR1RATE);
   fprintf(diskfile, "   you have %.2f U.S. dollars.\n", year1_usd);
   fprintf(diskfile, "At the rate of %d korunas per U.S. dollar,\n", YEAR2RATE);
   fprintf(diskfile, "   you have %.2f U.S. dollars.\n\n", year2_usd);
   fprintf(diskfile, "The difference is %.2f U.S. dollars.", diff);
   
   fclose(diskfile);   // close file

   return 0;
}

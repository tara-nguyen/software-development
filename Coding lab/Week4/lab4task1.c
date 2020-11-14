/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 4 (October 19th, 2020)
   Lab participants: Tara, Alex, & George
   Task 1
*/

// Include files

#include <stdio.h>

// Constant declaration

const int BASELINE = 120;   // baseline blood pressure

// Variable declarations

FILE *outputfile;   // output file
FILE *inputfile;    // input file
char name[16];      // user name
int age;            // user age
float max_sbp;      // maximum systolic blood pressure

// Main Function

main() {
   /* Get information from disk file */
   
   inputfile = fopen("c:\\class\\bpdata.txt","r");
   fgets(name, 16, inputfile);
   fscanf(inputfile, "%d", &age);
   fclose(inputfile);
   
   /* Calculate maximum systolic blood pressure */

   max_sbp = BASELINE + (age / 2.);

   /* Output results to disk file */
   
   outputfile = fopen("c:\\class\\lab4task1out.txt","w");
   fprintf(outputfile, "Patient first name: %s", name);
   fprintf(outputfile, "Patient age:        %d\n", age);
   fprintf(outputfile, "BP warning level:   %.1f", max_sbp);
   fclose(outputfile);

   return 0;
}

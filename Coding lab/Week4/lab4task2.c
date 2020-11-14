/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 4 (October 19th, 2020)
   Lab participants: Tara, Alex, & George
   Task 2
*/

// Include files

#include <stdio.h>
#include <strings.h>

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
   fgets(name, 16, inputfile);   // first line of input
   int len = strlen(name);     // length of name?
   name[len-1] = 0;
   fscanf(inputfile, "%d", &age);   // second line of input
   fclose(inputfile);
   
   /* Calculate maximum systolic blood pressure */

   max_sbp = BASELINE + (age / 2.);

   /* Output results to disk file */

   outputfile = fopen("c:\\class\\lab4task2out.txt","w");
   fprintf(outputfile, "Patient Name         Age     Bp Warning Level\n\n");
   fprintf(outputfile, "%-21s%3d%16.1f", name, age, max_sbp);
   fclose(outputfile);

   return 0;
}

/* UCLA Extension
   Fundamentals of Software Development
   Coding lab 5 (October 26th, 2020)
   Lab participants: Tara, Judy, & Siva
   Task 3
*/

// Include files

#include <stdio.h>

// Constant declaration

#define NAMELENGTH 17   // one more than the maximum length of patient name
#define BASELINE 120    // baseline blood pressure

// Variable declarations

FILE *inputfile;         // disk file for input
FILE *outputfile;        // disk file for output
char name[NAMELENGTH];   // user name
int age;                 // user age
float max_sbp;           // maximum systolic blood pressure
int count = 0;           // count of patients
float age_total = 0;     // total age of all patients
float sbp_total = 0;     // total maximum systolic blood pressure of all patients
float age_avg;           // average age of all patients
float sbp_avg;           // average maximum systolic blood pressure of all patients

// Main Function

main() {
   /* Open disk files */
   
   inputfile = fopen("c:/class/bpdata.txt","r");
   outputfile = fopen("c:/class/lab5task3out.txt","w");

   fprintf(outputfile, "Blood Pressure Report\n\n");
   fprintf(outputfile, "Patient Name           Age     Bp Warning Level\n\n");

   while (!feof(inputfile)) {
      /* Get information from disk file */

      fgets(name, NAMELENGTH, inputfile);
      fscanf(inputfile, "%d\n", &age);

      /* Do calculations */

      max_sbp = BASELINE + (age / 2.);   // maximum systolic blood pressure
      count++;                           // count of patients
      age_total = age_total + age;       // total age of all patients so far
      sbp_total = sbp_total + max_sbp;   // total blood pressure of all patients so far
      
      /* Write report to disk file */
      
      fprintf(outputfile, "%-23s%3d%16.1f\n", name, age, max_sbp);
   }
   
   /* Calculate averages and write to disk file */

   age_avg = age_total / count;   // average age
   sbp_avg = sbp_total / count;   // average blood pressure
   
   fprintf(outputfile, "\nAverage%19.0f%16.1f", age_avg, sbp_avg);
   
   /* Close disk files */

   fclose(inputfile);
   fclose(outputfile);
   
   return 0;
}

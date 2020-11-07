/* UCLA Extension
   Fundamentals of Software Development
   Tara Nguyen
   Assignment 2 - Current ratio
   This program reads in a file and produces a current ratio report.
*/

// Include files

#include <stdio.h>

// Constant and variable declarations

#define NAMELENGTH 31   // one more than maximum length of company name
#define YEAR1 2010      // first year in the report

FILE *outputfile;
FILE *inputfile;    // input and output files

char name[NAMELENGTH];      // company name
int asset1;
int asset2;
int asset3;         // three values of current assets
int liab1;
int liab2;
int liab3;          // three values of current liabilities
float ratio1;
float ratio2;
float ratio3;       // three values of current ratio
float asset_avg;    // average current asset
float liab_avg;     // average current liability
float ratio_avg;    // average current ratio

// Function prototypes

void ReadInput(void);
void Calculate(void);
void WriteToFile(void);

// MAIN FUNCTION

int main(void) {
   ReadInput();     // read data from input file
   Calculate();     // calculate current ratios and averages
   WriteToFile();   // write report to output file
   
   return 0;
}

// The ReadInput function reads data from an input file.

void ReadInput(void) {
   inputfile = fopen("c:/class/current.txt", "r");
   
   fgets(name, NAMELENGTH, inputfile);   // company name
   fscanf(inputfile, "%d%d%d%d%d%d", &asset1, &liab1, &asset2, &liab2, &asset3, &liab3);
                                     // current assets and liabilities
   
   fclose(inputfile);
}

/* The Calculate function calculates the current ratios as well as the averages of
   the following: current assets, current liabilities, and current ratio.
*/

void Calculate(void) {
   /* Current ratios */
   
   ratio1 = 1. * asset1 / liab1;
   ratio2 = 1. * asset2 / liab2;
   ratio3 = 1. * asset3 / liab3;
   
   /* Averages */
   
   asset_avg = (asset1 + asset2 + asset3) / 3.;
   liab_avg = (liab1 + liab2 + liab3) / 3.;
   ratio_avg = (ratio1 + ratio2 + ratio3) / 3.;
}

// The WriteToFile function writes a current ratio report to an output file.

void WriteToFile(void) {
   outputfile = fopen("c:/class/tnguyen_cr.txt", "w");
   
   fprintf(outputfile, "%s", name);
   fprintf(outputfile, "Current Ratio Report\n\n");
   fprintf(outputfile, "                Current           Current          Current\n");
   fprintf(outputfile, "Year            Assets            Liabilities      Ratio\n");
   fprintf(outputfile, "----------------------------------------------------------\n");
   fprintf(outputfile, "%-4d%19d%18d%17.2f\n", YEAR1, asset1, liab1, ratio1);
   fprintf(outputfile, "%-4d%19d%18d%17.2f\n", YEAR1+1, asset2, liab2, ratio2);
   fprintf(outputfile, "%-4d%19d%18d%17.2f\n", YEAR1+2, asset3, liab3, ratio3);
   fprintf(outputfile, "----------------------------------------------------------\n");
   fprintf(outputfile, "Average%16.f%18.f%17.2f\n\n", asset_avg, liab_avg, ratio_avg);
   fprintf(outputfile, "This report produced by Tara Nguyen.");

   fclose(outputfile);
}

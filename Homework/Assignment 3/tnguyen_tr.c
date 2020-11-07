/* UCLA Extension
   Fundamentals of Software Development
   Tara Nguyen
   Assignment 3 - Transactions
   This program reads in a file and produces a transaction report.
*/

// Include files

#include <stdio.h>
#include <math.h>

// Constant and variable declarations

#define COMPNAME "Turtle Bay Traders"         // company name
#define ADDRESS1 "4800 Palawan Way"           // first line of company address
#define ADDRESS2 "Mandalay Beach, CA 99499"   // second line of company address
#define TRANSNAMELEN 11                       // one more than the maximum length of transaction name
#define STARTBAL 1000.00                      // starting balance

FILE *inputfile;         // disk file for input
FILE *outputfile;        // disk file for output

char transtype[TRANSNAMELEN];   // transaction type
float trans_amt;                // transaction amount
float netbal = STARTBAL;        // net balance
int numtrans = 0;               // number of transactions

// Function prototypes

void WriteHeader(void);
void ReportTrans(void);
void WriteSummary(void);

// Main Function

int main(void) {
   WriteHeader();   // write report opening
   
   while (!feof(inputfile)) {
      ReportTrans();   // report transactions and net balance
   }
   
   WriteSummary();   // write report summary
   
   return 0;
}

// The WriteHeader() function writes the opening of the report as well as
// the headings of the transaction table.

void WriteHeader(void) {
   /* Open disk files */

   inputfile = fopen("c:/class/transactions.txt","r");
   outputfile = fopen("c:/class/tnguyen_tr.txt","w");

   /* Write company name and address, starting balance, and table headings */
   
   fprintf(outputfile, "%s\n", COMPNAME);
   fprintf(outputfile, "%s\n", ADDRESS1);
   fprintf(outputfile, "%s\n\n", ADDRESS2);
   fprintf(outputfile, "Operating Account Starting Balance: %8.2f\n\n", STARTBAL);
   fprintf(outputfile, "Transaction       Amount                 Net\n");
   fprintf(outputfile, "-----------       ------                 ---\n");
}

// The ReportTrans() function does three things:
// First, it reads the transaction type and amount from a disk file.
// Then, the function calculates the net balance and keeps count of the number of transactions.
// Finally, the function writes the transaction and net balance to a disk file.

void ReportTrans(void) {
   /* Read the transaction type and amount from input disk file */
   
   fgets(transtype, TRANSNAMELEN, inputfile);
   fscanf(inputfile, "%f\n", &trans_amt);
   
   /* Calculate net balance and keep count */
   
   netbal = netbal + trans_amt;
   numtrans++;
   
   /* Write report to output disk file */
   
   fprintf(outputfile, "%-11s%13.2f%20.2f\n", transtype, fabs(trans_amt), netbal);
}

// The WriteSummary() function writes to a disk file the ending balance and
// the number of transactions processed.

void WriteSummary(void) {
   /* Write summary */
   
   fprintf(outputfile, "\nOperating Account Ending Balance: %10.2f\n", netbal);
   fprintf(outputfile, "There were %d transactions processed.", numtrans);
   
   /* Close disk files */

   fclose(inputfile);
   fclose(outputfile);
}

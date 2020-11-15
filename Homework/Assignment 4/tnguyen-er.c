/* UCLA Extension
   Fundamentals of Software Development
   Tara Nguyen
   Assignment 4 - Payroll
   This program prompts user for payroll information and then writes a payroll report to a disk file.
*/

// INCLUDE FILES

#include <stdio.h>
#include <string.h>

// CONSTANT DECLARATIONS

#define FILEPATH "c:/class/tnguyen-er.txt"   // system path to disk file containing the report
#define COMPNAME "NetworkHaus Information Technology, LLC"   // company name
#define OVTRATEMULT 1.5   // multiplier for the overtime rate
#define MAXREGHOURS 40    // maximum possible regular hours
#define NAMELEN 15        // one plus maximum allowed length of first/last name

// VARIABLE DECLARATIONS

FILE *outputfile;          // disk file for output
char projname[21];         // project name
int count = 0;             // count of the number of staff members processed
char repeat;               // user response to question about repeating process

// Variables related to each individual staff member's information

char firstname[NAMELEN];          // first name
char lastname[NAMELEN];           // last name
char firstnamecpy[NAMELEN*2+1];   // copy of first name
char lastnamecpy[NAMELEN*2+2];    // copy of last name
float regwage;                    // regular hourly wage
float ovtwage;                    // overtime hourly wage
float hours;                      // total number of hours
float gross;                      // gross earning
float reghours;                   // number of regular hours
float ovthours;                   // number of overtime hours
float regpay;                     // regular pay
float ovtpay;                     // overtime pay

// Variables related to summary payroll information for all staff

float totalreghrs = 0;     // total regular hours
float totalovthrs = 0;     // total overtime hours
float totalregpay = 0;     // total regular pay
float totalovtpay = 0;     // total overtime pay
float totalgross = 0;      // total gross earnings

// FUNCTION PROTOTYPES

void WriteHeader(void);
void ReportPayroll(void);
void Calculate(void);
void WriteSummary(void);
int clear(void);

/* -------------------------
   ----- MAIN FUNCTION -----
   ------------------------- */

int main(void) {
   WriteHeader();   // write report opening
   ReportPayroll();   // report payroll information for each staff member
   WriteSummary();   // write report summary
   
   return 0;
}

// The WriteHeader() function writes the opening of the report as well as the headings of the payroll table.

void WriteHeader(void) {
   outputfile = fopen(FILEPATH, "w");   // open disk file where payroll report will be written

   printf("%s\n", COMPNAME);
   printf("Staff Earnings Report Generator\n\n");

   /* Prompt user for project name */

   printf("Please enter the project name: ", projname);
   gets(projname);

   /* Write header of payroll report to disk file */

   fprintf(outputfile, COMPNAME);
   fprintf(outputfile, "\nWeekly Staff Earnings Report\n\n");
   fprintf(outputfile, "Project: %s\n\n", projname);
   fprintf(outputfile, "Staff Member                     Reg Hrs        Overtime Hrs       Gross\n");
   fprintf(outputfile, "------------------------------------------------------------------------\n");
}

// The ReportPayroll() function does four things:
// First, it promps the user for each staff member's first name, last name, regular hourly wage, and
// number of hours worked.
// Next, the function calls another function, Calculate(), to do calculations.
// Then, ReportPayroll() writes the staff member's payroll information to a disk file.
// Finally, the function asks if the user would like to repeat the process.

void ReportPayroll(void) {
   /* Prompt user for information */

   do {
      count++;   // count number of staff member processed

      printf("\nEnter staff member #%d's first name: ", count, firstname);
      gets(firstname);

      printf("Enter staff member #%d's last name: ", count);
      gets(lastname);

      printf("Enter the hourly wage of %s: ", strcat(strcat(strcpy(firstnamecpy, firstname), " "), lastname), regwage);
      scanf("%f", &regwage);

      printf("Enter total number of hours: ", hours);
      scanf("%f", &hours);

      Calculate();   // calculate total hours and total pay for all staff members processed so far

      /* Write staff member's payroll information to disk file */

      fprintf(outputfile, "%-31s", strcat(strcat(strcpy(lastnamecpy, lastname), ", "), firstname));
      fprintf(outputfile, "%4.1f ($%5.2f) %6.1f ($%5.2f)    $%7.2f\n", reghours, regwage, ovthours, ovtwage, gross);

      /* Ask to repeat process */

      printf("\nThank you. Process another employee? ", repeat);
      scanf("%s", &repeat);
      clear();   // clear process for next round
   } while (repeat == 'Y' || repeat == 'y');

   printf("\nEnd of processing.");
}

// The Calculate() function calculates both statistics for individual staff members and cumulative statistics for all staff.

void Calculate(void) {
   /* ------------------------------------
      Individual staff member's statistics
      ------------------------------------ */

   /* Number of regular hours and number of overtime hours */
   
   if (hours > MAXREGHOURS) {
      reghours = MAXREGHOURS;
   } else {
      reghours = hours;
   }
   ovthours = hours - reghours;
   
   /* Overtime hourly wage, regular pay, overtime pay, and gross earning */
   
   ovtwage = regwage * OVTRATEMULT;
   regpay = regwage * reghours;
   ovtpay = ovtwage * ovthours;
   gross = regpay + ovtpay;
   
   /* -----------------------------------
      Cumulative statistics for all staff
      ----------------------------------- */

   totalreghrs = totalreghrs + reghours;   // regular hours
   totalovthrs = totalovthrs + ovthours;   // overtime hours
   totalregpay = totalregpay + regpay;     // regular pay
   totalovtpay = totalovtpay + ovtpay;     // overtime pay
   totalgross = totalgross + gross;        // total gross earning
}

// The clear() function facilitates the repetition of the processing loop in the ReportPayroll() function.

int clear()  {
    while ((getchar())^'\n');
}

// The WriteSummary() function writes to a disk file a summary of the payroll report.

void WriteSummary(void) {
   fprintf(outputfile, "------------------------------------------------------------------------\n\n");
   fprintf(outputfile, "Total Regular Hours Worked: %.1f\n", totalreghrs);
   fprintf(outputfile, "Total Overtime Hours Worked: %.1f\n", totalovthrs);
   fprintf(outputfile, "Percentage of Total Hours That Are Overtime: %.1f%%\n\n", totalovthrs*100/(totalreghrs+totalovthrs));
   fprintf(outputfile, "Total Regular Wages: $%.2f\n", totalregpay);
   fprintf(outputfile, "Total Overtime Wages: $%.2f\n\n", totalovtpay);
   fprintf(outputfile, "Total Wages This Period: $%.2f", totalgross);

   fclose(outputfile);   // close disk file
}

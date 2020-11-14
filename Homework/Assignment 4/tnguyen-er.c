/* UCLA Extension
   Fundamentals of Software Development
   Tara Nguyen
   Assignment 4 - Payroll
   This program prompts user for information and then writes a payroll report to a disk file.
*/

// Include files

#include <stdio.h>
#include <string.h>

// Constant declarations

#define FILEPATH "c:/class/tnguyen-er.txt"   // system path to disk file containing the report
#define COMPNAME "NetworkHaus Information Technology, LLC"   // company name
#define OVTRATEMULT 1.5   // multiplier for the overtime rate
#define MAXREGHOURS 40    // maximum possible regular hours
#define NAMELEN 15        // one plus maximum allowed length of first/last name

// Variable declarations

FILE *outputfile;          // disk file for output
char projname[21];         // project name
char firstname[NAMELEN];   // staff member's first name
char lastname[NAMELEN];    // staff member's last name
char firstnamecpy[NAMELEN*2+1];   // copy of staff member's first name
char lastnamecpy[NAMELEN*2+2];   // copy of staff member's last name
int count = 0;             // count of the number of staff members processed
float regwage;             // staff member's regular hourly wage
float ovtwage;             // staff member's overtime hourly wage
float hours;               // individual staff member's total number of hours
float gross;               // individual staff member's gross earning
float reghours;            // individual staff member's number of regular hours
float ovthours;            // individual staff member's number of overtime hours
float regpay;              // individual staff member's regular pay
float ovtpay;              // individual staff member's overtime pay
float totalreghrs = 0;     // total regular hours of all staff
float totalovthrs = 0;     // total overtime hours of all staff
float totalregpay = 0;     // total regular pay of all staff
float totalovtpay = 0;     // total overtime pay of all staff
float totalgross = 0;      // total gross earnings of all staff
char repeat;               // user response to question about repeating process

// Function prototypes

void Calculate(void);
int clear(void);

// MAIN FUNCTION

int main(void) {
   /* Open disk file where payroll report will be written */
   
   outputfile = fopen(FILEPATH, "w");
   
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
   
   /* Prompt user for his/her first name, last name, regular hourly wage, and number of hours worked */
   
   do {
      count++;   // count number of staff member processed

      /* First name and last name */
      
      printf("\nEnter staff member #%d's first name: ", count, firstname);
      gets(firstname);
      
      printf("Enter staff member #%d's last name: ", count);
      gets(lastname);

      /* Wage and hours */
      
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
   
   /* Write cumulate payroll statistics to disk file */
   
   fprintf(outputfile, "------------------------------------------------------------------------\n\n");
   fprintf(outputfile, "Total Regular Hours Worked: %.1f\n", totalreghrs);
   fprintf(outputfile, "Total Overtime Hours Worked: %.1f\n", totalovthrs);
   fprintf(outputfile, "Percentage of Total Hours That Are Overtime: %.1f%%\n\n", totalovthrs*100/(totalreghrs+totalovthrs));
   fprintf(outputfile, "Total Regular Wages: $%.2f\n", totalregpay);
   fprintf(outputfile, "Total Overtime Wages: $%.2f\n\n", totalovtpay);
   fprintf(outputfile, "Total Wages This Period: $%.2f", totalgross);
   
   fclose(outputfile);
   
   return 0;
}

// The clear() function facilitates the repetition of the processing loop in the main function.

int clear()  {
    while ((getchar())^'\n');
}

// The Calculate() function calculates both statistics for individual staff members and 
// cumulative statistics for all staff.
// Individual stats include number of regular hours, number of overtime hours, overtime hourly wage,
// regular pay, overtime pay, and gross earning.
// Cumulative stats include total number of regular hours, total number of overtime hours,
// total regular pay, total overtime pay, and total combined pay.

void Calculate(void) {
   /* ------------------------------------ */
   /* Individual staff member's statistics */
   /* ------------------------------------ */

   /* Number of regular hours and number of overtime hours */
   
   if (hours > 40) {
      reghours = 40;
      ovthours = hours - 40;
   } else {
      reghours = hours;
      ovthours = 0;
   }
   
   /* Overtime hourly wage, regular pay, overtime pay, and gross earning */
   
   ovtwage = regwage * OVTRATEMULT;
   regpay = regwage * reghours;
   ovtpay = ovtwage * ovthours;
   gross = regpay + ovtpay;
   
   /* ----------------------------------- */
   /* Cumulative statistics for all staff */
   /* ----------------------------------- */

   totalreghrs = totalreghrs + reghours;     // regular hours
   totalovthrs = totalovthrs + ovthours;   // overtime hours
   totalregpay = totalregpay + regpay;       // regular pay
   totalovtpay = totalovtpay + ovtpay;       // overtime pay
   totalgross = totalgross + gross;          // total gross earning
}

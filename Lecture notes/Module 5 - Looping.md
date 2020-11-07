###### *Fundamentals of Software Development*

# Module 5 - Looping

This module introduces one of the biggest fundamental concepts in programming: the ability to repeat an action over and over again. We call this **looping**.

Looping was a very big part of early computing, where large files were being processed. This is still in use today, as banks refresh their master files each night by visiting each account, updating it and producing notices and taking certain actions.

But looping is also part of working interactively. Every time a program repeats something, such as a simple prompt, looping makes that happen. Programs that you use every day, from Quickbooks, to Chrome, and from games to ATM machines - they all use looping.

##### *Part A*

## General Looping Concepts

C uses three different loop constructs. (A *construct* is another word for a complex statement.) In your future years of programming experience, you'll see these constructs used in a variety of ways. However, for the basic programs that you'll do in this class and your next two or three classes, you'll probably see them used in fairly specific ways. The three loops are the **do-while** loop, the **while** loop, and the **for** loop.

The **do-while** loop ensures that the task to be repeated is performed at least once and then possibly several more times as long as a particular condition is met. This condition might be something like answering 'Y' to the question "Do you wish to do another transaction?". Its most popular usage is in interactive situations such as these.

The **while** loop keeps repeating the task to be repeated as long as a particular condition is true. The most popular place for while loops are in programs that perform file input. For instance, let's say the task to be repeated is to read a set of data, process the set of data, and print a summary line for that data in a report. We will use a while loop to do this task again and again as long as there is data to be read in the file.

The **for** loop is used to repeat a task a certain number of times. We will use these a lot in printing lines, as well as in calculating what happens over a given number of days, months, or years,  When you move on to Visual Basic, you will learn about loops which are quite similar to the ones you will experience in C. Some languages have only one loop construct, but that one construct can be configured to represent any of the three loops that C utilizes.

No matter which loop construct you use, each has a couple of things in common. First of all, the task to be repeated (a single statement or group of statements) is called the **loop body**. The part of the construct that controls when the loop terminates is called the **loop condition**.

##### *Part B*

## The do-while Loop

The **do-while** loop is used whenever you wish to execute the loop body at least once. The loop condition that controls how the loop is repeated is a Boolean expression at the end of the loop structure. The Nassi-Shneiderman chart for a **do-while** loop illustrates the structure nicely:

![N-S Chart for do-while Loop](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20do-while%20Loop.JPG?raw=true)

Here's a very simple program segment which shows the usage of the **do-while** loop:

```c
printf("*****");

do {
   printf ("Please enter your name: ", name);
   gets(name);
   printf ("Please enter your age: ", age);
   scanf("%d", &age);
   printf("\nThe name is %s and the age is %d years./n/n", name, age);
   printf ("Would you like another? ");
   scanf("%s", &again);
} while (again == 'Y' || again == 'y');

printf("/nThank you!");
```

##### *Part C*

## The while Loop

This loop is used whenever its necessary to check the condition prior to executing the loop body (under all circumstances). We commonly use this loop for file input, but because it is the mother of all loops, we can configure it so that it can be used in every loop situation.

### Nassi-Shneiderman Chart for while Loop

The **while** loop's N-S chart takes the "L" style of the **do-while** and flips it upside down. This places the condition on the top, meaning that the condition is tested before the execution of the loop body. The **for** loop (next part of the module) can also use the same N-S style, although formally it is shaped like a letter C (for "counting") rather than an upside down "L". Here is an example for a **while** loop:

![N-S Chart for do-while Loop](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20while%20Loop.JPG?raw=true)

### A Simple Example

If we were reading a file full of names – with a single name (no embedded spaces) on each line of input – here's what our program segment would look like, assuming the file variable is `indata`:

```c
while (!feof(indata))
{
   fscanf(indata, "%s\n", &name);
   printf("I just read the name: %s\n", name);
}
```

Prior to entering the loop and reading the name, the program checks to see if data exists in the file `indata`. If it does, then the `feof()` function returns the value `FALSE`, and `!feof()` is therefore `TRUE`. The value `TRUE` means that we can execute the body once.

##### *Part D*

## The for Loop

The **for** loop is an "express" version of **while** loop. It does a limited number of things that the **while** loop does, but it does them more efficiently. We use the **for** loops to repeat the body a given number of times, either explicitly or for one time for every value from one value to another.

The **for** loop requires a loop variable. This is an `int` variable which is automatically incremented each time the loop body executes. It is given a start value in the *initial statement*. After each iteration, it is incremented in the *increment statement*. The *keep going condition* is a Boolean expression that, as long as it is true, the loop will iterate again. The value of the loop variable should never be changed by a statement while in the loop body, but you can use its value in output statements and expressions. Here's an example:

```c
for (count=1; count <= 9; count++) {
   printf("I love %d potatoes.\n", count);
}
```

We could use `count=count+1` for the increment, but the C way to do it is to use the increment operator `++`. If the loop body is a compound statement (surrounded by curly braces), then no semicolon is to be placed following the closing curly brace.

If you wish to count by a negative number, the *increment stmt* can be made a *decrement stmt*. Your starting value should then be higher than your ending value for the body to execute multiple times. For example:

```c
for (blastoff=5; blastoff>=1; blastoff--) {
   printf("T minus %d seconds and counting", blastoff);
}
```

Following the end of the loop, the value of the loop variable is undefined. This means that we can't rely on what the value is at that point (it varies from compiler to compiler, and is irrelevant anyway).

### An Example – Interest Calculation Program

```c
// example 5-6 - Interest Calculator
// This program determines interest on a savings account, given the monthly rate, the principal, and the term (in months).

// C Header Files

#include <stdio.h>

// Global Variable Declarations

float balance;           // holds the balance (originally input by user) throughoutthe process
float annualrateperc;    // Annual percentage rate expressed as a % (such as 5.3 for 5.3%, orig input by user)
int term;                // the number of periods (e.g. months if we are doing monthly interest

// Function Prototypes

void GetData(void);
void PrintReport(void);

//****************************************************
//         M A I N   F U N C T I O N
//****************************************************

int main (void){
  GetData();     // Prompt user for all necessary
  dataPrintReport(); // Calculate interest and produce chart

  return 0;
}

/* **********************************************************
   GetData prompts the user for all the needed information, including the starting balance, annual rate %, and the desired term (in months).
   **********************************************************
*/

void GetData (void){
  printf("Please enter the starting amount: $");
  scanf("%f", &balance);

  printf("Please enter the annual percentage rate (%%):");
  scanf("%f", &annualrateperc);

  printf("Please enter the desired term (in months):");
  scanf("%d", &term);

  printf("\nThank you, here's your interest chart: \n\n");
}

/* **********************************************************
   PrintReport uses a for loop to produce a chart, based on the amounts given by the user. The rates are converted from annual percentage to monthly decimal.
   **********************************************************
*/

void PrintReport (void){  
  // Local Variables

  int month;             // loop variable
  float monthlyrateperc; // Monthly interest rate expressed as a % - calculated
  float monthlyrate;     // Monthly interest rate expressed as a decimal
  float interest;        // Interest generated for a particular month
  float StartingBalance;

  monthlyrateperc = annualrateperc / 12;  // convert from annual to monthly
  monthlyrate = monthlyrateperc / 100;    // convert from % to decimal    

  // Produce the chart

  printf("After Month     Interest Earned    New Balance\n\n");    StartingBalance = balance;

  for (month=1; month<=term; month++){
    interest = balance * monthlyrate;
    balance = balance + interest;

    printf("%3d%25.2f%16.2f\n", month, interest, balance);
  }

  printf("\nBalance at end of term: %.2f\n", balance);
  printf("Total interest earned: $%.2f\n", balance - StartingBalance);
}
```

##### *Part D*

## Loop Invariant

The loop invariant is the single statement inside the loop body that eventually causes a change in the condition that controls the loop. It's a simple concept: something must eventually cause the loop to stop! So if you inadvertently have a loop that does NOT have its invariant, your loop will never stop (we call this an infinite loop).

In **do-while/while** loops that are controlled by comparisons with a value, the last statement in the loop body that alters the value of the expression that is tested is the invariant.

In **for** loops (in the C language), the loop invariant is the *increment statement* inside control area for the for loop. It causes the loop variable to change values each iteration, and eventually the loop test will fail causing the loop to stop. Most non-C-like languages (like Visual Basic) do not structure their **for** loop controls in the same manner; it is simplified. In these languages, you'd say that a **for** loop either has no invariant, or the basic control statement for the loop is the invariant (e.g., Visual Basic would use for `num = 1 to 10`  as the control statement for a for loop).

## Summary

So we can see a great deal of flexibility in looping in C. What's important is that you select the proper loops for your program, and that you specify the loop conditions the correct way. For now, when you see interactive, generally think of the **do-while** loop. When you see file input programs, generally think of the **while** loop. And when you see any program that requires a fixed number of times a task is to be executed, generally think of the **for** loop. This guideline will usually not steer you wrong.

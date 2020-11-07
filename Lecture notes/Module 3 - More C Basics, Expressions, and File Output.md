###### *Fundamentals of Software Development*

# Module 3 - More C Basics, Expressions, and File Output

This module introduces you to the syntax and semantics of the C language. The term "syntax" deals with the rules of the language, and "semantics" deals with the meaning of the statement. This module examines very basic elements of C programs:

- Basic program structure and commenting
- Printing text to the screen (screen output)
- Asking the user for data using variables (both text and numbers) and printing values to the screen (interactive input and output)
- Doing simple arithmetic calculations, as well as function-based calculations (expressions and functions)
- Printing to a data file on disk (file output)

We do this by introducing a little over 10 very simple programs of increasing (but still minimal) complexity.

By the end of this module, you should be able to write a simple program that asks the user for both text and numeric data, performs one or more calculations, and outputs that information either to the screen or to a file.

##### *Part A*

## Basic Interactive Input and Output

Example 3-1 is the simplest program that one can produce in C. It contains one line of output. The first few lines starting with `//` are comments, and are ignored by the compiler. They are for programmer clarification only. Following the comment lines is a compiler directive line. These (starting with `#`) are common in C programs. This particular one you will find in all of your programs. It instructs the C compiler to include the components of C which deal with standard input and output. Without this line, your programs won't know how to print or to accept input.

```c
/* Example 3-1   
   This program produces a single line of output
*/

#include <stdio.h>

main() {
  printf("** Mini Register Program **");
  return 0;
}
```

C programs are divided into units called "functions". Every program has at least a main function. The establishment of the main function requires its name in lower-case, along with the set of parentheses you see following the word main. (Even though they have nothing between them, they are still required.) Following them are the statements of the main function, enclosed by two curly braces. Each statement is an individual instruction which outputs something, inputs something, calculates something, controls the flow of execution, deals with a file in some way, or terminates the program.

There are two statements in this program. The first statement shown prints `**Mini-Register Program**` on-screen. `printf` statements take what appears between the parentheses and print it out on the screen. In this example, what appears between the parentheses is called a string literal. A string literal is always surrounded by double quotation marks in C. We call it a string literal because the program will literally print out what appears between the quotes. A bit of jargon: the item inside of the parentheses is referred to as an argument.

Each statement ends with a semicolon in C. C is a free-format language, so column numbers don't matter. However, we typically line up our statements with an even left margin for better readability. With free-format languages, anywhere were we can have a single space, we can have as many spaces as we want or we can break the line there. Nothing has to start in a particular column. And a single statement can actually appear over several lines. In general, you would not want to do this; your program should be readable to another programmer.

The second statement is one that you'll place in all of your programs. It tells the computer to end execution of the program with a `0` result code (meaning the program terminated successfully with no problems). The `0` is sent to the operating system. If another number is used, the operating system would see it as an execution error, and would halt the program and display that it abnormally terminated.

### I Didn't See Any Output!

If you are running Dev-C++, by default your program will run as a DOS program in a DOS window, as opposed to as a Windows program. If you are running the 32-bit version of Dev C++, your program will execute very quickly and once finished, the DOS window will disappear.

You can insert `system("pause");` before the `return 0;` line. It will cause the program to pause at the end prior to the window closing. The user then need only press a key to continue and have the program end and the window close.

```c
/* Example 3-1a
   This program produces a single line of output in the 32-bit version of Dev C++
*/

#include <stdio.h>

main() {
  printf("** Mini Register Program **");
  system("pause");
  return 0;
}
```
### Multi-Line Output

```c
// Example 3-2
//
// This program produces several lines of output and illustrates ways of printing string literals within printf.
// Note the special way we represent the double-quotation mark within a string literal.

#include <stdio.h>

main() {   
  printf("** Mini Register Program **\n\n");   
  printf("This program doesn't do much, but\n");   
  printf("if \"we\" really try,\n"); // You need \" to produce a regular " in the output
  printf("it illustrates how "
        "the printf\n");   
  printf("statement works 100%% ");   // You need %% to produce a single % in the output   
  printf("in the C language.\n\n");

  return 0;
}
```

The fourth statement shows how we can have more than 1 string in a `printf` statement. In actuality, we generally wouldn't do it this way, unless we were running out of space on the program line. The program will print the two string literals together with only one space between the word how and the word the. Why? Well, spaces outside string literals don't count; they are simply ignored. So the space that would appear after the word how in the output is indicated by the space that you see after the word how in the string literal (immediately prior to the closing quote mark).

The fifth and sixth statement illustrates this even better. The fifth statement will print the two phrases right next to each other with a space before the word in. The fact that the statement is split over two printf statements is irrelevant. Unless there's a `\n` in the string, the output stays on one line.

### Variables and User Input

A variable is a location in memory where a value can be held while the program is running. The following example illustrates how we can use a variable to hold the name of an employee which is input by the user.

```c
// Example 3-3
//
// This program introduces the concepts of variables and user input.

#include <stdio.h>

char name[15];   // variable declaration; 15 means a maximum size of 14 characters

main() {
  printf("** Mini Register Program **\n\n");   

  printf("Please enter your name: ");   
  gets(name);
  // An alternative to this would be:   
  // scanf("%s", &name);   
  // but this would not accommodate a name with a space in it   

  printf("\nThank you, %s!\n", name);   

  return 0;
}
```

First of all, we prompt the user to enter the name. A prompt always requires 2 statements: a `printf` statement which tells the user what to do and a `scanf` statement which performs the actual input. When the `scanf` statement is executed, the program will pause to allow the user to type in the value. If we didn't have a `printf` statement, the program would pause but the user would not know what to do. After entering the string value, the user must press the Enter key to tell the program that he's finished. At that moment, the value he types gets placed in RAM in the variable name. Now that name contains the value, we can use it in a `printf` statement to print out.

The `scanf` statement always has a string specifying the format of what will be read in. We use `%s` to indicate that a string will be read in. Then following this first argument is the variable we are inputting into. C requires that we precede this variable with an ampersand (`&`).

#### An Alternative to the Limited `scanf()` Function for String Input

`scanf()` has many limitations when working with strings, one of which being the inability to read blank spaces as part of the string. This is major, as many first and last names, addresses, cities, states and countries would be completely unreadable because they have a space in the middle.

Fortunately, a more forgiving functions exists within C that can be used for reading strings. It is called `gets()`.  It requires only one argument (remember, an argument is one of the elements inside the parentheses), and that is the string variable which will be receiving the input. The value read can have one or more spaces.

#### Numeric Data Types and Formatting

```c
// Example 3-4
// This introduces numeric data types and user input.
// Here we use int (for integers) and float (for real or "floating point" numbers).  
// Note what happens when we print the float value in printf.

#include <stdio.h>

/* Variable declaration */

char name[15];
int empnum;
float amount;

/* Main function */

main() {   
  printf("** Mini Register Program **\n\n");

  printf("Please enter your name: ");
  scanf("%s", &name);   /* gets() would be better here, but showing you scanf() for a string to
                        contrast it with numbers */   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);   

  printf("\n");   
  printf("Cashier: %s\n", name);
  printf("Employee #%d\n", empnum);   
  printf("Amount of sale: $%f\n", amount);

  return 0;
}
```

### Pseudocode Design

Before we press forward, I want to reach back to the discussion in **Module 2** on design. Remember how I stated that it is critical to establish a program design prior to writing code? That remains true, although I am approaching a bit backward (since I'm focusing more on learning syntax here).  However, you should see what a program design looks like.

If I hadn't developed the C program for this example, I would have actually begun by writing a pseudocode or Nassi-Shneiderman chart for the main function. Since a N-S chart would look exactly like the pseudocode at this early stage (with no flow-of-control logic happening), we'll skip it. (If you insist, simply draw a rectangular box around each statement). Our design would look something like this:

*Display "Mini Register Program".*

*Skip a display line.*

*Prompt user for name using "Please enter your name: " as prompt.*

*Prompt user for employee number (empnum) using their name and ", please enter your employee number:"*

*Prompt user for amount of sale (amount) using "Please enter amount of sale: $".*

*Skip a display line.*

*Display "Cashier: " and the name.*

*Display "Employee #" and the empnum.*

*Display "Amount of sale: $" and the amount.*

Each of these lines indicates what is to happen, but in a descriptive way in English rather than in the syntax of C. The terms I used are common, but are not standard. There is, in fact, an official standardized pseudocode, but that is akin to another language with syntax rules, and for you (introductory students) that defeats the purpose.

### Output Formatting

Output formatting occurs directly in the `printf` statement. Immediately after the `%` in the printing spec for the float number that we're printing, we place the field-width specification. The field-width specification indicates two things: 1) the number of print positions then we want the values to take up on the output line and 2) the number of decimal places we'd like printed. The first number indicates the width of the field. If there is no negative sign in front of it, C will print the value with right justification. If there is a negative sign in front of the field-width specification, the value will be printed with left justification.

```c
// Example 3-5
// This introduces output formatting to the printf statement.

#include <stdio.h>

// Variable declaration

char name[15];
int empnum;
float amount;

// Main function

main() {   
  printf("** Mini Register Program **\n\n");   
  printf("Please enter your name: ");   
  gets(name);   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);   

  printf("\n");   
  printf("Cashier: %s\n", name);   
  printf("Employee #%d\n", empnum);   
  printf("Amount of sale: $%8.2f\n", amount);

  return 0;
}
```

If we want the value to be printed with two decimal places but without any leading spaces, we use `0.2` or `1.2` or simply `.2` for the field-width specification.

##### *Part B*

## Expressions and Disk Output

### Expressions

The definition of an expression is rather broad: it's anything that gives us a value. It can be as simple as a numeric constant (such as 5.1) or variable (such as amount), or as complex as (((stuff + 5) / 2) - 40.7). Because an expressions ends up producing a value, we classify them by their data type. For now, we'll deal with integer expressions and float expressions. The following example shows how we can calculate the sales tax from the amount.

```c
/* Example 3-7
   This program shows the use of expressions in output statements.
   Expressions generally have an operator and two operands.
*/

#include <stdio.h>

// Variable declaration

char name[15];
int empnum;
float amount;

// Main function

main() {   
  printf("** Mini Register Program **\n\n");

  printf("Please enter your name: ");   
  gets(name);   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);   

  printf("\n");   
  printf("Cashier: %s\n", name);   
  printf("Employee #%d\n", empnum);   
  printf("Amount of sale: $%8.2f\n", amount);   
  printf("CA Sales Tax:   $%8.2f\n", amount * .095);   

  return 0;
}
```

There's a little bit of jargon involved in defining expressions. Taking the expression found in the `printf` statement in Example 3-7 (`amount * .095`), we can identify the `*` as the **operator**, and `amount` and `.095` as our **operands**. This particular expression simply multiplies the value in the variable amount by 0.095 (which is 9.5%, a typical California sales tax rate for L.A. County). The process of determining the value of an expression is called the **evaluation**.

Expressions use a variety of operators. Numeric expressions use addition (+), subtraction (-), multiplication (*), division (/), and modulo (%).

The data type of additions expression is based on the operands. For addition, subtraction and multiplication, if any of the operands are float, then the entire expression is float. If all the operands are integers, then the entire expression is integer.

For division, the same holds true. If either the top (dividend) or the bottom (divisor) is float, the division result will be float. If both the dividend and divisor are integer, the result will be an integer. We call this “integer division”. Essentially, the decimal part of the result is truncated and the result is an integer. So an integer division of `5/2` would give the integer result of `2`.

Expressions can use parentheses to indicate which part of the expression will be evaluated first. In fact, an entire set of rules regulates how expressions are evaluated. This set of rules is called the **precedence hierarchy**.

### Assignment Statements

In Example 3-7, we calculated the sales tax within the printf statement. However, if we needed to print the sales tax again, we would have to do the calculation again. So the following example shows us a way of calculating the sales tax and saving the results in a variable. We call this an **assignment statement**.

```c
// Example 3-8
// This program shows the use of assignment statements to place values into variables.

#include <stdio.h>

// Variable declaration

char name[15];
int empnum;
float amount;
float SalesTax;
float total;

// Main function

main() {   
  printf("** Mini Register Program **\n\n");   

  printf("Please enter your name: ");   
  gets(name);   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);   

  SalesTax = amount * .095;   // This means 9.5% tax   
  total = amount + SalesTax;   

  printf("\nCashier: %s\n", name);   
  printf("Employee #%d\n\n", empnum);   
  printf("Amount of sale: $%8.2f\n", amount);   
  printf("CA Sales Tax:   $%8.2f\n", SalesTax);   
  printf("-------------------------\n");   
  printf("Total:          $%8.2f\n", total);   

  return 0;
}
```

The data type of the expression must match the data type of the variable. If they do not match, you will receive a compilation error. C is forgiving if you try to assign an integer value to a float (or double) variable. It will not be forgiving if you try to "stuff" a float value into an integer variable though.

### C Library Functions

We have more than just the standard numeric operators. We also have something more complex called numeric functions. Functions are similar to the function keys on calculator. They handle things such as square root, sine and cosine, and business calculations such as IRR (internal rate of return). The pieces of data we give the functions (inside their parentheses) are called **arguments**.

`printf()` and `scanf()` are actually functions too, but they act like statements (rather than calculate something and return a value into an expression).  They are examples of **void** functions (functions that look like statements and do an action). Functions that return values are only found within expressions; they may not stand alone as statements (as void functions like `printf()` can).

C has numerous functions available, but they are stored in **function libraries** (also known as **C header files**). Each library has a group of loosely related functions, such as math, graphics, I/O, etc. When you purchase a C compiler, it comes with several libraries; you can also purchase additional ones (and you can learn in your later courses how to create your own libraries).

In Example 3-9, we see a couple of examples of numeric functions and libraries. It extends the previous example by calculating the number of dollars and the number of cents from the total.

```c
// Example 3-9
// This program shows the use of library function calls.

#include <stdio.h>
#include <math.h>

// Variable declaration

char name[15];
int empnum;
float amount;
float SalesTax;
float total;
int dollars;
float cents;

// Main function

main() {   
  printf("**Mini Register Program**\n\n");   

  printf("Please enter your name: ");   
  gets(name);   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);   

  SalesTax = amount * .095;   
  total = amount + SalesTax;   

  printf("\n");   
  printf("Cashier: %s\n", name);   
  printf("Employee #%d\n\n", empnum);   
  printf("Amount of sale: $%8.2f\n", amount);   
  printf("CA Sales Tax:   $%8.2f\n", SalesTax);   
  printf("-------------------------\n");   
  printf("Total:          $%8.2f\n", total);   

  dollars = floor(total);   
  cents = (total-dollars) * 100;   

  printf("\n");   
  printf("Pay %d dollars and %.f cents.\n", dollars, cents);   

  return 0;
}
```

At the top of our program is a list of compiler directives (starting with a #). The `#include` directives tell us which libraries are required for this particular program.

The `floor()` function is located in the `math.h` libary and returns the highest integer value contained in the argument, or, in other words, "rounding up to the nearest integer."

Some tricky things occur with C regarding data types. In this example, your first inclination would be to make `cents` an integer variable and to use `floor` in the cents calculation to chop off any fractional cents (`cents = floor((total-dollars)*100)`). But in testing this, you'd find that the program works only as long as fractional cents above .5 aren't in the original total. If so, the output statement would round up the cents portion of the sales tax and total. This would cause a mismatch with the cents in the final display (which had been "floored". So your total might be 1 cent off from your cents amount. Thorough testing of your program with different values would have revealed this problem with the incorrect approach.

### Defined Constants

Defined constants look like variables, but they cannot be changed during the execution of the program. We define defined constants at the top of a program along with our variable declarations.

There are two ways to define defined constants.

```c
# define NAMELENGTH 19   // one way of defining a defined constant

constant float TAXRATE = .095;   // another way of defining a defined constant
```

We have two major benefits in using defined constants. The first is that the expression where the constant is used is self-documenting, creating easier-to-read programs. The second is that it lets us change the value of the constants with ease. If the sales tax decreases to 9.25 percent, then all we need to change is the constant definition line. It will then read `TAXRATE = 0.0925`. And then all we'd need to do is to re-compile the program.

### Comments

Place a comment over each important section of code, and aside any statement that needs clarification.

```c
// Example 3-11
// This program shows proper commenting in a program.

#include <stdio.h>
#include <math.h>

// Constant declarations

const float TAXRATE = 0.095;   //  current tax rate

// Variable declarations

char name[15];  // name of the cashier     
int empnum;     /* employee number         */
float amount;   /* amount of the sale      */
float SalesTax; /* calculated sales tax    */
float total;    /* total including tax     */
int dollars;    /* dollar portion of total */
float cents;    /* cents portion of total  */

// Main Function

main() {      
  /* Prompt user for information   */    
  printf("** Mini Register Program **\n\n");   

  printf("Please enter your name: ");   
  gets(name);   

  printf("%s, please enter your employee number: ", name);   
  scanf("%d", &empnum);   

  printf("Please enter amount of sale: $");   
  scanf("%f", &amount);      

  /* Calculate tax and total */   

  SalesTax = amount * TAXRATE;   
  total = amount + SalesTax;      

  /* Display results */   

  printf("\n");   
  printf("Cashier: %s\n", name);   
  printf("Employee #%d\n\n", empnum);   
  printf("Amount of sale: $%8.2f\n", amount);   
  printf("CA Sales Tax:   $%8.2f\n", SalesTax);   
  printf("-------------------------\n");   
  printf("Total:          $%8.2f\n", total);      

  /* Separate dollars and cents */   
  dollars = floor(total);
  cents = (total-dollars) * 100;   
  printf("\n");   
  printf("Pay %d dollars and %0.0f cents.\n", dollars, cents);   

  return 0;
}
```

Here is a pseudocode listing for Example 3-11. Again, you should develop your pseudocode (or Nassi-Shneiderman charts) ***prior*** to coding, to make the coding process easier.

*Display "\*\* Mini Register Program \*\*".*

*Skip a line.*

*Display "Please enter your name: ".*

*Input the name from the user.*

*Display the name and ", please enter your employee number: ".*

*Input empnum (the employee number) from the user.*

*Display "Please enter amount of sale: $"*

*Input amount from the user.\**

*SalesTax <- amount * TaxRate (note: TaxRate is constant 9.75%)*

*total <- amount + SalesTax*

*Skip a line.*

*Display "Cashier: " and the name.*

*Display "Employee #" and empnum.*

*Skip a line.*

*Display "Amount of sale: $" and amount (rounded to nearest cent).*

*Display "CA Sales Tax: $" and SalesTax (rounded to nearest cent).*

*Display a line.*

*Display "Total: $" and total.*

*dollars <- total (rounded down to nearest integer)*

*cents <- (total - dollars) * 100*

*Skip a line.*

*Display "Pay ", dollars, " dollars and ", cents, "cents."*

*End of program.*

### File Output

Example 3-11disk is the same as the previous one, except it outputs the report to a file on disk.

Files are referenced by two names. The first is the **internal filename** or the **logical filename**. This version of the filename goes by the identifier naming rules, and is how we refer to the file throughout the program. The second file reference is the **external filename** or **physical filename**, which is the name of the file in the operating system. You will only see this filename once in the program, where it "links" up with the internal filename.

Each statement that outputs to the file should uses `fprintf` instead of `printf` and have the filename as the first argument.

```c
/* Example 3-11disk
   This program shows output to a disk file. To do this, one needs to define a file variable in the declaration area as shown. The external filename, FILE, must be uppercase, and the internal filename needs to have an asterisk (*) in front of it.
*/

// Include Files

#include <stdio.h>
#include <math.h>

// Constant declarations

const float TAXRATE = 0.095;

// Variable declarations

char name[15];  /* name of the cashier     */
int empnum;     /* employee number         */
float amount;   /* amount of the sale      */
float SalesTax; /* calculated sales tax    */
float total;    /* total including tax     */
int dollars;    /* dollar portion of total */
float cents;    /* cents portion of total  */

FILE *diskfile;

// Main Function

main() {      
  /* Prompt user for information */

  printf("** Mini Register Program **\n\n");

  printf("Please enter your name: ");
  gets(name);

  printf("%s, please enter your employee number: ", name);
  scanf("%d", &empnum);

  printf("Please enter amount of sale: $");
  scanf("%f", &amount);      

  /* Calculate tax and total */

  SalesTax = amount * TAXRATE;
  total = amount + SalesTax;      

  /* Print results to disk file */

  diskfile = fopen("c:\\class\\report.txt","w");   // This opens and creates the file
  // The \\ is used because a single \ is normally used to indicate a special escape character

  fprintf(diskfile,"\n");
  fprintf(diskfile,"Cashier: %s\n", name);
  fprintf(diskfile,"Employee #%d\n\n", empnum);
  fprintf(diskfile,"Amount of sale: $%8.2f\n", amount);
  fprintf(diskfile,"CA Sales Tax:   $%8.2f\n", SalesTax);
  fprintf(diskfile,"-------------------------\n");
  fprintf(diskfile,"Total:          $%8.2f\n", total);      

  /* Separate dollars and cents */

  dollars = floor(total);
  cents = (total-dollars) * 100;      

  /* Print final portion to disk file */

  fprintf(diskfile,"\n");
  fprintf(diskfile,"Pay %d dollars and %0.0f cents.\n", dollars, cents);

  fclose(diskfile);    // Close the file or all the info won't make it to the disk  

  return 0;
}
```

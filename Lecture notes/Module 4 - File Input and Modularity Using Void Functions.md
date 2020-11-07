###### *Fundamentals of Software Development*

# Module 4 - File Input and Modularity Using Void Functions

In this module, we change the Mini-Register program to include file input several ways. With file input, we get our values from a file that was already created (typically by us, in this class). This is also called "batch" programming, and is what is used to process files where an interactive interface is not needed.

We also "go back to the drawing board", and design a new version of the Mini-Register program from scratch using modularity techniques. We will design using the Hierarchy Chart and a series of Nassi-Shneiderman Charts, and then create our code using these charts as a guide.

##### *Part A*

## File Input

Not all programs receive their input interactively. Many programs receive both interactive input and input from disk files. The program which receives all of its input from a disk file is called a batch program. But typically today, business programs receive both kinds of input. Take an ATM for example. It does screen input and output, printer output, file input (to check the validity of your card and balances), file output (to notify the bank that your balance has changed), and card reader input. Several of the programs we will do in this class receive all their input from a disk file. We will do more work with this in our section on Looping. However, the next examples show how basic file input is accomplished.

### Setting up a File for Input

Let’s say you are planning to read from a file called `register.txt` (located in the root directory of C: drive). You decide that the internal file variable will be called `inputfile`. Your file declaration would read:

```c
FILE *inputfile;
```

To open the file for reading, we use the `fopen()` function. `fopen()` requires two arguments: a string containing the operating system (physical) filename, and a string indicating that the file will be used for reading. The `fopen()` function must take place before any input statements.

```c
inputfile = fopen("c:\\class\\register.txt", "r");
```

After reading the desired data from the file, the file needs to be closed, out of courtesy to the operating system. The operating system has a limitation on the number of files that are open simultaneously. Closing the file eases the pressure on these limitations and is good programming practice.

```c
fclose(inputfile)
```

### What About the Actual Input Statements?

```c
/* Example 4-1  
   Mini-Register with disk file input
   This program does not interact with the user; it is a "batch" or "file input" program. It gets its data directly from a file on disk. It also writes its output directly to another disk file. Here the three values are all on separate lines.
*/

#include <stdio.h>
#include <math.h>

// Constant definitionsconst

float TAXRATE = 0.09;

// Variable declarations

FILE *reportfile;          /* report file (for output) */
FILE *inputfile;           /* disk file (for input)    */
char name[16];             /* name of the cashier      */
int empnum;                /* employee number          */
float amount;              /* amount of the sale       */
float SalesTax;            /* calculated sales tax     */
float total;               /* total including tax      */
int dollars;               /* dollar portion of total  */
float cents;               /* cents portion of total   */

// Main Function

main(){
  /* Get information from disk file  */

  inputfile = fopen("c:\\class\\register.txt","r");
  fscanf(inputfile,"%s\n", &name);      // first line of input
  fscanf(inputfile,"%d\n", &empnum);    // second line of input
  fscanf(inputfile,"%f", &amount);      // third line of input    
  // fscanf(inputfile,"%s\n%d\n%f", &name, &empnum, &amount);    
  fclose(inputfile);

  /* Calculate tax and total */

  SalesTax = amount * TAXRATE;
  total = amount + SalesTax;

  /* Separate dollars and cents */

  dollars = floor(total);
  cents = (total-dollars) * 100;

  /* Output results to disk file */

  reportfile = fopen("c:\\class\\report.txt","w");
  fprintf(reportfile, "\n");
  fprintf(reportfile, "**Mini Register Program**\n");
  fprintf(reportfile, "\n");
  fprintf(reportfile, "Cashier: %s\n", name);
  fprintf(reportfile, "Employee #%d\n\n", empnum);
  fprintf(reportfile, "Amount of sale: $%8.2f\n", amount);
  fprintf(reportfile, "CA Sales Tax:   $%8.2f\n", SalesTax);
  fprintf(reportfile, "-------------------------\n");
  fprintf(reportfile, "Total:          $%8.2f\n", total);
  fprintf(reportfile, "\n");
  fprintf(reportfile, "Pay %d dollars and %0.0f cents.\n", dollars, cents);
  fclose(reportfile);

  return 0;
}
```

C reads strings a little differently than integers and float numbers in disk files. For a string, the program by default reads the entire line (up to where the `ENTER` key was pressed) or up to the first space, whichever comes first. On the other hand, integers and float numbers are read by skipping over spaces and ends of lines until the program encounters a number. The data type of the number must match the data type of the variable in the `fscanf()` statement, or an execution error might occur. If the program "runs into" a non-numeric value while it's trying to read the numeric value, the program will either quit with an execution error or read a value of zero. Dev C++ compiler and most others today will NOT give an error, and will simply read a value of zero. It's this unpredictability of C between various compilers that requires that you test your programs thoroughly with a wide variety of sample data, including "wrong" data.

#### What About Lines of Data?

This last example illustrated how to read in three values. Note that with numeric input, spaces and end-of-lines are skipped, so we could have used the following statement (in lieu of the three) and received the same results:

```c
fscanf(inputfile, "%s%d%f", &name, &empnum, &amount)
```

Even though the data appeared over three lines, the end-of-lines were skipped. (End-of-line is a real ASCII/Unicode "invisible" character for Windows, it is decimal 13-the carriage return character.) If we want to definitely direct the program to advance to the next line following the reading of a value (useful for working with strings), we'd issue the `\n` character in the format specifier.

#### What if We Have Multiple Values on an Input Line?

The above example had values on separate lines. We often have data files with multiple values on a line (or on several lines). To handle this, we change our format string. If the data file for our sample program is:

```
Maria       5793  2288.74
```

*(The above line has the M in Maria starting in column 1, 5793 starting in column 19 and, 2288.74 in column 26)*

then the following statement would read it:

```c
fscanf(inputfile, "%s%d%f", &name, &empnum, &amount);
```

as well as this one:

```c
fscanf(inputfile, "%s %d %f", &name, &empnum, &amount);
```

Because we do NOT have a `\n` in the format string, the program looks for the second and third values on the same line. Of course, if it doesn't find them there, it keeps looking on subsequent lines (which is what we did in the earlier example).

#### But My Strings Have Spaces!

To read a string that possibly has spaces, we simply replace that `fscanf()` with `fgets()` (but just for the string portion of the input, not for the numeric portion). `fgets()` requires three arguments. The first is the variable that will receive the input (but without the & symbol). The second is the number of characters we are reading. The third is the file from which to read.

The function stops reading when it reads either one character less than the number specified by the second argument or when it reads a newline character, whichever comes first. Typically, you will use the same length that you used in the declaration – that number that is one longer than the maximum specified length of the string. In addition, there's a quirk to how the input proceeds. `fgets()` retains the newline character at the end of the string read. This is important to note, as this extra newline will end up displaying if we output the contents of that variable.

So for the Mini Register Program example, let's say our data was structured with the first line dedicated to the cashier name and the second to the employee number and amount of sale. The data might look like this:

```
Maria Stein
5793  2288.74
```

*(Maria Stein and 5793 starts in column 1; 2288.74 starts in column 8.)*

We would use the following statements:

```c
fgets (name, 16, inputfile);
fscanf(inputfile,"%d %f", &empnum, &amount);
```

### The Final Version – With Style

Example 4-2 uses defined constants to describe the length of the two strings. C does not allow us to use `const` constants in the declaration of the two strings (as we are allowed to do down in the body of the program). However, C does allow us to use constants defined with the `#define` compiler directive in declarations of strings, as well as in the `fgets()` functions.

```c
// Example 4-2  
// Mini-Register with disk file input, multiple values on one line, and multiple string values with possible imbedded whitespace.

#include <stdio.h>
#include <math.h>

// Constant definitions

#define TAXRATE 0.09
#define NAMELENGTH 16
#define MSGLENGTH 61

// Variable declarations

FILE *reportfile;          /* report file (for output) */
FILE *inputfile;           /* disk file (for input)    */
char name[NAMELENGTH];     /* name of the cashier      */
int empnum;                /* employee number          */
float amount;              /* amount of the sale       */
float SalesTax;            /* calculated sales tax     */
float total;               /* total including tax      */
int dollars;               /* dollar portion of total  */
float cents;               /* cents portion of total   */
char message[MSGLENGTH];   /* trailer message          */

// Main Function

main(){
 /* Get information from disk file  */

 inputfile = fopen("c:\\class\\register.txt","r");
 fgets (name, NAMELENGTH, inputfile);        // string portion of line
 fscanf(inputfile,"%d %f", &empnum, &amount);  // rest of input line almost
 fgets (message, MSGLENGTH, inputfile);      // here's the final string
 fclose(inputfile);      // Only close the file once everything has been read

 /* Calculate tax and total */

 SalesTax = amount * TAXRATE;
 total = amount + SalesTax;

 /* Separate dollars and cents */

 dollars = floor(total);
 cents = (total-dollars) * 100;

 /* Output results to disk file */

 reportfile = fopen("c:\\class\\report.txt","w");
 fprintf(reportfile, "\n");
 fprintf(reportfile, "**Mini Register Program**\n\n");
 fprintf(reportfile, "\n");fprintf(reportfile,"Cashier: %s\n", name);
 fprintf(reportfile, "Employee #%d\n\n", empnum);
 fprintf(reportfile, "Amount of sale: $%8.2f\n", amount);
 fprintf(reportfile, "CA Sales Tax:   $%8.2f\n", SalesTax);
 fprintf(reportfile, "-------------------------\n");
 fprintf(reportfile, "Total:          $%8.2f\n", total);
 fprintf(reportfile, "\n");
 fprintf(reportfile, "Pay %d dollars and %0.0f cents.\n", dollars, cents);
 fprintf(reportfile, "\n");
 fprintf(reportfile, "%s", message);
 fclose(reportfile);
 return 0;
}
```

##### *Part B*

## Modularity Using Void Functions

In **Module 3**, we looked at simple straight-line programs. No logic (other than sequences) existed in these programs. And they were relatively short and simple. Programs in the real world, however, are never that straightforward. It is generally necessary to break down our real-world program into smaller chunks (using the divide-and-conquer problem-solving methods we discussed earlier). If we do this, then our design will lead us to methods where we develop a hierarchy chart (which shows the overall structure of the programs) and several Nassi-Shneiderman charts or pseudocode (each of which shows the detailed logic in each module). As we develop these charts, we keep the divide-and-conquer method in the back of our heads, and create a multitude of interrelated modules, each of which has a distinct task.

So, in essence, we have a large difficult task which has been broken down into many easy tasks. Picture a corporate organization chart. We start out with the president on the top. Then with each succeeding level, the positions become more limited and straightforward. By the time we are at the bottom of the chart, we are talking about people who, in the grand scheme of things, have the easiest and simplest jobs.

If we can think about problems using the divide-and-conquer method, and if we can develop our formal design using the same method, then we should have a mechanism where we can lay our program out using the same method. And we do! Each of the modules I refer to can be represented by a C function. Other languages may use the term "function" also, although some use "procedure", "subprogram", "subroutine", "object method", or "paragraph". Since we are programming in C, let's use the word "function".

The function is a group of statements that are viewed as a cohesive unit. In fact, if you look at the formal design of the program, each module you see on the hierarchy chart will be represented by a function. The best analogy that I like to use to describe functions is the Internal Revenue Service's Form 1040. When you do your taxes, you use Form 1040. Form 1040 is the master document; it does things in and of itself, and also directs you to other appropriate forms. It is similar to the main function in a C program. When your Form 1040 says "now it's time for business income", it directs you to complete Schedule C. So, you put your finger on that line and hold it there (figuratively speaking).

In the C language, we would call the line that directs you to Schedule C the **function call** (or the function invocation). Holding your finger on the function call, you now go to Schedule C (which is a fairly complete "module"). In the C language, Schedule C would be considered a function. Notice that Schedule C has its own questions (logic). After we complete it, we returned to where our finger was being held on Form 1040. We then continue, starting with the line immediately after the line that reference Schedule C (the function call).

### The Pre-cursor: The Design

As we first design a program, we look at tasks that we have to complete and ask ourselves if the task is easy or hard. If it task is hard, then we'll probably want to develop a function that contains the logic for that task. The idea here is that you should strive to be "lazy" in the development of your programs. What I mean by that is that you shouldn't let detail bog you down.

Remember, our design is going to be a combination of a single hierarchy chart plus multiple Nassi-Shneiderman charts or pseudocode listings. And we will develop them side-by-side as opposed to serially. We start by drawing a single rectangle for our hierarchy chart and labeling it MAIN.

![Sample Hierarchy Chart 1](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/Sample%20Hierarchy%20Chart%201.jpg?raw=true)

Now I'll develop the Nassi-Shneiderman chart for MAIN. For the Mini Register program, let's look at our main tasks. If we do it the lazy way, we probably see only about four things happening in the main program. The first is that we're going to display the header. The second is that we're going to ask the user for information. The third is that we're going to calculate all the necessary values for our summary. And the fourth is that we're going to display our summary. As we create the Nassi-Shneiderman chart for the main program, we look at each one of these tasks to decide if it is easy or hard.

Our Nassi-Shneiderman charts looks like a bunch of stacked rectangles, each of which contains a pseudocode instruction. Later, when we discuss looping and selection, we'll introduce other shapes into the Nassi-Shneiderman chart.

The first thing – displaying the header – we'll consider easy. It's most likely just a statement or two.

The second thing – prompting the user for several items of information – we'll consider "hard". The fact that there are several pieces of information that we'll be asking for makes this more than insignificant. In the Nassi-Shneiderman chart, I"d probably put the words "Prompt user for information". I"d probably call the module GET INFO, and place that name in parentheses next to the words.

The third thing – calculating everything necessary for the summary – we'll also consider hard. We have several things to calculate, including the sales tax, the total, the number of dollars, and the number of cents. Let's put the words "Calculate tax, total and dollar cents breakdown" in the Nassi-Shneiderman box, and label the module DO CALCS.

The fourth thing – displaying the summary report – we'll consider hard too. We have several lines of output to display, so it's best to deal with that detail later. The Nassi-Shneiderman chart should say "Display the summary report", and my module name will be REPORT.

![N-S Chart for MAIN](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20MAIN.jpg?raw=true)

I'm now finished with my Nassi-Shneiderman chart for the main program. I should now go over to the hierarchy chart to add my second level modules. Look at the four modules we named in the main program's Nassi-Shneiderman chart. For each of those modules, we should draw a box on the level underneath the main program box in the hierarchy chart; each box would contain its module name. Later on, we'll use a slight variation of these module names to designate our functions.

![Sample Hierarchy Chart 2](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/Sample%20Hierarchy%20Chart%202.jpg?raw=true)

Now that we've done the design for the main program, we look at each of the modules and do the design for each of them individually. First we do a Nassi-Shneiderman chart (or pseudocode listing) for GET INFO. In this chart, each entry would probably consist of a description of the prompt and what information was being requested.

![N-S Chart for GETINFO](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20GETINFO.jpg?raw=true)

Next we'd look at the Nassi-Shneiderman chart for DO CALCS. In this chart, each entry would represent a calculation. We'd have a calculation for the sales tax, for the total, for the dollars, and then the cents. By the way, none of the statements in any of the charts above would be considered "hard"; they are all relatively easy to construct.

![N-S Chart for DOCALCS](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20DO%20CALCS.jpg?raw=true)

Finally, we have the Nassi-Shneiderman chart for REPORT. Each line of the summary would be represented by a Nassi-Shneiderman statement in a box. And in general, none of then would need to be broken down any further.

![N-S Chart for REPORT](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20REPORT.jpg?raw=true)

So now we have a completed hierarchy chart (after connecting the boxes in the same manner as an organization chart). And we also have four Nassi-Shneiderman charts. Again, the hierarchy chart shows the overall organization of the modules of the program, and the Nassi-Shneiderman charts show the logic detail for each module. This should give us enough detail to develop the source code in C now.

### Function Definitions and Types

The function calls which take place in the main function will appear along with any other main program statements. This means that they will appear as they are called within the main function. The actual statements of each function will appear in a function definition. Because we have three modules other than the main one, we'll have three function definitions. The function definitions typically appear following the main function.

Each function definition also tells us if the function is one that either (a) is to be called as a statement (meaning it returns no values), or (b) is to be called from within an expression (meaning it returns at least one value). Below we discuss (a). These are called **void functions** because there's no "answer" that is the result of the function. Examples of such functions that are predefined that we've used are `printf()` and `scanf()`.

The other type (b) are more like the mathematical functions that we've used earlier, such as `floor()`. These functions when called cannot stand alone like statements; they must be called within an expression. Their purpose is to take the information passed to them (as arguments), do some type of number or character "crunching", and return an answer value to the expression that called the function. We will discuss these types of functions in a later lecture.

The syntax of C also requires that we list the functions PRIOR to the main function. These are called **function prototypes**. Each prototype is nothing more than the first part of the function definition. It gives the compiler basic information on how to call the function, so that when execution is occurring in the main program, it knows if the call itself is syntactically correct.

```c
void GetInfo(void);    // Prototype for GetInfo function
void DoCalcs(void);    // Prototype for DoCalcs function
void Report(void);     // Prototype for Report function
```

Both the function prototype and the function definition appear with a data type in front of the name, along with some information following the name in parentheses. The data type in front indicates what the function will return. In the case of (a) above where the function does not return anything, the data type listed is void. The information in the parentheses following the name indicates what is needed by the function to execute. For now, we aren't going to use this, so we will also place the word void there. We will refer to this parenthesized information later as the parameter list.

The name of the function should be an identifier name, so you might have to slightly alter the casual name that you gave to the module when doing the program design. Following the function header are the statements of the function surrounded by curly braces `{` and `}`. Later on, we'll see that other things (such as local variables and local constants) can be defined for a given function, and that these definitions will appear within the curly braces. The first of the examples is what we are about to discuss.

By the way, this is a good time to change the way we define the main function. Let's use the full syntax from now on instead of the abbreviated syntax which we were allowed to use. The main function requires no arguments when invoked, so there are no parameters to be listed. The main function also returns an integer value to the operating system (the completion code), which is `0` if the program ends normally or some other number (defined by you) if it doesn't end normally. So the header part of the main function should be:

```c
int main(void)
```

Our other functions will be defined similarly, all based on what they need (arguments) and what they return as a value (if they do).

### The Function Call for a Void Function

Moving back to the main program, anytime we are to have a function call, we should use the identifier which names the function. In C, a void function call is indicated only by the presence of the name of the function, followed by a set of parentheses. For this first example, there's nothing placed in the parentheses.

```c
int main(void){
  printf("**Mini Register Program**\n\n");

  GetInfo();       // Prompt user for information
  DoCalcs();       // Calculate tax and total, dollars and cents
  Report();        // Display the final report

  return 0;
}
```

The order of the function calls is extremely important. The order of the function definitions, however, is not necessarily important. C only requires that the use of any identifier be receded by that identifier's definition. This is why C uses function prototypes. With the prototypes defined, there's no need for worrying about the order of the actual definitions. There's also no worry about the order of the prototypes. So in this case, the three functions referred to in the main program can be in any order up in both the prototypes and the definition.

### Let's Look at One of the Functions Here as an Example

```c
/* The DoCalcs function calculates the sales tax and total, based on the amount read in during GetInfo and the tax rate constant. It also determines the dollar portion of the total and the cents portion of the total.
   This function relies on global variables and returns no values.
*/

void DoCalcs(void) {
  // Calculate tax and total

  SalesTax = amount * TAXRATE;
  total = amount + SalesTax;

  // Separate dollars and cents

  dollars = floor(total);
  cents = (total-dollars) * 100;
}
```

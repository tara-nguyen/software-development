###### *Fundamentals of Software Development*

# Module 9 - Code Subroutines; Functions; Arguments and Parameters

In this module, we will reintroduce modularity through code subroutines.

And our final topic in Visual Basic is functions and parameter passing. In this lecture, we'll discuss the difference between subroutines and functions in Visual Basic, and will illustrate the creation of functions through the QuickInterest program. In this illustration, we introduce the topic of arguments and parameters. We also give an example of looping in the Visual Basic using one kind of loop - the for loop.

##### *Part A*

## Code (Non-Event) Subroutines

While Visual Basic itself forces a certain amount of modularity because of the many event subroutines that you'll generate, you will still have a couple of reasons to create your own regular subroutines (similar to void functions):

A single event subroutine may prove to be long and complex. It's better to approach it using the top-down approach.
There might be some common code that is repeated in several places throughout your event subroutines or regular subroutines. It's better to place this code in a subroutine and then call it when needed.
Creating and calling regular subroutines (as opposed to event subroutines) in Visual Basic is easy. The definition of the subroutine is similar to that of event subroutines, just without the underscore and the event name (such as `_click`). Come up with a name for the subroutine using standard identifier rules (such as `EnableAllCheckboxes`). Some Visual Basic programmers like to precede regular subroutine names with sub (such as `subEnableAllCheckboxes`). By the way, for brevity I call these non-event subroutines **code subroutines**, simply because they deal with modularization of code rather than events.

Let's revamp the WelcomeUCLA program to include regular subroutines. Let's say we are writing the main "form_load" subroutine, and we know that we are going to need to do some statements to prepare the form for default Student status. And we'll also need to do several actions during run-time (when the user clicks the Student checkbox) to either reflect the status as a student or as a non-student. Using a top-down approach (actually the "lazy way" approach that makes layered development the easiest way to develop), we see that these are excellent places for subroutine calls. I would like to think we are either "enabling all the student stuff" or "disabling all the student stuff". Why not reflect this in our code?

When in `frmWelcomeUCLA_Load`, let's issue a statement that calls a subroutine that "enables all the student stuff":

```vb
EnableStudentStuff()
```

This is a call to the subroutine that we are going to write called `EnableStudentStuff`. It is similar to a void function call in C.  Interestingly, Visual Basic also allows one to call a subroutine by using the keyword `call`, such as:

```vb
Call EnableStudentStuff()
```

Here is how we would call it and its "alter-ego" subroutine `DisableStudentStuff` inside of the `chkStudent_CheckedChanged` event subroutine:

```vb
Private Sub chkStudent_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles chkStudent.CheckedChanged
    If chkStudent.Checked Then
       EnableStudentStuff()
    Else
       DisableStudentStuff()

    End If
End Sub
```

Let's see how the actual subroutine definitions will look. Non-event subroutines can be placed pretty much anywhere in the code. I prefer to place them just after the Windows Form Designer-generated code and before the event subroutines. Other than that, they can be in any order, even if one of them calls another one. Here's the definition for `EnableStudentStuff`:

```vb
Private Sub EnableStudentStuff()
   lblMajor.Enabled = True
   cboMajor.Enabled = True
End Sub
```

And here's the definition for `DisableStudentStuff`:

```vb
Private Sub DisableStudentStuff()
   lblMajor.Enabled = False
   cboMajor.Enabled = False
End Sub
```

In both cases, we use the keywords `Private` and `Sub` prior to the name of the subroutine. `Private` means that the subroutine can be called from anywhere in the form's code. `Sub` means subroutine, as opposed to `Function`.

##### *Part B*

## Visual Basic Functions; Arguments & Parameters

### Arguments and Parameters ("Parameter Passing")

Our final Visual Basic topic involves an important concept that we touched on briefly earlier in the course - arguments and parameters - also known as "parameter passing". The ability to create multiples of functions and subroutines written by many different programmers past and present is facilitated by parameter passing. It's how you utilize the many predefined functions and subroutines in C and Visual Basic, and it's how we create functions and subroutines for future use by others. Arguments are the expressions and variables you place in the parentheses when calling a routine; parameters are the special variables you define inside the routine to "catch" the arguments as they are passed in.

We've been passing arguments into various predefined C functions (void and other) and Visual Basic subroutines and functions quite easily; we do this to give the function or subroutine the data it needs to do its job without relying on any global variables. In other words, the function or subroutine should be seen as a sort of "black box"; no data gets into it except through parameter passing. So far in this course, we have violated this guideline when creating our own C void functions and Visual Basic subroutines; we've relied on existing global variables (variables declared at the main program level) to carry information in and out of these routines. This may be fine for the small programs you've been doing. However, when we increase the scale of our development - larger programs, more programmers, longer time spans - it's imperative we employ a more modular structure that isolates each routine into a "black box". This way, we'll have the following benefits:
- Each function or subroutine can stand completely on its own, utilizing only its own local variables and parameters. No global variables will be employed. This makes the routine fully modular, usable in any program.
- The now fully modular routine can be fully tested and certified using unit testing.
- The routine can be included in a C library/header file or a Visual Basic code module for easy deployment in future programs.
- Dozens or hundreds of programmers can work on their thousands of individual routines, and they can fit together in a clean component-like way.
- Programmers in the past/present can create routines for use by others in the future. The only information they need to provide is: the name of the routine, how it's called (function or subroutine), what it does in general, what kind of argument data needs to be passed, and it what order.

### Anatomy of a Visual Basic Function

In C, we spoke of void functions (which are called as statements) and functions that return a value (which are called from within expressions). Well, in Visual Basic, the terminology is different. A C void function is referred to in Visual Basic as a **subroutine procedure** (or just **subroutine**). A C function that returns a value is referred to in Visual Basic as a **function procedure** (or just **function**).

When we define a function, it's absolutely necessary to establish what information is going to be passed when the function is called. We need to set up the following:
- what types of values need to be given to the function to do its job
- the order of these values
- what type of value the function will return when it is finished executing

So from the calling side, we need to specify how the arguments are arranged and what data types they need to be. Witness the `math.round()` predefined function. This function rounds its first argument to the number of decimal digits specified by its second argument. Here are some samples (assume the variables are already declared and have values):

```vb
years = math.round(age,0)

SalDollars = math.round(salary,0)

bracket = (math.round(salary,0) / 10000) + 1
```

The `math.round()` function has two arguments, and they always appear in that particular order. The first is a floating point number (either single or double) and the second is integer. Moreover, the function returns a single value (as all functions do), and this is an integer value. So all three variables (`years`, `SalDollars`, and `bracket`) will be receiving integer values.

Now, this function is already predefined, so there's no need for us to define the function to use it in our programs. However, to illustrate how parameters are set up, if it were *not* already defined, we would set up the first line of the definition as follows:

```vb
Private Function math.round(ByVal NumToBeRounded as double, ByVal NumOfDigits as integer) as double
```

Because we want the programmer to call this function and pass two arguments in the order we discussed, we now need to specify a corresponding "parameter list". This parameter list is very similar to a local declaration. In fact, the parameters themselves are nothing more than variables. What makes them special is that they will receive an initial value once the function starts executing. Whatever their corresponding argument is, they receive that value. Because we want to have two arguments, we will have two parameter definitions in the parameter list. Parameter definitions in the list are separated by commas.

The first parameter definition is:

```vb
ByVal NumToBeRounded as double
```

The `ByVal` keyword is there to indicate that the parameter will be receiving the value of the argument expression. In other words, using the three examples above, it would be receiving the value of the variable `age` or `salary`. In the parameter passing world, we called this **passing by value**, and it is the most common type of parameter passing, especially with regard to functions. The other type of parameter passing is called **passing by reference**; this would occur if we did not place the `ByVal` keyword there. Passing by reference is used when we have a variable as the argument and we want the parameter to act as an alias for that variable while in the routine.

The next item in the definition is `NumToBeRounded`. This is the name of the parameter. Again, since a parameter is nothing more than a glorified local variable, we can use any acceptable Visual Basic identifier name here. Because this is the actual declaration, this identifier should not be declared again anywhere inside this function. And if this particular identifier appears anywhere else in the code for the form or application, it actually has nothing to do with this particular function. The concept of "local" is just that. `NumToBeRounded` is created once this function is called, and it dies once this function terminates.

The final two words in the definition are `as double` and this acts to declare `NumToBeRounded` as a `double` floating-point variable.

The element that lies to the right of the closing parenthesis in the function definition is not part of the parameter list. It is the return value data type. This tells Visual Basic what type of value the function will be returning. So, if `math.round()` will return a double value, the definition will conclude with:

```vb
as double
```

Now that we see what the main definition line is, let's move to the items inside the function. Before the actual code statements appear, any variables that are needed will be declared. Because these variables are used only inside this function, they are called "local variables". Their syntax is the same as when you declare global variables, except that the declaration lies within the function. For example:

```vb
dim RoundedValue as double
```

The final statement that is to be executed in a function should always be the "return" statement. In the C language, we actually used the keyword `return`, but in Visual Basic we use instead the name of the function. So let's say that `RoundedValue` has been given its final answer value. Then the final statement in the function will be:

```vb
math.round = RoundedValue
```

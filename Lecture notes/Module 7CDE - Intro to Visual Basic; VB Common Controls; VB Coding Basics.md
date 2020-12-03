###### *Fundamentals of Software Development*

# Module 7CDE - Intro to Visual Basic; Visual Basic Common Controls; Visual Basic Coding Basics

## Intro to Visual Basic

Visual Basic (VB) approaches programming from a completely different angle than traditional programming languages. With VB, one designs and specifies the user interface first, and then adds functionality to it via programming. In the final lectures of this course, you will gain basic familiarity with VB forms, controls, and coding.

### An Example to See Now and Build Later - Welcome to UCLA Program

Here's what the program we are going to develop will look like:

![Welcome to UCLA Program Interface](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/Welcome%20to%20UCLA%20Program%20Interface.png?raw=true)

While this program doesn't really accomplish anything in the end, it illustrates the main features of a Windows interface. The program asks that the user enter a name (string value) in the top text box and an age (numeric value) in the text box underneath. The age is validated, meaning it is checked to ensure that it meets the requirements of the specifications: age must be numeric. If validation fails, a "message box" is displayed showing an error message. The user must click OK to acknowledge the box before continuing. A validation test can be issued at any time, based on what the specs say. In this particular example, age is not validated until the user clicks on the Increase Age command button. Obviously, one cannot add 1 to the age unless age already contains a number. So the error message appears if age is either blank or contains a non-numeric value.

The user can either check or uncheck the Student and Resident checkboxes. When Student is checked, the user has access to the combo box and can select a major; when it is unchecked, the combo box is grayed out (we say that it is not enabled). When Resident is checked, the user has access to the group box and the radio buttons indicating the Residence Hall; when it is unchecked, the group box and radio buttons are disabled (not enabled) and the user can't select a hall.

The user can select a major from the combo box (in Dropdown List style). Based on which major the user selects, an appropriate enrollment message appears toward the bottom of the form.

The user can click on either of the buttons (the ones that give a command) at any time. Clicking Increase Age adds one to the value in the text box next to Age (as long as it contains a number already, otherwise an error message appears as described above). Clicking Exit terminates the program.

The user can select any of the menus and any item of that menu that is not disabled (grayed out). The appropriate action will result.

Clicking on the Exit button (or on the `x` in the upper right corner of the window) exits the program. You must exit it prior to editing the form or the code.

## VB Controls

Let's examine the interface of the WelcomeUCLA Program in detail to better understand its elements.

### Project

A VB program (or application) is developed by creating a **project**. One or more projects (VB, C#) can co-exist in a space called a *solution*. We'll only be working with single-project solutions in this class.

A project consists of one or more forms (showing the interface and containing program code), zero or more modules (containing program code), and other ancillary elements. When creating a project, you will give it a name, and all the necessary files will automatically be created on disk which describes the various elements in the project.

### Forms

The **form** is the first control we'll be dealing with and is the basis for our application. Any window that appears when a program is running is actually a form. Every application has at least one form; most professional applications utilize several. Program code is placed "behind" each of the forms, as well as in a special area called a *module*. For this course, we will only work with single form applications that do not employ modules.

Each form in a VB project will be stored in a *form file* (`.vb`) on disk, plus a *companion file* (`.designer.vb`). The default form is Form1. On this form, we will place the various controls that collectively form our interface. Each control will be given a unique name and we will use the Properties Window to alter the basic attributes of a control.

### Labels

"**Welcome to UCLA**", "Name", "Age" and "Major" are all called labels. Labels are simple text that is displayed on the form. They are typically for titles and for prompts. They can be displayed in a variety of ways, including with or without the 3D effect, in any font or font style, with one of several alignments, and in any color and with any color background. The ones shown are in the most standard style. There is also a label that selectively appears toward the bottom of the form; this label displays a message based on which major is selected. It's possible to make a label visible or invisible at will during execution, as well as to change what a label displays (including the null string).

### Text Box

The boxes next to "Name" and "Age" are called text boxes. Text boxes are used for inputting numeric and string values into the program. As with labels, the programmer can format a text box to present its text in a variety of ways. In fact, it's possible to create a text box that looks just like the standard label, and vice versa.

### Button

"Increase Age" and "Exit" are examples of buttons. Clicking on one of these performs a certain action. We typically set these to execute VB code upon the click. The code is hidden in the background.

### Checkbox

"Student" and "Resident" are examples of checkboxes. A checkbox can be either Checked or Unchecked. We use checkboxes for items that have only two possible states. We often execute some type of VB code based on changing the status of a checkbox.

### Radio Button and Group Box

"Sproul Hall", "Saxon Suites" and "DeNevePlaza" are examples of radio buttons. This term came from the days (1960s) when we had car radio selector buttons that popped out when a different button was pressed). They are grouped together in a group box, which is labeled "Residence Hall". The user may select one radio button only in a group box. Upon performing the selection, any other button that had been selected immediately becomes non-selected. We typically execute some type of VB code based on which option is selected.

### Combo Box

Finally there is a combo box. Combo boxes are like text boxes with a list of possible options that drop down below the box upon selection. Depending on how you set the DropDownStyle property of a combo box, you may or may not be able to edit (as opposed to replace) the value in the box after selecting it. In this course, we will use the DropdownList style of Combo Box, which does NOT allow the user to edit the list or to enter their own value; with Dropdown Lists they are only allowed to selected one of the values already in the list. This is the most common style seen in Windows-based programs.

### Menu Bar and Menu Item

A menu bar containing various menus appears at the top of the window. On each menu are several menu items. A menu item is typically an action or set of actions to be performed or a state to be set. For instance, the Scenarios menu displays two different menu items. Selecting Graduate Student initiates an action - the setting of various controls: it "checks" the Student checkbox and selects DeNevePlaza as the residence (which shows as enabled only if Resident is checked". (We are assuming here that DeNevePlaza is the campus' grad housing complex.)

### Properties That Are Most Often Modified

For most of the controls we will work with, we only need to alter 2 or 3 properties. Some are automatically altered simply by where we place a control on the form (such as height and width). Some are altered during execution by what the user does interactively. We can change properties at design time (now) by entering values directly, or we can have our program code alter them during execution.

Here are the properties which are most often modified for each control:
- Form controls - (Name), Text, FormBoderStyle
- Label controls - (Name), Text, Font, TextAlign, AutoSize, BorderStyle
- Text box controls - (Name), Text
- Check box controls - (Name), Text, Checked, CheckState
- Combo box controls - (Name), Items, DropDownStyle
- Group box controls - (Name), Text
- Radio button controls - (Name), Text, Checked
- Button controls - (Name), Text

## VB Coding Basics

You can see how easy it is to create the interface for a VB program. It really involves mostly clicking and dragging. But for the real functionality in the program, it is necessary to write VB Code "behind" all of the controls.

### The VB Interpreter

Visual Basic uses an interpreter to check your code as you type it in. It can only check basic syntax of a statement, but it cannot check things that stretch over several procedures. When you build a VB program, the interpreter checks the entire program as a unit and can flag additional errors. And even more errors can appear during run-time. With the built-in debugger, you even have the ability to step through your program one statement at a time to check what it's doing.

When creating an .EXE file, you are then running the VB compiler. The compiler actually converts your code into an intermediate object program so that it can run much more efficiently. The .NET Framework must then be installed on a computer in order for the object program to run. A Windows computer that keeps up its updates should have the .NET Framework already installed.

### Basic Code Structure

In a nutshell, VB code is made up of global declarations of variables, along with several event procedures that tie directly to individual controls on a particular form (and to the form itself). These are referred to as private procedures. We can also have public procedures which can be called from any of the event procedures in any form across the application. Some procedures contain code and perform one or more functions (similar to void functions in C); these are called subroutine procedures. Other procedures perform various calculations and logic and return a value directly into an expression in the calling procedure; these are called function procedures (and are like the functions in C that return a value).

For this class, we will limit ourselves to single form applications, hence, we will discuss only private procedures. If you study VB further, you will learn more about code modules and public procedures. Procedures themselves can have local variables and parameters as we will see illustrated in Module 9.

When double-clicking on a control, you open up a code window that allows you to write code for an event procedure. The skeleton of the most likely event of the control is presented to you automatically in the code window. However, this is only for convenience. The actual code of the program is NOT a disjoint bunch of procedures; it's actually all in one large document (similar to a C program). You are allowed to scroll anywhere in the program to add, delete, or alter the code.

Keep in mind, too, that the event that pops up on double-clicking is not necessarily the event you'd like to develop code for. For every control, there are literally dozens of possible events. We will stick with the most likely event for each control for this course.

Throughout the code you will see comments. VB comments are preceded by a single quotation mark (`'`). They may appear on the same line as actual code or on a line by themselves.

VB is NOT a free form language like C or C++. Each statement appears on a separate line, and there is no punctuation necessary to separate statements. Any statement that needs to continue to the next line, however, must employ a statement continuation symbol (the underscore `_`). So this sample statement:

```vb
txtAge.Text = txtAge.Text + 1
```

could be represented as:

```vb
txtAge.Text = txtAge.Text _
+ 1
```

#### Initializing Combo Boxes via `Form_Load()`

An important procedure in every VB program is the `Form_Load()` for each form used in the program. This procedure is automatically executed whenever a VB form is loaded and displayed. It is used to set the initial values of variables as well as values and properties of controls. Remember I mentioned that you had the option of setting initial values directly when designing the form, or you could do it via runtime code? Well, this is where you would do it via code. Again, the benefit is that you can easily document the setting of the initial values here.

`Form_Load()` in VB is actually named for the form itself, so if the form name is *frmWelcomeUCLA*, then the actual name of the subroutine procedure is `frmWelcomeUCLA_Load()`.

To create `frmWelcomeUCLA_Load()`, make sure you are viewing the form itself. Find a blank location on the form and double-click. This will open up the Code window, which is where you will enter the statements for `frmWelcomeUCLA_Load()`. You'll notice that the "skeleton" (the top and bottom lines) of `frmWelcomeUCLA_Load()` is already present for you, and the cursor is placed where you will start entering statements. (Images will look slightly different depending on which version of Visual Basic/Studio you are running.)

![frmWelcomeUCLA_Load()](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/frmWelcomeUCLA_Load.jpg?raw=true)

The top line is the header for the procedure. It indicates that the procedure is private (only usable in this form), that it is a subroutine procedure (similar to a void function in C, rather than a function procedure that returns a value), and that the name of the procedure is `frmWelcomeUCLA_Load()`.

The bottom line (the trailer or footer line) indicates the end of the procedure.

We can now type our statements in between these two lines. Most VB programmers indent 3 spaces for statements.

#### Setting Default Values for Controls Using frmWelcomeUCLA_Load()

When the program starts, let's say we'd like the Major to be pre-selected to a default value of "Mathematics". Why? Let's assume the specs say so. We'd also like the Student check box to be checked already, the Resident check box to be unchecked, and Saxon Suites Hall to be the default residence hall (even though Resident will be unchecked). We will use assignment statements to set these initial values.

Assignment statements in VB look like those in C, although string assignments are much easier in VB. The next batch of statements should be typed below the `Private Sub frmWelcomeUCLA_Load()` line:

```vb
cboMajor.Text = "Mathematics"    ' Display Math as the major
rdoSaxon.Checked = True          ' Saxon as the default hall
chkStudent.Checked = True        ' Assume this is a student
chkResident.Checked = False      ' Assume not a resident for now.
```

#### Enabling and Disabling Controls

For many reasons during execution, the programmer may want to disallow the use of certain controls, usually because they are not relevant to the user at that time. The user will see this disallowance by seeing the controls "grayed-out" where it is impossible for the user to change the control or enter a value into it. We call this *disabling* or *dis-enabling* a control. To change it back to normal so that the user has access to it, we *enable* the control. Like with most things, there's a property for this called Enabled. Enabled can be either True or False. True means the control is enabled; False means that it is disabled.

We can set an initial value for this property by entering it directly into the property sheet, but better, let's do it via code. Since the default value of the Resident check box is that it is unchecked, logic tells us that the entire Residence Halls group (the "frame" and the three radio buttons inside of it) should all be disabled at the start of the program. Only when the user clicks on a checks Resident should these controls be re-enabled. So let's place the following statement just before the footer of the procedure definition:

```vb
grpResidence.Enabled = False ' Disables entire RH group
```

This statement disables all the controls located in the group box grpResidence, including the three radio buttons.

Note that even though we had earlier selected Saxon Suites (rdoSaxon), we can still disable it. You'll see during runtime that it is still selected, even though it is not accessible by the user.

#### The Simplest Event Procedure - `btnExit_Click()`

Now that we've handled the things that will happen upon the form being loaded, let's turn our attention to things that will happen in response to events. An event occurs when the user does a particular action on a particular control, such as:
- Clicking on the Exit button
- Clicking on the Resident check box
- Choosing one of the residence halls

We specify event procedures to indicate what actions will take place once a particular event occurs. These event procedures are automatically invoked by Visual Basic upon the occurrence of an event, although it is possible to call them from our code too.

Let's first discuss the simplest of all the event procedures in this program. The button control we created for exiting the program, btnExit, should exit the program when clicked. (In fact, most of the controls that are buttons or combo boxes do their main action when they are clicked.) So we need to create an event procedure to take place when this happens.

The VB way for closing the current form is to call one of the methods of the form. Remember, methods are the built-in procedures for a particular class; it's what an instance of a particular class knows how to do. Forms know how to close themselves; they use the `Close` method. And the current form is more easily referred to `Me` instead of by its full name. Hence, the code for `btnExit_Click()` is:

```vb
Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
    Me.Close()
End Sub
```

#### Selection with the If-Then-Else Statement

The structure of the `if` statement in VB is a bit more intuitive than in C, as it is line-oriented. The first line presents the Boolean expression which is to be evaluated as `True` or `False`. This is followed by one or more lines that will be executed if the Boolean expression is `True`.  If there is no `else` part, a line then appears that indicates the end of the `if` statement. The structure is:

```vb
If boolean expression Then
   statement
   statement
   statement
End if
```

The indenting is purely for style reasons, although the VB editor is so smart it does the indenting for you automatically.

If there is an `else` part, it follows the `then` statements and is ended with an `end if`:

```vb
If boolean expression Then
   statement
   statement
   statement
Else
   statement
   statement
   statement
End If
```

Boolean expressions in VB are a bit simpler too. No parentheses are needed for a simple Boolean expression. And a simple equal sign (`=`) is all that is required to test for equality. Inequality is tested using the operator `<>`. The words `AND` and `OR` and `NOT` are used instead of `&&`, `||` and `!`. And because the precedence hierarchy of VB matches that of Excel and most other languages (other than the C/C++/Java family), it is proper to parenthesize each of the sub-expressions that are linked by `AND`, `OR` or `NOT`:

```vb
If (blah.txt = "Orange") OR (blah2.txt < 4) then
```

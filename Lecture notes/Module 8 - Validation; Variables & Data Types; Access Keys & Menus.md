###### *Fundamentals of Software Development*

# Module 8: Validation; Variables & Data Types; Access Keys & Menus

Module 8 brings us further into Visual Basic (VB), where you'll be able to do a variety of things to make your programs more sophisticated:
- We will introduce a simple form of validation to ensure that the user's response is proper. With this, we will introduce an object class called MessageBox that will help us.
- Variables are generally desirable in programs in order to process things. We will look at variables, defined constants and a couple of common data types.
- We'll look at making our interface more powerful and accessible using access keys and menus.

##### *Part A*

## Validation and the MessageBox Control

The one place where this program can stand some user input validation is with regard to the age. If the user enters an age that is non-numeric, the program will crash and go into a debug state. Or if the user does not enter anything into that field, the program will crash. It would be best to not let the Increase Age calculation happen if that text box contains a non-numeric value (including being empty, which we commonly called the "null" string).

We can check to see what was entered upon the user clicking on the Increase Age command button. There are other ways to perform validation in this example, but this is the easiest and most direct way. If what was entered into the Age text box is not numeric, we can display an error message. And if it is ok, we can then add 1 to it.

Visual Basic has some terrific built-in functions, including several that are useful in validating data. `IsNumeric()` is a Boolean function that returns a value of `True` if the argument is numeric and `False` if not. We'll use this function in this program, testing what's in the text box (`txtAge.Text`):

```vb
   .
   .
   .
If IsNumeric(txtAge.Text) Then
   txtAge.Text = txtAge.Text + 1
Else
   .
   .
   .
```

### Modality in Visual Basic programs - Keep it Limited!

You know when you are in a program and you go to Print or Save? The window that appears to let you enter your print or save options is called a dialog box. You have to set or select the necessary options and you can't do anything else until clicking OK or Cancel or Print or Save. The fact that you can't do anything else means that the dialog box is modal. If you could click back to the main part of the same application without finishing or canceling the dialog box, then it is considered non-modal. In event-driven environments, it is generally considered a good thing if the use of modal forms and windows is minimized. Sometimes it's necessary to use them. It's just that if you need not lock a user into a particular place or "mode of operation", then don't.

One excellent place for a modal dialog box, though, is when you wish to display an error message. You want the user's attention, and you want to ensure that they see and acknowledge the error message. A modal dialog box would accomplish this, and one particular type - a message box (MsgBox) - would be very simple to implement.

### The MessageBox - a perfect modal tool

The MessageBox is an easy-to-use built-in modal alert box (and is a control) that pops up on screen to display a message and waits for the user to press a button in the box. It is commonly used for informational, warning and critical error messages. To display the a MessageBox, you need to invoke its `Show()` method and pass along some arguments.

```vb
MessageBox.Show("Age must be a number", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
```

This call shows four arguments being given to the `Show()` method upon calling it; they determine how the MessageBox will be displayed and what will be displayed in it. The MessageBox is a small window that displays a message, a box title (which appears in the header of the window), an action button or set of buttons, and optionally a graphic indicating the severity of the error. The first argument is a string (or string expression) which contains the message to be displayed. The second argument is a string expression which gives what is to be displayed in the title bar of the window.

The third and forth arguments are optional. If you leave the third argument blank (showing two commas adjacent if you are going to include the fourth argument), you'll get a standard message box with an OK button for acknowledge. However, you can place one of several predefined Visual Basic constants there and it will include a different button or set of buttons depending on which constant you use. For our purposes, we can just use the default and either leave it blank or choose `MessageBoxButtons.OK` from the pop-up list, which does the same thing. Other button sets (such as Yes vs. No) are meant to be used by calling the method as an expression (typically in an `if` statement condition or on the right side of the `=` in an assignment statement [for example, `Yes` would give a value of 6 and `No` would give a value of 7]).

If you include a fourth argument, you will receive a graphic icon (and a sound) when your MessageBox is displayed. The three most common ones are *Information*, *Exclamation* and *Stop*, all preceded by `MessageBoxIcon` and a period. Each of these produces a MessageBox with a symbol indicating the severity of the error or message. *Information* gives a white I on a blue background, showing that the message is strictly informational. *Exclamation* shows a black exclamation point on a yellow triangular background, one of the international warning symbols. *Stop* shows a white X on a red circle. Choose your constant carefully to reflect the appropriate level of concern the user should exercise! An input error would generally be accompanied by *Exclamation*.

### Being Nice to Your User - Clearing the Text Box and Relocating the Focus to it

After displaying an error message to a user, you should try to minimize the number of steps the user would need to take to eliminate the error and type something correct. Otherwise, the user would have to grab the mouse, point to the text box, highlight what's in it, and then either type the correct input or delete the incorrect input and then type of it. That's a lot of irritating work! (Even though it just takes 3 seconds.)

It would help the user if you did some of this work for them. Two approaches could be considered:
- Clear the text box of the erroneous user input, then relocate the focus (the user cursor) back to the text box so the user can type the correct input; OR
- Relocate the focus back to the text box, and then highlight (Select All) the erroneous user input. When the user starts typing the correct input, the highlighted incorrect input will vanish.

These actions can easily be accomplished by calling on some of the methods of the text box. The text box knows how to clear its text property; use the `Clear()` method for this. To relocate the focus to the text box, use the `Focus()` method. And finally, to highlight all of the text in the text box's text property, use the `SelectAll()` method.

So the following code should replace what was previously in btnIncreaseAge_Click( ). Please make the appropriate changes, and run and test the program.

```vb
Private Sub btnIncreaseAge_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnIncreaseAge.Click

   ' Here we must validate txtAge to make sure it is numeric,
   ' otherwise we end up with an error when trying to add a number
   ' such as 1 to it.

   If IsNumeric(txtAge.Text) Then
      txtAge.Text = txtAge.Text + 1

   Else ' display an error message box
      MessageBox("Age must be a number","User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)   
      txtAge.Clear()
      txtAge.Focus()

   End If

End Sub
```

##### *Part B*

## Variables, Defined Constants and Data Types

### Do We Even NEED Variables?

We've accomplished a lot so far without even using variables! But we do still need variables. In fact, my preference is to NOT use text boxes and labels (Text property) to carry values in the same manner as variables. I like reserving their use strictly for user interaction.

Text boxes accept input from a user. So I like to use them only for that purpose. Once we get into the actual processing of what was input, I like to transfer (assign) the value that was input into a variable for further processing. I then use the variable exclusively throughout all processing. Then, when ready to output something for user view, I transfer (assign) the value of that variable (or whatever I'm outputting) into the caption property of a label. That action is what displays the value.

Of course, all of this depends on if the interface designer is properly using text boxes only for input and labels only for output. An interface designer may choose to use a text box when they probably should be using a label. They may have a specific reason to do so, even though it runs against the advised industry interface guidelines. But in general, you'll find that text boxes are used for input and labels are used for displays of values (even if made to look like a text box by changing some of the attributes).

### Variable Declarations

Similar to C and other languages, variables can be declared globally as well as locally. In VB, global variables are available through the form (and possibly throughout all forms in the application, if you add the `Public` keyword to the declaration). Local variables are available only inside a procedure, whether it be a event subroutine, non-event (general) subroutine, or function.

#### The Global Declarations Area

Let's go to the first part of the the code - the global declarations area. This area sits at the top of the code. To get to the code, click on the code tab or choose View/Code from the menu. You may have to double-click on the actual form icon in the Project window if Code is grayed out in the View menu. Once you see the code, choose (General) from the pulldown list on the top left of the code. This will bring up the declaration area.

Alternatively, once you get into the code, you can PgUp repeatedly or Ctrl+Home to get to the top. Any declarations you type at the top will automatically designate that top area as the declaration area.

In this area, it is customary to place a block of comments describing the program and its revisions and programmers. For instance, you could enter these two lines:

```vb
' WelcomeUCLA Program - illustrate various Visual Basic features
' by Keith Jefferies
```

Remember, VB is line-oriented, so each line is preceded by a comment symbol (single quote mark). You may place a comment on a line by itself or on a line with code. All comments and code should be placed between the `Public Class` and `End Class` lines.

All variable declarations in VB are "explicit"; there has to be a line declaring the variable; no automatic declarations occur. In this particular program, we are declaring only one string variable and one integer variable:

```vb
Dim intAge As Integer
Dim strEnrollRoom As String
```

The `Dim` statement declares a variable for use. By default, the data type is `Variant` if not otherwise specified. This is a special "open" type which allows either numeric or text data to be stored. You can also declare a variable to be of a specific data type, as we are doing above with these.

### Defined Constants

VB supports the definition of constants. We are going to modify the program by assuming that all majors will send people to the Murphy Hall Registrar location unless otherwise noted. So we could say that "Murphy Hall Registrar" is the default string for a location. Here we define `DefaultEnrollArea` to be equivalent to the string literal "Murphy Hall Registrar":

```vb
Const DefaultEnrollArea = "Murphy Hall Registrar" ' The default enroll area
```

Like the #define of C, a constant definition does not need a variable type. It simply says that if one uses DefaultEnrollArea in a statement, it really means "Murphy Hall Registrar" - nothing more, nothing less.

### String Variable Assignment & Concatenation

We want the label caption to display something like this:

```
Enroll room: Rolfe Hall Lobby
```

This is string is actually two parts. The first part is the literal `"Enroll room: "`. The second part is the enrollment area. So we can let the variable `strEnrollArea` stand in for the second part, and have it be given a value using the nested-`if` statement.

Go back into your code and change the `cboMajor_SelectedIndexChanged` procedure to the following:

```vb
Private Sub cboMajor_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles cboMajor.SelectedIndexChanged
   If cboMajor.Text = "English" Or _    ' Just showing you an example of splitting a statement over two lines
       cboMajor.Text = "Kinesiology" Then
       strEnrollRoom = "Rolfe Hall Lobby"
   ElseIf cboMajor.Text = "Cybernetics" Or cboMajor.Text = "Mathematics" Then
       strEnrollRoom = "Boelter Hall 6267"
   Else
       strEnrollRoom = DefaultEnrollArea       ' Here we assign a constant
   End If

   ' Now display the enrollment message in that label area at the
   ' bottom of the form

   lblMessage.Text = "Enroll room: " & strEnrollRoom

 End Sub
```

The concatenation operator is the ampersand (`&`). So here we join three strings together and the resulting string is assigned to the Text property of `lblMessage`. The & is a great operator in that it can join together strings and numeric values to result in a string. You can also use the plus sign (`+`) for concatenation, but it only works when all parts are strings.

### A Template for Validation

My strong preference in a VB program is to input and validate using a text box, but once we know that the input is a proper number, it's best to assign it to an appropriately-typed variable and use that variable for all future assignment and manipulation. Then when we are ready to display it, we can assign it to the text property of a label or text box. This turns out to be a bit more efficient for the compiler, who then doesn't have to waste RAM doing arithmetic with variant values, which is highly inefficient.

For the brief example above, we can illustrate this by using the intAge we declared earlier. And let's add more validation, ensuring that the age is a positive number and below 120. When doing multiple validations, you should always first test to see if the entry is numeric, and then test to see if it is in the proper range. (Any other order would cause an error when you check a non-numeric against the low or high of the range). We can do all this with a linear-nested `if`.  We will "flip" the if statement from what it was, so that we can now test for Validation #1 (non-numeric), Validation #2 (0 or less), and Validation #3 (over 120). In each case, we will test for the error situation, and True will get us a Then part that displays the error message. If we fail all of these tests (meaning the input IS indeed valid), then we can end up in the last else that transfers the entry to a variable and then handles all the processing.

Let's use this code instead:

```vb
Private Sub btnIncreaseAge_Click(sender As System.Object, e As System.EventArgs) Handles btnIncreaseAge.Click
   If Not IsNumeric(txtAge.Text) Then 'Validation test #1 "Passing" a test means the Boolean is False
      MessageBox.Show("Age must be a number", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
      txtAge.Clear()
      txtAge.Focus()
   ElseIf txtAge.Text <= 0 Then 'Validation test #2 We can now assume txtAge.Text has a bona fide number
      MessageBox.Show("Age must be greater than 0", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
      txtAge.Clear()
      txtAge.Focus()
   ElseIf txtAge.Text > 120 Then 'Validation test #3
      MessageBox.Show("Age must be 120 or less", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
      txtAge.Clear()
      txtAge.Focus()
   Else 'All tests were "passed", meaning all Booleans above were False
      intAge = txtAge.Text 'Only now can we assign the value to a variable, since it's definitely an integer
      intAge = intAge + 1 'This is the actual "processing"
      txtAge.Text = intAge 'Transfer back into the textbox after processing to output to the screen
   End If

End Sub
```

Note that we do the test with the text box and that we do NOT attempt to assign the entry to the variable immediately. Always do the validation on the control, and then only if all tests are passed do you then transfer the value to the variable.

We then do ALL the processing we need to do with the variable; in this case, it only happens to be a single statement. But it COULD be dozens of statements. Then we assign it BACK to the `txtAge`'s `Text` property strictly for display.

The idea is that once we've shown that it is a number, we shouldn't need to test for that again, and we should have all the benefits, functions, and operations that working with numeric variables and operators gives us.

### Summary (Part B)

We've seen in this lecture how to declare variables and how to define constants, as well as seeing some operations one can perform with strings variables and strings, such as concatenation. We've also seen how to perform user input validation and how to display an error message using `MsgBox`.

This short WelcomeUCLA program shows how sophisticated Visual Basic is. Do you notice that we still haven't covered looping in VB? In a procedural language, a loop is required to do validation. But with VB, such looping is inherent in the user interaction with the form. Without getting complicated, you need only issue an `if` statement to determine if an input value is valid or not. You simply block any further action until the value passes the `if` test. The user keeps entering values into the different controls. He either receives an error message (at which point he makes a correction and tries again - an inherent loop) or all the values are correct and execution proceeds. This approach tends to shuttle looping into the realm of batch processing of files or internal processing.

##### *Part C*

## Access Keys and Menus

### Menus in Visual Basic

If you've been a Windows user for a while, you'll note that the majority of programs utilize a system of menus at the top of each window. A menu gives the user a wide variety of options to execute at any given time. Initially visible at the top of the window is the menu bar. The menu bar shows by name the various menus available at that time.

From the VB programmer's point of view, each item on a menu acts as a separate control. When the user clicks the item, a click event is generated for that control, and your program can execute a procedure based on it. This is similar to a command button. Each item is represented by the text property (which is what the menu displays) and the name property (which is the control name). VB automatically names each item with an appropriate default name (one that is much better than what it usually names controls). For instance, if you specify the menu item to read File Open, Visual Basic will name the item FileOpenToolStripMenuItem. Many programmers prefer to use the naming convention used for years, preceding the name with *mnu* (such as *mnuFileOpen*).

Menus are created directly in the Designer using the MenuStrip tool from the Toolbox. We will discuss them more, but first want to discuss keyboard access to menus, menu items and other controls.

### Access Keys

In the vast majority of Windows programs, most controls, menu title and menu items have one letter underscored. Did you know this? If you are using Windows 2000 or later (which we all are at this point in time!), then you will not see the underscore unless you press the Alt key or set up a special Windows option. Then they appear. This allows a keyboard-oriented user to access a specific menu item without using the mouse. These are called access keys.

To access a button, checkbox or radio button, the user must press the Alt key and then the underscored (access) key of that control. The interface will respond as if the user had clicked on the control with the left mouse button.

To access a text box, the user must press the Alt key in the label immediately preceding the text box (according to the Tab Order, which is the order used when the user tabs around the form). While Tab Order is reflected in the Properties window, this is a tedious way to arrange the controls. You should use the Tab Order menu item (see the View menu; if you do not see Tab Order displayed there, choose Tools -> Settings -> Expert Settings in the menu). Once selecting this, each control on your form will have a numeric order label on it. Using your mouse, click on each control in their tab order. You may want your ordering to be more vertical (down the form, then back up to a second column) or more horizontal (left to right, row by row). Regardless, make sure that you click on the label for a text box immediately before it; since control can never land on a label (since they are inactive for a user), the following control (the text box) will receive the focus.

Menu access via access keys is also available. To access the menu title, the user must press the Alt key and then the underscored (access) key of that menu. Then to access the specific menu item, the user presses the access key for that item. On the sample menus above, for example, one can exit the program by pressing Alt, then f (to get to the File menu), then x to choose Exit. In a well-written Windows program, you will find these speed keys for every menu title and item.

These keys are very easy to set up. When specifying the text of each menu (see below), simply place an ampersand (&) in front of the character you wish to designate as the access key. For instance, for the File menu, the programmer would specify the caption as &File. Nothing more needs to be done; the Alt key functionality is built-in.

All access keys need to be unique for all the visible/enabled controls on a form, including the menu titles. Within a single menu, all the access keys need to be unique.

### Menu Shortcut Keys

Another way to provide quick keyboard access to menus is to specify a shortcut for a particular menu item. On the actual menu in the development tool I show above, the New Project item is followed on the same line by Ctrl+N. And Exit is followed on the same line by Alt+Q. Ctrl+N and Alt+Q are examples of shortcuts. When the two keys are pressed at the same time (for instance, the Ctrl key and the letter n), that menu item will be chosen. The menu need not be visible for this to occur; these are keys that are meant to be memorized by an experienced user. Some shortcuts utilize three keys. All shortcuts that a programmer can specify in Visual Basic include either Ctrl and a letter key, a function key (F1 through F12), Ctrl and a function key, Shift and a function key, Ctrl and Shift and a function key, as well as other combinations involving Alt. Five other combinations are available which use the Ins and Del keys; I recommend staying away from these last combinations for your first few VB programs.

Shortcuts are also very easy to set up. When specifying the properties for the menu item control, there is a dropdown list of all the available shortcuts; the programmer simply chooses one for that particular menu item. Most programmers do not specify a shortcut for each menu item; they do so only for the most commonly chosen items.

Please do not confuse access keys with shortcut keys. While either or both can be used for menu items, they are separately specified. Access keys use the & prior to the actual letter in the text property; shortcuts are specified using a dropdown list. Shortcut keys must be memorized to be effective, while access keys use the underscore to clue the user.

Now that you have an idea of how these two types of shortcuts work, we can take a look at the actual menu creation process.

### Creating Menus in the Designer

In Visual Basic, the menu bar is a control, and each menu item is a control. You must first create the menu bar by selecting it from the tool box. Double-clicking on the MenuStrip tool will create a special control called MenuStrip1. It will appear below the actual form, as do all special controls. You can rename the control, but since you will generally have only a single Main Menu, this name should suffice.

As long as the MenuStrip1 control below the form is selected, you should see the beginnings of a menu at the top of the form. (If you do not, it is probably because the cursor was inside a group box as you created the control. Choose Edit -> Undo from the menu, then click in a blank area of the form away from the group box. Now try creating the control again.) You will see always see what you have already created, plus a Type Here wherever you can create a new menu title or menu item or submenu item. Since you haven't entered anything yet, you will just see a single Type Here. You will essentially create your menu structure "on-the-fly", adding menu titles and items at will.

Let's say we'd like to add a menu to your WelcomeUCLA program. The menu bar will read:

```
File    Options    Help
```

The File menu will have the items (the horizontal line is a "separator bar"):

```
Print Form   Ctrl+P
-------------------------
Exit
```

The Options menu will have the items:

```
Faculty RA
Grad Student
```

The Help menu will have the item:

```
About...
```

On the File menu, choosing Print Form or pressing Ctrl+P would print the form on the currently designated default printer (this is set from Windows itself). We won't actually be specifying the code for this in this course, as it is a bit advanced. Choosing Exit will do the same as the user clicking on the Exit button on the form.

On the Scenarios menu, Grad Student will check the Student check box and select Saxon Suites as the residence hall, even if the student is not a resident. (This way, if they later become a resident, Saxon will automatically and already be selected.) Faculty RA will uncheck the Student check box, and check the Resident check box.

On the Help menu, choosing About... will bring up a information message box showing the name of the program, the programmer, and the copyright date.

Because you can specify things in any order, you can develop your menu in a rather chaotic fashion. I suggest doing it one menu at a time. Let's do the File menu first. Click where it says Type Here and type &File, and finish by pressing ENTER. You will now see a menu title that says File. And you'll see two more Type Here boxes, one to the right of File (for the next menu title) and one underneath File (for the first menu item on the File menu).

Let's work our way down the menu. Click in the Type Here box underneath File, and type &Print Form and press ENTER. You will be adding the CTRL+P shortcut later on in the Properties window. Let's put a separator bar under the Print Form so that Exit stands by itself on the menu. In the next Type Here box (underneath Print Form), type a hyphen (-) and press ENTER. You should see a separator bar be created across the entire menu. Now, type E&xit in the new Type Here box under the separator bar and press ENTER. You have now completed the File menu basic structure!

Now do the same with the next two menus. Click in the Type Here box to the right of File to start off the Options menu. Proceed as we did before. There will not be any separator bars in the Options or Help menus. When you are completely done with all the menus and menu items, you will still have two Type Here boxes. Don't worry about those; they won't appear during execution. In fact, if you click anywhere else on the form, those boxes will disappear and you'll only see the main menu bar.

### Menu Extras

Although we aren't doing this in our example, it is easy to create submenus. A submenu is a menu item that itself opens to another menu level. These are indicated by a little solid wedge-arrow to the right of the menu item. This is automatically created if we enter a menu item in the Type Here box immediately to the right of any menu item (not menu title).

### Properties of Menu Titles and Menu Items

With our structure completed, we now move on to specifying what will happen as each item is clicked by the user. We do this by giving each and every menu title and item a related control name. We do not specify here what happens, only which control procedure will be executed upon the user click. We can also specify any shortcut keys during this process. Later, we will visit the code editor and specify VB program code for each control procedure.

You may choose to use the default name VB gives each menu item, or you may rename the item. VB programmers have traditionally labeled their menu control names with the prefix *mnu*. In this course, we will be disciplined and will continue to use this naming convention. So let's move through the menu structure and provide a name for each entry. First, bring up the Properties window. For each menu entry, you'll highlight the entry by clicking once, and that will bring up the associated properties. Interestingly, for each menu title and for each separator bar, VB requires a control name, even though we won't later be entering code for that control. VB automatically understands that when the user selects a menu title, it should drop down that particular menu. It is up to you if you plan to give these controls a name beyond the default name given. It may be a good idea in a more developed program that makes certain menus disappear and reappear at various times. We won't be doing that in this program, so we'll just leave the default names for the menu titles and separator bars.

So let's do this for each of our menu items. Click on Print Form in the designer screen. Now enter the name mnuPrintForm in the (name) property in the Properties window. It can be any valid VB identifier, but it is more self-documenting to use *mnu* followed by the text of the actual menu item. Note some of the various other properties:
- *Enabled* indicates if the menu item is accessible to the user. If True, it is. If False, the item is grayed out. This (as with the other properties) can be specified at design time (now) or at runtime (via code).
- *Visible* indicates if the menu item can be seen at all. If True, it can. If False, it can't. Note how many programs you've used in the past that had the menus change dynamically. All they did was to vary this property for the various menu items. This means that your initial design of a menu should include ALL items that will eventually be on the menu.
- *Checked* is used to visibly indicate a menu item that is checked or not. This is similar to the way a checkbox operates. The menu item will actually show a checkmark (or not) next to it during runtime. This property is not used for every menu item. For instance, you'd never use it for an action like Print Form or Exit, or for something with an ellipsis (dialog box to be popped up). We could use it for something like the two menu items on the Options menu. In fact, we'll do so for Faculty RA in a bit.
- *ShortcutKeys* lets you specify a keyboard shortcut. Simply select it from the dropdown list, or check one or more of Ctrl, Shift, Alt and then select it from the dropdown list.
- *ShowShortcutKeys* indicates if a selected shortcut actually appears on the menu itself during runtime. If True, it will be displayed. If False, it won't.
- **Text** is the menu text you originally entered. You can edit it here or directly on the control in the designer.

For this program in general, leave *Checked*, *Visible* and *ShowShortcutKeys* with their default values of True. For mnuPrintForm, let's change the *ShortcutKeys* property to reflect CtrlP. You will need to check Ctrl and then select P from the dropdown list. This will cause a Ctrl+P to be displayed on the menu (same line as the item) during runtime. And since we aren't actually implementing this menu item, let's change Enabled to False. This way, it'll be shown during runtime, but will be grayed out.

Now click on each of the items in the layout area, and then enter a control name for each. I recommend the following names:
- *mnuExit* for the Exit menu item
- *mnuFacultyRA* for the Faculty RA menu item
- *mnuGradStudent* for the Grad Student menu item
- *mnuAbout* for the About... menu item

You can now execute (F5) the program and actually click on the various menu titles and items, although nothing will happen because we haven't yet specified any code.

### Specifying the Code for the Exit Menu Item

Now, let's specify for code for the menu items. We'll start with an easy one first - Exit on the File menu. In Designer, click on the File menu title, and then double-click on Exit.  The code window should open up with a skeleton procedure for this control:

```vb
Private Sub mnuExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuExit.Click

End Sub
```

So we can see here that the standard event for a menu item is the click event. If a user clicks this item, the code found in the procedure will execute. Eventually, there will be one of these for each of our menu items.

The code we should enter for this is simple: the `Me.Close()` statement that we used earlier for the form's Exit button:

```vb
Private Sub mnuExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuExit.Click
    Me.Close()
End Sub
```

Alternatively, though, I like using my existing procedures whenever possible. This way, if choosing Exit from the menu is the same as clicking the form's Exit button, the exact same procedure will be executed (for instance, we might have some extra processing happening in `btnExit()` that we'd like executed upon exiting the program). So, in this case, instead of directly specify the end statement, we tell the Exit button (`btnExit`) to "click itself":

```vb
Private Sub mnuExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuExit.Click
    btnExit.PerformClick()
End Sub
```

A common method of most controls is the `PerformClick()` method. It's a handy code way of telling a button or check box or radio button to be clicked. Remember this in the future; it's a great way to avoid code repetition.

Test this out by pressing F5 and executing the program a couple of times. You'll see that both the Exit button and the Exit menu item do the same thing.

### Specifying the Code for the Other Menu Items

Let's do the other three menu items now. Remember, to get to the code for each one, be in the Designer and double-click the menu item directly.

Here's the code for Grad Student on the Options menu:

```vb
Private Sub mnuGradStudent_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuGradStudent.Click
   chkStudent.Checked = True
   rdoSaxon.Checked = True
End Sub
```

We are assuming here that since it is a Grad Student, that Student should be checked and that, if the student is a resident, the Saxon Suites radio button be selected. We are assuming of course that all grad students are assigned to Saxon Suites if they are residents; they are not required to be residents. These statements are largely actions that a user could do. So if you think like that, it will direct you as to what to specify when coding. The first statement does the same as a user "checking" the Student check box. The second statement selects the Saxon Suites radio button.

Let's now do the code for Faculty RA on the Options menu. A Faculty RA lives in the dorms with students, so they are not a student and they are a resident. Note that we'll implement the checkmark for this menu item. When we first start, the Checked property for this control is False. The first time the user selects this item, VB will automatically change it to True (the menu item will then appear checked) and then we need to do the things necessary to reflect Faculty RA status. This is indicated under the Then part below. The next time the user selects the item, we want to say that they are no longer a Faculty RA. But this doesn't necessarily mean that they are a student or resident, so we could simply be satisfied with checkmark being automatically removed. If there were something else, this would be indicated under the Else part.

We will have the checked statuses of both chkStudent and chkResident possibly change based on what the new state of mnuFacultyRA is after we toggle it. Recognize that code already exists for chkStudent and chkResident to change all other things to reflect student and resident status. We can take advantage of that and allow that to take care of all other controls that would normally change if a user clicked on the checkboxes. Each of these will automatically cause a CheckedChanged event to happen for each checkbox.

```vb
Private Sub mnuFacultyRA_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuFacultyRA.Click
   If mnuFacultyRA.Checked = True Then  ' update the checkboxes to reflect Faculty RA status
      chkStudent.Checked = False         'Because it's faculty
      chkResident.Checked = True         'Because it's a resident
   End If
End Sub
```

Before running things, you will need to change the ClickOnChecked property of mnuFacultyRA to True. Be sure to do this.

Here's the code for About... on the Help menu:

```vb
‘ Note how you can force a new line in
' the next of the message box. & (ampersand) is used for string
' concatenation (easier than strcat() in C). Chr(13) represents
' ASCII/Unicode 13, which is the carriage return character, also
' known as CTRL+M.
Private Sub mnuAbout_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles mnuAbout.Click
MessageBox.Show("Welcome UCLA Program" & Chr(13) & " written by Keith Jefferies, Copyright, 2014", _
     "About Welcome", MessageBoxButtons.OK, MessageBoxIcon.Information)
End Sub
```

Please note the comments. `Chr()` is a function that returns an ASCII/Unicode character matching the value of the argument. `Chr(13)` happens to be the Carriage Return (that old typing term means "going back to the beginning of the line").

## The Entire Source Code in One Place

```vb
Public Class frmWelcomeUCLA

    ' WelcomeUCLA Program - illustrate various Visual Basic features
    ' by Keith Jefferies

    Dim intAge As Integer         ' This will hold the age after validation
    Dim strEnrollRoom As String   ' Holds the enrollment room/area
    Const DefaultEnrollArea = "Murphy Hall Registrar" ' The default enroll room/area

    Private Sub btnExit_Click(sender As System.Object, e As System.EventArgs) Handles btnExit.Click
        Me.Close()   ' Close the form (terminate the program)
    End Sub


    Private Sub chkStudent_CheckedChanged(sender As System.Object, e As System.EventArgs) Handles chkStudent.CheckedChanged

        ' Enable/disable all student-related controls based on Student checkbox status

        If chkStudent.Checked = True Then   ' enable all student-related controls
            lblMajor.Enabled = True
            cboMajor.Enabled = True
        Else                                ' disable all student-related controls
            lblMajor.Enabled = False
            cboMajor.Enabled = False
        End If
    End Sub

    Private Sub frmWelcomeUCLA_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        chkStudent.Checked = True       ' Always start off assuming we have a student
        cboMajor.Text = "Mathematics"   ' Default major, purely for display
        grpResidence.Enabled = False    ' Always start off assuming non-resident, Resident checkbox already unchecked via prop win
    End Sub

    Private Sub chkResident_CheckedChanged(sender As System.Object, e As System.EventArgs) Handles chkResident.CheckedChanged

        ' Enable or disable the Residence Hall group based on Resident checkbox status

        If chkResident.Checked = True Then
            grpResidence.Enabled = True
        Else
            grpResidence.Enabled = False
        End If
    End Sub

    Private Sub cboMajor_SelectedIndexChanged(sender As System.Object, e As System.EventArgs) Handles cboMajor.SelectedIndexChanged

        ' Determine the enrollment room/area based on major

        If cboMajor.Text = "English" Or cboMajor.Text = "Kinesiology" Then
            strEnrollRoom = "Rolfe Hall Lobby"
        ElseIf cboMajor.Text = "Cybernetics" Or cboMajor.Text = "Mathematics" Then
            strEnrollRoom = "Boelter 6267"
        Else
            strEnrollRoom = "Murphy Hall Registrar"
        End If

        ' Now display the enrollment message in that label area at the
        ' bottom of the form

        lblMessage.Text = "Enroll room: " & strEnrollRoom

    End Sub

    Private Sub btnIncreaseAge_Click(sender As System.Object, e As System.EventArgs) Handles btnIncreaseAge.Click

        ' Early simple validation routine - see further below for well-developed routine

        'If IsNumeric(txtAge.Text) Then
        '    txtAge.Text = txtAge.Text + 1
        'Else
        '    MessageBox.Show("Age must be a number", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
        '    txtAge.Clear()
        '    txtAge.Focus()
        '    ' txtAge.SelectAll()
        'End If

        ' Well-developed validation routine below

        If Not IsNumeric(txtAge.Text) Then 'Validation test #1  "Passing" a test means the Boolean is False
            MessageBox.Show("Age must be a number", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtAge.Clear()
            txtAge.Focus()
        ElseIf txtAge.Text <= 0 Then 'Validation test #2   We can now assume txtAge.Text has a bona fide number
            MessageBox.Show("Age must be greater than 0", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtAge.Clear()
            txtAge.Focus()
        ElseIf txtAge.Text > 120 Then 'Validation test #3  
            MessageBox.Show("Age must be 120 or less", "User Input Error", MessageBoxButtons.OK, MessageBoxIcon.Warning)
            txtAge.Clear()
            txtAge.Focus()
        Else   'All tests were "passed", meaning all Booleans above were False
            intAge = txtAge.Text  'Only now can we assign the value to a variable, since it's definitely an integer
            intAge = intAge + 1   'This is the actual "processing". Simple here but could be more complex elsewhere.
            txtAge.Text = intAge  'Transfer back into the textbox after processing to output to the screen
        End If
    End Sub

    Private Sub mnuAbout_Click(sender As System.Object, e As System.EventArgs) Handles mnuAbout.Click
        MessageBox.Show("WelcomeUCLA Program, " & Chr(13) & "Copyright 2014, by Keith Jefferies", "About WelcomeUCLA", MessageBoxButtons.OK, MessageBoxIcon.Information)
    End Sub

    Private Sub mnuGradStudent_Click(sender As System.Object, e As System.EventArgs) Handles mnuGradStudent.Click
        chkStudent.Checked = True
        rdoSaxon.Checked = True
    End Sub

    Private Sub mnuFacultyRA_Click(sender As System.Object, e As System.EventArgs) Handles mnuFacultyRA.Click
        If mnuFacultyRA.Checked Then
            chkStudent.Checked = False
            chkResident.Checked = True
        End If
    End Sub

    Private Sub mnuExit_Click(sender As System.Object, e As System.EventArgs) Handles mnuExit.Click
        btnExit.PerformClick()
    End Sub
End Class
```

###### *Fundamentals of Software Development*

# Module 7AB - Programming Paradigms; A Peek at C++

We now move into the world of OOP - Object-Oriented Programming. First, we examine the various types of programming and user interfaces (procedural, OOP, step-by-step prompting, event-driven) so that you have a clear understanding of their differences. We then continue with an OOP treatment of a program you know well - The Mini Register Program from earlier in the quarter. We view it in the C++ language.

Then, we visit a sample application in Visual Basic and explain the basic components from a user perspective. We review the configuration of several common controls for VB applications:
- Forms
- Labels
- Text Boxes
- Combo Boxes
- Check Boxes
- Radio Buttons
- Group Boxes
- Buttons

These are the basic controls found in virtually every program (except for menus and message boxes, which will be covered later).

After getting acquainted with these, we will start looking at the actual coding process in VB, something very different than the way we proceeded in C. It will employ a highly modular event-driven design, and also will be a very different experience for you in actually typing the code.

## Programming Paradigms (Interfaces & OOP)

During the past few weeks, we've been studying traditional programming in C. Traditional procedural programming—which breaks down the process into a series of procedures (or subroutines)--has been with us for over 40 years in various forms, reaching back to the original high-level languages of FORTRAN and COBOL.  At the center of this type of programming is top-down hierarchical design, as well as a user interface approach that is very directed (the user is lead through a series of prompts and screens and cannot deviate from that order). While this suited us fine for many years, new developments in interface design in the late 70s and 80s sought a completely different approach. Researchers were trying to find ways to make computers and work flow more like the way we operate in an office. Moreover, management was crying for a way to speed development by reusing components already developed. All of this led to the introduction and widespread adoption of Object-Oriented Programming (OOP), as well as its adaptation to a “desktop” environment.

Most new programming today uses OOP, so it is important to learn about it in your programming curriculum. However, it is very difficult to master OOP without having first tackled traditional programming. Also, your first job out of school will most likely consist of performing maintenance on old C code. So you need to know both the old way and the new way.

This lecture will discuss the main elements of each type of programming in a way you can easily understand, and will contrast the two types. It also discusses special methods of programming that can be done using either type.

### First: Step-by-step Prompting vs. Event-Driven Programming

Prior to the introduction of Windows and mice, most programs (especially business-oriented ones) were quite straightforward in the way they interacted with users. The program would prompt the user, wait for a response, and continue with another prompt or some other action. Your typical accounting/inventory program screen, for instance, would easily prompt the user for up to 45 questions per screen. You would typically have to start at no. 1 and proceed to no. 45 in order. It wasn’t natural to jump around to questions at will. You could usually go straight to a particular question only after finishing the input to all 45 questions. And you certainly could not simply jump to another place in the program to perform “oh-by-the-way” work.

Programs assumed that users needed to be led through step by step. Such programs were thought of as rigid and inflexible, but they did at least get the job done. I used to write these types of programs for a small custom software house in Westwood. I refer to them as **“step-by-step prompting”** programs, although there’s probably no formal term.

It was widely felt that these programs made people work for the computers, rather than the other way around. Imagine if some new “expert” came into your company, studied you and your co-workers for a while, and then decreed a new procedure for doing your work. You could not deviate from the rules; you’d have to follow them to the letter. Everything would be prescribed for you—all day every day. Not very exciting, huh?

The 80s brought us some flexibility in the form of the “desktop metaphor”. If one could make the screen look like a person’s desktop, and the person could jump around erratically from task to task (this IS what we all do, correct?), then we’d would have succeeded in making the computer work the way people do, which is the proper order of things.

Early programs that did this were written in the traditional programming languages, such as PL/I, Pascal, and C. And they did it without Windows. Windows was not introduced to the market until 1985. Using text-mode characters, programs such as VisiOn and Framework drew a “desktop” on the screen, and allowed the user to interact with such things as mice, pull-down menus and movable on-screen windows and check boxes. Windows introduced a purely graphical form of this, along with an operating system environment that supported multiple applications running at the same time.

Either way, programs could be executed and then just sit there waiting for the user to do something (one of many possible things) so that it could respond. At any given moment, one could move the cursor to different points on the screen and select menu options, check boxes, pull-down lists. The fact that the program would sit and wait for an “event “ to occur before responding lead to the term **event-driven programming**.

Event-driven programming had been used in non-interactive programs for many years. It’s precisely how an operating system has to be written, or how an elevator control system works. You can imagine that—for most of the day—an elevator control system sits in a simple loop that does nothing until someone pushes a button to summon the elevator. Upon sensing that the button is pushed, it starts doing a variety of things: determines where the elevator is and moves it in the direction of the rider, lights up the floor indicators outside the elevator on each floor. As it travels toward the rider, a button pressed on an intermediate floor summons its attention again. The program then must determine if a different elevator should be activated, or should the first one (en route to the first rider) be stopped on the way.

In this example, every exterior button being pressed is an event that the program must pay attention to. Also, each button pressed inside the elevator. Door timers are another example, as are people crossing the electric eye that controls the doors. The key is here that program waits for things to happen; each of these is an “event” and causes the program to react in various ways.

Today’s applications and operating systems are heavily event-driven, from an interactive standpoint. Note how the program moves the cursor as you move the mouse. That’s event driven, with each tiny move of the mouse being an event that triggers the program to redraw the cursor in a new location. Moving the mouse over certain areas changes the cursor to a new shape; it’s the same thing. Striking certain keys activate the appearance of a menu. Same thing. Double-clicking the mouse while pointing at an object might cause an “opening” action. Once again, event-driven.

With event-driven programming, we can now operate the way humans in an office operate. Most of us do not perform a task, finish it, and then move on to the next task. We are constantly interrupted, and have to juggle many tasks almost simultaneously. The phone rings; we pick it up. The boss comes in and asks for a status report; we give him one. Your project leader comes in to invite you to her impromptu meeting; you take 15 minutes and go.

### The Limits of Procedural Programming

We can use traditional procedural programming to do both step-by-step prompting programs as well as event-driven programming. Indeed, an event driven program written in C is likely to consist of a main loop that iterates “forever” and waits for a key to be struck or a mouse to be moved. Inside the loop is a huge selection statement (if or switch) that handles each of the possible events. Many, many programs are written in this manner.

But as interfaces became more powerful, programs to handle them became much more complex. What used to be a simple program that asked for data in an uninspiring way (and consisted of 20% input code and 80% processing code) became a spiffed up program with drop-down menus, drop-down lists, check boxes, radio buttons, and sliders (and consisted of a reverse mix of roughly 80% input code and 20% processing code). What growth! That’s one reason we need 4GB of RAM and 1TB hard drives today (in addition to running dozens of these programs simultaneously). Programs have grown to be humongous.

Programmers who used C and other traditional languages to do Windows programming in the 80s were dismayed to find that even the simplest Windows program required the knowledge of a full-fledged computer scientist to develop. The classic “Hello, world!” program (which displays those words on the screen) was several pages long. Microsoft provided libraries of functions to facilitate the programming, and published a list of function calls and required arguments for programmers to use (this is called an API—Application Programming Interface). But imagine—establishing and opening a window on screen with the words “Hello, world!” required many functions, several of which had up to 50 required arguments. 50!!!!

Moreover, a programmer had to have SOLID knowledge of how the bowels of Windows operated. Many veteran programmers took years of retraining. In fact, when Windows was first released in 1985, it took years and years before the killer DOS applications were ported over. Microsoft took 2 years to develop Excel for Windows, 4 years to migrate Word for Windows, and even longer to develop Windows-based database products (Access and FoxPro). There was a clear dearth of applications between 1985 and 1991.

It was the same with the Macintosh. Mac and Windows programming was simply damned difficult.

### The Dilemmas of Management

Not only did development become much more complex in the late 80s, but management was experiencing longer and longer application backlogs. An *application backlog* is the delay between a user requesting a custom application and its actual implementation. In most companies, this backlog was on average 2 years.  Yes, two years! This, of course, is not how business is supposed to operate. Business should be able to respond to external conditions quickly. A product manager who needs a program developed to analyze statistical data for a new product release simply can’t wait 2 years.

So management sought a more rapid way to develop software.

A big part of the problem (other than the simple complexity of Windows- and Mac-based programming) was that the rate of reusing code was low. We discussed earlier about how we can create a library of functions to be reused. This is good for number crunching and other types of processing, as well as basic input-output, but didn’t respond fully to the quantum leap in complexity of code. A new way had to be developed that allowed for easy reuse of a much higher percentage of code.

Management said, “Bring those costs down and get things out faster!”

Also, because of the heavy interactivity of programs with users, there was a greater desire to design and refine the actual user interface before the bulk of the coding. With traditional methods, code had to be written to display a “dummy” interface, and often this code was complex in and of itself. A new way had to be developed that supported easy yet sophisticated design, even by the end users themselves.

In essence, management said, “Make it so that our users are as productive as they can be. Listen to their needs, not your own.”

All of these ideas were quite radical, but the computer research community was listening, and the new wave of software companies (such as Microsoft and Apple) were too.

Enter OOP and Visual Programming.

### OOP to the Rescue

Object-oriented programming answered many of the cries for help issued by management. It turned programming development on its head, and approached it completely differently.

The core of OOP is based on the **object** concept. Here’s the easiest way to describe it. In procedural programming, you have simple and complex variables. Some of the complex variables are things such as records, which contain several values per variable. For instance, a personnel record variable would contain different compartments: first name, middle initial, last name, home address, city, state, zip, social security number, department, salary, start date, etc. In procedural programming, you would employ a multitude of functions to operate on this variable: printing out its contents, updating certain parts of the record, even deleting the record from a group of personnel records. The functions operate on the data.

With OOP, it’s the data that is key. Each person or thing in the application is considered an object. If you have employees represented in your application, then an employee is an object. All of your employees together would be considered a group of employee objects. Each object contains data about itself (similar to a record), such as name, address, city, state, department, etc. (same as above). Formally, these data items are known as **attributes** or **properties**. But the object itself also contains code (called **methods**) that dictates how it should operate. So, code is contained as a part of the object for creating itself, printing itself, updating different parts of itself, and even deleting itself.

As you venture into OOP, you will see an important term called a **class**. A class is essentially a template for an object, specifying what the properties and methods are for any object (or **instance**) of that class. So in your program, you will create many different classes and you will use other pre-defined classes. And then during the program when you wish to create actually manipulatable objects, for each one you will specify from which class it is to be *instantiated*. So given the example above, you’d create an employee class, and then each actual employee you work with would be an instantiated object of the employee class.

You as programmer will create some of your own classes, but you will also heavily use classes created by others. These classes will be fully documented as to: their names, their properties, their methods and required arguments, You can use others’ classes as is (without even seeing the actual code of the methods), or you can even add additional properties and methods to them. Creating your own classes in this manner allows your new class to *inherit* all of the aspects of the original class.

As an example, your programming language can define a “text box” class to represent and display text. The text box class will have several properties, such as the value represented inside the text box, its horizontal location on screen, its vertical location, the typeface, the font size, the font style (regular, bold, italic, etc.), the justification (left, center, right), and many other items. Methods of the text box class might include: displaying it, printing it, clearing it,”home-ing” it (sending it to the upper left corner of the screen).

You can create instances of this text box class and give each of them a name; each of these instances is an object. You can also create a more sophisticated class based on this text box class; call it “FlashingTextBox”. Instances of this new, more sophisticated box will have all the things the regular text box has, plus additional properties and methods. For instance, the text in it can flash at a certain rate when displayed, so you might have methods to start flashing and stop flashing. You might also have properties which control the rate of flashing, as well as the colors which the text will be while flashing.

You still, of course, create variables and write code to tie your objects together and to conduct the processes you desire. But the programming is made easier because the code to manipulate each object is also done and is an inherent part of the object. Many of your function/subroutine calls are actually calling one of your objects’ methods.

This method of programming is very efficient because it can fully use what you’ve done in previous projects (assuming you designed your objects well in those projects). Management gets their more rapid development wishes, plus code reusability. Because the object code (the methods) were already tested in the previous project, we can assume that they are fairly solid for this project.

### OOP and Traditional Languages

The original OOP language was called SmallTalk, and was developed at Xerox PARC in Palo Alto, a solid and important computer research facility (the desktop metaphor and mice were invented there too). But much had been invested in the traditional languages of C, Basic, COBOL, and also in the database world (dBASE/Xbase/Foxpro, Oracle, and others). To marry the two worlds together took several independent efforts.

Since C was the number one development language in the 80s, it was felt by many that OOP could be introduced into C giving an easy transition. So, C++ was created. C++ used a great deal of the C language, plus added its own commands and structure to represent objects. C++ is considered a rather difficult language, because it does require solid knowledge of C, plus solid knowledge of OOP principles. Microsoft introduced a new language in the last few years called C# (pronounced "C-sharp"), which builds on C++, simplifies its more arcane features and encases it in a "visual" environment (as described in the next section).

Other languages also had OOP principles introduced into them. Pascal and COBOL both had compilers created for them that added the ability to use OOP. Because OOP was tacked on to these products, many purists shunned them, but beleaguered programmers who wanted a way to improve their code embraced the opportunity to move to something more modern.

In all of these cases, serious development efforts could now introduce OOP into the cycle for future savings down the line in development costs, plus faster revision times. Moreover, the object concept fit much better with the Windows event-driven programming style. I should mention here, though, that OOP and Windows or event-driven programming are NOT one in the same. It’s possible to have non-Windows event-driven procedural programming, non-Windows event-driven object-oriented programming, Windows procedural programming, and Windows object-oriented programming. By definition, all Windows programming is event-driven.

### OOP and Visual Languages

Early OOP adaptations of traditional languages did not address the third desire of management—easy and quick interface design prior to coding.  It was still necessary to write a ton of code to present the interface.

Fortunately, our friend Bill Gates of Microsoft—creator of almost all of the microcomputer implementations of the BASIC language from 1975 on—stated that he wanted to create a language similar to BASIC which enabled programmers to create programs for Windows in an easier manner. This language and development environment would allow interface design prior to coding, as well as use many (but not all) of the principles of OOP.

The result was Visual Basic (VB).

During its infancy, VB was like a fun toy. It was great for creating simple Windows programs, but its guts didn’t stand up to applications created using industrial strength tools like C++. Many programmers used it as a prototyping tool only. And it wasn’t fully object-oriented, using non-OOP terminology and lacking such OOP concepts as class inheritance.

However, as we approached VB version 4, it appeared as if Microsoft definitely had its big guns behind the product. Professional conferences for VB developers had sprung up. Magazines supporting it were published. And Microsoft listened to the thousands of VB developers to make the product a solid, stable, efficient, and useful general-purpose development tool.

VB version 6 was probably the first really serious development tool in the series. And with the newest versions of Visual Basic--based on Microsoft's .NET platform embedded into Windows--VB has moved into the realm of fully object-oriented programming. The first of these was VB.NET 2003, and that since been replaced by newer versions every 2 to 3 years.

Today, VB is one of the most widely used programming languages on Earth (according to Microsoft, although their definition includes Excel macro developers [Excel macros are written in Visual Basic]). As you will discover in your final exercises, it’s easier to do more and do it faster with VB than with C. And Microsoft has designed its application products (such as Word, Excel, Access, and Outlook) so that VB (as VBA—Visual Basic for Applications) could serve as a super macro language. This is why you will find VB used in so many corporate environments. (You will notice, though, that VB is typically NOT used for systems programming, such as with the development of drivers and operating systems components. It does not contain the sophisticated non-database-oriented data manipulation that is available in C++ and C#.)

Microsoft’s success with Visual Basic did not go unnoticed within the company. Quickly, the company revamped its other language and database products so that they contained the “visual” part of Visual Basic—enabling complete interface design prior to coding. The result was a plethora of Microsoft development products for different areas: Visual C++, Visual FoxPro, Visual J++, Visual InterDev. Each of these products supports the “interface-first” paradigm, as well as sophisticated management of all the objects used within your programs. Many of these tools have been updated as products to be included in a suite called Visual Studio, including Visual Basic, Visual C++, Visual C#  and Visual J# (a Microsoft-only implementation of Java).

The above products (named “Visual”) are all Microsoft-developed, but other companies such as Borland/Micro Focus have developed similar products. You will not see the word “Visual” in front of their names, though. Microsoft has trademarked that name.

### Visual Basic Today

VB allows you to create the interface on a blank canvas called a **form** using **controls**. Each control is essentially an object. There are labels, textboxes, buttons, pull-down combo boxes, images, check boxes, radio buttons, menus and many other types of controls (many of which are “after-market”). VB makes it easy to set the many properties of each control without programming. It also allows you to attach code to every possible event that can occur with each control.

### The .NET Framework
All of Microsoft's modern languages are based on Microsoft's .NET Framework. The .NET Framework is a component which Windows Update adds to Windows (XP through 10). This component contains many object classes that are shared by applications written in the .NET-based Visual languages. When looking back at C, we talked about "code libraries". Well, this is like adding the code libraries to the operating system itself, instead of to the development environment. As the operating system is updated periodically, so is the .NET Framework. You should ensure that the system you use for development contains at least version 3.0 of the .NET Framework. Your installation of Visual Basic will ensure that you have the correct version of the framework installed.

The fact that this framework exists only inside Windows means that Microsoft's Visual languages can only produce applications for modern Microsoft Windows environment. If you wish to develop programs for Mac, UNIX or LINUX (or for older versions of Windows), Android or iOS, you cannot use these Microsoft tools. Instead, you will probably use some version of C, Objective C, C++, Swift, Java or other tool.

## A Peek at C++

Let's take Example 3-11 from **Module 3** and update it to a C++ program that defines an object class, instantiates from that class, and illustrates the calling of two of its methods.

```c++
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// Constant declarations

const float TAXRATE = 0.09;   //  current tax rate

// Variable declarations

class Cashier {    
  public:                
    // These functions (only 1 here) and attributes (none here) CAN be accessed from outside the object        

    void init() {       // Initializes the object by inputting info into the attributes           
      cout << "Please enter your name: ";           
      cin >> name;           
      cout << name << ", please enter your employee number: ";           
      cin >> empnum;        
    }        

    string getName() const {  // retrieves the name from within the object            
      return name;        
    }        

    int getEmpNum()  const {   // retrieves the empnum from within the object            
      return empnum;        
    }    

  private:               // These can't be accessed directly outside the object            
      string name;   // holds the name of the cashier            
      int empnum;    // holds the employee number of the cashier
};

// Main Function

main() {   
  // Local declarations   

  float amount;   /* amount of the sale      */   
  float SalesTax; /* calculated sales tax    */   
  float total;    /* total including tax     */   
  int dollars;    /* dollar portion of total */   
  float cents;    /* cents portion of total  */

  Cashier Cashier_Main;   /* This is an "instantiation",
                          which creates a single Cashier object and gives it a name */

  /* Prompt user for information   */   

  cout << "** Mini Register Program **\n\n";   

  Cashier_Main.init();   /* Tell the cashier we instantiated to initialize itself,
                          which it does by inputting information */

  cout << "Please enter amount of sale: $";   
  cin >> amount;      

  /* Calculate tax and total */   

  SalesTax = amount * TAXRATE;   
  total = amount + SalesTax;      

  /* Display results */   

  cout.precision(2);   // round floats to 2 decimal places
  cout << fixed;   

  cout << "\nCashier: " << Cashier_Main.getName() << "\n";      // call the method that retrieves the name
  cout << "Employee #" << Cashier_Main.getEmpNum() << "\n\n";   // call the method that retrieves the employee no.

  cout << "Amount of sale: $" << setw(8) << amount << "\n";   
  cout << "CA Sales Tax:   $" << setw(8) << SalesTax << "\n";   
  cout << "-------------------------\n";   
  cout << "Total:          $" << setw(8) << total << "\n";      

  /* Separate dollars and cents */   

  dollars = floor(total);   
  cents = (total-dollars) * 100;   

  cout << "\nPay " << dollars << " dollars and " << setprecision (0) << cents << "cents.\n";   

  return 0;
}
```

### Small Differences Between C and C++

There are a few syntax differences you will notice between the original C program and this C++ adaptation:
- C++ uses a different set of libraries than C, so our `#include` directives at the top of the program are different. `iostream` allows basic input and output. `iomanip` enhances the basic input and output with formatting. `cmath` allows you to use mathematical functions. And `string` allow string manipulation functions. We did not really need the `string` library in the above example.
- C++ has a string data type in addition to `char`.
- The functions used have a "full" name that includes something called a "namespace" that precedes the function name. So the proper name of `cout` is `std::cout`. By including the statement `using namespace std`; we can forego the `std::` in front of each of these functions when we use them.
- C++ is an OOP language, so we can define one or more classes, and we can instantiate objects of these classes. The example shows the definition of a class called `Cashier`. A class is like a data type. Instantiating a new class is like declaring a new variable. So we see a statement in the `main()` function that instantiates a new object from the `Cashier` class; it is called `Cashier_Main`.
- Calling a method of an object is similar to calling a function, whether void or not. To call the `init()` method of `Cashier_Main`, we say the statement `Cashier_Main.init()`.
- C++'s statements for input and output use `cin` and `cout` respectively. The syntax for these is very different than that for `printf()`, `scanf()`, and `gets()`. `cin` and `cout` are not statement-commands, but are names for standard files. `cin` is the standard input stream (keyboard); `cout` is the standard output stream (screen). A statement like `cin >> amount;` means to take what comes from the standard input stream and place it in `amount`. Note the direction of the "arrows" made by the greater than/less than signs. `cout << "Hello!\n";` takes the string literal `"Hello!\n"` and directs it to the standard output stream.
- Formatting in output is accomplished by calling various methods and functions. For example, `cout.precision(2)` calls the `precision` method of the `cout` output stream (which happens to be an object) and passes the argument 2 to it. It "sticks" for all numeric output until changed. `setw(8)` sets the width to 8. So placing these two calls in the output stream is like using `%8.2f` for every numeric value in `printf()`.  `fixed` is used to make C++ print float numbers in fixed notation as opposed to scientific notation.

### The `Cashier` Class Definition and Calling Its Methods

The class definition contains two main sections: the `public` area and the `private` area. In either area can be variable and defined constant declarations and function definitions. Those in the `public` area can be addressed (used or called) from outside the class. Those in the `private` area can only be used internally within the class.

In our example, the `private` area has two variable declarations (`name` and `empnum`). . These variables can be freely used within the methods (functions) inside the class. They cannot, however, be used or even seen in statements outside the class. It is entirely up to the programming whether these are `private` or `public`. If they were `public`, one could issue a statement such as:

```c++
cout << Cashier_Main.empnum
```

But because they are `private`, the programmer must provide some other means to extract the value of them (or to put a value into either of them).  And these must be done using `public` methods (so that they can be seen and called from outside the class).

We see three methods defined in the `public` section. `init()` is there to prompt the user for the name and employee number. It is a void method (similar to a void function) in that it does an operation and then ends. `getName()` is there to extract the value of `name`. `getEmpNum()` is there to extract the value of `empnum`. These two methods are methods that return a value (similar to functions that return a value). So when used, they provide the value (stated by the return statement) to the place where they are called. So,

```c++
cout << "\nCashier: " << Cashier_Main.getName() << "\n";
```

will print out a new line, then `Cashier:` followed by the name and then another new line. `Cashier_Main.getName()` is a method that has one statement: `return name`. The method can see `name` because `name` is `private` and accessible to anything inside the class definition for `Cashier`. Once the `return` statement returns the value of `name`, it's just a value (a `string`) at that point, and then that value is returned to the `cout` statement above.

The same applies to the employee number:

```c++
cout << "Employee #" << Cashier_Main.getEmpNum() << "\n\n";
```

This method call returns the value of the employee number variable `empnum` to the `cout` statement and prints it.

You might be curious why there's a `const` in two of the method definitions inside the class definition. It merely indicates that these particular method won't be changing anything inside the object. `init()` doesn't have one because it's purpose is to change values inside the object.

###### *Fundamentals of Software Development*

# Module 6 - Selection

In this module, we discuss the final flow-of-control (logic) type: **selection**. We introduce three forms of the **if** statement: **if**, **if-else**, and linear-nested **if**. Although your text also discusses the **select-case**, we will not be covering that in this course. EVERYTHING selection-wise can be done with one of the three **if** statements.

This module will present several examples that illustrate the if statement in its various forms. A variety of Nassi-Shneiderman charts will be shown to illustrate how selection is represented.

## General Selection Concepts

It's best to think of selection as a fork in the road. Your program executes a sequence of instructions, when suddenly a decision must be made as to which path to take. The program may have two possible choices, three possible choices, or many possible choices. Whichever numbers of choices the program has, a selection construct will be used to define both the condition which directs execution to one path or another, as well as the tasks on the divergent paths themselves.

In C, there are two main selection constructs - the **if** statement and the **switch-case** statement. The **if** statement is the more comprehensive of the two and has many different forms. We'll examine only the **if** statement in this course.

### Nassi-Shneiderman Charts for Selection

The N-S charts for Selection clearly illustrate this concept of choosing a pathway. Here's an example of a simple **if** statement represented by an N-S chart:

![N-S Chart for Selection](https://github.com/tara-nguyen/UCLA-Extension-coursework/blob/main/Fundamentals%20of%20Software%20Development/N-S%20Chart%20for%20Selection.jpg?raw=true)

As execution proceeds from the statement prior to the **if** statement, it flows into the middle-upper triangle. This triangle contains a Boolean condition, similar to those in **do-while** and **while** looping statements. The condition is evaluated at that moment, and produces a value of either `TRUE` or `FALSE`. If the condition is `TRUE`, execution follows the left side (under the True wedge). If the condition is `FALSE`, execution follows the right side (under the False wedge). Either the left or the right side can have a single statement (such as the True example above), a block of statements (such as the False example above), or no statements at all (typically the right side).

Once the statement or statements are done on the selected side, then further statements are stretched across the chart in the traditional manner. As soon as we get to one of those, we say that we have exited the selection.

## The if Statement

The simplest **if** statement has three parts. The first part specifies the Boolean condition that will be used to determine which action will be taken. This is the same type of Boolean condition as we used in looping. The condition may be simple or compound, and may be as complex or as simple as you'd like. Regardless, the condition will evaluate to the Boolean value true or false. Here's a schematic of the full **if** statement:

```c
if (condition) {
   statement;
   statement;
   statement;
   statement;
}
else {
   statement;
   statement;
   statement;
}
```

Notice that no semicolon follows a statement block.

## The Linear-Nested if Statement

In the linear-nested **if** statement, the statement following the keyword `else` is an **if** statement itself (and quite possibly a linear-nested **if** statement). What we end up having sort of a cascading statement, similar to those coin banks where you insert the coin and it bypasses all the openings until it gets to the opening for its size and then drops in.  Let's see an example based on the value of something input by the user:

```c
printf("Please enter your evaluation rating: ");
scanf("%d", &rating);

if (rating == 5)
   printf("Your performance was outstanding this year.");
else if (rating == 4)
   printf("Your performance exceeded our expectations.");
else if (rating == 3)
   printf("You did well this year.");
else if (rating == 2)
   printf("We know you can try harder!");
else
   printf("Please clean out your desk by morning.");

/* this is the first statement following the if statement */
printf("\n\nSigned,\n");
printf("The Management of CostContainmentCo\n");
```

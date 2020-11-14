// Coders: Tara, Anna, & Adela
// Wow! My first program!

#include <stdio.h>   // Include this line in all of your programs

// Variable Declarations

   char name[10];       // This will hold the first name of the user

// *** Main Program ***

main() {
   printf("This is my first C program\n\n");
   printf("Please enter your first name: ");
   scanf("%s", &name);
   printf("\nThank you, %s\n", name);
   
   return 0;   // This line is in every program
}

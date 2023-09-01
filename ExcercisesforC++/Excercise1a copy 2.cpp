// Import the following library.
#include <cstdio>


// -----------------------------------------------------------------------------+-
// Add your code to the following function as described in the worksheet.
// -----------------------------------------------------------------------------+-
#include <cctype>


void do_the_needful(void) 
{
   printf("\n");
   int my_int;
   int *my_int_ptr;
   printf("     my_int: %20d     address of my_int: %p \n",      my_int, &my_int);
   printf(" my_int_ptr: %20p address of my_int_ptr: %p \n", my_int_ptr, &my_int_ptr);

   printf("\n");
   my_int = 42;
   my_int_ptr = &my_int;
   printf("     my_int: %20d     address of my_int: %p \n",      my_int, &my_int);
   printf(" my_int_ptr: %20p address of my_int_ptr: %p \n", my_int_ptr, &my_int_ptr);

   printf("\n");
   *my_int_ptr = 96;
   printf("     my_int: %20d \n",      my_int, &my_int);
   printf(" my_int_ptr: %20p \n", my_int_ptr, &my_int_ptr);

   printf("\n");
   my_int = 256;
   printf("     my_int: %20d \n",      my_int);
   printf("*my_int_ptr: %20d \n", *my_int_ptr);

    return;
};



int main() 
{

    printf("Main starting... \n");

    do_the_needful();

    printf("Main Finished! \n");

    // The exit code is a signed integer value which is
    // provided to the operating system when a program terminates.
    // It indicates whether the program was successful or not.
    int exit_code = 0; // success
    return exit_code;
};
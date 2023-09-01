// Import the following library.
#include <cstdio>


// -----------------------------------------------------------------------------+-
// Add your code to the following function as described in the worksheet.
// -----------------------------------------------------------------------------+-
#include <cctype>


void do_the_needful(void) 
{
   char my_char;
   my_char = 'a';
   printf("my_char: %c \n", my_char);
   my_char = 'b';
   printf("my_char: %c \n", my_char);
   my_char = 'c';
   printf("my_char: %c \n", my_char);

   for(int c=0; c<=128; c++) 
   {
    my_char = c;
    if(isprint(my_char))
    {
        printf("my_char: %c (%#0x) \n", my_char, my_char);
    }
    else
    {
        printf("my_char: <%d> \n", c);
    }

   }

   int num_list[128];

   size_t num_elements = sizeof(num_list)/sizeof(num_list[0]);

   for(int idx=0; idx<num_elements; idx++)
   {
        num_list[idx] =  num_elements - idx;
   }
   for(auto elem : num_list)
   {
        char my_char = elem;
        if(isprint(my_char))
        {
            printf("my_char: %c (%#0x) \n", my_char, my_char);
        }
        else
        {
            printf("my_char: <%d> \n", elem);
        }
   }

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
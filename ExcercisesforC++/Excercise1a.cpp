// Import the following library.
#include <cstdio>


// -----------------------------------------------------------------------------+-
// Add your code to the following function as described in the worksheet.
// -----------------------------------------------------------------------------+-
void do_the_needful(void) 
{
    bool b;

    char fmt_string[] = "The value of %s is: %d \n";

    b = true;
    printf(fmt_string, "b", b);
    b = false;
    printf(fmt_string, "b", b);

    unsigned int i = 42;
    int j = -42;

//my additional variables

    short int first = -5;
    unsigned short int second = 2000;
    long int third = -1000000;
    unsigned long int fourth = -2000000;
    long long int fith = -10000000000;
    unsigned long long int sixth = 10000000000;
    float seventh = 4.88838;
    double eighth = 9.323E2;
    long double ninth = 4.4373847384374938;


    printf("The value of i is: %+d decimal, %#12X hex \n", i, i);
    printf("The value of j is: %+d decimal, %#12X hex \n", j, j);

//my additional printed variables
    printf("The value of first is: %+d decimal, %#12X hex\n", first, first);
    printf("The value of second is: %+d decimal, %#12X hex \n", second, second);
    printf("The value of third is: %+d decimal, %#12X hex \n", third, third);
    printf("The value of fourth is: %+d decimal, %#12X hex \n", fourth, fourth);
    printf("The value of fith is: %+d decimal, %#12X hex \n", fith, fith);
    printf("The value of sixth is: %+d decimal, %#12X hex \n", sixth, sixth);
    printf("The value of seventh is: %+d decimal, %#12X hex \n", seventh, seventh);
    printf("The value of eighth is: %+d decimal, %#12X hex \n", eighth, eighth);
    printf("The value of ninth is: %+d decimal, %#12X hex \n", ninth, ninth);

    char fmt_string2[] = "The siz of %-16s is: %d bytes. \n";

    printf(fmt_string2, "short int", sizeof(first));
    printf(fmt_string2, "unsigned short int", sizeof(second));
    printf(fmt_string2, "long int", sizeof(third));
    printf(fmt_string2, "unsigned long int", sizeof(fourth));
    printf(fmt_string2, "long long int", sizeof(fith));
    printf(fmt_string2, "unsigned long long int", sizeof(sixth));
    printf(fmt_string2, "float", sizeof(seventh));
    printf(fmt_string2, "double", sizeof(eighth));
    printf(fmt_string2, "long double", sizeof(ninth));

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
/*
================================================================================================#=
Unit-3/CODE/wk09B-Worksheet.cpp
================================================================================================#=
*/

#include <cstdio>
#include <cctype>


// -------------------------------------------------------------+-
// Do The Needful
// -------------------------------------------------------------+-


// ---------------------------------------------------------------------+-
// MAIN Entry Point
// ---------------------------------------------------------------------+-
int main() {

    printf("Main starting... \n");

    do_the_needful();

    printf("Main Finished! \n");

    // The exit code is a signed integer value which is
    // provided to the operating system when a program terminates.
    // It indicates whether the program was successful or not.
    int exit_code = 0; // success
    return exit_code;
};

#if 0
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|@
Code Parking Lot
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|@

    // -----------------------------------------------------------------------------+-
    // Exercise 1
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {
// sets ROWS as an int and assigns 12 to ROWS
    const int ROWS = 12;

    printf("\n\n");

//begins row at 1 and then interates through each ow until it gets to 12
    for(int row=1; row<=ROWS; row++)
    {
        for(int row=1; row<=ROWS; row++)
        {
            printf("L ");
        }
        printf("\n");
    }

    return;
};

    // -----------------------------------------------------------------------------+-
    // Exercise 2
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {
//sets ROWS as an integer and assigns 24 to it
//sets letter as a character and assigns ' ' to it
    const int ROWS = 26;
    char letter = '@';

    printf("\n\n");
//interates through each row and checks to make sure that row is less than or equal to ROWS
    for(int row=1; row<=ROWS; row++)
    {
        //updates letter by increments of one
        letter++;

        //iterates through colums and checks if col is less than or equal to row
        for(int col=1; col<=row; col++)
        {
            printf("%c", letter);
        }
        printf("\n");
    }

    return;
};

    // -----------------------------------------------------------------------------+-
    // Exercise 3
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {
//sets ROWS as an integer and assigns 24 to it
//sets letter as a character and assigns ' ' to it
    const int ROWS = 1;
    char letter = '@';

    printf("\n\n");
//interates through each row and checks to make sure that row is less than or equal to ROWS
    for(int row=26; row>=ROWS; row--)
    {
        //updates letter by increments of one
        letter++;

        //iterates through colums and checks if col is less than or equal to row
        for(int col=1; col<=row; col++)
        {
            printf("%c", letter);
        }
        printf("\n");
    }

    return;
};


    // -----------------------------------------------------------------------------+-
    // Exercise 4
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {
//sets ROWS as an integer and assigns 24 to it
//sets letter as a character and assigns ' ' to it
    const int ROWS = 1;

    printf("\n\n");
//interates through each row and checks to make sure that row is less than or equal to ROWS
    for(int row=26; row>=ROWS; row--)
    {
        //letter = @ moved so that each line starts at A rather than only the first line
        char letter = '@';

        //iterates through colums and checks if col is less than or equal to row
        for(int col=1; col<=row; col++)
        {
            //letter++ moved here so each colum proceeds to next letter
            letter++;
            printf("%c", letter);
        }
        printf("\n");
    }

    return;
};

    // -----------------------------------------------------------------------------+-
    // Exercise 5
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {

    const int ROWS = 16; // number of rows to print
    const int COLS = 24; // number of columns to print

    // the symbol to print
    char symbol;

    // the number of symbols to print on current line
    int syms = 1;

    // the number of spaces to print on current line
    // before the first * symbol.
    int num_leading_spaces;

    printf("\n\n");
    //iterates through each row
    for(int row = 1; row <= ROWS; row++)
    {
        //iterates through each colum
        for(int col = 1; col <= COLS; col++)
        {
            //depleates the number of spaces to print on a line before the '*' symbol
            num_leading_spaces = (COLS-syms)/2;

            //sets symbol to ' ' if a colum is less than or equal to the numbeer of leading spaces
            if(col <= num_leading_spaces) symbol = ' ';
            //if the colum is greater than the spaces and the number of symbols stop the program
            else if(col > num_leading_spaces + syms) break;
            //if the previous two are not correct print a '*'
            else symbol = '*';

            printf("%c ", symbol);
        }       
        printf("\n");
        syms += 2;
    }

    return;
};

    // -----------------------------------------------------------------------------+-
    // Exercise 6
    // -----------------------------------------------------------------------------+-
    void do_the_needful(void) {

    const int ROWS = 16; // number of rows to print
    const int COLS = 24; // number of columns to print

    // the symbol to print
    char symbol;

    // the number of symbols to print on current line
    int syms = 1;

    // the number of spaces to print on current line
    // before the first * symbol.
    int num_leading_spaces;

    //iterates through each row
    for(int row = 1; row <= ROWS; row++)
    {
        //iterates through each colum
        for(int col = 1; col <= COLS; col++)
        {
            //depleates the number of spaces to print on a line before the '*' symbol
            num_leading_spaces = (COLS-syms)/2;

            //sets symbol to ' ' if a colum is less than or equal to the numbeer of leading spaces
            if(col <= num_leading_spaces) symbol = ' ';
            //if the colum is greater than the spaces and the number of symbols stop the program
            else if(col > num_leading_spaces + syms) break;
            //if the previous two are not correct print a '*'
            else symbol = '*';

            printf("%c ", symbol);
        }       
        printf("\n");
        syms += 2;
    }

    return;
};

#endif
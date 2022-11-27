#include <stdio.h>
#include "fizzbuzz.h"

void fizzbuzz(int n, char* text)
{
    if ( (n % 15) == 0 )
    {
        sprintf(text, "fizzbuzz");
    } 
    else if ( (n % 3) == 0 )
    {
        sprintf(text, "fizz");
    }
    else if ( (n % 5) == 0 )
    {
        sprintf(text, "buzz");
    } 
    else 
    {
        sprintf(text, "%d", n);
    }
}

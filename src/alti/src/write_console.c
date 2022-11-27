#include <stdio.h>

#ifdef BUILD_TEST
char messages[5][10] = { 0 };
int message_index = 0;

static void replace_printf(char* const x, char* const y, char* const z) 
{
    sprintf(messages[message_index], x, y, z);
    message_index++;
}

#define printf( x, y, z ) replace_printf( x, y, z )
#endif

void write_console(int max, void func(int i, char* text))
{
    char text[10] = {0};
    for(int i = 1; i <= max; ++i)
    {
        func(i, text);
        printf("%d : %s\n", i, text);
    }
}

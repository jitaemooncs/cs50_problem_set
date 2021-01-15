#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name;

    // Prompt user
    name = get_string("What's your name?\n");

    printf("hello, %s\n", name);
}
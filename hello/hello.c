#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask user for name
    string name = get_string("What is your name? ");
    //print hello and users name
    printf("hello, %s\n", name);
}
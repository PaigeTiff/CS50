#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Get height of pyramid from input
    do
    {
        height = get_int("What is the Height?: ");
    }
    while (height < 1 || height > 8);

    //print lines for shape
    for (int row = 0; row < height; row++)
    {
        for (int space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }

        //print the hashes
        for (int column = 0; column < row + 1; column++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;

}
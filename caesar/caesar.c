#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check the command line argument
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    //define key
    string key = argv[1];

    //check that the input is a digit, if not send error message
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    printf("Success\n%s\n", key);

    //Get phrase from user to encript
    string plaintext = get_string("plaintext: ");

    //convert key into an integer
    int k = atoi(key);
    printf("ciphertext: ");

    //encript the input phrase
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + k) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) % 26) + 97);
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
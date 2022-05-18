#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
int sum_letters = 0 , sum_sent = 0 ;
float words = 1 ;

char* text =  get_string("Enter your Text :");

for (int i = 0 ; text[i] != 0x00 ; i++)
{
    if (isalpha(text[i]))
    {
        sum_letters ++ ;
    }
    else
    if (isspace(text[i]))
    {
        words ++;
    }
    else
    //isalnum(text[i]) == false)
    if (text[i] == '.' || text[i] =='!' || text[i] =='?')
    {
        sum_sent ++;
    }
}
    //L = average # of letters per 100 words
int L = (sum_letters / words * 100);

    //S = average # of sentences per 100 words
float S = (sum_sent / words * 100);

    //index = 0.0588 * L -0.269 * S - 15.8
float index = (0.0588 * L - 0.296 * S - 15.8) ;

printf("%i letter(s)\n", sum_letters);
printf("%.f word(s)\n", words);
printf("%i sentance(s)\n", sum_sent);

if (index >= 16) // determining the output
{
    printf("Grade 16+\n");
}
else
if (index < 1)
{
    printf("Before Grade 1\n");
}
else
printf("Grade %.f\n", round(index));

}
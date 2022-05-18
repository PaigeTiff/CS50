#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //FILE *fopen(filename, "r");
    //first bytes include 0xff, 0xd8 and 0xff

    if (argc != 2)
    {
        printf("Usage; ./recover IMAGE\n");
        return 1;
    }
    //open file to check if valid
    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
    {
        printf("Couldn't open file");
        return 2;
    }
    //store blocks of 512 bytes
    unsigned char buffer[512];

    //track number of images generated
    int count_image = 0;

    FILE *output_file = NULL;

    //malloc() points to the allocated memory, or NULL if the request fails
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //checking bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer [3] & 0xf0))
        {
            //write the JPEG filenames
            sprintf(filename, "%03i.jpg", count_image);

            //open the files for us to write into
            output_file = fopen(filename, "w");
            count_image++;
        }
        //check if file has been used or not
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}
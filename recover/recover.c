#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int i = 0;
    char num[8];
    FILE *file = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // If start of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // Close the previous file
            if (file != NULL)
            {
                fclose(file);
            }
            
            // Create output files
            sprintf(num, "%03i.jpg", i);
            i++;

            // Open the output files
            file = fopen(num, "w");

            // Can we open the output files
            if (file == NULL)
            {
                fclose(card);
                printf("Could not open the output file\n");
                return 1;
            }

            // Starting write to the output file
            fwrite(buffer, 1, 512, file);
        }
        // Continue writing to the output file until the file pointer reach the null character where
        // it located at the end of the file
        else if (file != NULL)
        {
            fwrite(buffer, 1, 512, file);
        }
    }

    // The file pointer reached the end of the file so we close the output file
    if (file == NULL)
    {
        fclose(file);
    }

    // Then close the input file
    fclose(card);
    return 0;
}

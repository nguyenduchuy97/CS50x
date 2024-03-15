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
    FILE *card = fopen(argv[1], 'r');

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, f) == 512)
    {
        // If start of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] & 0xf0 == 0xe0 )
        {
            int i = 1;
            // If first JPEG file
            FILE *file = fwrite(buffer, 1, 512, sprintf())
            FILE *w = fwrite(buff, 1, 512, )
        }

    }

    fclose(f);
    return 0;
}

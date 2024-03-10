#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    // Loop over all pixels.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Update pixel values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            swap= image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Create a copy of image.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate over all the pixels.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Iterate over the neighboring pixels.
            for (int ni = i - 1; ni <= i + 1; ni++)
            {
                for (int nj = j - 1; nj <= j + 1; nj++)
                {
                    // Check if the neighboring pixel is within bounds.
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += copy[ni][nj].rgbtRed;
                        sumGreen += copy[ni][nj].rgbtGreen;
                        sumBlue += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }
            // Calculate the average values and update the pixel.
            image[i][j].rgbtRed = round((float) sumRed / count);
            image[i][j].rgbtGreen = round((float) sumGreen / count);
            image[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int X[3][3] = {
                {-1, 0, 1},
                {-2, 0, 2},
                {-1, 0, 1}
            };

            int Y[3][3] = {
                {-1, -2, -1},
                {0, 0, 0},
                {1, 2, 1}
            };

            int redX = 0, greenX = 0, blueX = 0;
            int redY = 0, greenY = 0, blueY = 0;
            int newRed, newGreen, newBlue;

            // Iterate over the neighboring pixels.
            for (int ni = i - 1; ni <= i + 1; ni++)
            {
                for (int nj = j - 1; nj <= j + 1; nj++)
                {

                    // Check if the neighboring pixel is within bounds.
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redX += X[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtRed;
                        greenX += X[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtGreen;
                        blueX += X[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtBlue;

                        redY += Y[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtRed;
                        greenY += Y[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtGreen;
                        blueY += Y[ni - i + 1][nj - j + 1] * copy[ni][nj].rgbtBlue;
                    }
                }
            }
            newRed = round(sqrt(redX * redX + redY * redY));
            newGreen = round(sqrt(greenX * greenX + greenY * greenY));
            newBlue = round(sqrt(blueX  * blueX + blueY * blueY));

            // I use ternary operator to cap at 255.
            image[i][j].rgbtRed = newRed > 255 ? 255 : newRed;
            image[i][j].rgbtGreen = newGreen > 255 ? 255 : newGreen;
            image[i][j].rgbtBlue = newBlue > 255 ? 255 : newBlue;
        }
    }
    return;
}

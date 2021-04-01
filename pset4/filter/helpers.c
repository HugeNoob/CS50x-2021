#include "helpers.h"
#include <math.h>
#include <stdio.h>

//COMPLETED AGAIN zz (LESS)


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int newR;
            int newG;
            int newB;

            newR = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if(newR > 255){
                newR = 255;
            }

            newG = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if(newG > 255){
                newG = 255;
            }

            newB = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if(newB > 255){
                newB = 255;
            }

            image[i][j].rgbtRed = newR;
            image[i][j].rgbtGreen = newG;
            image[i][j].rgbtBlue = newB;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            temp[i][j] = image[i][width - j - 1];
 
        }
    }
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = temp[i][j];

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            float totalR = 0;
            float totalG = 0;
            float totalB = 0;
            int count = 0;

            for(int m = -1; m < 2; m++){
                for(int n = -1; n < 2; n++){
                    if(i + m >= 0 && j + n >= 0 && i + m < height && j + n < width){
                        totalR += image[i + m][j + n].rgbtRed;
                        totalG += image[i + m][j + n].rgbtGreen;
                        totalB += image[i + m][j + n].rgbtBlue;
                        count++;
                    }
                }
            }

            temp[i][j].rgbtRed = round(totalR/count);
            temp[i][j].rgbtGreen = round(totalG/count);
            temp[i][j].rgbtBlue = round(totalB/count);
        }

    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

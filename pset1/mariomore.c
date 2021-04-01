#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int height;
    do{
        height = get_int("Height: ");

    }while(height < 1 || height > 8);

    for(int i = 0; i < height; i++){ 
        int num_spaces = height - i - 1;
        int num_hash = i + 1;
        for(int a = 0; a < num_spaces; a++){
            printf(" ");
        }
        for(int b = 0; b < num_hash; b++){
            printf("#");
        }
        printf("  ");
        for(int c = 0; c < num_hash; c++){
            printf("#");
        }
        
        printf("\n");
    }


    return 0;
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    
    float dollars;
    int num_coins = 0;
    do{
        dollars = get_float("Change owed: ");

    }while(dollars < 0);

    int cents = round(dollars * 100);
    
    while(cents > 0){
        
        if(cents/25 >= 1){
            int temp = floor(cents/25);
            num_coins += temp;
            cents -= temp*25;
            continue;
        }
        
        else if(cents/10 >= 1){
            int temp = floor(cents/10);
            num_coins += temp;
            cents -= temp*10;
            continue;
        }
        
        else if(cents/5 >= 1){
            int temp = floor(cents/5);
            num_coins += temp;
            cents -= temp*5;
            continue;
        }
        
        else if(cents/1 >= 1){
            int temp = floor(cents/1);
            num_coins += temp;
            cents -= temp*1;
            continue;
        }
        
        
    }    
    
    printf("%i\n", num_coins);
    return 0;
}

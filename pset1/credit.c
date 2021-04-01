#include <stdio.h>
#include <cs50.h>
#include <strings.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    
    long number;
    do{
        number = get_long("Number: ");

    }while(number < 0);
    
    int numlen = floor(log10(number) + 1);
    int first_digit = number/pow(10, (numlen-1));
    int first_two = number/pow(10, (numlen-2));
    //printf("%i\n", numlen);
    //printf("%i\n", first_digit);
        
    //int a = number%10;
    //printf("%i", a);
    int total = 0;
    int pos = 1;
    int temp;
    
    
    
    while(number != 0){
        
        //removes last digit if odd position
        if(pos%2 != 0){
            temp = number%10;
            total += temp;
            number = number/10;
            //printf("%li\n", number);
            pos++;
            continue;
        }
        
        //for even position
        //obtain product
        int product = (number%10)*2;
        //printf("%i\n", product);
        int length = floor(log10(product)) + 1;
        //printf("%i\n", length);
        
        //adds last digit
        total += product%10;
        if(length > 1){
            //adds each digit to total
            for(int i = 1; i < length; i++){
                temp = product/(10*i);
                //printf("%i\n", temp);
                total += temp;
            }
        }

        number = number/10;
        pos++;
    }
    
    //printf("%i\n", total);
    
    if(total%10 == 0){
        
        if((first_two == 34 || first_two == 37) && numlen == 15){
            printf("AMEX\n");
            return 0;
        }
        
        else if((first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55) && numlen == 16){
            printf("MASTERCARD\n");
            return 0;
        }
        
        else if(first_digit == 4 && (numlen == 16 || numlen == 13)){
            printf("VISA\n");
            return 0;
        }
    }
    
    printf("INVALID\n");
    return 0;

}

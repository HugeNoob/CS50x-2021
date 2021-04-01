#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//COMPLETED!!!!!!!!!!!



bool is_key_valid(string s);
void encrypt(string s, string ciphertext, int k);

int main(int argc, string argv[])
{
    if(argc != 2 || !is_key_valid(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //valid now
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);
    char ciphertext[n + 1];
    encrypt(plaintext, ciphertext, k);

    printf("ciphertext: %s\n", ciphertext);
    return 0;

}


//encryption process
void encrypt(string s, string ciphertext, int k)
{

    int adjusted_key = k%26;
    int i = 0;
    for(i=0; i < strlen(s); i++)
    {
        char ch = s[i];

        if(isalpha(ch))
        {
            int initial_value = ch;

            //encrypt with key
            int shifted_value = initial_value + adjusted_key;
            
            //uppercase letters
            if(initial_value<=90)
            {
                if(shifted_value>90)
                {
                    shifted_value -= 26;
                }
                
                //adding to ciphertext
                char cshifted = shifted_value;
                ciphertext[i] = cshifted;
                
            }
            //lowercase letters
            else if(initial_value<=122 && initial_value >= 97)
            {
                if(shifted_value>122)
                {
                    shifted_value -= 26;
                }
                
                //adding to ciphertext
                char cshifted = shifted_value;
                ciphertext[i] = cshifted;
            }
        }
        else
        {
            ciphertext[i] = ch;
            
        }
    }
    ciphertext[i] = '\0';
}



//checks if key is purely integer
bool is_key_valid(string s)
{
    for(int i=0; i<strlen(s); i++)
    {
     if(!isdigit(s[i]))
     {
         return false;
     }
    }

    return true;
}









#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//COMPLETED!!!!!!!!!!!!!!!!!!!!!!!!!!



string substitute(string plaintext, string key, string ciphertext);
bool is_key_valid(string s);
char mapping[26];

int main(int argc, string argv[])
{
    //checks validity of key
    if(argc != 2 || !is_key_valid(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    
    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);
    char ciphertext[n + 1];
    
    //maps each letter to a buffer "mapping"
    for (int i=0; i < strlen(argv[1]) ; i++){
        mapping[i] = tolower(argv[1][i]);
    }
    
    printf("ciphertext: %s\n", substitute(plaintext, argv[1], ciphertext));
    return 0;
}



string substitute(string p, string key, string ciphertext){
    int i = 0;
    
    for(i = 0; i < strlen(p); i++){
        char ch = p[i];
        
        if(isalpha(ch)){
            //subbing via lowercase
            char temp = tolower(ch);
            char subbed = mapping[temp - 'a'];
            
            //correcting uppercase
            if(isupper(ch)){
                ciphertext[i] = toupper(subbed);
            }
            else{
                ciphertext[i] = subbed;
            }
        }
        //non alphabets
        else{
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0';
    return ciphertext;
}


//checks if key is purely integer
bool is_key_valid(string s)
{
    int i = 0;
    int buf[26]; 
    
    for(i=0; i<26; i++){
        buf[i] = -1; 
    }
    
    for(i = 0; i<strlen(s); i++){
     char ch = s[i];
     
     if(!isalpha(s[i])){
         return false;
     }
     
     if(buf[tolower(ch) - 'a'] != -1){
         return false; //repeating letters
     }
     else{
      buf[tolower(ch) - 'a'] = 1;  
     }
     
    }
    return i == 26;
}















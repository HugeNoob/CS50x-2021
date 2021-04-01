// Implements a dictionary's functionality


//completed but not perfected.


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1)*45;

// Hash table
node *table[N];

int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int bucket = hash(word);
    node *cursor = table[bucket];
    
    while(cursor != NULL){
        
        if(strcasecmp(cursor->word, word) == 0){
            return true;
        }
        
        cursor = cursor->next;
    }
    
    return false;
}


// Hashes word to a number
//http://www.cse.yorku.ca/%7Eoz/hash.html
//djb2 hash function
unsigned int hash(const char *word)
{
    // TODO
    int sum = 0;
    for(int i = 0; i < strlen(word); i++){
        sum += tolower(word[i]);
    }
    return(sum % N);
    
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Opens dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }


    char read_word[LENGTH + 1];
    node *n;
    //read each word
    while(true){

        //scan one word
        int eof = fscanf(file, "%s", read_word);

        //if end of dict
        if(eof == -1){
            fclose(file);
            break;
        }

        //else, read word
        else{
            //strcpy word into node, strcpy(n->word, "Hello");
            n = malloc((sizeof(node)));
            if(n == NULL){
                return false;
            }

            strcpy(n->word, read_word);

            //find bucket in hash table
            int bucket = hash(read_word);

            //link word to bucket: link new node to first node of list, then list point to new node
            n->next = table[bucket];
            table[bucket] = n;
            total_words++;
        }

    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}



// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N+1; i++){
        node *tmp = table[i];
        node *cursor = table[i];
        while(cursor != NULL){
            
            cursor = tmp->next;
            free(tmp);
            tmp = cursor;
        }
    
    }
    return true;
}

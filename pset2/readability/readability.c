#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//COMPLETED!!!!!!!!


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float grading(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i letter(s)\n", count_letters(text));
    printf("%i word(s)\n", count_words(text));
    printf("%i sentence(s)\n", count_sentences(text));
    printf("%f\n", grading(count_letters(text), count_words(text), count_sentences(text)));    //index based on formula: index = 0.0588 * L - 0.296 * S - 15.8, where L is average letters per 100 words and S is average number of sentences per 100 words

    if(grading(count_letters(text), count_words(text), count_sentences(text))>=16)
    {
        printf("Grade 16+\n");
    }
    else if(grading(count_letters(text), count_words(text), count_sentences(text))<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(grading(count_letters(text), count_words(text), count_sentences(text))));
    }

    return 0;
}





//counting letters 
int count_letters(string text)
{
    int letters = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if(isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}

//counting words
int count_words(string text)
{
    int words = 1;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

//counting sentences
int count_sentences(string text)
{
    int sentences = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if(text[i] == '.')
        {
            sentences++;
        }
        else if(text[i] == '!')
        {
            sentences++;
        }
        else if(text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

//applying formula to derive index
float grading(int letters, int words, int sentences)
{
    float letters_float = (float)letters;
    float words_float = (float)words;
    float sentences_float = (float)sentences;

    float L =(100*letters_float)/words_float;
    float S =(100*sentences_float)/words_float;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
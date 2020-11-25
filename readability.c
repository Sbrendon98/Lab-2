#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(const char* stringword);
int count_words();
int count_sentences();
int main(void)
{
    int a = 0;
    const char* b = 0;
    //Get text from user
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentence = count_sentences(text);

    float L = letters / words * 100;
    float S = sentence / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int TOTAL = round(index) - 1;

    if (TOTAL >=1 && TOTAL <= 16)
    {
        printf("Grade %i\n", TOTAL);
    }
    else if (TOTAL < 1)
        {
            printf("Before Grade 1\n");
        }
        if (TOTAL > 10)
        {
            printf("Grade 16+\n");
        }

    }
int count_letters(const char* stringword)
{
    float letters = 0;
    int i , n = 0;
         for (i = 0, n = strlen(stringword); i < n; i++)
   {
       if(isalnum(stringword[i]))
       {
           letters++;
       }
   }
   return letters;
}

int count_words(const char* stringword)
{
    float words = 1;
     for (int i = 0, n = strlen(stringword); i < n; i++)
     {
         if(stringword[i] == ' ')
         {
             words++;

         }
     }
      return words;
}
int count_sentences(const char* stringword)
{
    float sentences = 0;
    for (int i = 0, n = strlen(stringword); i < n; i++)

    if((stringword[i] == '.') || (stringword[i] == '!') || (stringword[i] == '?'))
    {
        sentences++;

    }
    return sentences;
}


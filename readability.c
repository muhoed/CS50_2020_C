#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// the program grades a text using Coleman-Liau index formula

long count_letters(char x[]);
long count_words(char x[]);
long count_sentences(char x[]);
int coleman_liau_index(int a, int b, int c);

char text[];

int main(void)
{
    printf("Text: ");
    //scanf("%s", text);
    fgets(text, 1000, stdin);
    long l = count_letters(text);
    long w = count_words(text);
    long s = count_sentences(text);
    int g = coleman_liau_index(l, w, s);
    // print grade according to calculated index   
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (g > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", g);
    }
}

// count a number of letters in a text
long count_letters(char x[])
{
    long n = 0;
    long j = strlen(x);
    for (long i = 0; i < j; i++)
    {
        if (isalpha(x[i]))
        {
            n++;
        }
    }
    printf("The number of letters is: %ld\n", n);
    return n;
}

// count a number of words in a text
long count_words(char x[])
{
    long n = 0;
    long j = strlen(x) - 1;
    for (long i = 0; i < j; i++)
    {
        if (isspace(x[i]))
        {
            n++;
        }
    }
    n++;
    printf("The number of words is: %ld\n", n);
    return n;
}

// count a number of sentences in a text
long count_sentences(char x[])
{
    long n = 0;
    long j = strlen(x);
    for (long i = 0; i < j; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            n++;
        }
    }
    printf("The number of sentences is: %ld\n", n);
    return n;
}

// calculate Coleman-Liau index
int coleman_liau_index(int a, int b, int c)
{
    // number of letters per 100 words
    float L = (((float) a * 100) / (float) b);
    // number of sentences per 100 words
    float S = (((float) c * 100) / (float) b);
    // index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    printf("Index is: %d\n", index);
    return index;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// the program when called with 1 command line argument (positive integer) prompts user to input some text and encrypts the text using Caesar algoritmus

int check(char p);
char incipher(char p, int k, int r);

char text[255];

int main(int argc, char *argv[])
{
    // check a number of command line arguments
    if (argc != 2)
    {
        // warn user if there are more than 1 argument and exit
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check whether the key argument meets requirements
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {}
        else
        {
            // warn user about the incompliance of the key and exit
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // prompt user to enter a text
    printf("plaintext: ");
    gets(text);
    // encrypt alphabetic characters of the text with the key
    int k = atoi(argv[1]);
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        int c = check(text[i]);
        switch (c)
        {
            case 1 :
                text[i] = incipher(text[i], k, 97);
                break;
            case 2 :
                text[i] = incipher(text[i], k, 65);
                break;
            case 3 :
                text[i] = text[i];
        }
    }
    // print encrypted text and exit
    printf("ciphertext: %s\n", text);
    return 0;
}
// the function checks whether a symbol is upper/lower case or is not alphabetic and return respective switch value
int check(char p)
{
    if (islower(p))
    {
        return 1;
    }
    else if (isupper(p)) 
    {
        return 2;
    }
    return 3;
}
// the function encrypts a symbol accordint to c = (p + k) % 26 formula taking into account ASCII code of the symbol 
char incipher(char p, int k, int r)
{
    int c0 = (p + k - r) % 26;
    char c = c0 + r;
    return c; 
}

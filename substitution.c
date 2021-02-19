#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// the program when called with 1 command line argument (26 alphabetic symbols) prompts user to input some text and encrypts the text using Caesar algoritmus

int check(char p);
char incipher(char k[], char p, int r);

char text[255];

int main(int argc, char *argv[])
{
    // check a number of command line arguments and a number of symbols in the key
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        // warn user if there are more than 1 argument and exit
        printf("Usage: ./substitution key. A key must contain of 26 uniq alphabetic symbols.\n");
        return 1;
    }
    // check whether the key argument meets requirements
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            if (i != 0)
            {
                for (int j = 0; j < i; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("A key must contain of 26 uniq alphabetic symbols\n");
                        return 1;
                    }
                }
            }
        }
        else
        {
            // warn user about the incompliance of the key and exit
            printf("A key must contain of 26 uniq alphabetic symbols key\n");
            return 1;
        }
    }
    // convert all symbols in the key to uppercase
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char t = argv[1][i];
        argv[1][i] = toupper(t);
    }
    // prompt user to enter a text
    printf("Please enter some text here: ");
    fgets(text, 255, stdin);
    // encrypt alphabetic characters of the text with the key
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        int c = check(text[i]);
        switch (c)
        {
            case 1 :
                text[i] = incipher(argv[1], text[i], 97);
                break;
            case 2 :
                text[i] = incipher(argv[1], text[i], 65);
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
char incipher(char k[], char p, int r)
{
    char c;
    int d = p - r;
    if (r == 97)
    {
        c = k[d] + 32;
    }
    else
    {
        c = k[d];
    }
    return c; 
}

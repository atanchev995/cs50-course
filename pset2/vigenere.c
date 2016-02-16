#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // checks for number of arguments
    if (argc != 2)
    {
        printf("Usage: /pset2/vigenere <key> \n");
        return 1;
    }
    else if (argv[1])
    {
        int l = strlen(argv[1]);
        for (int i = 0; i < l; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: /pset2/vigenere <key> \n");
                return 1;
            }
        }
    }
    
    // stores the key into a string
    string k = argv[1];
    int m = strlen(k);
    int keycount = 0;
    int count = 0;
    
    // gets input from the user
    string p = GetString();
    string encrypted = p;
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // checks if the character is a letter
        if (isalpha(p[i]))
        {
            keycount = count % m;
            // encrypts lowercase letters
            if (islower(p[i]))
            {
                if (islower(k[keycount]))
                {
                    encrypted[i] = ((((p[i] - 97) + (k[keycount] - 97)) % 26) + 97);
                    printf("%c", encrypted[i]);
                }
                else
                {
                    encrypted[i] = ((((p[i] - 97) + (k[keycount] - 97)) % 97) + 97);
                    printf("%c", encrypted[i]);
                }
            }
            // encrypts uppercase letters
            else if (isupper(p[i]))
            {
                if (islower(k[keycount]))
                {
                    encrypted[i] = ((((p[i] - 65) + (k[keycount] - 97)) % 26) + 65);
                    printf("%c", encrypted[i]);
                }
                else
                {
                    encrypted[i] = ((((p[i] - 65) + (k[keycount] - 65)) % 26) + 65);
                    printf("%c", encrypted[i]);
                }
            }
            count++;
        }
        else
        {
            printf("%c", encrypted[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}

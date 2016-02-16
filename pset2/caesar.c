#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // checks for number of arguments
    if (argc != 2 || atoi(argv[0]) < 0)
    {
        printf("Error.\n");
        return 1;
    }
    
    // converts string k to int
    int k = atoi(argv[1]);
    
    // gets input from the user
    string p = GetString();
    string encrypted = p;
    
    // checks if k is larger than 26
    if (k > 26)
    {
        k %= 26;
    }
    
    // loops through the string
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // checks if the character is a letter
        if (isalpha(p[i]))
        {
            // encrypts uppercase letters
            if (isupper(p[i]))
            {
                encrypted[i] = ((((p[i] - 65) + k) % 26) + 65);
            }
            // encrypts lowercase letters
            else if (islower(p[i]))
            {
                encrypted[i] = ((((p[i] - 97) + k) % 26) + 97);
            }
        }
    }
    
    // prints the encrypted string
    printf("%s\n", encrypted);
    
    return 0;
}

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    // take input from the user
    string name = GetString();
    
    // loop from the beginning to the end of the string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // determine the initials
        if (i == 0 || name[i - 1] == ' ')
        {
            // print the initials and convert them to uppercase
            printf("%c", toupper(name[i]));
        }
    }
    
    printf("\n");
}

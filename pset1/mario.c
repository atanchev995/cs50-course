#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare variable height and ask the user for input
    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
    
    for (int i = 0; i < height; i++)
    {
        // print the empty spaces
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        
        // print the hashes
        for (int k = -1; k <= i; k++)
        {
            printf("#");
        }
        
        // print new lines
        printf("\n");
    }
}

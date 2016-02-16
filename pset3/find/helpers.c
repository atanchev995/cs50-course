/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    // binary search
    int left = 0;
    int right = n - 1;
    int middle = (left + right) / 2;

    while (left <= right)
    {
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            left = middle + 1;
        }
        else if (values[middle] > value)
        {
            right = middle - 1;
        }
        
        middle = (left + right) / 2;
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm

    // selection sort
    int min_index;

    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (values[i] > values[j])
            {
                min_index = j;
            }
        }
        
        int temp = values[i];
        values[i] = values[min_index];
        values[min_index] = temp;
    }
    
    return;
}

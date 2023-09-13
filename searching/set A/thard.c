/*
Write a ‘C’ program to create a random array of n integers. Accept a value of n from user
and use Binary search algorithm to check whether the number is present in array or not.
(Students should accept sorted array and use Non-Recursive function also use random
function).
*/
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int a[], int key, int high, int low)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] > key)
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int a[7] = {1, 4, 5, 7, 8, 11, 14};
    int key = 8;
    int high = sizeof(a) / sizeof(a[0]) - 1;
    // binary serch
    int index = binarySearch(a, key, high, 0);
    if (index == -1)
        printf("%d is not present.", key);
    else
        printf("%d is present at %d index", key, index);

    return 0;
}
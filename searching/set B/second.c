/*
2) Write a C program to accept n elements from user store it in an array. Accept a value from
the user and use binary search method to check whether the value is present in array or not.
Display proper message. (Students should accept sorted array and use Recursive function).
*/
#include <stdio.h>
#include <conio.h>
int binarySearch(int a[], int high, int low, int key)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return binarySearch(a, high, mid + 1, key);
    else if (a[mid] > key)
        return binarySearch(a, mid - 1, low, key);
}

int main()
{
    int no, key;
    printf("how many elements in array : ");
    scanf("%d", &no);
    int a[no];
    printf("Enter array elements : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);

    printf("Enter the elemet to search  : ");
    scanf("%d", &key);
    int index = binarySearch(a, no - 1, 0, key);
    if (index == -1)
        printf("%d is not present.", key);
    else
        printf("%d is present at %d index.", key, index);
    return 0;
}
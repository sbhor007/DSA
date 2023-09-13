#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void insertionSort(int a[], int no)
{
    int key, j;
    for (int i = 1; i < no; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int no;
    printf("How many eliments to enter :");
    scanf("%d", &no);
    int a[no];
    printf("Enter array elements : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);

    // after appling insertion sort
    insertionSort(a, no);
    for (int i = 0; i < no; i++)
        printf("%d\t", a[i]);
}
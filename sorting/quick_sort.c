#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int i = low;
        int j = high;
        while (i < j)
        {
            while (pivot >= a[i])
                i++;
            while (pivot < a[j])
                j--;
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        a[low] = a[j];
        a[j] = pivot;
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}
int main()
{
    int no;
    printf("\nHow many elements to enter : ");
    scanf("%d", &no);
    int a[no];
    printf("\nEnter array Elements : \n");
    for (int i = 0; i < no; i++)
        scanf("%5d", &a[i]);
    printf("\noriginal array\n");
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
    quickSort(a, 0, no - 1);
    printf("\nsorted array\n");
    for (int i = 0; i < no; i++)
        printf("%5d", a[i]);
}
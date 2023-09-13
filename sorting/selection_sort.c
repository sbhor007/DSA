#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void selectionSort(int a[], int no)
{
    int i, j;
    for (i = i; i < no; i++)
    {
        int min = i;
        for (j = 0; j < no; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int no;
    printf("How many elements to enter  : ");
    scanf("%d", &no);
    int a[no];
    printf("Enter array elements : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
    // afrea applying selection sort algoritham
    selectionSort(a, no);
    for (int i = 0; i < no; i++)
        printf("%d\t", a[i]);
    return 0;
}
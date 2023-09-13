#include <stdio.h>
#include <conio.h>
void bubbleSort(int a[], int no)
{
    for (int i = 0; i < no - 1; i++)
    {
        for (int j = 0; j < no - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int no;
    printf("How many elements to enter : ");
    scanf("%d", &no);
    int a[no];
    printf("enter array elements : \n");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
    // appaing bubble sort
    bubbleSort(a, no);
    for (int i = 0; i < no; i++)
        printf("%d\t", a[i]);

    return 0;
}
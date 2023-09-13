/*
1) Write a ‘C’ program to accept the names of cities and store them in array. Accept the city
name from user and use linear search algorithm to check whether the city is present in array
or not.
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
int linearSearch(char cities[][20], char key[], int no)
{
    for (int i = 0; i < no; i++)
    {
        if (strcmp(cities[i], key) == 0)
            return i;
    }
    return -1;
}
int main()
{
    int no;
    char key[20];
    printf("How many cities to store : ");
    scanf("%d", &no);
    char cities[no][20];
    for (int i = 0; i < no; i++)
    {
        printf("\nCity no %d is : ", i + 1);
        scanf("%s", cities[i]);
    }
    printf("\nEnter the city name to search : ");
    scanf("%s", key);
    // finding city using linear search
    int index = linearSearch(cities, key, no);
    if (index == -1)
        printf("%s is not present.", key);
    else
        printf("%s is present at %d index.", key, index);

    return 0;
}
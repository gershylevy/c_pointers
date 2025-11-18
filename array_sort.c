/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: Print values and addresses of arrays.
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>

#define ARR_SIZE 10

#define BAD_INPUT_ERR -1

/*------------------------------------------------------
* Function Name -  swap
*
* Function Purpose - Swaps the values of 2 pointers in an array of pointers.
*
* Parameters –  [IN arr - Our array.]
*               [IN index1 - The index of one of the elements we wanna swap]
*               [IN index2 - The index of the other one of the elements we wanna swap]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

// no need for swap function since insertion sort uses shifts
int **swap(int *arr[], int index1, int index2)
{
    int *temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return arr;
}

/*------------------------------------------------------
* Function Name -  insertion_sort
*
* Function Purpose - Sorts an array of pointers using insertion sort.
*
* Parameters –  [IN arr - Our array.]
*               [IN n - The size of our array]
*
* Return Values - The updated array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

// use insertion sort since its efficiant for small data sets
void insertion_sort(int *arr[ARR_SIZE], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = *arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && *arr[j] > key)
        {
            *arr[j + 1] = *arr[j];
            --j;
        }
        *arr[j + 1] = key;
    }

    for (int i = 0; i < ARR_SIZE; ++i)
    {
        printf("Index: %p\n", *arr[i], arr[i]);
    }
}

int main()
{
    int arr[ARR_SIZE];
    int *ptr_arr[ARR_SIZE];
    int i;

    printf("Enter %d numbers\n", ARR_SIZE);

    for (i = 0; i < ARR_SIZE; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("bad input\n");
            return BAD_INPUT_ERR;
        }
    }

    printf("Before Sort\n");

    for (i = 0; i < ARR_SIZE; ++i)
    {
        ptr_arr[i] = &arr[i];
        printf("Value: %d\tIndex: %p\n", arr[i], ptr_arr[i]);
    }

    printf("\n\n\n\n\nAfter Sort\n");

    insertion_sort(ptr_arr, ARR_SIZE);
}
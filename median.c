/*------------------------------------------------------
* Filename: median.c
* Description: Find median of numbers given.
* Author: Gershon Levy
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define START_SIZE (1)
#define SIZE_JUMP (10)

#define FALSE (0)
#define TRUE (1)

#define BAD_INPUT_ERR (-1)

/*------------------------------------------------------
* Function Name -  insertion_sort
*
* Function Purpose - Sorts an array using insertion sort.
*
* Parameters –  [IN arr - Our array.]
*               [IN n - The size of our array]
*
* Return Values - The sorted array.
*
* Author - Gershon Levy
-------------------------------------------------------*/

int *insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

    return arr;
}

int median(int nums[], int size)
{
    // if size is odd then we want the middle element
    if (size % 2 != 0)
    {
        return nums[(size + 1) / 2];
    }

    // if size is even then we want the average of the 2 middle elements
    return (nums[size / 2] + nums[(size / 2) + 1]) / 2;
}

int main()
{
    // init
    int max_size = START_SIZE; // note this can change in the future
    int size = 0;
    int minus = FALSE;
    int i = 0;

    int *nums = (int *)malloc(max_size * sizeof(int)); // allocate space
    int temp = fgetc(stdin);

    nums[0] = 0;

    do
    {
        // if we ran outta space
        if (max_size == size)
        {
            max_size += SIZE_JUMP;
            nums = (int *)realloc(nums, max_size * sizeof(int)); // increase space allocated
        }

        if ((temp < '0' || temp > '9') && temp != '-' && temp != ' ')
        {
            --size;
            break;
        }

        // end of number
        if (temp == ' ')
        {
            ++size;
            nums[size] = 0;
            temp = fgetc(stdin);
            minus = FALSE;
            continue;
        }

        // make space for next part of number (e.g turn 12 into 120 so we could make it into 123 easier)
        nums[size] *= 10;

        if (temp == '-')
        {
            minus = TRUE;
        }

        // add the last part of number
        if (temp != '-' && minus == FALSE)
        {
            nums[size] += temp - '0';
        }

        // number is negative so do opposite
        if (temp != '-' && minus == TRUE)
        {
            nums[size] -= temp - '0';
        }

        temp = fgetc(stdin);
    } while (temp != '\n');

    // we didnt grow size for last number
    ++size;

    nums = insertion_sort(nums, size);

    int median_num = median(nums, size);

    printf("The median is: %d\n", median_num);

    // deallocate space
    free(nums);

    return 0;
}
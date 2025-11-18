/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: Print values and addresses of arrays.
* Author: Gershon Levy
-------------------------------------------------------*/

#include <stdio.h>
#define SIZE 8
#define BAD_INPUT_ERR -1

int main()
{
    int arr[SIZE];
    char str[SIZE];
    int i = 0;

    /*get all ints*/
    printf("Enter %d nums\n", SIZE);
    for (i = 0; i < SIZE; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("bad input\n");
            return BAD_INPUT_ERR;
        }
    }

    /*get all chars*/
    printf("Enter %d chars\n", SIZE);
    for (i = 0; i < SIZE; ++i)
    {
        if (scanf(" %c", &str[i]) != 1)
        {
            printf("bad input\n");
            return BAD_INPUT_ERR;
        }
    }

    printf("-----INTS-----\n");
    for (i = 0; i < SIZE; ++i)
    {
        /*print the ints using []*/
        printf("Value: %d\tAddress: 0x%p\n", arr[i], &arr[i]);
    }

    printf("-----CHARS-----\n");
    for (i = 0; i < SIZE; ++i)
    {
        /*print the chars using * */
        printf("Value: %c\tAddress: 0x%p\n", *(str + i), str + i);
    }

    return 0;
}
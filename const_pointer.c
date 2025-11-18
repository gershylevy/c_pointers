/*------------------------------------------------------
* Filename: const_pointert.c
* Description: Change consts with pointers.
* Author: Gershon Levy
-------------------------------------------------------*/
#include <stdio.h>
#define BAD_INPUT_ERR -1

int main()
{
    const int channel_num;
    int *const channel_ptr = &channel_num;

    printf("Enter channel num\n");
    if (scanf("%d", &channel_num) != 1)
    {
        printf("bad input\n");
        return BAD_INPUT_ERR;
    }

    printf("You chose channel number: %d (its const)\n", channel_num);

    printf("Enter new channel num\n");

    if (scanf("%d", channel_ptr) != 1)
    {
        printf("bad input\n");
        return BAD_INPUT_ERR;
    }

    printf("New channel number is: %d (its still const)", channel_num);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "Algo.h"

int main(int argc, char *argv[])
{
    int item_count, volume, box_count = 0;
    item_count = argc - 1;
    volume = atoi(argv[1]);
    int *item_volumes = (int *)calloc(item_count, sizeof(int));

    for (int i = 2; i < argc; i++)
    {
        item_volumes[i - 2] = atoi(argv[i]);
        if (item_volumes[i - 2] > volume)
        {
            printf("Error: Item volume is greater than box volume\n");
            return 0;
        }
    }

    minimum_boxes(item_volumes, item_count, volume, &box_count);

    printf("%d", box_count);

    free(item_volumes);
    return 0;
}
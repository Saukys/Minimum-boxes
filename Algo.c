#include "Algo.h"
#include <stdlib.h>

int minimum_boxes(int *item_volumes, int item_count, int volume, int *box_count)
{
    sort(item_volumes, item_count);
    int *box_volumes = (int *)calloc(item_count, sizeof(int));
    for (int i = 0; i < item_count; i++)
    {
        for (int j = 0; j < item_count; j++)
        {
            if (box_volumes[i] + item_volumes[j] <= volume)
            {
                box_volumes[i] += item_volumes[j];
                item_volumes[j] = 0;
            }
        }
    }
    for (int i = 0; i < item_count; i++)
    {
        if (box_volumes[i] != 0)
        {
            *box_count += 1;
        }
        else
        {

            free(box_volumes);
            return 0;
        }
    }
    free(box_volumes);
    return 0;
}

void sort(int *item_volumes, int item_count)
{
    for (int i = 0; i < item_count; i++)
    {
        for (int j = 0; j < item_count - i - 1; j++)
        {
            if (item_volumes[j] < item_volumes[j + 1])
            {
                int temp = item_volumes[j];
                item_volumes[j] = item_volumes[j + 1];
                item_volumes[j + 1] = temp;
            }
        }
    }
}
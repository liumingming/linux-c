#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

int main(void) {
    int *arr = malloc(sizeof(int)  * MAX_SIZE);

    if (arr == NULL) {
        printf("malloc memory filead");
    }

    for (int i = 0; i <  MAX_SIZE;  i++)  {
        arr[i] = i * i;
    }

    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
}
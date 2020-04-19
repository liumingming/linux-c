#include <stdlib.h>
#include <string.h>

#include "heap.h"

#define heap_parent(npos) ((int)(((npos) - 1) / 2))

#define heap_left(npos) (((npos) * 2) + 1)

#define heap_right(npos) (((npos) * 2) + 2)


void heap_init(Heap *heap, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data))
{
    heap->size = 0;
    heap->compare = compare;
    heap->destroy = destory;
    heap->tree = NULL;
}


void head_destroy(Heap *heap)
{
    
}

int heap_insert(Heap *heap, void **data)
{

}

int heap_extract(Heap *heap, void **data)
{

}
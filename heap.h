#ifndef HEAP_H
#define HEAP_H

typedef struct heap_
{
    /* data */
    int size;
    int (*compare)(const void *key1, const void *key2);
    int (*destroy)(void *data);
    void **tree;
} Heap ;

void heap_init(Heap *heap, int(*compare)(const void *key1, const void *key2), void(*destory)(void *data));

void head_destroy(Heap *heap);

int heap_insert(Heap *heap, void **data);

int heap_extract(Heap *heap, void **data);

#define heap_size(heap) ((heap)->size)
#endif
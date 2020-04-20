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
    if (heap->destroy != NULL) {
        for (int i = 0; i < heap_size(heap); i++) {
            heap->destroy(heap->tree[i]);
        }
    }
    free(heap->tree);
    memset(heap, 0, sizeof(heap));
    return;
}

int heap_insert(Heap *heap, void **data)
{
    void *temp;
    int ipos, ppos;
    temp = realloc(heap->tree, (heap_size(heap)+1)*sizeof(void *));
    if (temp == NULL) {
        return -1;
    }
    heap->tree = temp;

    heap->tree[heap_size(heap)] = (void *)data;

    ipos = heap_size(heap);
    ppos = heap_parent(ipos);

    while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0 ) {
        temp = heap->tree[ppos];
        heap->tree[ppos] = heap->tree[ipos];
        heap->tree[ipos] = temp;

        ipos = ppos;
        ppos = heap_parent(ipos);
    }
    heap->size++;
    return 0;
}

int heap_extract(Heap *heap, void **data)
{
    void *save, *temp;
    int ipos, lpos, rpos, mpos;

    if (heap_size(heap) == 0) {
        return -1;
    }

    data = heap->tree[0];
    save = heap->tree[heap_size(heap) - 1];

    if (heap_size(heap) - 1 > 0) {
        temp = realloc(heap->tree, (heap_size(heap)-1)*sizeof(void *));
        if (temp == NULL) {
            return -1;
        } else
        {
            heap->tree = temp;
        }
        heap->size--;
    } else
    {
        free(heap->tree);
        heap->tree = NULL;
        heap->size = 0;
        return 0;
    }

    heap->tree[0] = save;
    ipos = 0;
    lpos = heap_left(ipos);
    rpos = heap_right(ipos);

    while (1)
    {
        lpos = heap_left(ipos);
        rpos = heap_right(ipos);

        if (lpos < heap_size(heap) && heap->compare(heap->tree[ipos], heap->tree[lpos]) > 0) {
            mpos = lpos;
        } else {
            mpos = ipos;
        }

        if (rpos < heap_size(heap) && heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0) {
            mpos = rpos;
        }

       if (mpos == ipos) {
            break;
       } else {
            temp = heap->tree[mpos];
            heap->tree[mpos] = heap->tree[ipos];
            heap->tree[ipos] = temp;
            ipos = temp;
       }
        
    }
    return 0;
}
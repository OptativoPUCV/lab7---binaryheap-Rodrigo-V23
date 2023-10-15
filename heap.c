#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

void* heap_top(Heap* pq)
{
  if(pq -> size == 0)
  {
    return NULL;
  }
  return pq -> heapArray[0].data;
}
void heap_push(Heap* pq, void* data, int p)
{
  if (pq->size == pq->capac)
  {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
  }
  int index = pq->size;
  pq->size++;

  while (index > 0)
  {
    int parentIndex = (index - 1) / 2;
    if (pq->heapArray[parentIndex].priority >= p)
    {
      break;
    }
    pq->heapArray[index] = pq->heapArray[parentIndex];
    index = parentIndex;
  }
  pq->heapArray[index].data = data;
  pq->heapArray[index].priority = p;
}
void heap_pop(Heap* pq)
{
  if(pq -> size == 0)
  {
    return;
  }
  pq -> size--;
  int index = 0;
  heapElem last = pq -> heapArray[pq -> size];

  int child;
  while(2 * index + 1 < pq -> size)
  {
    child = 2 * index  + 1;
    if(child + 1 < pq -> size && pq -> heapArray[child + 1].priority > pq -> heapArray[child].priority)
    {
      child++;
    }
    if(last.priority >= pq -> heapArray[child].priority)
    {
      break;
    }
    pq -> heapArray[index] = pq -> heapArray[child];
    index = child;
  }
  pq -> heapArray[index] = last
}
Heap* createHeap()
{
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
  newHeap->size = 0;
  newHeap->capac = 3;
  return newHeap;
}
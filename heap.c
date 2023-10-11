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
void heap_push(Heap* pq, void* data, int priority)
{
  if(pq -> size == pq -> capac)
  {
    pq -> capac = (pq -> capac * 2) + 1;
    pq -> heapArray = (heapElem *) realloc(pq -> heapArray, sizeof(heapElem);
  }
  int index = pq -> size;
  pq -> size++;

  while(index > 0)
  {
    int parentIndex = (index - 1) / 2;
    if(pq -> heapArray[parentIndex].priority < priority)
    {
      break;
    }
    pq -> heapArray[index] = pq -> heapArray[parentIndex];
    index = parentIndex;
  }
  pq->heapArray[index].data = data;
  pq->heapArray[index].priority = priority;
}
void heap_pop(Heap* pq)
{

}
Heap* createHeap()
{
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
  newHeap->size = 0;
  newHeap->capac = 3;
  return newHeap;
}
/* Queue.h -- contiguous implementation of a Queue of integers */

typedef struct {
  int top;
  int max;
  int *elts;
} Queue;

Queue *createQueue(int maxSize);
void destroyQueue(Queue *q);
int isEmpty(Queue *q);
void enQueue(Queue *q, int elt);
void deQueue(Queue *q);
int top(Queue *q);
int isFull(Queue *q);
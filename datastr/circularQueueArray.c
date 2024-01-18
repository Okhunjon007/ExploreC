#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Queue{
	uint32_t capacity;
	int32_t head, tail;
	int32_t *data;
}Queue;

int createQueue(Queue **q, uint32_t capa)
{
	*q=(Queue *)malloc(sizeof(Queue));
	(*q)->capacity=capa;
	(*q)->head=(*q)->tail=-1;
	(*q)->data=(int *)malloc(sizeof(int)*capa);
	return 0;
}

int enqueue(Queue *q, uint32_t data)
{
	if(q->tail==-1){
		q->head=q->tail=0;
		q->data[q->head]=q->data[q->tail]=data;
		return 0;
	}

	if(((q->tail+1)%q->capacity)==q->head)
	{
		printf("Queue is full\n");
		return 1;
	}

	q->tail=(q->tail+1)%q->capacity;
	q->data[q->tail]=data;
	return 0;
}

int dequeue(Queue *q, int *data)
{
	if(q->tail==-1)
		return 1;
	if(q->head==q->tail){
		*data=q->head;
		q->head=q->tail=-1;
		return 0;
	}
	*data=q->data[q->head];
	q->head=(q->head+1)%q->capacity;
	return 0;
}

int printQueue(Queue *q)
{
	if(q->head==-1){
		return 1;
	}
	else if(q->tail>=q->head && q->head != -1)
	{
		for(int i=q->head;i<=q->tail;i++)
		{
			printf("%d ", q->data[i]);
		}
	}
	else if(q->tail < q->head)
	{
		for(int i=q->head;i<q->capacity;i++)
		{
			printf("%d ", q->data[i]);
		}
		for(int i=0;i<=q->tail;i++)
		{
			printf("%d ", q->data[i]);
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	Queue *q;
	createQueue(&q, 2);
	printf("Before enqueueing\n");
	printQueue(q);
	printf("\nEnqueueing\n");
	enqueue(q, 3);
	enqueue(q, 8);
	enqueue(q, 9);
	printf("\nAfter enqueueing\n");
        printQueue(q);
	int i;
	dequeue(q, &i);
	printf("\nafter dequeueing %d look\n", i);
        printQueue(q);

	return 0;
}

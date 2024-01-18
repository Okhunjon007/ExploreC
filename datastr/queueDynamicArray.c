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

int resize(Queue *q)
{
	printf("Resize has been called\n");
	uint32_t oldsize=q->capacity;
	q->capacity=2*(q->capacity);
	q->data=(int *)realloc(q->data, q->capacity);
	if(q->head>q->tail)
	{
		for(int i=oldsize-1;i>=q->head;i--)
		{
			q->data[i+oldsize]=q->data[i];
		}
	}
	return 0;
}

int enqueue(Queue *q, int32_t ele)
{
	if(q->tail==-1)
	{
		q->head=q->tail=0;
		q->data[q->tail]=ele;
		return 0;
	}

	if(((q->tail+1)%q->capacity)==q->head)
		resize(q);
	q->tail=(q->tail+1)%q->capacity;
	q->data[q->tail]=ele;
	return 0;
}

int dequeu(Queue *q, int *poped)
{
	if(q->head==-1)
		return 1;
	*poped=q->data[q->head];
	
	if(q->head==q->tail)
	{
		q->head=q->tail=-1;
		return 0;
	}

	q->head=(q->head+1)%q->capacity;
	return 0;
}

int printQueue(Queue *q)
{
	if(q->head<q->tail)
	{
		for(int i=q->head;i<=q->tail;i++)
		{
			printf("%d ", q->data[i]);
		}
	}
	else
	{
		for(int i=q->head;i<q->capacity;i++)
		{
			printf("%d ", q->data[i]);
		}
		for(int i=0;i<=q->head;i++)
			printf("%d ", q->data[i]);
	}
}

int main(int argc, char *argv[])
{
	Queue *q;
	createQueue(&q,2);
	printf("Before enqueing the queue\n");
	printQueue(q);
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	printf("\nAfter enqueing the queue\n");
        printQueue(q);
	int i;
	dequeu(q, &i);
	printf("\nAfter dequeing the queue\n");
        printQueue(q);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
	int32_t data;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *head;
	Node *tail;
}Queue;


int createQueue(Queue **q)
{
	*q=(Queue *)malloc(sizeof(Queue));
	(*q)->head=NULL;
	(*q)->tail=NULL;
	return 0;
}

int enqueue(Queue *q, int32_t data)
{
	Node *tmp=(Node *)malloc(sizeof(Node));
	tmp->data=data;
	tmp->next=NULL;
	if(q->head==NULL){
		q->head=tmp;
		q->tail=tmp;
		return 0;
	}

	q->tail->next=tmp;
	q->tail=tmp;
	return 0;
}

int dequeue(Queue *q, int32_t *data)
{
	if(q->head==NULL)
		return 1;

	(*data)=q->head->data;
	Node *tmp=q->head;
	q->head=q->head->next;
	if(q->head==NULL)
		q->tail=NULL;
	free(tmp);
	return 0;
}

int printQueue(Queue *q)
{
	Node *cur=q->head;
	while(cur!=NULL)
	{
		printf("%d ", cur->data);
		cur=cur->next;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	Queue *q;
	createQueue(&q);
	printf("Before enqueueing \n");
	printQueue(q);
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	printf("After enqueueing \n");
	printQueue(q);
	int32_t i;
	dequeue(q,&i);
	printf("After dequeueing %d\n", i);
	printQueue(q);
	return 0;
}


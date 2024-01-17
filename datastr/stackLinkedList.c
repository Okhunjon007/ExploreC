#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
	uint32_t data;
	struct Node *next;
}Node;


int createStack(Node **stack)
{
	*stack=NULL;
	return 0;
}

int push(Node **stack, uint32_t data)
{
	Node *tmp=(Node*)malloc(sizeof(Node));
	//check for failure of memory allocation
	tmp->data=data;
	tmp->next=*stack;
	*stack=tmp;
	return 0;
}

int pop(Node **stack, uint32_t *data)
{
	Node *tmp=*stack;
	if(!tmp)
		return 1;

	(*data)=tmp->data;
	*stack=tmp->next;
	free(tmp);
	return 0;
}

int deleteStack(Node **stack)
{
	while(*stack !=NULL)
	{
		Node *tmp=*stack;
		*stack=tmp->next;
		free(tmp);
	}
	return 0;
}

int printStackTopDown(Node **stack)
{
	Node *cur=*stack;
	while(cur !=NULL)
	{
		printf("%d ", cur->data);
		cur=cur->next;
	}
	return 0;
}

int main(int argc,char *argv[])
{
	Node *stack;
	createStack(&stack);
	printf("before push\n");
	printStackTopDown(&stack);
	push(&stack, 10);
	push(&stack, 98);
	push(&stack, 69);
	printf("after push\n");
	printStackTopDown(&stack);
	uint32_t i;
	pop(&stack, &i);
	printf("after poping %d\n", i);
	printStackTopDown(&stack);
	return 0;
}

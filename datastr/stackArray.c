#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
	int32_t capacity;
	int32_t top;
	uint32_t *data;
}Node;

int createStack(Node **stack, uint32_t cap)
{
	*stack=(Node *)malloc(sizeof(Node)); //check return
	(*stack)->capacity=cap;
	(*stack)->top=-1;
	(*stack)->data=(uint32_t *)malloc(sizeof(uint32_t)*cap); //check return
	return 0;
}

int push(Node *stack, uint32_t elem)
{
	if(stack->top < stack->capacity -1)
	{
		stack->data[++(stack->top)]=elem;
		return 0;
	}
	else
		return 1;
}

int pop(Node *stack, uint32_t *data)
{
	if(stack->top == -1)
		return 1;
	else{
		data=stack->data[(stack->top)--];
		return 0;
	}
}

int printStack(Node *stack)
{
	int count=stack->top;
	for(int i=0;i<=count;i++)
	{
		printf("%d ", stack->data[stack->top -i]);
	}
}

int main(int argc, char *argv[])
{
	Node *stack;
	createStack(&stack,7);
	printf("Before pushing any element\n");
	printStack(stack);
	push(stack, 10);
	push(stack, 98);
	push(stack, 69);
	printf("\nAfter pushing elements\n");
        printStack(stack);
	int el;
	pop(stack, &el);
	printf("\nAfter poping %d element\n", el);
        printStack(stack);

	return 0;
}


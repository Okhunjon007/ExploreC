#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
	int32_t *data;
	uint32_t capacity;
	int32_t top;
}Node;

int createStack(Node **stack, uint32_t icap)
{
	*stack=(Node *)malloc(sizeof(Node));
	(*stack)->capacity=icap;
	(*stack)->top=-1;
	(*stack)->data=(int *)malloc(sizeof(int)*icap);
	return 0;
}

int resizeStack(Node **stack)
{
        uint32_t origSize=(*stack)->capacity;
        (*stack)->capacity=2*origSize;
        (*stack)->data=(Node *)realloc((*stack)->data, 2*origSize);
}

int push(Node *stack, uint32_t elem)
{
        if(stack->top==stack->capacity-1)
                resizeStack(&stack);
        stack->data[++(stack->top)]=elem;
        return 0;
}

int pop(Node *stack, int *data)
{
        if(stack->top==-1)
                return 1;
        else{
                data=stack->data[(stack->top)--];
                return 0;
        }
}

int printStackTopDown(Node *stack)
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
        createStack(&stack,2);
        push(stack, 19);
        push(stack, 28);
	printStackTopDown(stack);
	push(stack, 999);
	push(stack, 109);
	printStackTopDown(stack);
        return 0;
}


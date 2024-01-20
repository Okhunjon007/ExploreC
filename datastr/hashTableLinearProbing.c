#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 20

typedef struct Node{
	int32_t key;
	int32_t value;
}Node;

Node *hashtable[SIZE];
Node *dummy;

int32_t hashcode(int32_t key)
{
	return key%SIZE;
}

int32_t insert(int32_t key, int32_t value)
{
	Node *tmp=(Node *)malloc(sizeof(Node));
	tmp->key=key;
	tmp->value=value;
	int32_t index=hashcode(key);
	while(hashtable[index] !=NULL && hashtable[index]->key != -1)
	{
		index++;

		if(index==SIZE)
		{
			printf("Hash table is full\n");
			return 1;
		}
	}
	hashtable[index]=tmp;
}

void delete(int32_t key){
	int32_t index=hashcode(key);
	while(hashtable[index]->key != key)
	{
		index++;
		if(index==SIZE)
                {
                        printf("Not found\n");
                        //return 1;
                }
	}
	Node *tmp=hashtable[index];
	hashtable[index]=dummy;
	free(tmp);
}

void display(void)
{
	for(int i=0;i<SIZE;i++)
	{
		if(hashtable[i]!=NULL)
			printf("index= %d     key:%d value:%d\n", i, hashtable[i]->key, hashtable[i]->value);
		else
			printf("\n");
	}
}

int main(void)
{
	dummy=(Node *)malloc(sizeof(Node));
	dummy->key=-1;
	dummy->value=-1;

	insert(1, 20);
   	insert(2, 70);
   	insert(42, 80);
   	insert(4, 25);
   	insert(12, 44);
   	insert(14, 32);
   	insert(17, 11);
   	insert(13, 78);
   	insert(37, 97);

   	display();

	delete(37);
	delete(42);
	printf("After deletion\n");
	display();

	return 0;
}

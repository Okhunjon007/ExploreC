#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 31

typedef struct Node{
	int32_t value;
	int32_t key;
	struct Node *next;
}Node;

Node *hashtable[SIZE];

int32_t hashcode(int32_t key)
{
	return key%SIZE;
}


Node *search(int32_t key)
{
	uint32_t index=hashcode(key);
	Node *cur=hashtable[index];
	while(cur!=NULL)
	{
		if(cur->key==key)
			return cur;
		cur=cur->next;
	}
	return NULL;
}

int32_t insert(int32_t key, int32_t value)
{
	Node *tmp=(Node *)malloc(sizeof(Node));
	tmp->key=key;
	tmp->value=value;
	uint32_t index=hashcode(key);
	if(hashtable[index] == NULL)
		hashtable[index]=tmp;
	else{
		Node *cur=hashtable[index];
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=tmp;
	}
	return 0;
}

int32_t delete(int32_t key)
{
	int32_t index=hashcode(key);
	if(hashtable[index]==NULL)
		return 1;
	else if(hashtable[index]->key == key)
	{
		Node *cur=hashtable[index];
		hashtable[index]=cur->next;
		free(cur);
	}
	else{

		Node *cur=hashtable[index]->next;
		Node *prev=hashtable[index];
		while(cur != NULL && cur->key != key)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=cur->next;
		free(cur);		
	}
}

void printHashtable(void)
{
	for(int i=0;i<SIZE;i++)
	{
		Node *cur=hashtable[i];
		if(cur != NULL)
                        printf("\n");
		while(cur!=NULL)
		{
			printf("key:%d = value:%d ", cur->key, cur->value);
			cur=cur->next;
		}
	}
}

int main(int argc, char *argv[])
{
	printHashtable();
	insert(5, 89);
	insert(30, 65);
	insert(7, 8);
	insert(36, 76);
	insert(160, 90);
	printHashtable();
	delete(36);
	printHashtable();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int32_t data;
	struct Node *next;
};

void printList(struct Node *head)
{
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head=head->next;
	}
}

int insertHead(struct Node **head, int data)
{
	struct Node *tmp=(struct Node *) malloc(sizeof(struct Node));
	if(tmp==NULL)
	{
		printf("Cannot allocate memory. Returning...");
		return 1;
	}

	tmp->data=data;
	tmp->next=*head;
	*head=tmp;
	return 0;
}	

int deleteHead(struct Node **head)
{
	if(*head == NULL)
	{
		printf("Empty.\n");
		return 1;
	}
	else
	{
		struct Node *tmp=*head;
		*head=(*head)->next;
		int32_t data=tmp->data;
		free(tmp);
		return data;
	}
}

int main(int argc, char *argv[])
{
	struct Node **head=(struct Node **)malloc(sizeof(struct Node **));
	*head=NULL;
	insertHead(head, 8);
	insertHead(head, 9);
	insertHead(head, 10);
	printList(*head);
	deleteHead(head);
	printf("\nafter deleteion: ");
	printList(*head);
	return 0;
}

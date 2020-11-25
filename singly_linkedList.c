#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head = NULL;
//insert at beginning
void insertBeg(int x)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	if(head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head = newNode;
	}
	printf("Node inserted successfully at beginning.\n");
}

//insert at end

void insertEnd(int x)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	newNode -> next = NULL;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		struct Node *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
	printf("Node inserted successfully at end.\n");	
}

//insertion at specific position

void insertPos(int x, int pos)
{
	int i = 0;
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	if(head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
	}
	else
	{
		struct Node *temp = head;
		for(i = 0; i < pos - 1; i++)
		{
			temp = temp -> next;
			
		}
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}
	printf("Node inserted successfully at position %d\n", pos);
}

//deletion at beginning

void delBeg()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct Node *temp = head;
		if(head -> next == NULL)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			head = temp -> next;
			free(temp);
			printf("Node deleted at the beginning.\n");
		}
	}
}
void delEnd()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct Node *temp1 = head , *temp2;
		if(head -> next == NULL)
		{
			head = NULL;
		}
		else
		{
			while(temp1 -> next != NULL)
			{
				temp2 = temp1;
				temp1 = temp1 -> next;
			}
			temp2 -> next = NULL;
		}
		free(temp1);
		printf("Node deleted at the end.\n");			
	}
}

//deletion at particular position

void delPos(int pos)
{
	int i, flag = 0;
	struct Node *temp1 = head, *temp2;
	if(pos == 1)
	{
		head = temp1 -> next;
		free(temp1);
		printf("Node deleted from position %d\n",pos);
	}
	else
	{
		for(i = 0; i < pos - 1; i++)
		{
			if(temp1 ->next != NULL)
			{
				temp2 = temp1;
				temp1 = temp1 -> next;
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			temp2 -> next = temp1 -> next;
			free(temp1);
			printf("Node deleted at position %d\n", pos);
		}
		else
		{
			printf("Positiong exceeds linked list. \n");
		}
	}
}

//displaying

void show(struct Node* n)
{
	while(n != NULL)
	{
		printf("%d\n", n ->data);
		n = n -> next;
	}
	if(head == NULL)
	{
		printf("List is empty\n");
	}
}

int main()
{
	int ch, val, pos;
	do
	{
		printf("===================================================================\n");
		printf("Available Linked List Operations:\n");
		printf("===================================================================\n");
		printf("1. Insert at Beginning\n");
		printf("2. Insert at End\n");
		printf("3. Insert at Spcific Position\n");
		printf("4. Delete at Beginning\n");
		printf("5. Delete at End\n");
		printf("6. Delete at Specific Position\n");
		printf("7. Show Linked List\n");
		printf("8. Exit\n");
		printf("3. Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter value to insert at beginning: ");
					scanf("%d", &val);
					insertBeg(val);
					break;
			
			case 2: printf("Enter value to insert at end: ");
					scanf("%d",&val);
					insertEnd(val);
					break;
					
			case 3: printf("Enter value to insert at certain position: ");
					scanf("%d", &val);
					printf("Enter position: ");
					scanf("%d", &pos);
					insertPos(val, pos);
					break;
					
			case 4: delBeg();
					break;
		
			case 5: delEnd();
					break;
					
			case 6: printf("Enter position from which you want to delete: ");
					scanf("%d", &pos);
					delPos(pos);
					break;
					
			case 7: show(head);
					break;
					
			case 8: printf("Exiting..\n");
					break;
					
			default:printf("Invalid choice\n");
					break;
		}
	}while(ch != 8);
	return(0);
}

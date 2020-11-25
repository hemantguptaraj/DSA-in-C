/*
	DOUBLY LINKED LIST
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* previous;
};
struct Node* head = NULL;
struct Node *current = NULL;
//insert at beginning
void insertBeg(int x)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	newNode -> previous = NULL;
	if(head == NULL)
	{
		newNode -> next = NULL;
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head -> previous = newNode;
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
		head -> previous = NULL;
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
		newNode -> previous = temp;
	}
	printf("Node inserted successfully at end.\n");	
}


//insertion at specific position

void insertPos(int x, int pos)
{
	int i, flag = 1;
	struct Node *newNode, *temp = head;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	if(head == NULL)
	{
		newNode -> previous = newNode ->next =  NULL;
		head = newNode;
	}
	else
	{
		for(i = 0; i < pos - 1; i++)
		{
			temp = temp -> next;
			if(temp -> next == NULL)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			newNode -> next = temp -> next;
			temp -> next -> previous = newNode;	
			temp -> next = newNode;
			newNode -> previous = temp;
			printf("Node inserted successfully at position %d\n", pos);
		}		
		else
		{
			printf("Number of elements is less than position entered\n");
		}
	}
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
		if(temp -> previous == temp -> next)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			head = temp -> next;
			head -> previous = NULL;
			free(temp);
		}			
		printf("Node deleted at the beginning.\n");
	}
}

//deletion at end

void delEnd()
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct Node *temp = head;
		if(temp -> previous == temp -> next)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> previous -> next == NULL;
			free(temp);
		}
		printf("Node deleted at the end.\n");
	}
}

//deletion at particular position

void delPos(int pos)
{
	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		struct Node *temp = head;
		while(temp -> data != pos)	
		{
			if(temp -> next == NULL)
			{
				printf("Given node is not found in the list\n");
				break;
			}
			else
			{
				temp = temp -> next;
			}
		}
		if(temp == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			temp -> previous -> next = temp -> next;
			free(temp);
		}
		printf("Deletion Successfully\n");
	}	
}

//displaying(forward traversing)

void show(struct Node* n)
{
	//start from beginning
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

void search(int data)
{
	int pos = 0;
	if(head == NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	current = head;
	while(current != NULL)
	{
		pos++;
		if(current->data == data)
		{
			printf("%d found at position %d\n", data, pos);
			return;
		}
		if(current -> next != NULL)
		{
			current = current -> next;
		}
		else
		{
			break;
		}
	}
	printf("%d does not exist in the list\n", data);
}
int main()
{
	int ch, val, pos;
	do
	{
		printf("===================================================================\n");
		printf("Available Doubly Linked List Operations:\n");
		printf("===================================================================\n");
		printf("1. Insert at Beginning\n");
		printf("2. Insert at End\n");
		printf("3. Insert at Spcific Position\n");
		printf("4. Delete at Beginning\n");
		printf("5. Delete at End\n");
		printf("6. Delete at Specific Position\n");
		printf("7. Show Linked List\n");
		printf("8. Search in Linked List\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
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
			
			case 8: printf("Enter element to search in Linked List: ");
					scanf("%d", &val);
					search(val);		
					break;
					
			case 9: printf("Exiting..\n");
					break;
					
			default:printf("Invalid choice\n");
					break;
		}
	}while(ch != 9);
	return(0);
}

/*
	CIRCULAR LIKNKED LIST
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

void beg_insert(int val)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = val;
	if(head == NULL)
	{
		head = newNode;
		newNode -> next = head;
	}
	else
	{
		struct Node *temp = head;
		while(temp -> next != head)
		{
			temp = temp -> next;
		}
		newNode -> next = head;
		head = newNode;
		temp -> next = head;
	}
	printf("\n Insertion Successfully");
}


void last_insert(int val)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = val;
	if(head == NULL)
	{
		head = newNode;
		newNode -> next;
	}
	else
	{
		struct Node *temp = head;
		while(temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
	printf("Insertion Successfull\n");
}

void random_insert(int val, int pos)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	if(head == NULL)
	{
		head = newNode;
		newNode->next = head;
	}
	else
	{
		struct Node *temp = head;
		while(temp->data != pos)
		{
			if(temp->next == head)
			{
				printf("Location not found\n");
			}
			else
			{
				temp = temp->next;
			}
		}
		newNode->next = temp->next;
		temp->next = newNode;
		printf("Insertion Successfull\n");
	}
}

void beg_delete()
{
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node *temp = head, *last = NULL;
		if(temp->next == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			last = temp;
			temp = head;
			head = head->next;
			free(temp);
			last->next = head;
		}
		printf("Deletion Successfull\n");
	}
}

void last_delete()
{
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node *temp = head, *last = NULL;
		if(temp->next == head)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			last = temp;
			temp = head;
			head = head->next;
			free(temp);
			last->next = head;
		}
		printf("Deletion Successfull\n");
	}
}

void random_delete(int del_val)
{
	if(head == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		struct Node *temp1 = head, *temp2;
		while(temp1->data != del_val)
		{
			if(temp1->next == head)
			{
				printf("Given node is not found\n");
			}
			else
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
		}
		if(temp1->next == head)
		{
			head = NULL;
			free(temp1);
		}
		else
		{
			if(temp1 == head)	
			{
				temp2 = head;
				while(temp2->next != head)
				{
					temp2 = temp2->next;
				}
				head = head->next;
				temp2->next = head;
				free(temp1);
			}
			else
			{
				if(temp1->next == head)
				{
					temp2->next = head;
				}
				else
				{
					temp2->next = temp1->next;
				}
				free(temp1);
			}
		}
		printf("Deletion Successfull\n");
	}
}

void show()
{
	struct Node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("List is Empty\n");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr-> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }           
}

void search()
{
	struct Node *ptr;  
    int item,i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        if(head ->data == item)  
        {  
	        printf("item found at location %d",i+1);  
	        flag=0;  
        }  
        else   
        {  
        while (ptr->next != head)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr->next;
        }  
        }  
        if(flag != 0)  
        {  
            printf("Item not found\n");  
        }  
    }     
}

int main()
{
	int ch,val, pos, sch;
	do
	{
		printf("CIRCULAR LINKED LIST OPERATIONS\n");
		printf("1. Insert at begining\n");
		printf("2. Insert at end\n");
		printf("3. Insert at any position\n");
		printf("4. Delete at begining\n");
		printf("5. Delete at end\n");
		printf("6. Delete at at any prosition\n");
		printf("7. Show Circular Linked List\n");
		printf("8. Search\n");
		printf("9. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter value to insert: ");
					scanf("%d", &val);
			 		beg_insert(val);
					break;
					
			case 2: printf("Enter value to insert: ");
					scanf("%d", &val);
					last_insert(val);
					break;
					
			case 3: printf("Enter value to insert: ");
					scanf("%d", &val);
					printf("Enter position after which you want to insert: ");
					scanf("%d", &pos);
					random_insert(val, pos);
					break;
					
			case 4: beg_delete();
					break;
					
			case 5: last_delete();
					break;
					
			case 6: printf("Enter the element after which you want to delete: ");
					scanf("%d", &pos);
					random_delete(pos);
					break;
					
			case 7: show();
					break;
			
			case 8: printf("Enter value to search: ");
					scanf("%d", &sch);
					search(sch);
					break;
					
			case 9: break;
			
			default: printf("Invalid Choice");
					 break;
		}
	}while(ch != 9);
	return(0);
}

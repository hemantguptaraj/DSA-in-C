#include<stdio.h>

struct list
{
    int data;
    struct list *link;
}*front=NULL,*rear=NULL;

void create()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    struct list *tmp;
    tmp=(struct list *)malloc(sizeof(struct list));
    tmp->data=n;
    tmp->link=NULL;
    if(front==NULL)
    front=tmp;
    else
    rear->link=tmp;
    rear=tmp;
}

void del()
{
    struct list *tmp;
    if(front==NULL)
    printf("\n\nQueue is full");
    else
    {
        tmp=front;
        printf("Deleted element is %d",tmp->data);
        front=front->link;
        free(tmp);
    }
}

void disp()
{
    struct list *q;
    if(front==NULL)
    printf("Queue is empty");
    else
    {
        q=front;
        printf("Queue elements are ");
        while(q!=NULL)
        {
            printf("%d==>",q->data);
            q=q->link;
        }
    }
}

void main()
{
    int i,ch;
    printf("------MENU------\n1. Insert\n2. Delete\n3. Display\n4. Exit");
    while(ch)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:del();break;
            case 3:disp();break;
            case 4:exit(0);break;
            default:printf("Invalid choice");break;
        }
    }
}
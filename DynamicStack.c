#include<stdio.h>
#include<malloc.h>

struct list
{
    int data;
    struct list *link;
}*top=NULL;

void push()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    struct list *temp;
    temp=(struct list*)malloc(sizeof(struct list));
    temp->data=n;
    temp->link=top;
    top=temp;
}

void pop()
{
    struct list *temp;
    if(top==NULL)
    printf("Stack is empty");
    else
    {
        temp=top;
        printf("Deleted element is %d",temp->data);
        top=top->link;
        free(temp);
    }
}

void display()
{
    struct list *q;
    if(top==NULL)
    printf("Stack is empty");
    else
    {
        q=top;
        while (q!=NULL)
        {
            printf("%d->",q->data);
            q=q->link;
        }
    }
}

void main()
{
    int i,c;
    printf("------MENU------\n1. Push\n2. Pop\n3. Display\n4. Exit");
    while (c)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&c);
        switch (c)
        {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: exit(0); break;
        default: printf("Invalid input"); break;
        }
    }
}
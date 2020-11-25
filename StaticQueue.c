#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int q[MAX],rear=-1,front=-1;

void insert()
{
    int item;
    if(rear==MAX-1)
    printf("Queue is full");
    else
    {
        if(front==-1)
        front=0;
        printf("Insert element in queue: ");
        scanf("%d", &item);
        rear++;
        q[rear]=item;
    }
}

void delete()
{
    if(front==-1||front>rear)
    printf("Queue is already empty");
    else
    {
        printf("Element deleted from queue is : %d", q[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1)
    printf("Queue is empty");
    else
    {
        printf("Queue is ");
        for(i=front;i<=rear;i++)
        printf("%d",q[i]);
    }
}

void main()
{
    int c;
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
    while (c)
    {
        printf("\n\nEnter your choice : ");
        scanf("%d", &c);
        switch(c)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice"); break;
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
#define max 20
int top=-1,s[max];

void push()
{
    int n;
    if(top==max-1)
    printf("Stack is full");
    else
    {
        printf("Enter element to push: ");
        scanf("%d",&n);
        top++;
        s[top]=n;
    }
}

void pop()
{
    int d;
    if(top==-1)
    printf("Stack is empty");
    else
    {
        d=s[top];
        printf("Deleted element is %d",d);
        top--;
    }
}

void display()
{
    int i;
    if(top==-1)
    printf("Stack is empty");
    else
    {
        printf("Elements are");
        for(i=0;i<=top;i++)
        printf("\t%d",s[i]);
    }
}

void main()
{
    int c;
    printf("------MENU------\n1. Push\n2. Pop\n3. Display\n4. Exit");
    while(c)
    {
    printf("\n\nEnter choice: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: exit(0); break;
        default: printf("Invalid choice"); break;
    }
    }
}
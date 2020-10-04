#include<stdio.h>
#include<conio.h>
int main(){
	int i, flag;
	int a[10];
	int element;
	printf("Enter values of array : \n");
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
		
	}
	printf("enter element to be searched  :");
	scanf("%d",&element);
	for(i=0;i<10; i++)
	{
		if(element==a[i])
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
		}
		    
	}
	if(flag==1)
	{
		printf("This element is on %d position",i);
    } 
    else
	{
		printf("This element is not there in array");
	}
	getch();
	return 0;
}

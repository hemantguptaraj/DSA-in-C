#include<stdio.h>
#include<conio.h>
int main(){
	int a[10];
	printf("Total Size of Array is 10, Make sure that total no of elements are not more then total size of array.\n");
	int i,n;
	int position, element;
	printf("Total Elements to be Inserted   : ");
	scanf("%d",&n);
	{	
	printf("Enter values of array : \n");
	for(i=0; i<n; i++)
 	  {
		scanf("%d",&a[i]);
	  }
    }
	
	printf("Enter Position at which elements needs to be inserted  :");
	scanf("%d",&position);
	printf("Enter Element to be inserted  :");
	scanf("%d",&element);
	
    for(i=n; i>=position; i--)
    {
    	a[i+1]=a[i];
	}
	a[position]=element;
	n=n+1;

	printf("Array Elements are\n");
	for(i=0; i<n; i++)
	{
		printf("%d   ",a[i]);
	}
	getch();
	return 0;
}

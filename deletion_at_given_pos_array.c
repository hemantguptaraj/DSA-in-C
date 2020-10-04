#include<stdio.h>
#include<conio.h>
int main(){
	int a[10];
	int i,n;
	int position, element;
	printf("Total Elements to be Inserted   : ");
	scanf("%d",&n);
	
	printf("Enter values of array : \n");
	for(i=0; i<n; i++)
 	  {
		scanf("%d",&a[i]);
	  }
	
	printf("Enter Position at which elements needs to be deleted  :");
	scanf("%d",&position);
	
	
    for(i=position; i<n; i++)
    {
    	a[i]=a[i+1];
	}
	n=n-1;

	printf("Array Elements are\n");
	for(i=0; i<n; i++)
	{
		printf("%d   ",a[i]);
	}
	getch();
	return 0;
}

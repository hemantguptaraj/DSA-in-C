#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;
	int key;
	printf("Enter size of array    : ");
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++)
	{
		printf("Enter value for a[%d] location   :",i);
		scanf("%d",&a[i]);
	}
	
	printf("Array Befor Sorting is\n");
	for(i=0; i<n; i++)
	{
		printf("%d   ",a[i]);
	}
	printf("\n");
	
	//insertion sort begins here
	for(i=0;i<n; i++)
	{
		key=a[i];
		j= i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	//insertion sort ends here
	
	printf("Sorted Array is\n");	
	for(i=0; i<n; i++)
	{
		printf("%d   ",a[i]);	
	}
	getch();
	return 0;
}

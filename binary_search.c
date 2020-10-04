#include<stdio.h>
#include<conio.h>
int main(){
	int n,i,search;
	int first=0;
	int last,mid;
	
	printf("Enter total size of array\n");
	scanf("%d",&n);
	int arr[n];
	last=n-1; 
	mid=(first+last)/2;
	printf("Enter Array Elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter value to be searched\n");
	scanf("%d",&search);
	
	while(first<=last)
	{
		if(arr[mid]<search)
			first=mid+1;
		else if(arr[mid]==search)
		{
			printf("Value found at %d location",mid+1);
			break;
		}
		else
			last=mid-1;
			mid=(first+last)/2;
	}
	if(first>last)
		printf("This Value %d is not there in list.",search);
	getch();
	return 0;
}

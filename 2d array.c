#include<stdio.h>
#include<conio.h>
int main()
{
   int row;
   int column;
   int i,j;
   
   printf("enter total rows to be inserted   :");
   scanf("%d",&row);
   printf("enter total column to be inserted   :");
   scanf("%d",&column);
   int arr[row][column];
   for(i=0;i<row;i++)
   {
   	for(j=0; j<column;j++) 	
     {
   	  printf("Enter value for [%d][%d] location   : ",i,j);
   	  scanf("%d",&arr[i][j]);
     }	 
   }

  for(i=0;i<row;i++)
  {
    for(j=0;j<column;j++)
	{
		printf("%d  ",arr[i][j]);
	}
	if(j==column)
	printf("\n");
  }
  
  int m,n;
  printf("\Enter the element to be printed   :");
  scanf("%d%d",&m,&n);
  printf("Element You reuested is at [%d][%d] location\nThe Element is %d",m,n,arr[m][n]);
getch();
return 0;
}

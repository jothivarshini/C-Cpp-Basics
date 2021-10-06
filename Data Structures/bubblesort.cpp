#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void bubble(int arr[],int n)
{
	int i,j,count_swap=0,count_comp=0;
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			count_comp++;
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				count_swap++;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nThe number of comparisons: %d",count_comp);
	printf("\nThe number of swaps: %d",count_swap);
}

int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble(arr,n);
	return 0;
}

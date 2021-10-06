#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}
void selection(int arr[],int n)
{
int i,j,min,countswap=0,countcomp=0;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
countcomp++;
if(arr[j]<arr[min])
{
min=j;
}
}
if(min!=i)
{
swap(&arr[min],&arr[i]);
countswap++;
}
 }
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
printf("\nThe number of comparisons: %d",countcomp);
printf("\nThe number of swaps: %d",countswap);
}
int main()
{
int arr[]={1,2,3,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
selection(arr,n);
return 0;
}

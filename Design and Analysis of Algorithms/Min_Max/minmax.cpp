#include <iostream>
#include<time.h>
using namespace std;


int no_of_ops=0;
void findMinMax (int A[], int start, int end);
int A[1000], max_0, min_0;

int main () 
{
clock_t startTime=clock();
int n;
cout << "Enter the number of elements:" << endl;
cin >> n;
for(int i=0;i<n;i++)
      A[i]=rand()%100;  //Generate numbers between 0 to 99
max_0 = A[0];
min_0 = A[0];
findMinMax(A, 0, n - 1);
cout << "\nThe minimum array element is " << min_0 << endl;
cout << "The maximum array element is " << max_0 << endl;
cout<<"Number of Operations "<<no_of_ops;
cout<< "\nExecution time of program " << double( clock() - startTime )/ (double) CLOCKS_PER_SEC << " seconds." << endl;
return 0;
}

void findMinMax(int A[], int start, int end) 
{
int max1;
int min1;
if (start == end)
{
max_0 = A[start];
min_0 = A[start];
}

else if (start + 1 == end)
    {
      if (A[start] < A[end])
        {
           max_0 = A[end];
           min_0 = A[start];
        }

      else
    {
      max_0 = A[start];
      min_0 = A[end];
    }
}

else
   {

      int mid = start + (end - start) / 2;
      findMinMax (A, start, mid);
      max1 = max_0;
      min1 = min_0;
      findMinMax (A, mid + 1, end);
      if (min1 < min_0)
        min_0 = min1;
      if (max_0 < max1)
         max_0 = max1;
    }
    no_of_ops++;
}
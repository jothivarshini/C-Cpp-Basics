#include<iostream>
#include <algorithm>
#include<time.h>
using namespace std;
int max_val=0;
struct Item{
    int val, weight;
    Item()
    {
        this->val=1+rand()%(100);
        this->weight=1+rand()%(100);
        max_val+=this->val;
    }
};

double comp(struct Item a, struct Item b)
{
    double r1 = (double)a.val / (double)a.weight;
    double r2 = (double)b.val / (double)b.weight;
    return r1 > r2;
}

void fK(int W, struct Item arr[], int n)
{
    clock_t startTime=clock();
    for(int i=0;i<n;i++)
    {
        cout<<"\nitem "<<i+1<<" value: "<<arr[i].val<<" weight: "<<arr[i].weight; 
    }
    int cur_Weight=0;
    double final_val=0.0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        count+=1;
        if(cur_Weight + arr[i].weight <=W)
        {
            cur_Weight += arr[i].weight;
            final_val += arr[i].val;
        }
        else
        {
            int remain = W - cur_Weight;
            cur_Weight+=remain;
            final_val += arr[i].val * ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    cout<<"\n\nTotal worth of items: "<<max_val;
    cout <<"\nMaximum worth taken = "<<final_val;
    cout<<"\nExecution time for program " << double( clock() - startTime )/ (double) CLOCKS_PER_SEC << " seconds." << endl;
    cout<<"No. of comparisons performed: "<<count<<endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int W=n*25;
    Item arr[n];
    cout<<"unsorted elements: ";
    fK(W, arr, n);
    cout<<"sorted elements: ";
    sort(arr,arr+n,comp);
    fK(W, arr, n);
    return 0;
}
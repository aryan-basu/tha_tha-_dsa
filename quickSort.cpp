#include <iostream>
#include <climits>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i=l, j=h;

    do
    {
        do{ i++; }while(A[i]<=pivot);
        do{ j--; }while(A[j]>pivot);

        if(i < j) {
            swap(&A[i], &A[j]);
        }
    }while(i<j);


    swap(&A[l], &A[j]);
    return j;
}


void quickSort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);     
    }
}

int main()
{
    int A[] = { 3,7,9,10,6,5,12,4,11,2, INT_MAX };

    quickSort(A, 0, 10);


    for(int i=0; i<10; i++)
    {
        cout<<A[i]<<" ";
    }

    cout<<endl;


    return 0;
}
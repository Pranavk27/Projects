#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

void swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

int heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<n && arr[l] < arr[largest])
		largest = l;
	if(r<n && arr[r] < arr[largest])
		largest = r;

	if(largest != i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

int heapsort(int arr[], int length)
{
	for(int i = length/2-1; i>=0; i--)
		heapify(arr,length,i);

	for(int i = length-1; i>=0; i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
	return 0;
}

int main()
{
	int arr[] = {2,4,6,3,7,5,8,9,1};

	heapsort(arr,9);

	copy(arr,arr+9,ostream_iterator<int> (cout," "));

	return 0;
}

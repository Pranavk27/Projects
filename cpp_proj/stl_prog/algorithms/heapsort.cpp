#include <iostream>
#include <iterator>

using namespace std;

void heapify(int *arr,int arrsize, int pos)
{
	int large = pos;
	int l = 2*pos + 1;
	int r = 2*pos + 2;

	if(l < arrsize && arr[l] > arr[large])
		large = l;
	if(r < arrsize && arr[r] > arr[large])
		large = r;

	if(large != pos)
	{
		swap(arr[pos],arr[large]);
		heapify(arr, arrsize, large);
	}
}

void heapsort(int *arr, int arrsize)
{
	for(int i = arrsize/2 - 1; i >= 0; i--)
		heapify(arr, arrsize, i);

	ostream_iterator<int> it(cout," ");
	std::copy(arr,arr+10,it);
	for(int i = arrsize-1 ; i >= 0; i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[10] = {3,6,4,7,1,5,8,9,2,10};
	heapsort(arr, 10);
	ostream_iterator<int> it(cout," ");
	std::copy(arr,arr+10,it);
	return 0;
}

#include <iostream>
#include <array>
#include <unistd.h>
#include <iterator>

using namespace std;

int selectionSort(array<int,10>& arr);
void swap(array<int,10>& arr,int a, int b)
{
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

int bubbleSort(array<int,10>& arr)
{
	int length = arr.size();
	for(int i = 0; i < length - 1 ; i++)
	{
		for(int j = 0 ; j < length - i - 1 ; j++)
		{
			if(arr[j] > arr[j+1])
			{
				cout << "Swap: " << i << " " << j << endl;
				swap(arr,j,j+1);
			}
		}
	}
}

int merge(array<int,10>& arr, int l, int p, int r)
{
	array<int,10> larr;
	array<int,10> rarr;

	cout << l << " # " << p << " # " << r << endl;
	int i = 0, j = 0;
	for(i = l; i <= p ; i++)
	{
		larr[j++] = arr[i];
	}
	larr[j] = 999;
	j = 0;
	for(i = p+1; i <= r ; i++)
	{
		rarr[j++] = arr[i];
	}
	rarr[j] = 999;

	i = 0;
       	j = 0;
	while(l<=r)
	{
		if((larr[i] >= rarr[j]))
		{
			arr[l] = rarr[j];
			cout << arr[l] << " = " << rarr[j] << endl ;
			j++;
		}
		else
		{
			arr[l] = larr[i];
			cout << arr[l] << " = " << larr[i] << endl ;
			i++;
		}
		l++;
	}
}
int mergeSort(array<int,10>& arr, int l, int r)
{
	sleep(1);
	if(l<r)
	{
		int p = (r+l)/2;
		cout << "(Left)MergeSort: " << l << " " << p << endl;
		mergeSort(arr,l,p);
		cout << "(Right)MergeSort: " << p << " " << r << endl;
		mergeSort(arr,p+1,r);
		cout << "MergeSort: " << l << " " << p << " " << r << endl;
		merge(arr,l,p,r);
	}

}

void insertionSort(array<int,10>& arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;

		/* Move elements of arr[0..i-1], that are
		 *           greater than key, to one position ahead
		 *                     of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}
 

int selectionSort(array<int,10>& arr)
{
	int min_index, length = arr.size();
	for(int i = 0; i < length - 1 ; i++)
	{
		min_index = i;
		for(int j = i+1 ; j < length ; j++)
		{
			if(arr[min_index] > arr[j])
				min_index = j;
		}
		cout << "Swap: " << i << " " << min_index << endl;
		swap(arr,i,min_index);
	}
}

int main(int argc, const char **argv)
{
	array<int,10> arr = {1,6,8,4,7,3,10,10,2,20};
	//selectionSort(arr);
	//bubbleSort(arr);
	//insertionSort(arr, 10);
	mergeSort(arr,0,9);
	std::ostream_iterator<int> out(std::cout,", ");
	std::copy(arr.begin(), arr.end(), out);
	return 0;
}

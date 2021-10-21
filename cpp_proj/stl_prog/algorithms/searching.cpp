#include <iostream>
#include <array>
#include <unistd.h>

using namespace std;

int binarySearch(array<int,10> arr, int num, int start, int end)
{
	int index = end - start;
	if(start > end)
		return -1;
	index = start + (index - 1)/2;
	if(num == arr[index])
		return index;
	if(num > arr[index])
		start = index + 1;
	else
		end = index - 1;
	cout << start << " " << end << endl;
	sleep(1);
	return binarySearch(arr, num, start, end);
}

int exponentialSearch(array<int,10> arr, int num, int start, int end)
{

	int index = end - start;
	cout << start << " " << end << endl;
	if(start > end)
		return -1;
	index = (start + ((end - start)*(num - arr[start])/(arr[end] - arr[start])));
	cout << index << endl;
	if(num == arr[index])
		return index;
	if(num > arr[index])
		start = index + 1;
	else
		end = index - 1;
	cout << start << " " << end << endl;
	sleep(1);
	return exponentialSearch(arr, num, start, end);
}

int interpolationSearch(array<int,10> arr, int num, int start, int end)
{
	if(arr[start] == num)
		return start;

	start++;
	while(end >= start && arr[start] <= num)
		start *= 2; 
	
	return binarySearch(arr, num, start/2, end);
}

int main(int argc, const char **argv)
{
	array<int,10> arr = {1,3,4,5,7,8,10,14,19,20};
	cout << binarySearch(arr, atoi(argv[1]), 0, 9) << endl;
	cout << interpolationSearch(arr, atoi(argv[1]), 0, 9) << endl;
	cout << exponentialSearch(arr, atoi(argv[1]), 0, 9) << endl;
	return 0;
}

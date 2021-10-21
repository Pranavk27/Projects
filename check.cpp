#include <iostream>

using namespace std;
int NeighbourSum( int maxRow, int maxCol, int i, int j)
{
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	if( i-1 >=0 && j-1 >=0 && j+1 <= maxCol && i+1 <= maxRow )
	{
		return (arr)[i-1][j-1] + 
		(arr)[i-1][j] + 
		(arr)[i-1][j+1] + 
		(arr)[i][j-1] + 
		(arr)[i][j+1] + 
		(arr)[i+1][j-1] + 
		(arr)[i+1][j] + 
		(arr)[i+1][j+1];

	}
	if( i == 0 && j == 0 )
	{
		return (arr)[i][j+1] + 
		(arr)[i+1][j] + 
		(arr)[i+1][j+1];
	}
	if( i == maxRow && j == maxCol )
	{
		return (arr)[i-1][j-1] + 
		(arr)[i-1][j] + 
		(arr)[i][j-1]; 
	}
	if( i == maxRow && j == 0 )
	{
		return (arr)[i-1][j] + 
		(arr)[i-1][j+1] + 
		(arr)[i][j+1];
	}
	if( i == 0 && j == maxCol )
	{
		return (arr)[i][j-1] + 
		(arr)[i+1][j-1] + 
		(arr)[i+1][j];
	}
	if( i == 0 )
	{
		return (arr)[i][j-1] + 
		(arr)[i][j+1] + 
		(arr)[i+1][j-1] + 
		(arr)[i+1][j] + 
		(arr)[i+1][j+1];
	}
	if( j == 0 )
	{
		return (arr)[i-1][j] + 
		(arr)[i-1][j+1] + 
		(arr)[i][j+1] + 
		(arr)[i+1][j] + 
		(arr)[i+1][j+1];
	}
	if( i == maxRow )
	{
		return (arr)[i-1][j-1] + 
		(arr)[i-1][j] + 
		(arr)[i-1][j+1] + 
		(arr)[i][j-1] + 
		(arr)[i][j+1];
	}
	if( j == maxCol )
	{
		return (arr)[i-1][j-1] + 
		(arr)[i-1][j] + 
		(arr)[i][j-1] + 
		(arr)[i+1][j-1] + 
		(arr)[i+1][j];
	}
	return 0;
}

int main()
{
	cout << NeighbourSum(2,2,0,0);
	return 0;
}

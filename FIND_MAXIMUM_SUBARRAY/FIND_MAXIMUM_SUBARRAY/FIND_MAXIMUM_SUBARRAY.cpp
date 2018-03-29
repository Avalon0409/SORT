#include<iostream>
using namespace std;

struct MAXIMUM{
	MAXIMUM(int _low, int _high, int _sum)
	{
		low = _low;
		high = _high;
		sum = _sum;
	}
	int low;
	int high;
	int sum;
};
MAXIMUM FIND_MAX_CROSSING_SUBARRY(int *a, int low, int mid, int high)
{
	int left_sum = -INT_MAX;
	int sum = 0;
	int max_left;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = -INT_MAX;
	sum = 0;
	int max_right;
	for (int i = mid+1; i <= high; i++)
	{
		sum = sum + a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return(MAXIMUM(max_left, max_right, left_sum + right_sum));
}

MAXIMUM FIND_MAXIMUM_SUBARRAY(int *a, int low, int high)
{
	if (high == low)
	{
		return(MAXIMUM(low, high, a[low]));
	}
	else
	{
		int mid = floor((low + high) / 2);
		MAXIMUM left = FIND_MAXIMUM_SUBARRAY(a, low, mid);
		MAXIMUM right = FIND_MAXIMUM_SUBARRAY(a, mid + 1, high);
		MAXIMUM cross = FIND_MAX_CROSSING_SUBARRY(a, low, mid, high);
		if (left.sum >= cross.sum&&left.sum >= right.sum)
		{
			return(left);
		}
		else
		if (right.sum >= left.sum&&right.sum >= cross.sum)
		{
			return(right);
		}
		else return(cross);
	}
}

int main()
{
	int a[20];
	for (int i = 0; i < 20; i++)
	{
		a[i] = rand()%(201)-100;
		cout << a[i] << " ";
	}
	MAXIMUM max = FIND_MAXIMUM_SUBARRAY(a, 0, 19);
	cout << endl;
	cout <<max.low<<" "<<max.high << " " <<max.sum <<endl;
	
	return 0;
}
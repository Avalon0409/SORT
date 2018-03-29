#include<iostream>

using namespace std;



////////////////////��������////////////////////////////
void INSERTION_SORT(int *A,int k)
{
	
	for (int j = 1; j<k; j++)
	{
		
		int key = A[j];
		int i = j - 1;
		while (i>=0 && A[i]>key)
		{
			A[i + 1] = A[i];
			i = i - 1;

		}
		A[i + 1] = key;
	}
}
////////////////�鲢����///////////////
void MERGE(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = (int*)malloc(sizeof(int)*(n1 + 1)); 
	int *R = (int*)malloc(sizeof(int)*(n2 + 1));
	for (int i = 0; i < n1; i++)
	{
		L[i] = A[p + i ];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = A[q + i+1];
	}
	L[n1 ] = INT_MAX;
	R[n2 ] = INT_MAX;
	int j = 0, i = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
		//cout << A[k] ;
		//cout << endl;
	}
}
void MERGE_SORT(int *A, int p, int r)
{
	if (p < r)
	{
		int q = floor((p + r) / 2);
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}
////////////////ð������///////////////
void BUBBLESORT(int *A,int n)
{
	int key;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1 ; j > i ; j--)
		{
			if (A[j] < A[j - 1])
			{
				key = A[j]; A[j] = A[j - 1]; A[j - 1] = key;
			}
		}
	}

}




int main()
{
	int a[6] = { 8,3,7,9,0 ,9};
	//INSERTION_SORT(a,6);
	//MERGE_SORT(a, 0, 5);
	BUBBLESORT(a, 6);
	for (int i = 0; i<6; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

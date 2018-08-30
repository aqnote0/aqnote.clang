
#include "com.aqnote.sort.h"

void swap(int a[], int n, int m);

void bubbleSort(int array[], int n)
{
	int i,j,tmp;
	for (i = 0; i < n - 1; i++) 
  {
		for (j = 0; j < n -1 -i; j++) 
    {
			if (array[j] > array[j+1]) 
      {
				tmp = array[j+1];
				array[j+1] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void insertSort(int a[], int n)
{
	int i,j,tmp;
	for (i = 1; i < n; i++) {
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
			a[j+1] = a[j];
		}
		a[j+1] = tmp;
	}
}

void selectSort(int a[], int n)
{
	int i, j, k;
	for (i = 0; i< n-1; i++) {
		k = i;
		for (j = i+1; j < n; j++) {
			if (a[k] > a[j])
				k = j;
		}
		if (k != i) {
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}
}

void quickSort(int a[], int n)
{
	int i, j;
	int last = 0;
	if (n < 2) return;
	swap(a, 0, n/2);
	for (i = 1; i < n; i++) {
		if (a[i] < a[0]) {
			swap(a, ++last, i);
		}
	}
	swap(a, 0, last);
	quickSort(a, last);
	quickSort(a+last+1, n-last-1);
}

// inner function
void swap(int a[], int n, int m)
{
	if (n == m) return;
	int tmp = a[n];
	a[n] = a[m];
	a[m] = tmp;
}







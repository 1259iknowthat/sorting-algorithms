#include <algorithm>

void heapify(int arr[], long N, long i)
{

	
	long largest = i;

	long l = 2 * i + 1;

	long r = 2 * i + 2;

	if (l < N && arr[l] > arr[largest])
		largest = l;

	if (r < N && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, N, largest);
	}
}


void heapSort(int arr[], long N)
{

	for (long i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	for (long i = N - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void main_heap_sort(int *arr, long size){
	heapSort(arr, size);
}

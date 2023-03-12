#include <algorithm>

long partition(int arr[], long low, long high)
{
	long pivot = arr[rand() % (high-low)+low]; // pivot
	long i = (low - 1); 
	for (long j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++; 
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], long low, long high)
{
	if (low < high) {
		long pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void main_quick_sort(int *arr, long size){
	quickSort(arr, 0, (size-1));
}

// This code is contributed by rathbhupendra

#include "sort.h"

/**
 * swap - Swap two elements of an array.
 *
 * @array: The array.
 * @idx1: The first element index.
 * @idx2: The second element index.
 */
void swap(int *array, int idx1, int idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

/**
 * sortArray - Sort an array in DOWN or UP version.
 *
 * @array: The array.
 * @way: UP or DOWN
 * @size: The size of the array.
 */
void sortArray(int *array, size_t way, size_t size)
{
	int gap = size / 2;
	int i;

	for (i = 0; i < gap; i++)
	{
		if ((array[i] > array[i + gap]) == way)
		{
			swap(array, i, (i + gap));
		}
	}
}

/**
 * mergeBitonicSorted - Merge sub-arrays already sorted upwards and downwards.
 *
 * @array: The array to sort (transform into sub array).
 * @way: UP or DOWN
 * @size: Size of the array, or sub-array.
 */
void mergeBitonicSorted(int *array, size_t way, size_t size)
{
	int middle;

	if (size <= 1)
		return;

	middle = size / 2;
	sortArray(array, way, size);
	mergeBitonicSorted(array, way, middle);
	mergeBitonicSorted((array + middle), way, middle);
}

/**
 * bitonicSortRec - Sort array using recursive bitonic algorithm.
 *
 * @array: Array to sort.
 * @way: UP or DOWN.
 * @size: Size of the sub-array being sorted.
 * @sizeArray: Size of the array.
 */
void bitonicSortRec(int *array, size_t way, size_t size, size_t sizeArray)
{
	int middle;

	if (size <= 1)
		return;

	middle = size / 2;

	printf("Merging [%ld/%ld]", size, sizeArray);
	way == 1 ? printf(" (UP):\n") : printf(" (DOWN):\n");
	print_array(array, size);
	bitonicSortRec(array, 1, middle, sizeArray);
	bitonicSortRec((array + middle), 0, middle, sizeArray);
	mergeBitonicSorted(array, way, size);
	printf("Result [%ld/%ld]", size, sizeArray);
	way == 1 ? printf(" (UP):\n") : printf(" (DOWN):\n");
	print_array(array, size);
}

/**
 * bitonic_sort - Sort an array using the bitonic sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	bitonicSortRec(array, 1, size, size);
}

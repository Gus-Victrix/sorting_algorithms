#include "sort.h"

/**
 * mergeArray - Merge two sorted sub-arrays into a one.
 *
 * @array: The parent array.
 * @arrayBuff: Temporary array container.
 * @low: The lower index of the sub-array.
 * @middle: The middle of the sub-array
 * @high: The higher index of sub-array.
 */
void mergeArray(int *array, int *arrayBuff, size_t low, size_t middle,
size_t high)
{
	size_t i = low, j = middle, k = low;

	printf("Merging...\n[left]: ");
	print_array(array + low, middle - low);

	printf("[right]: ");
	print_array(array + middle, high - middle);

	while (k < high)
	{
		if (i < middle && (j >= high || array[i] <= array[j]))
		{
			arrayBuff[k] = array[i];
			i++;
		}
		else
		{
			arrayBuff[k] = array[j];
			j++;
		}
		k++;
	}
	for (i = low; i < high; i++)
		array[i] = arrayBuff[i];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * mergeSortRec - Recursive mergeSort algo for the sort. 
 *
 * @array: The parent array.
 * @arrayBuff: Temporary array container.
 * @low: The lower index of array.
 * @high: The higher index of array.
 */
void mergeSortRec(int *array, int *arrayBuff, size_t low, size_t high)
{
	size_t middle;

	if ((high - low) > 1)
	{
		middle = low + (high - low) / 2;
		mergeSortRec(array, arrayBuff, low, middle);
		mergeSortRec(array, arrayBuff, middle, high);
		mergeArray(array, arrayBuff, low, middle, high);
	}
}

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 *
 * @array: The array.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *arrayBuff;

	if (!array || size <= 1)
		return;
	arrayBuff = malloc(sizeof(int) * size);
	if (!arrayBuff)
		return;
	mergeSortRec(array, arrayBuff, 0, size);
	free(arrayBuff);
}

#include "sort.h"

/**
 * searchMax - Search the largest value in an integer array.
 *
 * @array: The array to be searched.
 * @size: The size of the array.
 *
 * Return: The largest value stored in an int array.
 */
int searchMax(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
		if (max < array[i])
			max = array[i];
	return (max);
}

/**
 * memInit - Initialize array memory to 0s.
 *
 * @array: The array.
 * @size: The size of the array.
 */
void memInit(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * counting_sort - Sort an array using the counting sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t max, i;
	int *arrayCounter = NULL, *output = NULL;

	if (!array || size <= 1)
		return;

	max = searchMax(array, size);
	output = malloc(sizeof(int) * size);
	arrayCounter = malloc(sizeof(int) * max + 2);
	if (!arrayCounter || !output)
		return;
	memInit(arrayCounter, max);

	for (i = 0; i < size; i++)
		arrayCounter[array[i]]++;

	for (i = 1; i <= max; i++)
		arrayCounter[i] += arrayCounter[i - 1];

	print_array(arrayCounter, max + 1);

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[arrayCounter[array[i]] - 1] = array[i];
		arrayCounter[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(arrayCounter);
	free(output);
}

#include "sort.h"

/**
 * getMaxDigit - Search the largest int in an array.
 *
 * @array: The given array.
 * @size: The size of the array.
 *
 * Return: The largest value int in an array.
 */
int getMaxDigit(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radixSort - Sort the array by radix sort.
 *
 * @array: Array to be sorted.
 * @buf: Temporary array to perform operations in before storage into array.
 * @size: Size of the array.
 * @digit: The digit being assesed.
 */
void radixSort(int *array, int *buf, size_t size, size_t digit)
{
	size_t i;
	int arrayCount[10];

	for (i = 0; i < 10; i++)
		arrayCount[i] = 0;

	for (i = 0; i < size; i++)
		arrayCount[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		arrayCount[i] += arrayCount[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[arrayCount[(array[i] / digit) % 10] - 1] = array[i];
		arrayCount[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buf[i];
}

/**
 * radix_sort - Sort an array using the radix sort algorithm.
 *
 * @array: The array being sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t max, i;
	int *buf;

	if (!array || size <= 1)
		return;

	max = getMaxDigit(array, size);

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	for (i = 1; max / i > 0; i *= 10)
	{
		radixSort(array, buf, size, i);
		print_array(array, size);
	}
	free(buf);
}

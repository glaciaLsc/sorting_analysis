#include <stdio.h>
#include <time.h>

int radixGetMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void radixCountSort(int arr[], int n, int exp)
{
	int output[n]; 
	int i, count[10] = {0};
  
	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
	int m = radixGetMax(arr, n);

	for (int exp = 1; m/exp > 0; exp *= 10)
		radixCountSort(arr, n, exp);
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main()
{
	char filename[20], data[64];
	FILE *file;
	int arraysize;

	// Get file for reading
	printf("Enter the file to be read: ");
	scanf("%s", filename);
	file = fopen(filename, "r");

	// Get array size
	printf("Enter the size of the array: ");
	scanf("%d", &arraysize);
	
	// Loop through lines of file & assign values to array	
	int array[arraysize];
	int i = 0;
	while ((i < arraysize) && (fgets(data, 64, file) != NULL)) // Read lines from file, writing to data
	{
		sscanf(data, "%d", &array[i]); // Convert char in data to integer in array
		//printf("%d\n", array[i]);
		i++;
	}

	/*
	printf("Unsorted Array: \n");
	print(array, arraysize);
	*/
	// Sort array & obtain sorting time
	clock_t t;
	t = clock();
	radixsort(array, arraysize);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;
	/*
	printf("\n Radix Sort Solution: \n");
	print(array, arraysize);
	*/
	
	// Print final time	
	printf("\n Runtime: %f seconds \n",timeTaken);

	// Write sorted data to file
	file = fopen("sorted_radix.txt", "w");
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", array[i]);

	return 0;
}

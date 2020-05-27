#include <stdio.h>
#include <time.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void partition(int *arr, int low, int high, int *pivotpoint)
{
	int i, j;
	int pivotitem;
	
	pivotitem = arr[low];
	
	j = low;
	for (i=low+1; i <= high; i++)
	{
		if (arr[i] < pivotitem)
		{
			j++;

			// Swap
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	*pivotpoint = j;

	// Swap
	int temp = arr[low];
	arr[low] = arr[*pivotpoint];
	arr[*pivotpoint] = temp;
}

void quicksort(int *arr, int low, int high)
{
	int pivotpoint;

	if (high > low)
	{
		partition(arr, low, high, &pivotpoint);
		quicksort(arr, low, pivotpoint-1);
		quicksort(arr, pivotpoint+1, high);
	}
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

	//printf("Unsorted Array: \n");
	//print(array, arraysize);
	
	// Sort array & obtain sorting time
	clock_t t;
	t = clock();
	quicksort(array, 0, arraysize-1);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;
	
	//printf("\n Solution: \n");
	//print(array, arraysize);
	
	// Print final time
	printf("\n Runtime: %f seconds \n",timeTaken);
	
	// Write sorted data to file
	file = fopen("sorted_quicksort.txt", "w");
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", array[i]);

	fclose(file);

	return 0;
}

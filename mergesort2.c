#include <stdio.h>
#include <time.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void merge(int *arr, int low, int mid, int high)
{
	int U[high+1];

	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			U[k] = arr[i];
			i++;
		}
		else
		{
			U[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		U[k] = arr[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		U[k] = arr[j];
		j++;
		k++;
	}
	for (int b=low; b <= high; b++)
		arr[b] = U[b];
}

void mergesort(int *arr, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		mergesort(arr, low, mid);
		mergesort(arr, mid+1, high);
		merge(arr, low, mid, high);
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
	mergesort(array, 0, arraysize-1);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;

	//printf("\n Solution: \n");
	//print(array, arraysize);
	
	// Print final time
	printf("\n Runtime: %f seconds \n",timeTaken);
	
	// Write sorted data to file
	file = fopen("sorted_mergesort.txt", "w");
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", array[i]);

	fclose(file);

	return 0;
}

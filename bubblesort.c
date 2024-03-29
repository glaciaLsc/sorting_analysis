#include <stdio.h>
#include <time.h>

void swap(int *arr, int i, int k)
{
	int temp = arr[i];
	arr[i] = arr[k];
	arr[k] = temp;
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void bubblesort(int *arr, int n)
{
	if (n <= 1)
		return;

	for (int i=0; i < n-1; i++)
		for (int j=0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(arr, j, j+1);
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
	bubblesort(array, arraysize);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;
	
	//printf("\n Solution: \n");
	//print(array, arraysize);
	
	// Print final time
	printf("\n Runtime: %f seconds \n",timeTaken);
	
	// Write sorted data to file
	file = fopen("sorted_bubblesort.txt", "w");
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", array[i]);

	fclose(file);

	return 0;
}

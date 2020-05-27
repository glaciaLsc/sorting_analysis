#include <stdio.h>
#include <time.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void merge(int *arr, int *U, int *V, int h, int m)
{
	int i, j, k = 0;

	while (i < h && j < m)
	{
		if (U[i] < V[j])
		{
			arr[k] = U[i];
			i++;
		}
		else
		{
			arr[k] = V[j];
			j++;
		}
		k++;
	}
	
	while (i < h)
	{
		arr[k] = U[i];
		i++;
		k++;
	}
	while (j < m)
	{
		arr[k] = V[j];
		j++;
		k++;
	}
}

void mergesort(int *arr, int n)
{
	if (n > 1)
	{
		int h = n / 2;
		int m = n - h;
		int U[h], V[m]; 

		for (int i=0; i < h; i++)
			U[i] = arr[i];
		for (int i=0; i < m; i++)
			V[i] = arr[h+i];
		
		mergesort(U, h);
		mergesort(V, m);
		merge(arr, U, V, h, m);
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
	mergesort(array, arraysize);
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

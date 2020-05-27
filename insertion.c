#include <stdio.h>
#include <time.h>

void insertionSort (int arr[], int n)
{
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
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

	
	//printf("Unsorted Array: \n");
	//print(array, arraysize);
	
	// Sort array & obtain sorting time
	clock_t t;
	t = clock();
	insertionSort(array, arraysize); // sorting_algorithm(parameters_here);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;
	
	//printf("\n Solution: \n");
	//print(array, arraysize);
	
	
	// Print final time
	printf("\n Runtime: %f seconds \n",timeTaken);
	
	// Write sorted data to file
	file = fopen("insertionSort.txt", "w");
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", array[i]);

	fclose(file);

	return 0;
}

#include <stdio.h>
#include <time.h>

struct node
{
	int data;
	struct node* next;
};

void merge(int *arr, int *U, int *V, int h, int m)
{
}

void mergesort(struct node **head, int low, int high)
{
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
	
	// Loop through lines of file & assign values to linked list
	struct node *head;
	struct node *current = head;
	int i = 0;
	while ((i < arraysize) && (fgets(data, 64, file) != NULL)) // Read lines from file, writing to data
	{
		sscanf(data, "%d", current->data); // Convert char in data to integer in list
		current = current->next;
		i++;
	}

	//printf("Unsorted Array: \n");
	//print(array, arraysize);
	
	// Sort array & obtain sorting time
	clock_t t;
	t = clock();
	mergesort(&head, 0, arraysize-1);
	t = clock()-t;
	double timeTaken = ((double)t)/CLOCKS_PER_SEC;

	//printf("\n Solution: \n");
	//print(array, arraysize);
	
	// Print final time
	printf("\n Runtime: %f seconds \n",timeTaken);
	
	// Write sorted data to file
	current = head;
	file = fopen("sorted_mergesort.txt", "w");
	for (i=0; i < arraysize; i++)
	{
		fprintf(file, "%d\n", current->data);
		current = current->next;
	}

	fclose(file);

	return 0;
}

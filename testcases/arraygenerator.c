#include <stdio.h>
#include <stdlib.h>

int main()
{
	char filename[20];
	FILE *file;
	int arraysize, i;
	time_t t;
	
	// Initialize rand()
	srand((unsigned) time(&t));

	// Get filename
	printf("Enter the name of the file to be outputted: ");
	scanf("%s", filename);

	// Get array size
	printf("Enter the size of the array to be randomly generated: ");
	scanf("%d", &arraysize);

	// Create file & write to it
	file = fopen(filename, "w");
	
	for (i=0; i < arraysize; i++)
		fprintf(file, "%d\n", rand());

	fclose(file);

	return 0;
}

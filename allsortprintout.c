#include <stdio.h>
#include <time.h>


/////////////////////////EXCHANGE START///////////////////////////
void exchangeSort (int arr[], int n)
{
    int temp = 0;
    for(int i = 0; i < (n -1); i++)
	{
		for (int j=(i + 1); j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
/////////////////////////EXCHANGE END/////////////////////////////

/////////////////////////INSERTION START///////////////////////////
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
/////////////////////////INSERTION END//////////////////////////

/////////////////////////BINARY INSERTION START///////////////////////////
int binarySearch(int a[], int item, int low, int high) 
{ 
    if (high <= low) 
        return (item > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(item == a[mid]) 
        return mid+1; 
  
    if(item > a[mid]) 
        return binarySearch(a, item, mid+1, high); 
    return binarySearch(a, item, low, mid-1); 
} 
  
void binaryInsertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        selected = a[i]; 
  
        loc = binarySearch(a, selected, 0, j); 
  
        while (j >= loc) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = selected; 
    } 
} 
/////////////////////////BINARY INSERTION END//////////////////////////


////////////////////////SELECTION START//////////////////////////////
void swap(int *i, int *j) 
{ 
    int temp = *i; 
    *i = *j; 
    *j = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min]) 
            min = j; 
  
        swap(&arr[min], &arr[i]); 
    } 
} 
/////////////////////////SELECTION END//////////////////////////////


/////////////////////////RADIX START//////////////////////////////
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
/////////////////////////RADIX END//////////////////////////////

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
	
	int array[arraysize];
	int radixArray[arraysize];
	int exchangeArray[arraysize];
	int insertionArray[arraysize];
	int binaryInsertionArray[arraysize];
	int i = 0;
	while ((i < arraysize) && (fgets(data, 64, file) != NULL)) // Read lines from file, writing to data
	{
		sscanf(data, "%d", &array[i]); // Convert char array to int
		sscanf(data, "%d", &radixArray[i]); // new arrays for each method as there is no way to unsort atm 
		sscanf(data, "%d", &exchangeArray[i]); // new arrays for each method as there is no way to unsort atm 
		sscanf(data, "%d", &insertionArray[i]); // new arrays for each method as there is no way to unsort atm 
		sscanf(data, "%d", &binaryInsertionArray[i]); // new arrays for each method as there is no way to unsort atm 

		//printf("%d\n", array[i]);
		i++;
	}

	fclose(file);

	//////////EXCHANGE SORT/////////
	printf("Unsorted Array: \n");
	print(exchangeArray, arraysize);
	clock_t t;
	t = clock();
	exchangeSort(exchangeArray, arraysize);
	t = clock()-t;
	float timeTaken = ((float)t)/CLOCKS_PER_SEC;
	printf("\n Exchange Sort Solution: \n");
	print(exchangeArray, arraysize);
	printf("\n Runtime: %f seconds \n",timeTaken);
	////////////////////////////

	//////////INSERTION SORT/////////
	printf("Unsorted Array: \n");
	print(insertionArray, arraysize);
	t = clock();
	insertionSort(insertionArray, arraysize);
	t = clock()-t;
	timeTaken = ((float)t)/CLOCKS_PER_SEC;
	printf("\n Insertion Sort Solution: \n");
	print(insertionArray, arraysize);
	printf("\n Runtime: %f seconds \n",timeTaken);
	////////////////////////////

	//////////BINARY INSERTION SORT/////////
	printf("Unsorted Array: \n");
	print(binaryInsertionArray, arraysize);
	t = clock();
	binaryInsertionSort(binaryInsertionArray, arraysize);
	t = clock()-t;
	timeTaken = ((float)t)/CLOCKS_PER_SEC;
	printf("\n Binary Insertion Sort Solution: \n");
	print(binaryInsertionArray, arraysize);
	printf("\n Runtime: %f seconds \n",timeTaken);
	////////////////////////////

	//////////SELECTION SORT/////////
	printf("Unsorted Array: \n");
	print(array, arraysize);
	t = clock();
	selectionSort(array, arraysize);
	t = clock()-t;
	timeTaken = ((float)t)/CLOCKS_PER_SEC;
	printf("\n Selection Sort Solution: \n");
	print(array, arraysize);
	printf("\n Runtime: %f seconds \n",timeTaken);
	////////////////////////////

	//////////RADIX SORT/////////
	printf("Unsorted Array: \n");
	print(radixArray, arraysize);
	t = clock();
	radixsort(radixArray, arraysize);
	t = clock()-t;
	timeTaken = ((float)t)/CLOCKS_PER_SEC;
	printf("\n Radix Sort Solution: \n");
	print(radixArray, arraysize);
	printf("\n Runtime: %f seconds \n",timeTaken);
	////////////////////////////
	return 0;
}

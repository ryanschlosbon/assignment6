#include <stdio.h>
#include <stdlib.h>

//Ryan Schlosbon - COP 3502C - Lab Assignment 6 - Recursion Search
int search(int numbers[], int low, int high, int value) 
{
	//Base case, checks if low is greater than high in which case it fails
	if(low > high)
		return -1;
	//find the mid point
	int mid = low + (high-low)/2;
	//if numbers[mid] == value, return mid as it is equal to the vaue we're searching for (base case)
	if(numbers[mid] == value){
		return mid;
	}
	//if numbers[mid] is less than the value being searched,. search in the left side of the array by making
	//mid the low marker and add one to it making the search size smaller
	else if(numbers[mid]<value){
		return search(numbers, mid+1, high, value);
	}
	//if numbers[mid] is greater than the value being searched, search in the right side of the array by 
	//making mid the high marker and subtracting one by it, making the search size smaller
	else if(numbers[mid]>value)
		return search(numbers,low,mid-1,value);
	//covers low == high case
	else
		return mid;
	return -1; //returns -1 if the function fails
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
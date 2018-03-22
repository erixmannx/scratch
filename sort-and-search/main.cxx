#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <time.h>

using namespace std;

void printArry(int* arry, int size) {
	for (int x = 0; x < size; x++) {
		printf("%d ", arry[x]);
	}
}

int* merge(int* left, int leftSize, int* right, int rightSize) {
	int* result = new int[leftSize + rightSize];

	int leftIndex = 0;
	int rightIndex = 0;
	int resultIndex = 0;

	while ((leftIndex < leftSize) && (rightIndex < rightSize)) {
		if (left[leftIndex] < right[rightIndex]) {
			result[resultIndex] = left[leftIndex];
			leftIndex++;
		} else {
			result[resultIndex] = right[rightIndex];
			rightIndex++;
		}
		resultIndex++;
	}

	while(leftIndex < leftSize) {
		result[resultIndex++] = left[leftIndex++];
		
	}

	while(rightIndex < rightSize) {
		result[resultIndex++] = right[rightIndex++];
	}

	return result;
}

int* mergeSort(int* orgArry, int startAt, int endAt) {
	int size = endAt - startAt;
	if (size <= 0) {
		return NULL;	
	}

	if (size == 1) {
		int* result = new int[1];
		result[0] = orgArry[startAt];
		return result;
	}

	int middle = (endAt + startAt) / 2;
	int* left = mergeSort(orgArry, startAt, middle);
	int* right = mergeSort(orgArry, middle, endAt);

	int* result = merge(left, middle - startAt, right, endAt - middle);

	delete [] left;
	delete [] right;

	return result;
}

int* sort(int* orgArry, int size) {
	return mergeSort(orgArry, 0, size);
}

bool binSearch(int* arry, int find, int startAt, int endAt) {

	int size = (endAt - startAt);
	if (size <= 0) {
		return false;
	}

	if (size == 1) {
		return arry[startAt] == find;
	}

	int middle = (startAt + endAt) / 2;

	if (arry[middle] == find) {
		return true;
	}

	bool left = binSearch(arry, find, startAt, middle);
	bool right = binSearch(arry, find, middle, endAt);

	return left || right;
}

bool search(int* arry, int size, int find) {
	return binSearch(arry, find, 0, size); 
}

void fill(int* arry, int size) {
	srand(time(NULL));

	for (int x = 0; x < size; x++) {
		arry[x] = rand() % 100;
	}
}

int main(int argc, char** argv) {
	char* sizeStr = argv[1];
	int size = atoi(sizeStr);

	int arry[size] = {0};
	fill(arry, size);

	printf("\nSTART\n");
	printArry(arry, size);
	printf("\nSTART\n");

	int* sortedArry = sort(arry, size);

	printf("\nSORTED\n");
	printArry(sortedArry, size);
	printf("\nSORTED\n");

	int find = 0;
	printf("\nWhat to Find: ");
	scanf("%d", &find);

	bool found = search(sortedArry, size, find);
	if (found == true) {
		printf("FOUND %d\n", find);
	} else {
		printf("NOT FOUND %d\n", find);
	}

	delete [] sortedArry;

	return 0;
}

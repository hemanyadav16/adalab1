#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
int i, j, minIndex, temp;
for (i = 0; i< n - 1; i++) {
minIndex = i;
for (j = i + 1; j < n; j++) {
if (arr[j] <arr[minIndex]) {
minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
temp = arr[minIndex];
arr[minIndex] = arr[i];
arr[i] = temp;
    }
}

int main() {
int n, min, max;
clock_t start, end;

printf("Enter the size of the array: ");
scanf("%d", &n);

if (n < 2) {
printf("Please provide a number greater than 1.\n");
return 1;
    }


printf("Enter the min num of the array: ");
scanf("%d", &min);

printf("Enter the max num of the array: ");
scanf("%d", &max);

srand(time(NULL));

int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Memory allocation failed.\n");
return 1;
    }

printf("[");
int i;
for (i = 0; i< n; i++) {
arr[i] = rand() % (max - min + 1) + min;
printf("%d ", arr[i]);
    }
printf("]");
printf("\n");

start = clock();
selectionSort(arr, n);
end = clock();
double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("[");
for (i = 0; i< n; i++) {
printf("%d ", arr[i]);
    }
printf("]");
printf("\n");
printf("Time taken for sorting: %lf seconds\n", cpu_time_used);
return 0;
}

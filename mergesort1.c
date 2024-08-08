#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
       int mid= ((low+high)/2);
       mergesort(arr,low,mid);
       mergesort(arr,mid+1,high);
       merge(arr,low,mid,high);
    }
}

int merge(int arr[],int low,int mid,int high)
{
    int h=low;int i = low;int j=mid+1;
    int b[20];
    while((h<=mid)&&(j<=high)){
        if(arr[h]<arr[j])
        {
            b[i]=arr[h];
            h=h+1;

        }
        else{
            b[i]=arr[j];
            j=j+1;
        }
        i=i+1;
    }
    if(h>mid)
    {
        for(int k=j;k<=high;k++)
        {
            b[i]=arr[k];
            i=i+1;

        }
    }
    else{
        for(int k=h;k<=mid;k++)
        {
            b[i]=arr[k];
            i=i+1;
        }
    }
    for(int k=low;k<=high;k++)
      arr[k]=b[k];
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
mergesort(arr, 0, n - 1);
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

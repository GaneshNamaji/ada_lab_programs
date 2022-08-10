#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define START 10
#define END 100
#define INCR 10
int count;
void heapify(int arr[], int n, int i)
{
    count++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n, char filename[])
{
    int count = 0;
    int i, j, temp, flag;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%d\t", n);
    fprintf(fp, " %d\n", count);
}

void bubblesort(int arr[], int n, char filename[])
{
}
void main()
{
    int i, n;
    system("rm -f count_*.txt");
    srand(time(NULL));
    for (n = START; n <= END; n += INCR)
    {
        int arr[n];
        for (i = 0; i < n; i++)
            arr[i] = i;
        heapsort(arr, n, "count_best.txt");
        for (i = 0; i < n; i++)
            arr[i] = n - i;
        heapsort(arr, n, "count_worst.txt");
        for (i = 0; i < n; i++)
            arr[i] = rand() % 5;
        heapsort(arr, n, "count_average.txt");
    }
}

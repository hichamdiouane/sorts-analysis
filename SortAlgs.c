#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


double tri_bulle(int arr[], int n){
    double sec;
    clock_t start = clock();
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j + 1]);
            }
        }
    }
    clock_t end = clock();
    sec = ((double)(end - start)) / CLOCKS_PER_SEC;
    return sec;
}


double tri_insertion(int arr[], int n){
    double sec;
    clock_t start = clock();
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    clock_t end = clock();
    sec = ((double)(end - start)) / CLOCKS_PER_SEC;
    return sec;
}


double tri_selection(int arr[], int n) {
    double sec; 
    clock_t start = clock();
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i],&arr[minIndex]);
    }
    clock_t end = clock();
    sec = ((double)(end - start)) / CLOCKS_PER_SEC;
    return sec;
}

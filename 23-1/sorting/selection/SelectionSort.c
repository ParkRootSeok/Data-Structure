#include <stdio.h>

typedef int Data;

void SelectionSort(Data arr[], int len) {

    int i, j, maxIdx, tmp;


    for (i = 0; i < len - 1; i++) {

        maxIdx = i;

        for (j = i+1; j < len; j++) {

            if (arr[j] < arr[maxIdx])  {
                maxIdx = j;
            }

        }

        tmp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = tmp;

    }

}

int main() {

    Data arr[4] = {3, 2, 4, 1};
    int len = sizeof(arr) / sizeof(int);
    SelectionSort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}
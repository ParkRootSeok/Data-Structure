#include <stdio.h>

typedef int Data;

void InsertionSort(Data arr[], int len) {

    int i, j, insertData;


    for (i = 1; i < len; i++) {
        
        insertData = arr[i];

        for (j = i - 1; j >= 0; j--) {

            if (arr[j] > insertData)  {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
            arr[j + 1] = insertData;
    }

}

int main() {

    Data arr[4] = {3, 2, 4, 1};
    int len = sizeof(arr) / sizeof(int);
    InsertionSort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}
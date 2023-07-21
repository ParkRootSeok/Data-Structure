#include <stdio.h>

typedef int Data;

void BubbleSort(Data arr[], int len) {

    int i, j, tmp;


    for (i = 0; i < len - 1; i++) {

        for (j = 0; j < (len-i)-1; j++) {

            if (arr[j] > arr[j + 1])  {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            
        }
        

    }

}

int main() {

    Data arr[4] = {3, 2, 4, 1};
    int len = sizeof(arr) / sizeof(int);
    BubbleSort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    } printf("\n\n");
    
    return 0;

}
#include "../include/sorts.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

void merge(float input_data[], int begin, int middle, int end){
    int cont1 = begin;
    int cont2 = (middle + 1);
    int contAux = 0;
    float *arrAux = malloc((end - begin + 1) * sizeof(float));

    while(cont1 <= middle && cont2 <= end){
        if(input_data[cont1] <input_data[cont2]){
            arrAux[contAux] = input_data[cont1];
            cont1++;
        }
        else{
            arrAux[contAux] = input_data[cont2];
            cont2++;
        }

        contAux++;
    }

    while(cont1 <= middle){
        arrAux[contAux] = input_data[cont1];
        contAux++;
        cont1++;
    }

    while(cont2 <= end){
        arrAux[contAux] = input_data[cont2];
        contAux++;
        cont2++;
    }

    for(contAux = begin; contAux <= end; contAux++)
        input_data[contAux] = arrAux[contAux-begin];

    free(arrAux);
}

void mergeSortRecursive(float input_data[], int begin, int end){
    if(begin < end){
        int middle = (begin + end) / 2;

        mergeSortRecursive(input_data, begin, middle);
        mergeSortRecursive(input_data, middle + 1, end);
        merge(input_data, begin, middle, end);
    }
}

void swap(float *a, float *b){
    float c = *a;
    *a = *b;
    *b = c;
}

int partition(float input_data[], int low, int high){
    float pivot = input_data[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(input_data[j] <= pivot){
            i++;
            swap(&input_data[i], &input_data[j]);
        }
    }

    swap(&input_data[i+1], &input_data[high]);

    return (i + 1);
}

void quickSortRecursive(float input_data[], int low, int high){
    if(low < high){
        int p = partition(input_data, low, high);

        quickSortRecursive(input_data, low, p - 1);
        quickSortRecursive(input_data, p + 1, high);
    }
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

void bubbleSort(float *input_data, int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - 1 - i; j++){
            if(input_data[j] > input_data[j+1]){
                float aux = input_data[j];
                input_data[j] = input_data[j+1];
                input_data[j+1] = aux;
            }
        }
    }
}

void insertionSort(float *input_data, int length){
    for(int i = 1; i < length; i++){
        float key = input_data[i];
        int j = i - 1;

        while(j >= 0 && input_data[j] > key){
            input_data[j + 1] = input_data[j];
            j--;
        }

        input_data[j + 1] = key;
    }
}

void mergeSort(float *input_data, int length){
    mergeSortRecursive(input_data, 0, length - 1);
}

void optimizedBubbleSort(float *input_data, int length){
    int ok = 0;

    for(int i = 0; i < length - 1 && ok == 0; i++){
        ok = 1;
        for(int j = 0; j < length - 1 - i; j++){
            if(input_data[j] > input_data[j+1]){
                ok = 0;
                float aux = input_data[j];
                input_data[j] = input_data[j+1];
                input_data[j+1] = aux;
            }
        }
    }
}

void quickSort(float *input_data, int length){
    quickSortRecursive(input_data, 0, length - 1);
}

void selectionSort(float *input_data, int length){
    int min; 
    float temp;

    for(int i = 0; i < length - 1; i++){
        min = i;
        for(int j = i + 1; j < length; j++){
            if(input_data[j] < input_data[min])
                min = j;
        }

        temp = input_data[min];
        input_data[min] = input_data[i];
        input_data[i]= temp;
    }
}

/*********************************************************************************************************************************/
#include "../include/sorts.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

void merge(float array[], int begin, int middle, int end){
    int cont1 = begin;
    int cont2 = (middle + 1);
    int contAux = 0;
    float *arrAux = malloc((end - begin + 1) * sizeof(float));

    while(cont1 <= middle && cont2 <= end){
        if(array[cont1] <array[cont2]){
            arrAux[contAux] = array[cont1];
            cont1++;
        }
        else{
            arrAux[contAux] = array[cont2];
            cont2++;
        }

        contAux++;
    }

    while(cont1 <= middle){
        arrAux[contAux] = array[cont1];
        contAux++;
        cont1++;
    }

    while(cont2 <= end){
        arrAux[contAux] = array[cont2];
        contAux++;
        cont2++;
    }

    for(contAux = begin; contAux <= end; contAux++)
        array[contAux] = arrAux[contAux-begin];

    free(arrAux);
}

void mergeSortRecursive(float array[], int begin, int end){
    if(begin < end){
        int middle = (begin + end) / 2;

        mergeSortRecursive(array, begin, middle);
        mergeSortRecursive(array, middle + 1, end);
        merge(array, begin, middle, end);
    }
}

void swap(float *a, float *b){
    float c = *a;
    *a = *b;
    *b = c;
}

int partition(float array[], int low, int high){
    float pivot = array[high];
    int i = (low - 1);

    for(int j = low; j < high; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);

    return (i + 1);
}

void quickSortRecursive(float array[], int low, int high){
    if(low < high){
        int p = partition(array, low, high);

        quickSortRecursive(array, low, p - 1);
        quickSortRecursive(array, p + 1, high);
    }
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

void bubbleSort(float *array, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j+1]){
                float aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }
}

void insertionSort(float *array, int size){
    for(int i = 1; i < size; i++){
        float key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void mergeSort(float *array, int size){
    mergeSortRecursive(array, 0, size - 1);
}

void optimizedBubbleSort(float *array, int size){
    int ok = 0;

    for(int i = 0; i < size - 1 && ok == 0; i++){
        ok = 1;
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j+1]){
                ok = 0;
                float aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
        }
    }
}

void quickSort(float *array, int size){
    quickSortRecursive(array, 0, size - 1);
}

void selectionSort(float *array, int size){
    int min; 
    float temp;

    for(int i = 0; i < size - 1; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] < array[min])
                min = j;
        }

        temp = array[min];
        array[min] = array[i];
        array[i]= temp;
    }
}

/*********************************************************************************************************************************/
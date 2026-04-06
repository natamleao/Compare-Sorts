#include "../include/sorts.h"
#include <stdio.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

void merge(float array[], int begin, int middle, int end){
    int cont1 = begin;
    int cont2 = (middle + 1);
    int contAux = 0;
    int arrAux[end - begin + 1];

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

    for(contAux = begin; contAux < end; contAux++)
        array[contAux] = arrAux[contAux-begin];
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

void bubbleSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            if(data[j] > data[j+1]){
                float aux = data[j];
                data[j] = data[j+1];
                data[j+1] = aux;
            }
        }
    }
}

void insertionSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    for(int i = 1; i < size; i++){
        float key = data[i];
        int j = i - 1;

        while(j >= 0 && data[j] > key){
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}

void mergeSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    mergeSortRecursive(data, 0, size - 1);
}

void optimizedBubbleSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);
    int ok = 0;

    for(int i = 0; i < size - 1 && ok == 0; i++){
        ok = 1;
        for(int j = 0; j < size - 1; j++){
            if(data[j] > data[j+1]){
                ok = 0;
                float aux = data[j];
                data[j] = data[j+1];
                data[j+1] = aux;
            }
        }
    }
}

void quickSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    quickSortRecursive(data, 0, size - 1);
}

void selectionSort(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    int min; 
    float temp;

    for(int i = 0; i < size - 1; i++){
        min = i;
        for(int j = 0; j < size; j++){
            if(data[j] < data[min])
                min = j;
        }

        temp = data[min];
        data[min] = data[i];
        data[i]= temp;
    }
}

void sortWrapper(void *a, int f){
    switch(f){
        case 1:
            bubbleSort((StructureArray*)a);
            break;
        
        case 2:
            insertionSort((StructureArray*)a);
            break;

        case 3:
            mergeSort((StructureArray*)a);
            break;
        
        case 4:
            optimizedBubbleSort((StructureArray*)a);
            break;

        case 5:
            quickSort((StructureArray*)a);
            break;

        case 6:
            selectionSort((StructureArray*)a);
            break;

        default:
            printf("+ Opção inválida (%d não é o código de nenhum sort)\n", f);
            printf("+------------------------------------------------------------------+\n");
            break;
    }
}

/*********************************************************************************************************************************/
#include "../include/array.h"
#include "../include/execution_time.h"
#include "../include/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TESTS 7
#define N_ITERATIONS 100

int main(){ 

    int tests[] = {10000, 20000, 50000, 100000, 200000, 500000, 1000000};

    printf("+------------------------------------------------------------------+\n");
    printf("+------------------------ Testes iniciados ------------------------+\n");

    for(int i = 0; i < MAX_TESTS; i++){
        int size = tests[i];
        printf("+------------------------------------------------------------------+\n");
        printf("+ Teste nº: %d | Tamanho da entrada: %d\n", i+1, size);
        printf("+------------------------------------------------------------------+\n");
        StructureArray *arrayInsertion = structureArrayCreate(size);
        StructureArray *arrayBubble = structureArrayCreate(size);
        StructureArray *arrayOptimizedBubble = structureArrayCreate(size);
        StructureArray *arraySelection = structureArrayCreate(size);
        StructureArray *arrayQuick = structureArrayCreate(size);
        StructureArray *arrayMerge = structureArrayCreate(size);

        srand(time(NULL));
        for(int j = 0; j < size; j++){
            float min = -1e6f;
            float max =  1e6f;
            float value = min + ((float)rand() / RAND_MAX) * (max - min);
            structureArraySet(arrayOptimizedBubble, j, value);
            structureArraySet(arrayBubble, j, value);
            structureArraySet(arrayInsertion, j, value);
            structureArraySet(arraySelection, j, value);
            structureArraySet(arrayQuick, j, value);
            structureArraySet(arrayMerge, j, value);
        }

        double executionTimeBubbleSort = benchmarkExecutionTime(bubbleSort, structureArrayGetData(arrayBubble), size, N_ITERATIONS);
        printf("+ Bubble Sort - ");
        //structureArrayPrint(arrayBubble);
        executionTimePrint(executionTimeBubbleSort);
        structureArrayDestroy(arrayBubble);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeInsertionSort = benchmarkExecutionTime(insertionSort, structureArrayGetData(arrayInsertion), size, N_ITERATIONS);
        printf("+ Insertion Sort - ");
        //structureArrayPrint(arrayInsertion);
        executionTimePrint(executionTimeInsertionSort);
        structureArrayDestroy(arrayInsertion);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeMergeSort = benchmarkExecutionTime(mergeSort, structureArrayGetData(arrayMerge), size, N_ITERATIONS);
        printf("+ Merge Sort - ");
        //structureArrayPrint(arrayMerge);
        executionTimePrint(executionTimeMergeSort);
        structureArrayDestroy(arrayMerge);
        printf("+------------------------------------------------------------------+\n");
    
        double executionTimeOptimizedBubbleSort = benchmarkExecutionTime(optimizedBubbleSort, structureArrayGetData(arrayOptimizedBubble), size, N_ITERATIONS);
        printf("+ Optimized Bubble Sort - ");
        //structureArrayPrint(arrayOptimizedBubble);
        executionTimePrint(executionTimeOptimizedBubbleSort);
        structureArrayDestroy(arrayOptimizedBubble);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeQuickSort = benchmarkExecutionTime(quickSort, structureArrayGetData(arrayQuick), size, N_ITERATIONS);
        printf("+ Quick Sort - ");
        //structureArrayPrint(arrayQuick);
        executionTimePrint(executionTimeQuickSort);
        structureArrayDestroy(arrayQuick);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeSelectionSort = benchmarkExecutionTime(selectionSort, structureArrayGetData(arraySelection), size, N_ITERATIONS);
        printf("+ Selection Sort - ");
        //structureArrayPrint(arraySelection);
        executionTimePrint(executionTimeSelectionSort);
        structureArrayDestroy(arraySelection);
    }

    printf("+------------------------------------------------------------------+\n");
    printf("+----------------------- Testes finalizados -----------------------+\n");
    printf("+------------------------------------------------------------------+\n");

    return 0;
}
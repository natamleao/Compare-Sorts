#include "../include/array.h"
#include "../include/execution_time.h"
#include "../include/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BS  1
#define IS  2
#define MS  3
#define OBS 4
#define QS  5
#define SS  6

#define MAX_TESTS 7

int main(){ 

    int tests[] = {10000, 20000, 50000, 100000, 200000, 500000, 1000000};

    printf("+------------------------------------------------------------------+\n");
    printf("+------------------------ Testes iniciados ------------------------+\n");

    for(int i = 0; i < MAX_TESTS; i++){
        printf("+------------------------------------------------------------------+\n");
        printf("+ Teste nº: %d | Tamanho da entrada: %d\n", i+1, tests[i]);
        printf("+------------------------------------------------------------------+\n");
        StructureArray *arrayInsertion = structureArrayCreate(tests[i]);
        StructureArray *arrayBubble = structureArrayCreate(tests[i]);
        StructureArray *arrayOptimizedBubble = structureArrayCreate(tests[i]);
        StructureArray *arraySelection = structureArrayCreate(tests[i]);
        StructureArray *arrayQuick = structureArrayCreate(tests[i]);
        StructureArray *arrayMerge = structureArrayCreate(tests[i]);

        srand(time(NULL));
        for(int j = 0; j < tests[i]; j++){
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

        double executionTimeBubbleSort = executionTimeCalculate(sortWrapper, arrayBubble, BS);
        printf("+ Bubble Sort - ");
        //structureArrayPrint(arrayBubble);
        executionTimePrint(executionTimeBubbleSort);
        structureArrayDestroy(arrayBubble);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeInsertionSort = executionTimeCalculate(sortWrapper, arrayInsertion, IS);
        printf("+ Insertion Sort - ");
        //structureArrayPrint(arrayInsertion);
        executionTimePrint(executionTimeInsertionSort);
        structureArrayDestroy(arrayInsertion);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeMergeSort = executionTimeCalculate(sortWrapper, arrayMerge, MS);
        printf("+ Merge Sort - ");
        //structureArrayPrint(arrayMerge);
        executionTimePrint(executionTimeMergeSort);
        structureArrayDestroy(arrayMerge);
        printf("+------------------------------------------------------------------+\n");
    
        double executionTimeOptimizedBubbleSort = executionTimeCalculate(sortWrapper, arrayOptimizedBubble, OBS);
        printf("+ Optimized Bubble Sort - ");
        //structureArrayPrint(arrayOptimizedBubble);
        executionTimePrint(executionTimeOptimizedBubbleSort);
        structureArrayDestroy(arrayOptimizedBubble);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeQuickSort = executionTimeCalculate(sortWrapper, arrayQuick, QS);
        printf("+ Quick Sort - ");
        //structureArrayPrint(arrayQuick);
        executionTimePrint(executionTimeQuickSort);
        structureArrayDestroy(arrayQuick);
        printf("+------------------------------------------------------------------+\n");

        double executionTimeSelectionSort = executionTimeCalculate(sortWrapper, arraySelection, SS);
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
#include "../include/array.h"
#include "../include/execution_time.h"
#include "../include/sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TESTS 7
#define NUM_RUNS 100

void runTest(FILE *file, const char *name, void (*sort)(float*, int), StructureArray *structure, int length, int isLast);

int main(){ 

    int tests[] = {10000, 20000, 50000, 100000, 200000, 500000, 1000000};

    FILE *file = fopen("results.csv", "w");
    if(!file){
        perror("fopen failed");
        return 1;
    }

    fprintf(
        file, 
        "length," 
        "bubble_mean,bubble_std," 
        "insertion_mean,insertion_std," 
        "merge_mean,merge_std," 
        "opbubble_mean,opbubble_std," 
        "quick_mean,quick_std," 
        "selection_mean,selection_std\n"
    );

    printf("+----------------------------------------------------------------------------------------+\n");
    printf("+----------------------------------- Testes iniciados -----------------------------------+\n");

    srand(time(NULL));

    for(int i = 0; i < MAX_TESTS; i++){
        printf("+----------------------------------------------------------------------------------------+\n");
        printf("+ Teste nº: %d | Tamanho da entrada: %d\n", i+1, tests[i]);
        printf("+----------------------------------------------------------------------------------------+\n");
        StructureArray *structureInsertion = structureArrayCreate(tests[i]);
        StructureArray *structureBubble = structureArrayCreate(tests[i]);
        StructureArray *structureOptimizedBubble = structureArrayCreate(tests[i]);
        StructureArray *structureSelection = structureArrayCreate(tests[i]);
        StructureArray *structureQuick = structureArrayCreate(tests[i]);
        StructureArray *structureMerge = structureArrayCreate(tests[i]);

        for(int j = 0; j < tests[i]; j++){
            float min = -1e6f;
            float max =  1e6f;
            float value = min + ((float)rand() / RAND_MAX) * (max - min);
            structureArraySet(structureOptimizedBubble, j, value);
            structureArraySet(structureBubble, j, value);
            structureArraySet(structureInsertion, j, value);
            structureArraySet(structureSelection, j, value);
            structureArraySet(structureQuick, j, value);
            structureArraySet(structureMerge, j, value);
        }

        fprintf(file, "%d,", tests[i]);

        runTest(file, "Bubble Sort", bubbleSort, structureBubble, tests[i], 0);
        printf("+----------------------------------------------------------------------------------------+\n");
        runTest(file, "Insertion Sort", insertionSort, structureInsertion, tests[i], 0);
        printf("+----------------------------------------------------------------------------------------+\n");
        runTest(file, "Merge Sort", mergeSort, structureMerge, tests[i], 0);
        printf("+----------------------------------------------------------------------------------------+\n");
        runTest(file, "Optimized Bubble Sort", optimizedBubbleSort, structureOptimizedBubble, tests[i], 0);
        printf("+----------------------------------------------------------------------------------------+\n");
        runTest(file, "Quick Sort", quickSort, structureQuick, tests[i], 0);
        printf("+----------------------------------------------------------------------------------------+\n");
        runTest(file, "Selection Sort", selectionSort, structureSelection, tests[i], 1);
    }

    fclose(file);

    printf("+----------------------------------------------------------------------------------------+\n");
    printf("+---------------------------------- Testes finalizados ----------------------------------+\n");
    printf("+----------------------------------------------------------------------------------------+\n");

    return 0;
}

void runTest(FILE *file, const char *name, void (*sort)(float*, int), StructureArray *structure, int length, int isLast){
    Result *r = benchmarkExecutionTime(sort, structureArrayGetData(structure), length, NUM_RUNS);

    if(isLast)
        fprintf(file, "%.6f,%.6f\n", resultGetMean(r), resultGetStddev(r));
    else
        fprintf(file, "%.6f,%.6f,", resultGetMean(r), resultGetStddev(r));

    printf("+ %s - ", name);
    executionTimePrint(r);

    structureArrayDestroy(structure);
    resultDestroy(r);
}

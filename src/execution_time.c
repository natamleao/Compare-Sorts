#define _POSIX_C_SOURCE 199309L
#include "../include/execution_time.h"
#include "../include/array.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

double elapsed(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec) * 1e9 + (b.tv_nsec - a.tv_nsec);
}

float **allocMatrix(int nLines, int nColumns){
    float **m = calloc(nLines, sizeof(float*));
    if(!m){
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < nLines; i++){
        m[i] = calloc(nColumns, sizeof(float));

        if(!m[i]){
            perror("calloc failed");
            exit(EXIT_FAILURE);
        }
    }

    return m;
}

void copyData(float **m, float *array, int nLines, int nColumns){
    for(int i = 0; i < nLines; i++)
        memcpy(m[i], array, nColumns * sizeof(float));
}

void destroyMatrix(float **m, int nLines){
    for(int i = 0; i < nLines; i++)
        free(m[i]);
    free(m);
}

void calculateTime(void (*function)(float*, int), float *array, int size, double *sum){
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    function(array, size);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    (*sum) += elapsed(t1, t2);
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

double benchmarkExecutionTime(void (*function)(float*, int), float *array, int size){
    int n_times = 4;

    float **m = allocMatrix(n_times, size);
    
    copyData(m, array, n_times, size);

    double sum = 0.0;

    for(int i = 0; i < n_times; i++)
        calculateTime(function, m[i], size, &sum);

    destroyMatrix(m, n_times);

    return sum / n_times;
}

void executionTimePrint(double executionTime){
    printf("Tempo de execução: %.6f ms\n", executionTime / 1e6);
}

/*********************************************************************************************************************************/
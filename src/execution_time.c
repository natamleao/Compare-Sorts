#define _POSIX_C_SOURCE 199309L
#include "../include/execution_time.h"
#include <time.h>
#include <stdio.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

double elapsed(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec) * 1e9 + (b.tv_nsec - a.tv_nsec);
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

double executionTimeCalculate(void (*function)(void *, int), void *data, int f){
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    function(data, f);
    clock_gettime(CLOCK_MONOTONIC, &t2);
    
    return elapsed(t1, t2);
}

void executionTimePrint(double executionTime){
    printf("Tempo de execução: %.6f ms\n", executionTime / 1e6);
}

/*********************************************************************************************************************************/
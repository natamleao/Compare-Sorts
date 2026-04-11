#define _POSIX_C_SOURCE 199309L
#include "../include/execution_time.h"
#include "../include/array.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _result{
    double mean, stddev;
};

double elapsed(struct timespec a, struct timespec b){
    return (b.tv_sec - a.tv_sec) * 1e9 + (b.tv_nsec - a.tv_nsec);
}

float **allocMatrix(int nLines, int nColumns){
    float **m = calloc(nLines, sizeof(float*));

    if(!m){
        perror("calloc failed");
        return NULL;
    }

    for(int i = 0; i < nLines; i++){
        m[i] = calloc(nColumns, sizeof(float));

        if(!m[i]){
            for(int j = 0; j < i; j++)
                free(m[j]);
            free(m);
            return NULL;
        }
    }

    return m;
}

void copyData(float **m, float *input_data, int nLines, int nColumns){
    for(int i = 0; i < nLines; i++)
        memcpy(m[i], input_data, nColumns * sizeof(float));
}

void destroyMatrix(float **m, int nLines){
    for(int i = 0; i < nLines; i++)
        free(m[i]);
    free(m);
}

double calculateTime(void (*sort_fn)(float *, int), float *input_data, int length){
    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    sort_fn(input_data, length);
    clock_gettime(CLOCK_MONOTONIC, &t2);
 
    return elapsed(t1, t2);
}

double calculateMean(double *times, int num_runs){
    double mean = 0.0;

    for(int i = 0; i < num_runs; i++)
        mean += times[i];

    return mean / num_runs;
}

double calculateStandardDeviation(double *times, int num_runs, double mean){
    double variance = 0.0;

    for(int i = 0; i < num_runs; i++){
        double diff = times[i] - mean;
        variance += diff * diff;
    }

    variance /= num_runs;

    return sqrt(variance);
}

/******************************************************* INTERFACE PUBLICA *******************************************************/

double resultGetMean(Result *res){return res->mean;}
double resultGetStddev(Result *res){return res->stddev;}

Result *benchmarkExecutionTime(void (*sort_fn)(float *, int), float *input_data, int length, int num_runs){
    float **m = allocMatrix(num_runs, length);
    double *times = calloc(num_runs, sizeof(double));
    if(!times){
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }
    
    copyData(m, input_data, num_runs, length);

    for(int i = 0; i < num_runs; i++)
        times[i] = calculateTime(sort_fn, m[i], length);

    destroyMatrix(m, num_runs);

    Result *res = malloc(sizeof(Result));
    if(!res){
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    res->mean = calculateMean(times, num_runs);
    res->stddev = calculateStandardDeviation(times, num_runs, res->mean);

    free(times);
    return res;
}

void executionTimePrint(Result *res){
    printf(
        "Mean: %.6f ms | StdDev: %.6f ms | CV: %.2f%%\n",
        resultGetMean(res) / 1e6,
        resultGetStddev(res) / 1e6,
        (resultGetStddev(res) / resultGetMean(res)) * 100.0
    );
}

void resultDestroy(Result *res){
    free(res);
}

/*********************************************************************************************************************************/
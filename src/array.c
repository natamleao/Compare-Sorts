#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>


/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _structureArray{
    float *_data;
    int _size;
};

/******************************************************* INTERFACE PUBLICA *******************************************************/

StructureArray* structureArrayCreate(int size){
    StructureArray *array = (StructureArray*)malloc(sizeof(StructureArray));
    if(!array) return NULL;

    array->_size = size;

    array->_data = (float*)calloc(size, sizeof(float));
    if(!array->_data){
        free(array);
        return NULL;
    }

    return array;
}

float* structureArrayGetData(StructureArray *array){return array->_data;}
int structureArrayGetSize(StructureArray *array){return array->_size;}

void structureArraySet(StructureArray *array, int index, float value){array->_data[index] = value;}
float structureArrayGet(StructureArray *array, int index){return array->_data[index];}

void structureArrayPrint(StructureArray *array){
    float *data = structureArrayGetData(array);
    int size = structureArrayGetSize(array);

    printf("["); 
    for(int i = 0; i < size - 1; i++)
        printf("%.2f  ", data[i]);
    
    printf("%.2f]\n", data[size - 1]);
}

void structureArrayDestroy(StructureArray *array){
    if(array){
        free(array->_data);
        free(array);
    }
}

/*********************************************************************************************************************************/
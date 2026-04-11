#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>


/******************************************************* INTERFACE PRIVADA *******************************************************/

struct _structureArray{
    float *_input_data;
    int _length;
};

/******************************************************* INTERFACE PUBLICA *******************************************************/

StructureArray* structureArrayCreate(int length){
    StructureArray *array = (StructureArray*)malloc(sizeof(StructureArray));
    if(!array) return NULL;

    array->_length = length;

    array->_input_data = calloc(length, sizeof(float));
    if(!array->_input_data){
        free(array);
        return NULL;
    }

    return array;
}

float* structureArrayGetData(StructureArray *structure){return structure->_input_data;}
int structureArrayGetSize(StructureArray *structure){return structure->_length;}

void structureArraySet(StructureArray *structure, int index, float value){structure->_input_data[index] = value;}
float structureArrayGet(StructureArray *structure, int index){return structure->_input_data[index];}

void structureArrayPrint(StructureArray *structure){
    float *data = structureArrayGetData(structure);
    int size = structureArrayGetSize(structure);

    printf("["); 
    for(int i = 0; i < size - 1; i++)
        printf("%.2f  ", data[i]);
    
    printf("%.2f]\n", data[size - 1]);
}

void structureArrayDestroy(StructureArray *structure){
    if(structure){
        free(structure->_input_data);
        free(structure);
    }
}

/*********************************************************************************************************************************/
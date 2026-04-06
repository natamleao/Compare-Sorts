/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef STRUCTURE_ARRAY_H
#define STRUCTURE_ARRAY_H

typedef struct _structureArray StructureArray;

/**
 * @brief Cria uma estrutura de array com tamanho fixo.
 *
 * Aloca memória para a estrutura e para o vetor interno de dados.
 *
 * @param size Tamanho do array (número de elementos).
 * @return Ponteiro para a estrutura criada ou NULL em caso de falha.
 */
StructureArray* structureArrayCreate(int size);

/**
 * @brief Retorna o ponteiro para o vetor interno de dados.
 *
 * Permite acesso direto aos elementos do array.
 *
 * @param array Ponteiro para a estrutura.
 * @return Ponteiro para o vetor de floats.
 */
float* structureArrayGetData(StructureArray *array);

/**
 * @brief Retorna o tamanho do array.
 *
 * @param array Ponteiro para a estrutura.
 * @return Quantidade de elementos do array.
 */
int structureArrayGetSize(StructureArray *array);

/**
 * @brief Define o valor em um índice específico.
 *
 * @param array Ponteiro para a estrutura.
 * @param index Índice do elemento.
 * @param value Valor a ser atribuído.
 */
void structureArraySet(StructureArray *array, int index, float value);

/**
 * @brief Retorna o valor de um índice específico.
 *
 * @param array Ponteiro para a estrutura.
 * @param index Índice do elemento.
 * @return Valor armazenado no índice.
 */
float structureArrayGet(StructureArray *array, int index);

/**
 * @brief Imprime todos os elementos do array.
 *
 * Os valores são exibidos no formato [x1 x2 x3 ...].
 *
 * @param array Ponteiro para a estrutura.
 */
void structureArrayPrint(StructureArray *array);

/**
 * @brief Libera toda a memória associada à estrutura.
 *
 * Desaloca o vetor interno e a própria estrutura.
 *
 * @param array Ponteiro para a estrutura a ser destruída.
 */
void structureArrayDestroy(StructureArray *array);

#endif

/*********************************************************************************************************************************/
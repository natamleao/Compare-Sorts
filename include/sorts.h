/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef SORTS_H
#define SORTS_H

#include "array.h"

/********************************************************** BUBBLE SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Bubble Sort.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details O algoritmo percorre o array diversas vezes, comparando elementos adjacentes 
 * e trocando-os de posição caso estejam fora de ordem. O processo se repete até que 
 * nenhum elemento precise ser trocado, garantindo que o array esteja totalmente ordenado.
 *
 * @note Este algoritmo possui complexidade O(n²) no pior caso e é mais adequado para arrays pequenos.
 */
void bubbleSort(StructureArray *array);

/******************************************************** INSERTIONS SORT ********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Insertion Sort.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details O algoritmo percorre o array do segundo elemento até o final, 
 * inserindo cada elemento na posição correta em relação aos elementos anteriores.
 * Isso garante que a parte já percorrida do array esteja sempre ordenada.
 *
 * @note Este algoritmo possui complexidade O(n²) no pior caso, mas é eficiente para arrays pequenos ou quase ordenados.
 */
void insertionSort(StructureArray *array);

/*********************************************************** MERGE SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Merge Sort.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details O Merge Sort é um algoritmo de ordenação baseado na técnica "dividir para conquistar". 
 * Ele divide recursivamente o array em subarrays menores até que cada subarray tenha apenas um elemento,
 * e então os mescla de forma ordenada, reconstruindo o array final completamente ordenado.
 *
 * @note Este algoritmo possui complexidade O(n log n) no pior caso e é eficiente para arrays grandes.
 */
void mergeSort(StructureArray *array);

/****************************************************** OPTIMIZE BUBBLE SORT *****************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Bubble Sort otimizado.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details Este algoritmo é uma versão otimizada do Bubble Sort. 
 * Ele percorre o array comparando elementos adjacentes e trocando-os de posição quando necessário,
 * mas para a execução mais cedo se nenhum elemento precisar ser trocado, 
 * evitando iterações desnecessárias.
 *
 * @note Possui complexidade O(n²) no pior caso, mas é mais eficiente que o Bubble Sort simples quando o array está quase ordenado.
 */
void optimizedBubbleSort(StructureArray *array);

/*********************************************************** QUICK SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Quick Sort.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details O Quick Sort é um algoritmo de ordenação baseado na técnica "dividir para conquistar". 
 * Ele escolhe um pivô, particiona o array de forma que todos os elementos menores fiquem à esquerda 
 * e os maiores à direita, e então aplica recursivamente o mesmo processo nas subpartes.
 *
 * @note Possui complexidade média O(n log n) e pior caso O(n²), sendo muito eficiente para arrays grandes.
 */
void quickSort(StructureArray *array);

/******************************************************** SELECTION SORT *********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Selection Sort.
 *
 * @param array Ponteiro para a estrutura `StructureArray` que será ordenada.
 *
 * @details O algoritmo percorre o array repetidamente, selecionando a cada iteração 
 * o menor elemento da parte não ordenada e trocando-o com o primeiro elemento não ordenado.
 * Esse processo se repete até que todos os elementos estejam ordenados.
 *
 * @note Possui complexidade O(n²) no pior caso, sendo adequado apenas para arrays pequenos.
 */
void selectionSort(StructureArray *array);

/**
 * @brief Wrapper para permitir chamar `selectionSort` através de ponteiros genéricos.
 *
 * @param a Ponteiro para a estrutura `Array` (passado como `void*` para compatibilidade).
 * @param f Flag para saber qual função deve ser chamada.
 *
 * @note Usado principalmente com funções como `executionTimeCalculate` que aceitam `void*`.
 */
void sortWrapper(void *a, int f);

#endif

/*********************************************************************************************************************************/
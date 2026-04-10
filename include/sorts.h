/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef SORTS_H
#define SORTS_H

/********************************************************** BUBBLE SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Bubble Sort.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 *
 * @details O algoritmo percorre o array diversas vezes, comparando elementos adjacentes 
 * e trocando-os de posição caso estejam fora de ordem. O processo se repete até que 
 * nenhum elemento precise ser trocado, garantindo que o array esteja totalmente ordenado.
 *
 * @note Este algoritmo possui complexidade O(n²) no pior caso e é mais adequado para arrays pequenos.
 */
void bubbleSort(float *array, int size);

/******************************************************** INSERTION SORT ********************************************************/
 
/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Insertion Sort.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 * 
 * @details O algoritmo percorre o array do segundo elemento até o final, 
 * inserindo cada elemento na posição correta em relação aos elementos anteriores.
 * Isso garante que a parte já percorrida do array esteja sempre ordenada.
 *
 * @note Este algoritmo possui complexidade O(n²) no pior caso, mas é eficiente para arrays pequenos ou quase ordenados.
 */
void insertionSort(float *array, int size);

/*********************************************************** MERGE SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Merge Sort.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 * 
 * @details O Merge Sort é um algoritmo de ordenação baseado na técnica "dividir para conquistar". 
 * Ele divide recursivamente o array em subarrays menores até que cada subarray tenha apenas um elemento,
 * e então os mescla de forma ordenada, reconstruindo o array final completamente ordenado.
 *
 * @note Este algoritmo possui complexidade O(n log n) no pior caso e é eficiente para arrays grandes.
 */
void mergeSort(float *array, int size);

/****************************************************** OPTIMIZED BUBBLE SORT *****************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Bubble Sort otimizado.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 * 
 * @details Esta é uma versão otimizada do Bubble Sort. 
 * O algoritmo interrompe a execução antecipadamente caso nenhuma troca seja necessária em uma passagem,
 * evitando iterações desnecessárias.
 *
 * @note Possui complexidade O(n²) no pior caso, mas pode ser mais eficiente quando o array está quase ordenado.
 */
void optimizedBubbleSort(float *array, int size);

/*********************************************************** QUICK SORT **********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Quick Sort.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 * 
 * @details O Quick Sort escolhe um pivô, particiona o array de forma que elementos menores fiquem à esquerda 
 * e maiores à direita, e então aplica recursivamente o mesmo processo nas subpartes.
 *
 * @note Possui complexidade média O(n log n) e pior caso O(n²), sendo muito eficiente na prática.
 */
void quickSort(float *array, int size);

/******************************************************** SELECTION SORT *********************************************************/

/**
 * @brief Ordena os elementos de um array em ordem crescente usando o algoritmo Selection Sort.
 *
 * @param array Ponteiro para o vetor de `float` que será ordenado.
 * @param size O tamanho do array.
 * 
 * @details O algoritmo percorre o array repetidamente, selecionando a cada iteração 
 * o menor elemento da parte não ordenada e trocando-o com o primeiro elemento não ordenado.
 *
 * @note Possui complexidade O(n²) no pior caso, sendo adequado apenas para arrays pequenos.
 */
void selectionSort(float *array, int size);

#endif

/*********************************************************************************************************************************/
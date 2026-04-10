/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef CALCULATE_TIME_H
#define CALCULATE_TIME_H

#include "sorts.h"

/**
 * @brief Mede o tempo médio de execução de uma função de ordenação.
 * 
 * @param function Ponteiro para função que recebe (float*, int).
 * @param array Vetor de float que será ordenado.
 * @param size Tamanho do vetor.
 * @param nIterations Número de execuções do algoritmo de ordenação.
 * 
 * @return Tempo médio de execução em nanosegundos.
 * 
 * @details A função executa o algoritmo múltiplas vezes sobre cópias do array original,
 * evitando efeitos colaterais e garantindo uma média mais estável do tempo de execução.
 * 
 * @note Usa clock_gettime com CLOCK_MONOTONIC (tempo real de alta precisão).
 */
double benchmarkExecutionTime(void (*function)(float*, int), float *array, int size, int nIterations);

/**
 * @brief Imprime o tempo de execução formatado em milissegundos.
 *
 * @param executionTime Tempo total em nanosegundos.
 *
 * @details Converte o tempo de nanosegundos para milissegundos e exibe na saída padrão.
 */
void executionTimePrint(double executionTime);

#endif

/*********************************************************************************************************************************/
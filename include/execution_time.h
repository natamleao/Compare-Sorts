/******************************************************* INTERFACE PUBLICA *******************************************************/

#ifndef EXECUTION_TIME_H
#define EXECUTION_TIME_H

typedef struct _result Result;

/**
 * @brief Retorna o tempo médio de execução (em nanosegundos).
 * 
 * @param res Estrutura com os dados de tempo.
 */
double resultGetMean(Result *res);

/**
 * @brief Retorna o desvio padrão dos tempos (em nanosegundos).
 * 
 * @param res Estrutura com os dados de tempo.
 */
double resultGetStddev(Result *res);

/**
 * @brief Mede o tempo médio de execução de uma função de ordenação.
 * 
 * @param sort_fn Ponteiro para função que recebe (float*, int).
 * @param input_data Vetor de float que será ordenado.
 * @param length Tamanho do vetor.
 * @param num_runs Número de execuções do algoritmo.
 * 
 * @return Estrutura contendo:
 * - tempo médio (ns)
 * - desvio padrão (ns)
 * 
 * @details Executa o algoritmo múltiplas vezes sobre cópias do array original,
 * evitando efeitos colaterais e produzindo uma média estatisticamente mais estável.
 * 
 * @note Usa clock_gettime com CLOCK_MONOTONIC.
 */
Result *benchmarkExecutionTime(void (*sort_fn)(float *, int), float *input_data, int length, int num_runs);

/**
 * @brief Imprime o resultado do benchmark em milissegundos.
 *
 * @param res Estrutura com os dados de tempo.
 *
 * @details Exibe o tempo médio e o desvio padrão convertidos de ns para ms.
 */
void executionTimePrint(Result *res);

/**
 * @brief Libera a memória associada ao resultado.
 * 
 * @param res Estrutura com os dados de tempo.
 */
void resultDestroy(Result *res);

#endif

/*********************************************************************************************************************************/
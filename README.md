# Compare-Sorts

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-array-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-comparison-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Visão geral

Este projeto implementa e compara diversos algoritmos de ordenação em **C**, com foco em **medição de desempenho real**.

Os algoritmos são executados múltiplas vezes sobre cópias idênticas dos dados, garantindo uma comparação **justa e consistente**.

---

## Algoritmos implementados

- *Bubble Sort*  
- *Optimized Bubble Sort*  
- *Insertion Sort*  
- *Selection Sort*  
- *Merge Sort*  
- *Quick Sort*  

---

## Estrutura de dados

Todos os algoritmos operam sobre uma estrutura dinâmica chamada `StructureArray`, que encapsula:

- Ponteiro para dados (`float*`)
- Tamanho do *array*

Isso permite melhor organização e controle de memória.

---

## Geração de dados

Para cada teste:

- Um conjunto de valores aleatórios é gerado no intervalo: ```[-1e6, 1e6]```
- Os mesmos valores são copiados para todos os algoritmos

Isso garante que todos ordenem exatamente o mesmo dataset.

---

## *Benchmark*

A medição de tempo é feita utilizando:

```c
clock_gettime(CLOCK_MONOTONIC, ...)
````

Características:

* Alta precisão (nanosegundos)
* Tempo real (não CPU time)
* Independente de alterações do sistema

---

## Metodologia

Cada algoritmo:

1. Recebe uma cópia do *array* original
2. É executado **100 vezes**
3. O tempo médio é calculado

```c
double time = benchmarkExecutionTime(bubbleSort, data, size);
executionTimePrint(time);
```

---

## Saída

Formato típico:

```text
+ Bubble Sort - Tempo de execução: 361.624544 ms
+ Insertion Sort - Tempo de execução: 76.949429 ms
+ Merge Sort - Tempo de execução: 1.451690 ms
+ Quick Sort - Tempo de execução: 0.859636 ms
```

---

## Estrutura do projeto

```text
Compare-Sorts/
│
├── app/             # Arquivo principal da aplicação (main)
├── bin/             # Executável gerado
├── include/         # Arquivos de cabeçalho (.h)
├── build/           # Arquivos objeto (.o)
├── src/             # Código-fonte da aplicação (.c)
├── lib/             # Biblioteca estática
│
├── Makefile         # Regras de compilação
├── README.md        # Documentação 
└── LICENSE          # Licença 
```

---

> [!IMPORTANT]
>
> ## Requisitos
>
> * *GCC* ou *Clang*
> * *GNU Make*
> * Sistema *Linux* ou *macOS*

---

## Instalação

```bash
git clone git@github.com:natamleao/Compare-Sorts.git
cd Compare-Sorts
```

---

## Compilação

```bash
make
```

---

## Execução

```bash
make run
```

---

## Limpeza

```bash
make clean
make cleanapp
```

---

## Observações

* Todos os algoritmos recebem os mesmos dados
* O benchmark usa múltiplas execuções para reduzir ruído
* Algoritmos O(n log n) escalam muito melhor para grandes entradas
* Algoritmos O(n²) tornam-se inviáveis para grandes volumes

---

> [!WARNING]
>
> ## Licença
>
> Este projeto está sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---

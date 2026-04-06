# *Compare-Sorts*

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-array-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-comparison-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Visão geral

Este projeto implementa e compara diversos algoritmos de ordenação em **C**, utilizando uma **biblioteca única** que contém todas as implementações.  

O objetivo é **comparar desempenho real** de cada algoritmo sobre os mesmos conjuntos de dados aleatórios.  

Algoritmos implementados:

* Bubble Sort
* Optimized Bubble Sort
* Insertion Sort
* Selection Sort
* Merge Sort
* Quick Sort

---

## Estruturas utilizadas

Todos os algoritmos trabalham sobre uma **estrutura `StructureArray`**, que encapsula um array de `float` dinâmico.  
O mesmo conjunto de valores é usado em todos os algoritmos, garantindo **comparação justa**.

---

## Algoritmos

### Bubble Sort
* Troca repetidamente elementos adjacentes se estiverem fora de ordem
* Complexidade: O(n²)

### Optimized Bubble Sort
* Variante que interrompe se nenhuma troca foi feita em uma passada
* Complexidade: O(n²), mas mais eficiente em arrays quase ordenados

### Insertion Sort
* Insere cada elemento na posição correta em relação aos anteriores
* Complexidade: O(n²), eficiente apenas para arrays pequenos

### Selection Sort
* Seleciona o menor elemento da parte não ordenada e troca com a posição atual
* Complexidade: O(n²)

### Merge Sort
* Divide e conquista, combinando subarrays ordenados
* Complexidade: O(n log n)

### Quick Sort
* Seleciona um pivô, particiona o array e aplica recursão
* Complexidade média: O(n log n), pior caso: O(n²)

---

## Medição de tempo

Foi utilizado `clock_gettime` com `CLOCK_MONOTONIC` para medir o tempo de execução de cada algoritmo:

```c
double executionTimeBubbleSort = executionTimeCalculate(sortWrapper, arrayBubble, BS);
executionTimePrint(executionTimeBubbleSort);
````

Formato de saída:

```text
Bubble Sort           - Tempo de execução: 0 H : 0 M : 3 S : 542 ms
Insertion Sort        - Tempo de execução: 0 H : 0 M : 0 S : 124 ms
Optimized Bubble Sort - Tempo de execução: 0 H : 0 M : 0 S : 110 ms
Selection Sort        - Tempo de execução: 0 H : 0 M : 0 S : 200 ms
Merge Sort            - Tempo de execução: 0 H : 0 M : 0 S : 10 ms
Quick Sort            - Tempo de execução: 0 H : 0 M : 0 S : 9 ms
```

> Observação: valores variam conforme o tamanho do array e hardware.

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

* Todos os algoritmos recebem exatamente os mesmos valores aleatórios
* Facilita **comparação direta de desempenho**
* Merge Sort e Quick Sort escalam melhor para arrays grandes, enquanto os O(n²) são mais lentos

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

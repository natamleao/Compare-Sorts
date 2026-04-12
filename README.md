# *Compare-Sorts*

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Algorithm](https://img.shields.io/badge/algorithm-benchmark-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Visão geral

Este projeto implementa e compara algoritmos de ordenação em **C**, com foco em ***benchmark* real e análise estatística de desempenho**.

Cada algoritmo é executado múltiplas vezes sobre **cópias idênticas dos dados**, garantindo uma comparação **justa, consistente e reprodutível**.

---

## Algoritmos implementados

- *Bubble Sort*  
- *Optimized Bubble Sort*  
- *Insertion Sort*  
- *Selection Sort*  
- *Merge Sort*  
- *Quick Sort*  

---

## Metodologia

Para cada tamanho de entrada:

1. Um vetor aleatório é gerado no intervalo `[-1e6, 1e6]`
2. Esse vetor é copiado para todos os algoritmos
3. Cada algoritmo é executado **100 vezes**
4. São calculados:
   - **Tempo médio (mean)**
   - **Desvio padrão (stddev)**
   - **Coeficiente de variação (CV)**

> Para os algoritmos menos eficientes (*Bubble*, *Optimized Bubble*, *Insertion* e *Selection Sort*), a execução é controlada a entradas com tamanho menor (até 200000), escalando somentes para os mais eficientes (*Merge* e *Quick Sort*),

---

## Ambiente de execução

Os testes foram executados no meu notebook:

* CPU: AMD Ryzen 7 5825U (8 cores / 16 threads)
* RAM: 7.2 GiB
* Sistema: Debian GNU/Linux 12 (Bookworm)
* Arquitetura: x86-64
* Armazenamento: SSD
* Compilador: GCC
* Flags: `-O2 -Wall -Werror -g`

Isso é necessário deixar claro, o tempo depende e vária de máquina para máquina.

## *Benchmark*

A medição de tempo é feita com:

```c
clock_gettime(CLOCK_MONOTONIC, ...)
````

Características:

* Alta precisão (nanosegundos)
* Tempo real (wall-clock time)
* Independente de mudanças no sistema

---

## Saída no terminal

Exemplo:

```text
+ Bubble Sort - Mean: 361.624544 ms | StdDev: 5.321000 ms | CV: 1.47%
+ Quick Sort  - Mean: 0.859636 ms  | StdDev: 0.012000 ms | CV: 1.39%
```

---

## Saída em CSV

Os resultados também são exportados para:

```text
results.csv
```

Formato:

```csv
length,
bubble_mean,bubble_std,
opbubble_mean,opbubble_std,
insertion_mean,insertion_std,
selection_mean,selection_std,
merge_mean,merge_std,
quick_mean,quick_std
```

Exemplo:

```csv
10000,0.123,0.005,0.098,0.003,...
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
├── results.csv      # Saída do benchmark
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

* Todos os algoritmos recebem **exatamente o mesmo dataset**
* O benchmark usa múltiplas execuções para reduzir ruído
* O desvio padrão mede a **estabilidade do algoritmo**
* O coeficiente de variação (CV) mede a **variabilidade relativa**
* Algoritmos **O(n log n)** escalam muito melhor que **O(n²)**

---

## Limitações

* Algoritmos O(n²) tornam-se inviáveis para grandes entradas (ex: 1e6)
* O benchmark mede tempo real, não uso detalhado de CPU/cache
* Resultados podem variar dependendo do hardware

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

/*

PROCESSO AVALIATIVO N3 – ESTRUTURA DE DADOS

EQUIPE
NOMES: JOÃO MIGUEL DE CASTRO MENNA, GRAZIELA TORRES

CONSEGUIU CHEGAR NO RESULTADO?
R: SIM

SE NÃO, POR QUE NÃO CONSEGUIU CHEGAR NO RESULTADO?
R.:

*/
#include <stdio.h>
#include <time.h>

#define TAMANHO 10000

void geraNumero(int *vet, int op);
void quickSort(int vet[], int ini, int fim, int *qtd_comparacoes, int *qtd_trocas);
int partition(int vet[], int ini, int fim, int *qtd_comparacoes, int *qtd_trocas);
void fazerQuickSort(int *vet);
void imprimirVetor(int *vet);

int main()
{
    int vet1[TAMANHO];

    geraNumero(vet1,3);
    fazerQuickSort(vet1);
    // imprimirVetor(vet1);

    return 0;
}

void geraNumero(int *vet, int op)
{
    int i, j;
    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++)
                vet[i] = i + 1;
            break;

        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++)
                vet[i] = TAMANHO - i;
            break;

        case 3: // Aleatórios
            for (i = 0; i < TAMANHO; i++)
                vet[i] = (int) (rand() % TAMANHO);
            break;
    }
}


void quickSort(int vet[], int ini, int fim, int *qtd_comparacoes, int *qtd_trocas) { 
    int meio; 

    if (ini < fim) { 
        meio = partition(vet, ini, fim, qtd_comparacoes, qtd_trocas); 
        quickSort(vet, ini, meio, qtd_comparacoes, qtd_trocas); 
        quickSort(vet, meio + 1, fim, qtd_comparacoes, qtd_trocas); 
    } 
} 

int partition(int vet[], int ini, int fim, int *qtd_comparacoes, int *qtd_trocas) { 
    int pivo, topo, i; 
    pivo = vet[ini]; 
    topo = ini; 

    for (i = ini + 1; i <= fim; i++) { 
        *qtd_comparacoes += 1;
        if (vet[i] < pivo) { 
            *qtd_trocas += 1;
            vet[topo] = vet[i]; 
            vet[i] = vet[topo + 1]; 
            topo++; 
        } 
    } 

    vet[topo] = pivo; 
    return topo; 
} 

void fazerQuickSort(int *vet)
{
    int qtd_trocas, qtd_comparacoes;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();

    quickSort(vet, 0, TAMANHO - 1, &qtd_comparacoes, &qtd_trocas);

    float tempo_final = clock() - tempo_inicial;

    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
}


void imprimirVetor(int *vet)
{
    for(int i = 0; i < TAMANHO; i++)
    {
        printf("%i, ", vet[i]);
        if ((i + 1) % 14 == 0)
        {
            printf("\n");
        }
    }
}
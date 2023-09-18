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
void insertionSort(int *vet);
void imprimirVetor(int *vet);

int main()
{
    int vet1[TAMANHO];

    geraNumero(vet1,3);
    insertionSort(vet1);
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


void insertionSort(int *vet)
{
    int qtd_trocas, qtd_comparacoes;
    int i, j, eleito;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();

    for (i = 1; i <= TAMANHO - 1; i++) { 
        qtd_comparacoes++;
        eleito = vet[i]; 
        j = i - 1; 

        while (j >= 0 && vet[j] > eleito) { 
            qtd_comparacoes++;
            vet[j + 1] = vet[j]; 
            j = j - 1; 
            qtd_trocas++;
        } 

        vet[j + 1] = eleito; 
        qtd_trocas++;
        qtd_trocas++;
    } 

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
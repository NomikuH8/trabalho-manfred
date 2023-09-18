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
void selectionSort(int *vet);
void imprimirVetor(int *vet);

int main()
{
    int vet1[TAMANHO];

    geraNumero(vet1,3);
    selectionSort(vet1);
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


void selectionSort(int *vet)
{
    int qtd_trocas, qtd_comparacoes;
    int i, j, eleito, menor, pos;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();

    for (i = 0; i <= TAMANHO - 2; i++) { 
        eleito = vet[i]; 
        menor = vet[i + 1]; 
        pos = i + 1; 
        qtd_trocas++;

        for (j = i + 2; j <= TAMANHO - 1; j++) { 
            qtd_comparacoes++;
            if (vet[j] < menor) { 
                menor = vet[j]; 
                pos = j; 
            } 
        } 

        qtd_comparacoes++;
        if (menor < eleito) { 
            qtd_trocas++;
            vet[i] = vet[pos]; 
            vet[pos] = eleito; 
        } 
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
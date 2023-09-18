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
void fazerMergeSort(int *vet);
void intercala(int x[], int inicio, int fim, int meio, int *qtd_comparacoes, int *qtd_trocas);
void imprimirVetor(int *vet);

int main()
{
    int vet1[TAMANHO];

    geraNumero(vet1,3);
    fazerMergeSort(vet1);
    //imprimirVetor(vet1);

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

void merge(int x[], int inicio, int fim, int *qtd_comparacoes, int *qtd_trocas) { 
    int meio; 
    if (inicio < fim) { 
        meio = (inicio + fim) / 2; 
        merge(x, inicio, meio, qtd_comparacoes, qtd_trocas); 
        merge(x, meio + 1, fim, qtd_comparacoes, qtd_trocas); 
        intercala(x, inicio, fim, meio, qtd_comparacoes, qtd_trocas); 
    } 
} 

void intercala(int x[], int inicio, int fim, int meio, int *qtd_comparacoes, int *qtd_trocas) { 
    int poslivre = inicio, iniciovetor1 = inicio, iniciovetor2 = meio + 1, i; 
    int aux[TAMANHO]; 

    while (iniciovetor1 <= meio && iniciovetor2 <= fim) { 
        if (x[iniciovetor1] <= x[iniciovetor2]) { 
            aux[poslivre] = x[iniciovetor1]; 
            iniciovetor1++; 
        } else { 
            aux[poslivre] = x[iniciovetor2]; 
            iniciovetor2++; 
        } 

        *qtd_trocas += 1;
        *qtd_comparacoes += 1;
        poslivre++; 
    } 

    for (i = iniciovetor1; i <= meio; i++) { 
        aux[poslivre] = x[i]; 
        poslivre++; 
    } 

    for (i = iniciovetor2; i <= fim; i++) { 
        aux[poslivre] = x[i]; 
        poslivre++; 
    } 

    for (i = inicio; i <= fim; i++) { 
        x[i] = aux[i]; 
    } 
} 


void fazerMergeSort(int *vet)
{
    int qtd_trocas, qtd_comparacoes;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();

    merge(vet, 0, TAMANHO, &qtd_comparacoes, &qtd_trocas);

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
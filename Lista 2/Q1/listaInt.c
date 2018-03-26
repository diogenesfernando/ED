#include "listaInt.h"
#include <stdio.h>
#include <stdlib.h>

static int EstaCheia(const tLista *lista){
    return lista->elementos[0] >= MAX_ELEMENTOS;
}

void IniciaLista(tLista *lista){
    lista->elementos[0] = 0;
}

int Comprimento(const tLista *lista){
    return lista->elementos[0]; /* Não há o que calcular */
}

tElemento ObtemElemento(const tLista *lista, int indice){
    if (indice < 0 || indice >= lista->elementos[0]) {
        printf("\nElemento inexistente\n");
        exit(1);
    }

    return lista->elementos[indice];
}

static int InsereElemento(tLista *lista, tElemento item, int indice){
    /* Se a lista estiver cheia, não há */
    /* como inserir mais um elemento    */
    if (EstaCheia(lista)) {
        printf("\nA lista esta cheia\n");
        return 1;
    }
    /* Verifica se o índice é válido */
    if (indice < 0 || indice > lista->elementos[0]) {
        printf("\nPosicao de insercao inexistente\n");
        return 1;
    }

    /* Abre espaço para o novo elemento */
    int i;
    for (i = lista->elementos[o] - 1; i >= indice; --i)
        lista->elementos[i + 1] = lista->elementos[i];

    /* Insere o novo elemento */
    lista->elementos[indice] = item;
    lista->elementos[0]++; /* O tamanho da lista aumentou */

    return 0;
}

tElemento RemoveElemento(tLista *lista, int indice){
    tElemento itemRemovido;
    /* Verifica se o índice é válido */
    if (indice < 0 || indice >= lista->elementos[0]) {
        printf("\nPosicao de remocao inexistente\n");
        exit(1);
    }
    itemRemovido = lista->elementos[indice];

    /* Remover um elemento significa mover cada elemento  */
    /* uma posição para trás a partir do próximo elemento */
    /* adiante daquele que será  removido                 */
    int i;
    for (i = indice; i < lista->elementos[0] - 1; i++)
        lista->elementos[i] = lista->elementos[i + 1];

    --lista->elementos[0]; /* O tamanho da lista diminuiu */

    return itemRemovido;
}

int EstaVazia(const tLista *lista){
    return lista->elementos[0] == 0;
}

int AcrescentaElemento(tLista *lista, tElemento elemento){
    /* Verifica se é possível acrescentar */
    /* mais um elemento na lista          */
    if (EstaCheia(lista)) {
	puts("Esta cheia!!!");
        return 1; /* A lista está cheia */
    }

    /* Acrescenta um novo elemento ao final da lista */
    lista->elementos[lista->elementos[0]] = elemento;
    ++lista->elementos[0]; /* O tamanho da lista aumentou */

    return 0;
}

int BuscaElemento(const tLista *lista, tElemento elemento){
    int i;
    for (i = 0; i < lista->elementos[0]; ++i) {
        if (lista->elementos[i] == elemento) {
            return i; /* Elemento foi encontrado */
        }
    }

    return -1; /* Elemento não foi encontrado */
}

void ExibeLista(const tLista *lista){
    int i;
    for(i = 0; i < Comprimento(lista); i++){
        printf("[%d] = %d%s", i, ObtemElemento(lista, i),
                i == Comprimento(lista) - 1 ? "\n" : ", ");
    }
}

int InsereEmOrdem(tLista *lista, tElemento elemento){
    int indice;
    /* procura a posicao na lista que o elemento deve estar */
    for (indice = 0; indice < lista->elementos[0]; indice++){
        if (lista->elementos[indice] > elemento){
            break;
        }
    }

    /* usa a implementacao de InsereElemento na posicao encontrada */
    return InsereElemento(lista, elemento, indice);
}

int BuscaBinaria(const tLista *lista, tElemento elemento){
    int inf, sup, meio;

    inf = 0;
    sup = Comprimento(lista) - 1;

    while(inf <= sup){
        meio = (inf + sup) / 2;
        if (lista->elementos[meio] == elemento){
            return meio; //posicao do elemento encontrado
        }

        if (elemento < lista->elementos[meio]){
            sup = meio - 1;
        }else{
            inf = meio + 1;
        }
    }

    return -1; //elemento nao encontrado
}

int EstaNaLista(const tLista *lista, tElemento elemento){
    return BuscaBinaria(lista, elemento) != -1;
}

void DeletarDuplicata(tLista *lista){
    int i, j;
    for(i=0;i < Comprimento(lista);i++){
        for(j = i + 1; j < Comprimento(lista); j++){
            if(lista->elementos[j]==lista->elementos[i]){
                RemoveElemento(lista, j);
                j--;
            }
        }
    }
}

tElemento RemovePorValor(tLista *lista, tElemento elemento){
    int i = BuscaBinaria(lista, elemento);
    return RemoveElemento(lista, i);
}

tElemento RemoveTodosComValor(tLista *lista, tElemento elemento){
    int i;
    for(i = 0; i < Comprimento(lista); i++){
        if (lista->elementos[i] == elemento){
            RemoveElemento(lista, i);
            i--;
        }
    }
    return elemento;
}

void IntersecaoListas(const tLista *lista1, const tLista *lista2, tLista *lista3){
    int i, j;
    for(i = 0; i < Comprimento(lista1); i++){
        if (EstaNaLista(lista3, lista1->elementos[i])){
            continue;
        }
        for(j = 0; j < Comprimento(lista2); j++){
            if(lista1->elementos[i] == lista2->elementos[j]){
                InsereEmOrdem(lista3, lista1->elementos[i]);
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "listaInt.h"

void ApresentaMenu(){
    printf("\n\n******************** Menu ********************\n"
           "\t1. Insere Elemento\n"
           "\t2. Busca Elemento\n"
           "\t3. Remove Elemento pelo Indice\n"
           "\t4. Remove Elemento pelo Valor\n"
           "\t5. Remove Elementos pelo Valor\n"
           "\t6. Alterna Lista Atual\n"
           "\t7. Intersecao de Listas\n"
           "\t8. Copia Elementos Faltantes para Lista\n"
           "\t9. Exibe Lista Atual\n"
           "\t0. Sair\n");

}

int main(void){
    puts("Esse programa gerencia listas.");

    tLista minhaLista[3];
    int listaAtual = 0;

    IniciaLista(&minhaLista[0]);
    IniciaLista(&minhaLista[1]);
    IniciaLista(&minhaLista[2]);

    while(1){
        ApresentaMenu();
        printf("Lista atual: %d\n", listaAtual);
        printf("Escolha uma opcao do menu acima: ");

        int op, r, i;
        tElemento elem;
        scanf("%d", &op);
        if (op == 0)
            break;
        switch(op){
            case 1:
                printf("Digite o valor do elemento a ser inserido: ");
                scanf("%d", &elem);
                r = InsereEmOrdem(&minhaLista[listaAtual], elem);
                if (r == 0)
                    puts("Elemento inserido com sucesso.");
                break;
            case 2:
                printf("Digite o valor do elemento que quer encontrar: ");
                scanf("%d", &elem);
                r = BuscaBinaria(&minhaLista[listaAtual], elem);
                if (r < 0)
                    printf("Elemento (%d) nao foi encontrado.\n", elem);
                else
                    printf("Elemento (%d) foi encontrado na posicao [%d].\n", elem, r);
                break;
            case 3:
                printf("Digite o INDICE do elemento que deseja remover: ");
                scanf("%d", &i);
                elem = RemoveElemento(&minhaLista[listaAtual], i);
                printf("Elemento (%d) removido do indice [%d].\n", elem, i);
                break;
            case 4:
                printf("Digite o VALOR do elemento que deseja remover: ");
                scanf("%d", &elem);
                elem = RemovePorValor(&minhaLista[listaAtual], elem);
                printf("Elemento (%d) removido.\n", elem);
                break;
            case 5:
                printf("Digite o VALOR dos elementos que deseja remover: ");
                scanf("%d", &elem);
                elem = RemoveTodosComValor(&minhaLista[listaAtual], elem);
                printf("Elementos (%d) removidos.\n", elem);
                break;
            case 6:
                i = -1;
                while(i != 0 && i != 1){
                    printf("Digite a lista que quer trabalhar (0 ou 1): ");
                    scanf("%d", &i);
                }
                listaAtual = i;
                break;
            case 7:
                IntersecaoListas(&minhaLista[0], &minhaLista[1], &minhaLista[2]);
                printf("Resultado: ");
                ExibeLista(&minhaLista[2]);
                break;
            case 8:
                DeletarDuplicata(&minhaLista[listaAtual]);
                break;
            case 9:
                ExibeLista(&minhaLista[listaAtual]);
                break;
        }

    }

    puts("Obrigado, de nada.");

    return 0;
}

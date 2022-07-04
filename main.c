#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "exame.c"

void verifica(bool teste, char* mensagem){
    char resultado[50];
    strcpy(resultado, (teste ? "OK" : "FALHOU"));
    printf("[%s] - %s\n", resultado, mensagem);
}

void imprimeCabecalho(char* mensagem){
    printf("\n");
    printf("----------------------------------- \n");
    printf("%s \n", mensagem);
    printf("----------------------------------- \n");
}

void teste_lista_compara(){
    Lista* l1 = lista_criar();
    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    
    Lista* l2 = lista_criar();
    lista_anexar(l2, 10);
    lista_anexar(l2, 20);
    lista_anexar(l2, 30);
    
    imprimeCabecalho("Teste lista_compara");
    verifica(lista_comparar(l1,l2) == true, "Listas iguais");

    Lista* l3 = lista_criar();
    lista_anexar(l3, 2);
    lista_anexar(l3, 4);
    lista_anexar(l3, 6);
    lista_anexar(l3, 8);
    
    Lista* l4 = lista_criar();
    lista_anexar(l4, 2);
    lista_anexar(l4, 3);
    lista_anexar(l4, 8);
    lista_anexar(l4, 6);
    
    verifica(lista_comparar(l3,l4) == false, "Listas diferentes");
}

void teste_lista_soma(){
    imprimeCabecalho("Teste lista_soma");

    Lista* l1 = lista_criar();
    verifica(lista_soma(l1) == -1, "Lista vazia");

    lista_anexar(l1, 2);
    lista_anexar(l1, 4);
    lista_anexar(l1, 6);
    lista_anexar(l1, 8);
    
    verifica(lista_soma(l1) == 20, "Soma");
}

void teste_lista_max(){
    imprimeCabecalho("Teste lista_max");

    Lista* l1 = lista_criar();
    verifica(lista_max(l1) == -1, "Lista vazia");

    lista_anexar(l1, 2);
    lista_anexar(l1, 4);
    lista_anexar(l1, 6);
    lista_anexar(l1, 8);
    
    verifica(lista_max(l1) == 8, "Max");
    lista_inserir(l1, 10, 0);
    verifica(lista_max(l1) == 10, "Max");
    lista_inserir(l1, 20, 3);
    verifica(lista_max(l1) == 20, "Max");
}

void teste_lista_insereTodos(){
    imprimeCabecalho("Teste lista_insereTodos");

    Lista* l1 = lista_criar();
    int v1[] = {2,4,6,8};

    lista_insereTodos(l1, v1, 4);
    char str[500];
    lista_toString(l1, str);
    verifica(strcmp(str, "[2,4,6,8]")==0, "Insere todos");

    int v2[] = {10,55,13,25};
    lista_insereTodos(l1, v2, 4);
    lista_toString(l1, str);
    verifica(strcmp(str, "[2,4,6,8,10,55,13,25]")==0, "Insere todos");
}

void teste_lista_duplicar(){
    imprimeCabecalho("Teste lista_duplicar");

    Lista* l1 = lista_criar();
    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    lista_anexar(l1, 40);
    lista_anexar(l1, 50);
    Lista* l2 = lista_duplicar(l1);

    char str[500];
    lista_toString(l2, str);
    verifica(strcmp(str, "[10,20,30,40,50]")==0, "Duplicar");
    
    lista_inserir(l1, 5, 0);
    lista_anexar(l2, 60);

    lista_toString(l1, str);
    verifica(strcmp(str, "[5,10,20,30,40,50]")==0, "Lista 1");
    
    lista_toString(l2, str);
    verifica(strcmp(str, "[10,20,30,40,50,60]")==0, "Lista 2");
}

void teste_lista_interseccao(){
    imprimeCabecalho("Teste lista_interseccao");

    Lista* l1 = lista_criar();
    lista_anexar(l1, 10);
    lista_anexar(l1, 20);
    lista_anexar(l1, 30);
    lista_anexar(l1, 40);
    lista_anexar(l1, 50);

    Lista* l2 = lista_criar();
    lista_anexar(l2, 50);
    lista_anexar(l2, 40);
    lista_anexar(l2, 31);
    lista_anexar(l2, 20);
    lista_anexar(l2, 11);
    
    Lista* l3 = lista_interseccao(l1,l2);

    char str[500];
    lista_toString(l3, str);
    printf("%s\n", str);
    verifica(strcmp(str, "[20,40,50]")==0, "Interseccao");
}


int main(){
//    teste_lista_compara();
//   teste_lista_soma();
    teste_lista_max(); //ERRO
//    teste_lista_insereTodos();
//    teste_lista_duplicar();
//    teste_lista_interseccao();
    return 0;
}
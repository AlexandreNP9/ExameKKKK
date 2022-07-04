#ifndef _LISTA_H_
#define _LISTA_H_


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define TAM 100
typedef int TipoElemento;



/**************************************
* DADOS
**************************************/
typedef struct no{
    struct no* ant;
    struct no* prox;
    TipoElemento dado;
}No;

typedef struct{
    No* inicio;
    No* fim;
    int qtde;
}Lista;


/**************************************
* PROTÓTIPOS
**************************************/
Lista* lista_criar();
void lista_destruir(Lista** endLista);
bool lista_anexar(Lista* l, TipoElemento elemento);
bool lista_inserir(Lista* l, TipoElemento elemento, int posicao);
bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco);
int lista_removerElemento(Lista* l, TipoElemento elemento);
bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista* l, TipoElemento elemento);
bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco);
int lista_tamanho(Lista* l);
bool lista_vazia(Lista* l);
bool lista_toString(Lista* l, char* str);


/**************************************
* FUNÇÕES AUXILIARES
**************************************/
bool lista_ehValida(Lista* l){    
    return (l != NULL? true: false);    
}

No* criar_no(TipoElemento elemento){
    No* no = (No*) malloc(sizeof(No));    
    no->dado = elemento;
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

bool posicao_ehValida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos > l->qtde) return false;

    return true;
}

bool posicao_ehPreenchida(Lista* l, int pos){
    if(pos < 0) return false;
    if(pos >= l->qtde) return false;

    return true;
}

No* enderecoNo(Lista* l, int pos){
    No* aux = l->inicio;
    for(int cont = 0; cont < pos; cont++){
        aux = aux->prox;
    }
    return aux;
}

int convertePosicao(Lista* l, int pos){
    return pos < 0 ? l->qtde+pos : pos;
}

/**************************************
* IMPLEMENTAÇÃO DAS FUNÇÕES
**************************************/
Lista* lista_criar(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtde = 0;
    return lista;
}

void lista_destruir(Lista** endLista){
    Lista* l = *endLista;
    No* aux;
    while(l->inicio != NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }    
    free(l);
    *endLista = NULL;
}

bool lista_anexar(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    No* novo = criar_no(elemento);
    if(lista_vazia(l)){
        l->inicio = novo;        
    }else{
        l->fim->prox = novo;
        novo->ant = l->fim;
    }
    l->fim = novo;
    l->qtde++;
    return true;
}

bool lista_inserir(Lista* l, TipoElemento elemento, int posicao){
    if(!lista_ehValida(l)) return false;    
    posicao = convertePosicao(l, posicao);
    if(!posicao_ehValida(l, posicao)) return false;

    No* novo = criar_no(elemento);
    if(lista_vazia(l)){
        l->inicio = novo;
        l->fim = novo;
        l->qtde++;
    }else if(posicao == l->qtde){
        lista_anexar(l, elemento);
    }else if(posicao == 0){
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
        l->qtde++;
    }else{
        No* aux = enderecoNo(l,posicao-1);        

        novo->prox = aux->prox;
        novo->ant = aux;
        novo->prox->ant = novo;
        aux->prox = novo;  
    }
    return true;
}

bool lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false;
    if(lista_vazia(l)) return false;
    posicao = convertePosicao(l, posicao);
    if(!posicao_ehPreenchida(l, posicao)) return false;

    
    No* aux;
    if(l->qtde == 1){
    
        aux = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;

    }else if(posicao == 0){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        l->inicio->ant = NULL;
        aux->prox = NULL;

    }else if(posicao == l->qtde-1){
        aux = l->fim;
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        aux->ant = NULL;
    }else{
        aux = enderecoNo(l, posicao);
        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        aux->prox = NULL; 
        aux->ant = NULL; 
    }
    *endereco = aux->dado;
    free(aux);
    l->qtde--;
    return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return false;

    int posicao = lista_posicao(l, elemento);
    if(posicao == -1) return -1;
    TipoElemento item;
    lista_removerPosicao(l, posicao, &item);
    return posicao;
}

bool lista_substituir(Lista* l, int posicao, TipoElemento novoElemento){
    if(!lista_ehValida(l)) return false;    
    if(!posicao_ehValida(l, posicao)) return false;

    No* no = enderecoNo(l, posicao);
    no->dado = novoElemento;
    return true;
}

int lista_posicao(Lista* l, TipoElemento elemento){
    if(!lista_ehValida(l)) return -1;    

    int pos = 0;
    No* aux = l->inicio;
    while(aux != NULL){
        if(elemento == aux->dado) return pos;
        pos++;
        aux = aux->prox;
    }
    return -1;  
}

bool lista_buscar(Lista* l, int posicao, TipoElemento* endereco){
    if(!lista_ehValida(l)) return false; 
    posicao = convertePosicao(l, posicao);   
    if(!posicao_ehValida(l, posicao)) return false;

    No* no = enderecoNo(l, posicao);
    *endereco = no->dado;
    return true;
}

int lista_tamanho(Lista* l){
    if(!lista_ehValida(l)) return -1;

    return l->qtde;
}

bool lista_vazia(Lista* l){
    if(!lista_ehValida(l)) return true;

    return (l->qtde == 0 ? true : false);
}

bool lista_toString(Lista* l, char* str){
    if(!lista_ehValida(l)) return false;

    int qtde = 0;
    char elemento[TAM];
    
    str[0] = '\0';
    strcat(str, "[");
    No* aux = l->inicio;
    while(aux != NULL){
        sprintf(elemento, "%d", aux->dado);        
        strcat(str, elemento);
        
        if(aux->prox != NULL) strcat(str, ",");

        aux = aux->prox;
    }

    strcat(str, "]");
    return true;
}

#endif
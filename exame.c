#include "lista_encadeada.c"


/**
 * Compara 2 listas. 
 * Devolver true se l1 e l2 forem iguais e false caso contrário.
 * As listas são consideradas iguais se todos os elementos forem iguais e ocuparem as mesmas posições
 * Por exemplo, [1,2,3] é diferente [1,3,2]
 * Em caso de erro, a função deve devolver false
 */
bool lista_comparar(Lista* l1, Lista* l2){
    No* atual1 = l1->inicio;
    No* atual2 = l2->inicio;

    //verifica se são de tamanhos diferentes, logo diferentes
    if (l1->qtde != l2->qtde){
        return false;
    
    //verifica se são de tamanhos iguais
    } else {
        //percorre o tamanho das listas e compara elemento por elemento do nó, a partir do 2o nó
        for (int i = 0; i<l1->qtde; i++){
            if (atual1->dado != atual2->dado){ 
                return false;
                } else {
                atual1 = atual1->prox;
                atual2 = atual2->prox;
            }
        }
    }

    //se não caiu em nenhuma das validações acima, logo é verdadeiro
    return true;
}

/**
 * Devolve a soma de os valores contidos na lista
 * Em caso de erro, a função deve devolver -1
 * 
 */
int lista_soma(Lista* l){
    int soma = 0;
    No* atual = l->inicio;

    if (lista_vazia(l)){
        return -1;

    } else {

        for (int i = 0; i < l->qtde; i++){
            soma = soma + atual->dado;
            atual = atual->prox;
        }

    }
    return soma;
}

/**
 * Devolve o maior elemento da lista
 * Em caso de erro, a função deve devolver -1
 * 
 */
int lista_max(Lista* l){
    int maior = l->inicio->dado;
    No* atual = l->inicio;

    if (lista_vazia(l)){
        return -1;

    } else {

        for (int i = 0; i < l->qtde; i++){
            
            if (atual->dado > maior){
                maior = atual->dado;
            }

            atual = atual->prox;
        }

    }
    return maior;
}

/**
 * Insere na lista todos os elementos contidos no vetor recebido por parâmetro
 * Devolve o tamanho da lista após a inserção de todos os elementos. 
 * Devolver -1 caso não ocorra nenhuma inserção
 */
int lista_insereTodos(Lista* l, int* vetor, int tamVetor){
    int tamListaOriginal = l->qtde;
    No* novoNo;

    for (int i = 0; i < tamVetor; i++){
        lista_anexar(l, vetor[i]);
    }

    if (tamListaOriginal = l->qtde){
        return -1;
    } else {
        return l->qtde;
    }
}

/**
 * Cria um clone da lista. A lista duplicada deve ser independente da original.
 * Devolve o clone da lista l.
 */
Lista* lista_duplicar(Lista* l){
    Lista* nova = lista_criar();
    No* atual = l->inicio;

    for (int i = 0; i < l->qtde; i++){
        lista_anexar(nova, atual->dado);
        atual = atual->prox;
    }

    return nova;
}

/**
 * Cria e devolve uma nova lista com somente os elementos que estão contidos nas 2 listas
 * Os elementos NÃO precisar estar nas mesmas posições
 * A: [2,4,6,8,10]  B:[10,3,4] = [4,10]
 * A: [2,4,6,8,10]  B:[12,3,5] = []
 * A: []            B:[12,3,5] = NULL
 * A: [2,4,6,8,10]  B:[]       = NULL
 * 
 * A função deve devolver o endereço da lista criada. 
 * - Em caso de erro, a função deve devolver NULL
 * - Caso não haja elementos em comum, a função deve devolver o endereço da lista vazia. 
 * 
 */
Lista* lista_interseccao(Lista* l1, Lista* l2){
    Lista* inter = lista_criar(); //lista intersecção
    if (!lista_ehValida(l1) || !lista_ehValida(l2)){
        return NULL;
    } else {
        No* eL1 = l1->inicio; //elemento de L1
        for (int i = 0; i < l1->qtde; i++){

            No* eL2 = l2->inicio; //elemento de L2
            for (int j = 0; j < l2->qtde; j++){
                if (eL1->dado == eL2->dado){
                    lista_anexar(inter, eL1->dado);
                }
                eL2 = eL2->prox;
            }
            eL1 = eL1->prox;
        }

        if (lista_ehValida(inter)){
            return inter;
        } else {
            return NULL;
        }
    } 
}
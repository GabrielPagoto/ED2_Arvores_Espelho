#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include<bits/stdc++.h>
using namespace std;
 
/* Estrutura de um n�, com o valor do n� e 
	um ponteiro para o n� da esquerda e outro para o da dirteita */
struct Node
{
    int valor;
    Node* esq, *dir;
};

/* Aloca mem�ria para um novo n� */
Node * novoNode(int valor)
{
    Node* node = new Node;
    node->valor  = valor;
    node->esq  =  node->dir  = NULL;
    return(node);
}
 
/* Dado duas �rvores, retorna 1 caso sejam iguais, 0 caso contr�rio*/
int eh_espelho(Node* a, Node* b)
{
    /* Caso base : ambas vazias */
    if (a == NULL && b == NULL)
        return 1;
 
    // Apenas uma � vazia
    if (a == NULL || b == NULL)
        return 0;
 
    /* Ambas n�o vazias, compara��o entre elas recursivamente
     Alternando o valor da esquerda e direita entre eles */
    return  a->valor == b->valor &&
            eh_espelho(a->esq, b->dir) &&
            eh_espelho(a->dir, b->esq);
}

/* Dado duas �rvores, retorna 1 caso sejam iguais, 0 caso contr�rio*/
Node * cria_espelho(Node* a)
{
	if (a == NULL) {
        Node *raiz = NULL;
        return raiz;
    }
	
    Node *raiz = novoNode(a->valor);
    
    if(a->esq != NULL){
    	raiz->dir = cria_espelho(a->esq);
	}
	if(a->dir != NULL){
    	raiz->esq = cria_espelho(a->dir);
	}	
	return raiz;
}
 
void imprime_arvore(Node* a){
	if(a == NULL) {
		return;
	}
	imprime_arvore(a->esq);
	printf(" %d", a->valor);
	imprime_arvore(a->dir);
} 
 

 
/* Driver program to test saoIguais() */
int main()
{
    Node *raiz1 = novoNode(1);
    Node *raiz2 = novoNode(1);
    											/*         1          */  
    raiz1->esq = novoNode(3);					/*       /   \        */		  
    raiz1->dir = novoNode(2);					/*      3     2       */		  
    raiz1->dir->esq  = novoNode(5);				/*          /   \     */ 	
    raiz1->dir->dir = novoNode(4);				/*         5     4    */			
 
 												/*         1          */ 
    raiz2->esq = novoNode(2);					/*       /   \        */
    raiz2->dir = novoNode(3);					/*      2     3       */
    raiz2->esq->esq = novoNode(4);				/*    /   \           */
    raiz2->esq->dir = novoNode(5);		    	/*   4    5           */
 	
 	int retorno = eh_espelho(raiz1, raiz2);
 	printf("O retorno da funcao eh_espelho eh : ");
 	printf("%d", retorno);
 
 	printf("\n----------------------------\n");
 
 	Node *espelho = cria_espelho(raiz1);
 	printf("O retorno da arvore eh_espelho eh : (a ordem esta esq/mei/dir)\n");
 	imprime_arvore(espelho);
 	/*	Exemplo do retorno acima  */
 	/*		  ( 4 2 5 1 3 )       */
 	/*               1            */ 
    /*             /   \          */
    /*            2     3         */
    /*          /   \             */
    /*         4    5             */
 	
    return 0;
}

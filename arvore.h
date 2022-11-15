#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#pragma once

//------- Inclusoes

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//-------- Fim Inclusoes


//-------- Constantes

#define SUCESSO (0)
#define TRUE (1==1)
#define FALSE (1!=1)
#define max2(a,b) ((a >b)? a : b)
#define TAM_MAX 100

//-------- Fim Constantes


//-------- Dado Armazenado Arvore

typedef struct casal_s1 info_t1;

struct casal_s1{
    char person1[TAM_MAX];
    int size1;
    char person2[TAM_MAX];
    int size2;
    int altura;
};
typedef struct casal_s1 casal_t1;

//-------- Fim Dado Armazenado Arvore


//-------- Estrutura Arvore

struct arvore_s {
	info_t1 dadoArmazenado;
	struct arvore_s* esquerda;
	struct arvore_s* direita;
};

typedef struct arvore_s arvore_t;

//-------- Fim Estrutura Arvore


//-------- Modelagem de Funcoes de Manipulacao e tipos

typedef uint32_t boolean_t;

typedef void(*imprimirDado_f1)(info_t1 dadoImprimir);
typedef void(*atribuirDado_f1)(info_t1* enderecoArmazenar, info_t1 dadoArmazenar);
typedef int(*compararDado_f1)(info_t1 dadoUm, info_t1 dadoDois);

//-------- Fim Modelagem de Funcoes de Manipulacao e tipos


//-------- Enumeracao

enum lado_s {
	ladoEsquerdo,
	ladoDireito
};

typedef enum lado_s lado_t;

enum ordemExibir_s {
	preOrdem,
	simetrica,
	posOrdem
};

typedef enum ordemExibir_s ordemExibir_t;

//-------- Fim Enumeracao


//-------- Assinatura Funcoes Arvore

void preencheFolha(info_t1* enderecoArmazenar, info_t1 dadoArmazenar);
arvore_t* criaArvoreVazia();
arvore_t* insereOrdenadoArvore(arvore_t* arvore, info_t1 dado, atribuirDado_f1 metodoAtribuicao, compararDado_f1 metodoComparacao);
boolean_t arvoreVazia(arvore_t* arvore);
void imprimeArvore(arvore_t* arvore, imprimirDado_f1 metodoImpressao, ordemExibir_t ordemExibicao);
arvore_t* liberaArvore(arvore_t* arvore);
boolean_t infoPertenceArvoreBinaria(arvore_t* arvore, info_t1 info, compararDado_f1 metodoComparacao);
int alturaArvore(arvore_t* arvore);
void imprimirArvoreSimples(info_t1 dadoImprimir);
int compararDado(info_t1 dadoUm, info_t1 dadoDois);

//-------- Fim Assinatura Funcoes Arvore

#endif // ARVORE_H_INCLUDED

//------- Inclusoes

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "arvore.h"

//-------- Fim Inclusoes

#define max2(a,b) ((a >b)? a : b)


//-------- Funcoes Arvore

arvore_t* criaArvoreVazia() {
	return NULL;
}

void preencheFolha(info_t1* enderecoArmazenar, info_t1 dadoArmazenar){
    strcpy(enderecoArmazenar->person1, dadoArmazenar.person1);
    enderecoArmazenar->size1 = dadoArmazenar.size1;
    strcpy(enderecoArmazenar->person2, dadoArmazenar.person2);
    enderecoArmazenar->size2 = dadoArmazenar.size2;
    enderecoArmazenar->altura = dadoArmazenar.altura;
}

arvore_t* insereOrdenadoArvore(arvore_t* arvore, info_t1 dado, atribuirDado_f1 metodoAtribuicao, compararDado_f1 metodoComparacao) {

	if (arvore == NULL) { // Caso Base
		arvore = malloc(sizeof(arvore_t));

		if (arvore != NULL) {
			metodoAtribuicao(arvore, dado);
			arvore->esquerda = NULL;
			arvore->direita = NULL;
		}
	}
	else if (metodoComparacao(arvore->dadoArmazenado, dado) < 0) {
        dado.altura+=1;
		arvore->esquerda = insereOrdenadoArvore(arvore->esquerda, dado, metodoAtribuicao, metodoComparacao);
	}
	else {
        dado.altura+=1;
		arvore->direita = insereOrdenadoArvore(arvore->direita, dado, metodoAtribuicao, metodoComparacao);
	}

	return arvore;
}

boolean_t arvoreVazia(arvore_t* arvore) {
	return arvore == NULL;
}

void imprimeArvore(arvore_t* arvore, imprimirDado_f1 metodoImpressao, ordemExibir_t ordemExibicao) {

	if (!arvoreVazia(arvore)) {

		switch (ordemExibicao) {
		case preOrdem:
			metodoImpressao(arvore->dadoArmazenado);
			imprimeArvore(arvore->esquerda, metodoImpressao, ordemExibicao);
			imprimeArvore(arvore->direita, metodoImpressao, ordemExibicao);
			break;

		case posOrdem:
			imprimeArvore(arvore->esquerda, metodoImpressao, ordemExibicao);
			imprimeArvore(arvore->direita, metodoImpressao, ordemExibicao);
			metodoImpressao(arvore->dadoArmazenado);
			break;

		default:
			imprimeArvore(arvore->esquerda, metodoImpressao, ordemExibicao);
			metodoImpressao(arvore->dadoArmazenado);
			imprimeArvore(arvore->direita, metodoImpressao, ordemExibicao);
			break;
		}
	}
}

arvore_t* liberaArvore(arvore_t* arvore) {
	if (!arvoreVazia(arvore)) {
		liberaArvore(arvore->esquerda);
		liberaArvore(arvore->direita);;
		free(arvore);
	}
	return NULL;
}

boolean_t infoPertenceArvoreBinaria(arvore_t* arvore, info_t1 info, compararDado_f1 metodoComparacao) {
	boolean_t pertece = FALSE;

	if (!arvoreVazia(arvore)) {
		pertece = (metodoComparacao(arvore->dadoArmazenado, info)
			|| infoPertenceArvoreBinaria(arvore->esquerda, info, metodoComparacao)
			|| infoPertenceArvoreBinaria(arvore->direita, info, metodoComparacao));
	}

	return pertece;
}

int alturaArvore(arvore_t* arvore) {
	int niveisCaminhados = 0;

	if (arvoreVazia(arvore)) {
		niveisCaminhados = -1;
	}
	else {
		niveisCaminhados = 1 + max2(alturaArvore(arvore->esquerda), alturaArvore(arvore->direita));
	}

	return niveisCaminhados;
}

void imprimirArvoreSimples(info_t1 dadoImprimir){
    printf("%i - %s e %s \n", dadoImprimir.altura, dadoImprimir.person1, dadoImprimir.person2);
}

int compararDado(info_t1 dadoUm, info_t1 dadoDois){
    int retorno = 0;
    if(dadoUm.size1 < dadoDois.size1)
        retorno = -1;
    else if(dadoUm.size1 > dadoUm.size1)
        retorno = 1;
    else {
        if(dadoUm.size2 > dadoDois.size2)
            retorno = 1;
        else
            retorno = -1;
    }
    return retorno;
}

//-------- Fim Funcoes Arvore

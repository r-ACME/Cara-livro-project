/**
 * @file   lista.c
 * @author Raphael Menezes
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"
#include "define.h"
#include "hash.h"
#include "lista.h"

/* Constantes */

/* Fun��es */

/**
 * Fun��o de cria��o.
 * @param hash Pointer pointer do hash a ser criada
 * @return Verdadeiro para conseguiu criar, falso para n�o.
 */
bool_t hash_cria(hash_likes_t **my_hash, int pattern_size) {
    //(*my_hash) = malloc(sizeof(hash_likes_t));

    hash_likes_t **temp = hash;

    for(int i = 0; i < pattern_size; i++){
        (*temp) = malloc(sizeof(hash_likes_t));
        (*temp)->size_pattern = pattern_size;
        (*temp)->pattern = i;
        (*temp)->next_pattern = NULL;
        (*temp)->likes = 0;
        temp = (*temp)->next_pattern;
    }
    return VERDADEIRO;
}

bool_t hash_insere(hash_likes_t *my_hash, likes_t new_like){

    hash_likes_t *current = hash;

    int pattern = new_like.id_user % current->size_pattern;

    while(current->pattern != pattern){
        current = current->next_pattern;
    }

    if(current->likes == NULL){
        lista_cria_like(current->likes);
    }
    lista_insere_ordenado_like(current->likes, new_like);

    current->likes++;

    return VERDADEIRO;
}


bool_t hash_remove(hash_likes_t *my_hash, likes_t like_to_remove){

    hash_likes_t *current = hash;

    int pattern = like_to_remove.id_user % current->size_pattern;

    while(current->pattern != pattern){
        current = current->next_pattern;
    }

    if(current->likes == NULL){
        return FALSO;
    }
    lista_remove_like(current->likes, like_to_remove);

    current->likes++;

    return VERDADEIRO;
}

bool_t hash_confere_like(hash_likes_t *my_hash, likes_t user){

    hash_likes_t *current = hash;

    int pattern = user.id_user % current->size_pattern;

    while(current->pattern != pattern){
        current = current->next_pattern;
    }

    return lista_confere_user(current->likes, user);
}





#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#pragma once

/**
 * @file   hash.h
 * @brief  Arquivo com a defini��o das fun��es de hash
 *         utilizados na prova de AEDS.
 * @author Raphael Menezes
 * @date   2022-11-19
 */

/* Inclus�es */
#include "define.h"
#include "data.h"
/* Constantes */

/* C�digos de Erros */

/* Tipos */




/* Fun��es Exportadas */


bool_t hash_cria(hash_likes_t **my_hash, int pattern_size);
bool_t hash_insere(hash_likes_t *my_hash, likes_t new_like);
bool_t hash_remove(hash_likes_t *my_hash, likes_t like_to_remove);
bool_t hash_confere_like(hash_likes_t *my_hash, likes_t user);




#endif // HASH_H_INCLUDED

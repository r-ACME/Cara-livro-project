/**
 * @file   data.c
 * @brief  Arquivo com as implementações das funções de manuseio de dados
 * @author Raphael Menezes
 * @date   2022-11-10
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "data.h"


/*
 * Funções para struct de profile
 */


bool_t valida_id(int id){
    //se id existir, retornar falso
    return VERDADEIRO;
}

bool_t valida_senha(char user[TAM_MAX], char password[TAM_MAX_SENHA]){
    //procura usuário por login e validar se a senha é a recebida
    return VERDADEIRO;
}



bool_t preenche_perfil(profile_t * profile, profile_t new_profile){

    (*profile).id = new_profile.id;
    strcpy( (*profile).name, new_profile.name );
    strcpy( (*profile).login, new_profile.login );
    strcpy( (*profile).password, new_profile.password);
    //posts
    //amigos
    (*profile).deleted = FALSO;

    return VERDADEIRO;
}






/*
 * Funções para struct de postagem
 */

 /* Função não será mais utilizada pois será utilizado um campo para contar as curtidas
int conta_likes(hash_likes_t *recived){
    likes_t *current = recived->user;
    hash_likes_t *next = recived->next_like;

    if(current == NULL){
        return 0;
    }
    int count = 0;

    while(next != NULL){
        if( (*current).like)
            count++;
        current = (*next).user;
        next = (*next).next_like;
    }
    return count;
}*/

bool_t grava_post(post_t *novo, post_t *new_post){

    novo->id = new_post->id;
    strcpy(&novo->info, new_post->info);
    novo->post_likes = (hash_likes_t *) malloc(sizeof(hash_likes_t));
    if(preenche_data_post(&novo->publish_at) == FALSO)
        return FALSO;
    novo->active = VERDADEIRO;

    return VERDADEIRO;
}


bool_t grava_like(likes_t *novo, likes_t new_like){

    novo->id_user = new_like.id_user;
    novo->like = new_like.like;

    return VERDADEIRO;
}












/*
 * Funções para struct de datas
 */



bool_t preenche_data(date_t * date, date_t new_date){

    //preencher com data especifica
    (*date).year = new_date.year;
    (*date).month = new_date.month;
    (*date).day = new_date.day;
    (*date).hour = new_date.hour;
    (*date).minutes = new_date.minutes;
    (*date).seconds = new_date.seconds;

    return VERDADEIRO;
}

bool_t preenche_data_post(date_t *date){

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //preencher com data da gravação
    (*date).year = tm.tm_year;
    (*date).month = tm.tm_mon;
    (*date).day = tm.tm_mday;
    (*date).hour = tm.tm_hour;
    (*date).minutes = tm.tm_min;
    (*date).seconds = tm.tm_sec;

    return VERDADEIRO;
}

bool_t imprime_data_post(date_t *date){
    if(date == NULL)
        return FALSO;
    printf("%i/%i/%i - %i:%i:%i", (*date).month, (*date).day, (*date).year, (*date).hour, (*date).minutes, (*date).seconds);
}















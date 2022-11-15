#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "define.h"

#pragma once

typedef unsigned char bool_t;

struct likes_s{ //Estrutura para armazenar se 1 usuário curtiu o post
    int id_user;
    bool_t like;
}; typedef struct likes_s likes_t;

//Hash
typedef struct hash_likes_s hash_likes_t;
struct hash_likes_s{ //Estrutura para armazenar a relação de varias curtidas em 1 post
    likes_t *user;
    hash_likes_t *next_like;
};

struct date_s{ //Estrutura para armazenar e preencher uma data para as publicações
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
}; typedef struct date_s date_t;

typedef struct post_s post_t;
struct post_s{ //Estrutura para armazenar uma publicação
    int id;
    date_t publish_at;
    char info[TAM_MAX_POST];
    hash_likes_t *post_likes;
    bool_t active;
};

//lista
typedef struct my_posts_s my_posts_t;
struct my_posts_s{ //Estrutura para relacionar as publicações com um usuário
    my_posts_t *prev_post;
    post_t *my_post;
    my_posts_t *next_post;
    int qtd_posts;
};


//grafo
typedef struct graph_profiles_s graph_profiles_t;
struct graph_profiles_s{ //Estrutura para armazenar a lista de amigos do usuários
    int profile_friend_id;
    bool_t friended;
    graph_profiles_t *next_friend;
};


struct profile_s{ //Estrutura para armazenar um usuário
    int id;
    char name[TAM_MAX];
    char login[TAM_MAX];
    char password[TAM_MAX_SENHA];
    my_posts_t posts;
    graph_profiles_t follow_list;
    bool_t deleted;
};typedef struct profile_s profile_t;




//Functions


bool_t valida_senha(char user[TAM_MAX], char password[TAM_MAX_SENHA]);
bool_t preenche_perfil(profile_t * profile, profile_t new_profile);
int conta_likes(hash_likes_t *recived);
bool_t grava_post(post_t *novo, post_t *new_post);
bool_t preenche_data(date_t * date, date_t new_date);
bool_t preenche_data_post(date_t *date);
bool_t imprime_data_post(date_t *date);

#endif // DATA_H_INCLUDED

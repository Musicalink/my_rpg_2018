/*
** EPITECH PROJECT, 2018
** rpg.h
** File description:
** main include for rpg
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfText *play;
    sfText *exit;
    sfText *main;
    sfFont *font;
    int launch_game;
} menu_t;

typedef struct stats {
    int level;
    int xp;
    int hp;
    int hp_max;
    int atk;
    int def;
    sfText *level_t;
    sfText *hp_t;
    sfText *atk_t;
    sfText *def_t;
} stats_t;

typedef struct anim {
    sfSprite *spr;
    sfTexture *txt;
    sfIntRect rect;
    int frame;
    sfClock *clock;
    sfVector2f size;
} anim_t;

typedef struct moving {
    sfSprite *s_right;
    sfTexture *t_right;
    sfSprite *s_left;
    sfTexture *t_left;
    sfSprite *s_up;
    sfTexture *t_up;
    sfSprite *s_down;
    sfTexture *t_down;
    sfIntRect rect;
} moving_t;

typedef struct stuff {
    anim_t *anim;
    int type;
    int lvl;
    int atk;
    int def;
    int hp;
} stuff_t;

typedef struct player {
    stats_t *stats;
    stuff_t **stuff;
    stuff_t **inventory;
    moving_t *move;
} player_t;

typedef struct bhud {
    sfRectangleShape *hp;
    sfRectangleShape *xp;
    sfRectangleShape *ene_hp;
    sfText *lvl;
    sfFont *font;
} bhud_t;

typedef struct loots {
    sfSprite *s_back;
    sfTexture *t_back;
    sfFont *font;
    sfText *status;
    sfText *xp;
    sfText *loot;
    anim_t *drop;
} loots_t;

typedef struct ebattle {
    int type;
    sfSprite *s_ene;
    sfTexture *t_ene;
    sfIntRect rect;
    sfVector2f size;
    anim_t *flm;
    int frame;
    int action;
    int wait;
    stats_t *stats;
    sfClock *clock;
} ebattle_t;

typedef struct pbattle {
    sfSprite *s_player;
    sfTexture *t_player;
    sfIntRect rect;
    stats_t *stats;
    int action;
    sfClock *clock;
} pbattle_t;

typedef struct battle {
    sfSprite *s_back;
    sfTexture *t_back;
    sfSprite *s_hud;
    sfTexture *t_hud;
    bhud_t *hud;
    pbattle_t *player;
    ebattle_t *enemy;
    int turn;
    int end;
} battle_t;

typedef struct map {
    char *name;
    int y;
    int x;
    sfSprite *sprite;
    sfTexture *texture;
    sfImage *hitbox;
} map_t;

typedef struct inventory {
    int boolean;
    sfSprite *spr;
    sfTexture *tex;
    stuff_t *stuff[10];
} inventory_t;

typedef struct pnj {
    anim_t *a;
    int x;
    int y;
} pnj_t;

typedef struct game {
    ebattle_t **enem;
    player_t *player;
    int y;
    int x;
    sfSprite *moves;
    sfTexture *moves_t[4];
    sfIntRect moves_r;
    sfVector2f p_pos;
    sfClock *clock;
    sfTime time;
    inventory_t *inventory;
    anim_t *stat_spr;
    anim_t *pnj;
    int pnj_increment;
    sfText *pnj_text;
    menu_t *pause;
} game_t;

static const char *QUEST_STR[] = {
    "Eh toi ! Va voir au village forestier si j'y suis !",
    "Je t'ai menti !j'y etait pas ! Va tuer 5 monstres de la foret !",
    "Il t'en reste 4 a tuer !", "Il t'en reste 3 a tuer !",
    "Il t'en reste 2 a tuer !", "Il t'en reste 1 a tuer !",
    "Super ! Va tuer des cailloux dans le desert !",
    "Mouai ... Encore 4 et ca ira !",
    "Bof bof ... Encore 3 et je te laisse y aller!",
    "J'ai volley a 14 heures, depeche toi d'en tuer deux !",
    "J'ai surement deja rate mon cours, il t'en reste un, limace !",
    "Pas trop tot ! Vu le temps que t'as pris, va tuer des monstres de glace !",
    "Tu as pris autant de temps pour un seul monstre ?",
    "J'appelerai ma grand-mere la prochaine fois",
    "Et ca se dit aventurier ? Encore deux ...", "T'es la toi ? Encore un ...",
    "Un gars furax t'attends sur la côte, je t'avais dit de pas tout taper",
    "Bon ... J'ai peut-etre ete un peu mechant, prends un susucre."};

static const sfVector2f INV_POS[] = {{.x = 257, .y = 922}, {.x = 415, .y = 922},
    {.x = 573, .y = 922}, {.x = 731, .y = 922}, {.x = 889, .y = 922},
    {.x = 1047, .y = 922}, {.x = 1205, .y = 922}, {.x = 1363, .y = 922},
    {.x = 1521, .y = 922},};

#endif /*MY_STRUCT_H*/

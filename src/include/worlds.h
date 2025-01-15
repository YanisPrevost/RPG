/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** worlds.h
*/

#ifndef WORLDS_H
    #define WORLDS_H
    #define GET_SIZE sfView_getSize
    #include "../rpg.h"
    #define NUM_PARTICLES 2000
    #define RAIN_SPEED 500.0f
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080

typedef struct {
    sfVector2f position;
    sfVector2f speed;
} rain_t;

typedef struct hub {
    sfMusic* music;
    sfIntRect rect;
    sfClock *clock_hub;
    sfSprite *sprite_perso;
    sfTexture *texture_perso;
    sfTexture *texture_hub;
    sfTexture *texture_hub_night;
    sfSprite *sprite_hub;
    sfSprite *sprite_hub_night;
    sfVector2f movement;
    sfTime time;
    sfImage *hitbox;
    sfVector2f pos_sprite;
    sfColor color;
    sfView *view;
    sfView *normal_view;
    sfSprite *pouilleux;
    sfTexture *Pouilleux;
    sfSprite *bulle;
    sfTexture *Bulle;
    sfSprite *dia_pouill;
    sfTexture *Dia_pouill;
    sfSprite *cadre;
    sfTexture *Cadre;
    sfTexture *Cadre2;
    sfIntRect rect_dia;
    sfClock *clock;
    sfClock *bouche_clock;
    bool is_talking;
    bool prologue_ok;
    sfClock *swap_clock;
    int what_word;
    sfClock *rain_clock;
    rain_t particles[NUM_PARTICLES];
    sfVertexArray *vertexArray;
} hub_t;

typedef struct Loading {
    sfSprite *vert;
    sfSprite *fond;
    sfSprite *text;
    sfTexture *Vert;
    sfTexture *Fond;
    sfTexture *Text;
    sfSprite *back_screen;
    sfTexture *Back_screen;
}Loading_t;

typedef struct Shop {
    sfSprite *shop;
    sfTexture *Shop;
    sfRectangleShape *hooved;
    int hovered_index;
    sfSprite *coin;
    sfTexture *Coin;
    sfText *gold;
    sfSprite *fond;
    sfTexture *Fond;
    sfText *text;
    sfFont *Font;
    bool is_select;
    sfSprite *all_head;
    sfSprite *cursor;
    sfSprite *lock;
    bool is_lock;
    sfVector2f cursor_pose;
    int buyer;
    sfSprite *contour;
    sfClock *buy_clock;
    int num_columns;
    int num_rows;
    int spacing_x;
    int spacing_y;
}Shop_t;

typedef struct interface {
    int who;
    sfSprite *fond_interf;
    sfTexture *Fond_interf;
    bool select_inteface;
    sfSprite *cursor;
    sfTexture *Cursor;
    sfClock *curs_clock;
    int where;
    bool attack_gpy;
    bool attack_gpy2;
    sfVector2f pose_curs;
    int cursor_position;
    int limite_tour;
    sfText *tour;
    bool go_fight;
    int attacker;
    int defender;
    char current_emy;
    int heal_capa;
    bool is_passif_apply;
    bool fake_save;
    sfClock *emy_clock;
    int queue;
}Interface_t;

typedef struct {
    int x;
    int y;
}Position_t;

typedef struct Zone {
    sfSprite *map_cursor_sprite;
    sfTexture *map_cursor_text;
    sfBool is_case_visible;
    sfClock *clock_cursor;
    sfClock *clock_select_perso;
    sfIntRect rect;
    sfSprite *spr_roy;
    sfSprite *spr_infe;
    sfSprite *spr_xmara;
    sfSprite *spr_pate;
    sfSprite *spr_raca;
    sfTexture *txr_roy;
    sfTexture *txr_infe;
    sfTexture *txr_xmara;
    sfTexture *txr_pate;
    sfTexture *txr_raca;
    sfSprite *spr_Boss1;
    sfSprite *spr_Boss2;
    sfSprite *spr_Boss3;
    sfSprite *spr_Boss4;
    sfSprite *spr_Boss5;
    sfSprite *spr_Boss6;
    sfSprite *spr_Boss7;
    sfSprite *spr_Boss8;
    sfTexture *txr_Boss1;
    sfTexture *txr_Boss2;
    sfTexture *txr_Boss3;
    sfTexture *txr_Boss4;
    sfTexture *txr_Boss5;
    sfTexture *txr_Boss6;
    sfTexture *txr_Boss7;
    sfTexture *txr_Boss8;
    sfSprite *spr_emy1_axe;
    sfSprite *spr_emy2_axe;
    sfSprite *spr_emy3_axe;
    sfSprite *spr_emy1_spear;
    sfSprite *spr_emy2_spear;
    sfSprite *spr_emy3_spear;
    sfSprite *spr_emy1_sword;
    sfSprite *spr_emy2_sword;
    sfSprite *spr_emy3_sword;
    sfSprite *spr_emy_mage;
    sfTexture *txr_emy1_axe;
    sfTexture *txr_emy2_axe;
    sfTexture *txr_emy3_axe;
    sfTexture *txr_emy1_spear;
    sfTexture *txr_emy2_spear;
    sfTexture *txr_emy3_spear;
    sfTexture *txr_emy1_sword;
    sfTexture *txr_emy2_sword;
    sfTexture *txr_emy3_sword;
    sfTexture *txr_emy_mage;
    sfRectangleShape *barre_de_vie;
    sfRectangleShape *barre_fond;
    sfText *boss_name;
    sfSprite *image_barre;
    sfTexture *Image_barre;
    Interface_t interface;
}ZoneUniversel_t;

typedef struct Zone1 {
    sfView *view_w1;
    sfSprite *w1_map;
    sfTexture *w1_Map;
    bool is_w1_clear;
    char **tab_map;
}Zone1_t;

typedef struct Zone2 {
    sfView *view_w2;
    sfSprite *w2_map;
    sfTexture *w2_Map;
    bool is_w2_clear;
    char **tab_map;
}Zone2_t;

typedef struct Zone3 {
    sfView *view_w3;
    sfSprite *w3_map;
    sfTexture *w3_Map;
    bool is_w3_clear;
    char **tab_map;
}Zone3_t;

typedef struct Zone4 {
    sfView *view_w4;
    sfSprite *w4_map;
    sfTexture *w4_Map;
    bool is_w4_clear;
    char **tab_map;
}Zone4_t;

typedef struct Zone5 {
    sfView *view_w5;
    sfSprite *w5_map;
    sfTexture *w5_Map;
    bool is_w5_clear;
    char **tab_map;
}Zone5_t;

typedef struct Zone6 {
    sfView *view_w6;
    sfSprite *w6_map;
    sfTexture *w6_Map;
    bool is_w6_clear;
    char **tab_map;
}Zone6_t;

typedef struct Zone7 {
    sfView *view_w7;
    sfSprite *w7_map;
    sfTexture *w7_Map;
    bool is_w7_clear;
    char **tab_map;
}Zone7_t;

typedef struct Zone8 {
    sfView *view_w8;
    sfSprite *w8_map;
    sfTexture *w8_Map;
    bool is_w8_clear;
    char **tab_map;
}Zone8_t;

#endif

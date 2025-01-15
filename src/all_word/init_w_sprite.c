/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_w_sprite.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void init_other_sprites(Global_t *m)
{
    m->univ.barre_de_vie = sfRectangleShape_create();
    sfRectangleShape_setSize(m->univ.barre_de_vie, (sfVector2f){400, 30});
    sfRectangleShape_setFillColor(m->univ.barre_de_vie,
    sfColor_fromRGB(159, 5, 169));
    m->univ.barre_fond = sfRectangleShape_create();
    sfRectangleShape_setSize(m->univ.barre_fond, (sfVector2f){400, 30});
    sfRectangleShape_setFillColor(m->univ.barre_fond,
    sfColor_fromRGB(128, 128, 128));
    m->univ.Image_barre = SET_TX("assets/fight/Barre_boss.png", NULL);
    m->univ.image_barre = sfSprite_create();
    sfSprite_setTexture(m->univ.image_barre, m->univ.Image_barre, sfFalse);
}

void load_texte_map(Global_t *m)
{
    m->zone1.view_w1 = sfView_createFromRect((sfFloatRect){0, 0, 1203, 802});
    m->zone2.view_w2 = sfView_createFromRect((sfFloatRect){0, 0, 1204, 799});
    m->zone3.view_w3 = sfView_createFromRect((sfFloatRect){0, 0, 1204, 802});
    m->zone4.view_w4 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone5.view_w5 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone6.view_w6 = sfView_createFromRect((sfFloatRect){0, 0, 1207, 799});
    m->zone7.view_w7 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone8.view_w8 = sfView_createFromRect((sfFloatRect){0, 0, 1200, 801});
}

void load_sprite_map(Global_t *m)
{
    m->zone1.w1_map = sfSprite_create();
    m->zone1.w1_Map = SET_TX("maps/map1/map1.png", NULL);
    m->zone2.w2_map = sfSprite_create();
    m->zone2.w2_Map = SET_TX("maps/map2/map2.png", NULL);
    m->zone3.w3_map = sfSprite_create();
    m->zone3.w3_Map = SET_TX("maps/map3/map3.png", NULL);
    m->zone4.w4_map = sfSprite_create();
    m->zone4.w4_Map = SET_TX("maps/map4/map4.png", NULL);
    m->zone5.w5_map = sfSprite_create();
    m->zone5.w5_Map = SET_TX("maps/map5/map5.png", NULL);
    m->zone6.w6_map = sfSprite_create();
    m->zone6.w6_Map = SET_TX("maps/map6/map6.png", NULL);
    m->zone7.w7_map = sfSprite_create();
    m->zone7.w7_Map = SET_TX("maps/map7/map7.png", NULL);
    m->zone8.w8_map = sfSprite_create();
    m->zone8.w8_Map = SET_TX("maps/map8/map8.png", NULL);
    m->univ.map_cursor_sprite = sfSprite_create();
    m->univ.map_cursor_text = SET_TX("maps/cursor_map.png", NULL);
}

void init_w_sprite(Global_t *m)
{
    load_sprite_map(m);
    load_texte_map(m);
    sfSprite_setTexture(m->zone1.w1_map, m->zone1.w1_Map, sfFalse);
    sfSprite_setTexture(m->zone2.w2_map, m->zone2.w2_Map, sfFalse);
    sfSprite_setTexture(m->zone3.w3_map, m->zone3.w3_Map, sfFalse);
    sfSprite_setTexture(m->zone4.w4_map, m->zone4.w4_Map, sfFalse);
    sfSprite_setTexture(m->zone5.w5_map, m->zone5.w5_Map, sfFalse);
    sfSprite_setTexture(m->zone6.w6_map, m->zone6.w6_Map, sfFalse);
    sfSprite_setTexture(m->zone7.w7_map, m->zone7.w7_Map, sfFalse);
    sfSprite_setTexture(m->zone8.w8_map, m->zone8.w8_Map, sfFalse);
    sfSprite_setTexture(
    m->univ.map_cursor_sprite, m->univ.map_cursor_text, sfFalse);
    sfSprite_setScale(m->univ.map_cursor_sprite, (sfVector2f){1.29, 1.29});
    m->univ.clock_cursor = sfClock_create();
    m->univ.clock_select_perso = sfClock_create();
    m->univ.is_case_visible = 0;
    init_sp_perso_boss(m);
    init_other_sprites(m);
    m->univ.interface.emy_clock = sfClock_create();
}

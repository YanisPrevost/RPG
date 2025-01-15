/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** bid_destroydessprites.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void destory_enemy_sprites(Global_t *m)
{
    sfSprite_destroy(m->univ.spr_emy1_axe);
    sfSprite_destroy(m->univ.spr_emy2_axe);
    sfSprite_destroy(m->univ.spr_emy3_axe);
    sfSprite_destroy(m->univ.spr_emy1_sword);
    sfSprite_destroy(m->univ.spr_emy2_sword);
    sfSprite_destroy(m->univ.spr_emy3_sword);
    sfSprite_destroy(m->univ.spr_emy1_spear);
    sfSprite_destroy(m->univ.spr_emy2_spear);
    sfSprite_destroy(m->univ.spr_emy3_spear);
    sfSprite_destroy(m->univ.spr_emy_mage);
    sfTexture_destroy(m->univ.txr_emy1_axe);
    sfTexture_destroy(m->univ.txr_emy2_axe);
    sfTexture_destroy(m->univ.txr_emy3_axe);
    sfTexture_destroy(m->univ.txr_emy1_sword);
    sfTexture_destroy(m->univ.txr_emy2_sword);
    sfTexture_destroy(m->univ.txr_emy3_sword);
    sfTexture_destroy(m->univ.txr_emy1_spear);
    sfTexture_destroy(m->univ.txr_emy2_spear);
    sfTexture_destroy(m->univ.txr_emy3_spear);
    sfTexture_destroy(m->univ.txr_emy_mage);
}

static void destory_boss_sprites(Global_t *m)
{
    sfSprite_destroy(m->univ.spr_Boss1);
    sfSprite_destroy(m->univ.spr_Boss2);
    sfSprite_destroy(m->univ.spr_Boss3);
    sfSprite_destroy(m->univ.spr_Boss4);
    sfSprite_destroy(m->univ.spr_Boss5);
    sfSprite_destroy(m->univ.spr_Boss6);
    sfSprite_destroy(m->univ.spr_Boss7);
    sfSprite_destroy(m->univ.spr_Boss8);
    sfTexture_destroy(m->univ.txr_Boss1);
    sfTexture_destroy(m->univ.txr_Boss2);
    sfTexture_destroy(m->univ.txr_Boss3);
    sfTexture_destroy(m->univ.txr_Boss4);
    sfTexture_destroy(m->univ.txr_Boss5);
    sfTexture_destroy(m->univ.txr_Boss6);
    sfTexture_destroy(m->univ.txr_Boss7);
    sfTexture_destroy(m->univ.txr_Boss8);
}

static void destory_perso_sprites(Global_t *m)
{
    sfSprite_destroy(m->univ.spr_roy);
    sfSprite_destroy(m->univ.spr_infe);
    sfSprite_destroy(m->univ.spr_xmara);
    sfSprite_destroy(m->univ.spr_pate);
    sfSprite_destroy(m->univ.spr_raca);
    sfTexture_destroy(m->univ.txr_roy);
    sfTexture_destroy(m->univ.txr_infe);
    sfTexture_destroy(m->univ.txr_xmara);
    sfTexture_destroy(m->univ.txr_pate);
    sfTexture_destroy(m->univ.txr_raca);
}

static void free_all_maptxt_and_view(Global_t *m)
{
    free(m->zone1.tab_map);
    free(m->zone2.tab_map);
    free(m->zone3.tab_map);
    free(m->zone4.tab_map);
    free(m->zone5.tab_map);
    free(m->zone6.tab_map);
    free(m->zone7.tab_map);
    free(m->zone8.tab_map);
    sfView_destroy(m->zone1.view_w1);
    sfView_destroy(m->zone2.view_w2);
    sfView_destroy(m->zone3.view_w3);
    sfView_destroy(m->zone4.view_w4);
    sfView_destroy(m->zone5.view_w5);
    sfView_destroy(m->zone6.view_w6);
    sfView_destroy(m->zone7.view_w7);
    sfView_destroy(m->zone8.view_w8);
}

void destroy_other(Global_t *m)
{
    sfRectangleShape_destroy(m->univ.barre_de_vie);
    sfRectangleShape_destroy(m->univ.barre_fond);
    sfClock_destroy(m->univ.interface.emy_clock);
}

void destory_all_w_maps(Global_t *m)
{
    sfSprite_destroy(m->zone1.w1_map);
    sfTexture_destroy(m->zone1.w1_Map);
    sfSprite_destroy(m->zone2.w2_map);
    sfTexture_destroy(m->zone3.w3_Map);
    sfSprite_destroy(m->zone3.w3_map);
    sfTexture_destroy(m->zone4.w4_Map);
    sfSprite_destroy(m->zone5.w5_map);
    sfTexture_destroy(m->zone6.w6_Map);
    sfSprite_destroy(m->zone7.w7_map);
    sfTexture_destroy(m->zone8.w8_Map);
    sfSprite_destroy(m->univ.map_cursor_sprite);
    sfTexture_destroy(m->univ.map_cursor_text);
    sfClock_destroy(m->univ.clock_cursor);
    destory_perso_sprites(m);
    destory_boss_sprites(m);
    destory_enemy_sprites(m);
    free_all_maptxt_and_view(m);
    destroy_other(m);
}

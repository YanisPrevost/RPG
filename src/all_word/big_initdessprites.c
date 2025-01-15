/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** perso_spr.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void set_texturerect_enemy(Global_t *m)
{
    sfSprite_setTextureRect(m->univ.spr_emy1_axe, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy2_axe, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy3_axe, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy1_sword, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy2_sword, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy3_sword, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy1_spear, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy2_spear, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy3_spear, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_emy_mage, m->univ.rect);
}

static void set_texturerect_boss_perso(Global_t *m)
{
    sfSprite_setTextureRect(m->univ.spr_roy, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_infe, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_xmara, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_pate, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_raca, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss1, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss2, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss3, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss4, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss5, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss6, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss7, m->univ.rect);
    sfSprite_setTextureRect(m->univ.spr_Boss8, m->univ.rect);
}

static void set_scale_enemy(Global_t *m)
{
    sfSprite_setScale(m->univ.spr_emy1_axe, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy2_axe, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy3_axe, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy1_sword, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy2_sword, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy3_sword, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy1_spear, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy2_spear, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy3_spear, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_emy_mage, (sfVector2f){0.61, 0.61});
}

static void set_scale_perso_boss(Global_t *m)
{
    sfSprite_setScale(m->univ.spr_roy, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_infe, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_xmara, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_pate, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_raca, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss1, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss2, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss3, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss4, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss5, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss6, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss7, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univ.spr_Boss8, (sfVector2f){0.61, 0.61});
}

static void set_texture_enemy(Global_t *m)
{
    m->univ.txr_emy_mage = SET_TX(m->perso[ENEMY_MAGE].texture_battle, NULL);
    SP_TXR(m->univ.spr_emy1_axe, m->univ.txr_emy1_axe, sfTrue);
    SP_TXR(m->univ.spr_emy2_axe, m->univ.txr_emy2_axe, sfTrue);
    SP_TXR(m->univ.spr_emy3_axe, m->univ.txr_emy3_axe, sfTrue);
    SP_TXR(m->univ.spr_emy1_sword, m->univ.txr_emy1_sword, sfTrue);
    SP_TXR(m->univ.spr_emy2_sword, m->univ.txr_emy2_sword, sfTrue);
    SP_TXR(m->univ.spr_emy3_sword, m->univ.txr_emy3_sword, sfTrue);
    SP_TXR(m->univ.spr_emy1_spear, m->univ.txr_emy1_spear, sfTrue);
    SP_TXR(m->univ.spr_emy2_spear, m->univ.txr_emy2_spear, sfTrue);
    SP_TXR(m->univ.spr_emy3_spear, m->univ.txr_emy3_spear, sfTrue);
    SP_TXR(m->univ.spr_emy_mage, m->univ.txr_emy_mage, sfTrue);
}

static void set_texture_boss(Global_t *m)
{
    sfSprite_setTexture(m->univ.spr_Boss1, m->univ.txr_Boss1, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss2, m->univ.txr_Boss2, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss3, m->univ.txr_Boss3, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss4, m->univ.txr_Boss4, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss5, m->univ.txr_Boss5, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss6, m->univ.txr_Boss6, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss7, m->univ.txr_Boss7, sfTrue);
    sfSprite_setTexture(m->univ.spr_Boss8, m->univ.txr_Boss8, sfTrue);
}

void init_sp_texture_enemy(Global_t *m)
{
    m->univ.spr_emy1_axe = sfSprite_create();
    m->univ.spr_emy2_axe = sfSprite_create();
    m->univ.spr_emy3_axe = sfSprite_create();
    m->univ.spr_emy1_sword = sfSprite_create();
    m->univ.spr_emy2_sword = sfSprite_create();
    m->univ.spr_emy3_sword = sfSprite_create();
    m->univ.spr_emy1_spear = sfSprite_create();
    m->univ.spr_emy2_spear = sfSprite_create();
    m->univ.spr_emy3_spear = sfSprite_create();
    m->univ.spr_emy_mage = sfSprite_create();
    m->univ.txr_emy1_axe = SET_TX(m->perso[19].texture_battle, NULL);
    m->univ.txr_emy2_axe = SET_TX(m->perso[20].texture_battle, NULL);
    m->univ.txr_emy3_axe = SET_TX(m->perso[21].texture_battle, NULL);
    m->univ.txr_emy1_sword = SET_TX(m->perso[13].texture_battle, NULL);
    m->univ.txr_emy2_sword = SET_TX(m->perso[14].texture_battle, NULL);
    m->univ.txr_emy3_sword = SET_TX(m->perso[15].texture_battle, NULL);
    m->univ.txr_emy1_spear = SET_TX(m->perso[16].texture_battle, NULL);
    m->univ.txr_emy2_spear = SET_TX(m->perso[17].texture_battle, NULL);
    m->univ.txr_emy3_spear = SET_TX(m->perso[18].texture_battle, NULL);
    set_texture_enemy(m);
}

void init_sp_texture_boss(Global_t *m)
{
    m->univ.spr_Boss1 = sfSprite_create();
    m->univ.spr_Boss2 = sfSprite_create();
    m->univ.spr_Boss3 = sfSprite_create();
    m->univ.spr_Boss4 = sfSprite_create();
    m->univ.spr_Boss5 = sfSprite_create();
    m->univ.spr_Boss6 = sfSprite_create();
    m->univ.spr_Boss7 = sfSprite_create();
    m->univ.spr_Boss8 = sfSprite_create();
    m->univ.txr_Boss1 = SET_TX(m->perso[BOSS1].texture_battle, NULL);
    m->univ.txr_Boss2 = SET_TX(m->perso[BOSS2].texture_battle, NULL);
    m->univ.txr_Boss3 = SET_TX(m->perso[BOSS3].texture_battle, NULL);
    m->univ.txr_Boss4 = SET_TX(m->perso[BOSS4].texture_battle, NULL);
    m->univ.txr_Boss5 = SET_TX(m->perso[BOSS5].texture_battle, NULL);
    m->univ.txr_Boss6 = SET_TX(m->perso[BOSS6].texture_battle, NULL);
    m->univ.txr_Boss7 = SET_TX(m->perso[BOSS7].texture_battle, NULL);
    m->univ.txr_Boss8 = SET_TX(m->perso[BOSS8].texture_battle, NULL);
    set_texture_boss(m);
}

void init_sp_texture_perso(Global_t *m)
{
    m->univ.spr_roy = sfSprite_create();
    m->univ.spr_infe = sfSprite_create();
    m->univ.spr_xmara = sfSprite_create();
    m->univ.spr_pate = sfSprite_create();
    m->univ.spr_raca = sfSprite_create();
    m->univ.txr_roy = SET_TX(m->perso[ROY].texture_battle, NULL);
    m->univ.txr_infe = SET_TX(m->perso[INFENIUM].texture_battle, NULL);
    m->univ.txr_xmara = SET_TX(m->perso[XMARANO].texture_battle, NULL);
    m->univ.txr_pate = SET_TX(m->perso[PATECARBO].texture_battle, NULL);
    m->univ.txr_raca = SET_TX(m->perso[RACAILLOU].texture_battle, NULL);
    sfSprite_setTexture(m->univ.spr_roy, m->univ.txr_roy, sfTrue);
    sfSprite_setTexture(m->univ.spr_infe, m->univ.txr_infe, sfTrue);
    sfSprite_setTexture(m->univ.spr_xmara, m->univ.txr_xmara, sfTrue);
    sfSprite_setTexture(m->univ.spr_pate, m->univ.txr_pate, sfTrue);
    sfSprite_setTexture(m->univ.spr_raca, m->univ.txr_raca, sfTrue);
}

void init_sp_perso_boss(Global_t *m)
{
    m->univ.rect = (sfIntRect){0, 512 + 65 * 2, 65, 65};
    init_sp_texture_perso(m);
    init_sp_texture_boss(m);
    init_sp_texture_enemy(m);
    set_scale_perso_boss(m);
    set_scale_enemy(m);
    set_texturerect_boss_perso(m);
    set_texturerect_enemy(m);
}

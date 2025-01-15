/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** mini_barre.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include "../include/fight.h"

void init_mini_barre_emy(Global_t *m, fight_t *f, sfSprite *sprite, int who)
{
    sfVector2f pose;
    int maxhp = m->perso[who].stat_p.max_hp;
    int currhp = m->perso[who].stat_p.current_hp;

    pose = sfSprite_getPosition(sprite);
    pose.x += 6;
    pose.y -= 7;
    f->rect_empty_bar2 = (sfIntRect){2, 99, maxhp * 2 + 1, 7};
    sfSprite_setTextureRect(f->empty_bar_sprite2, f->rect_empty_bar2);
    sfSprite_setPosition(f->empty_bar_sprite2, pose);
    sfSprite_setScale(f->empty_bar_sprite2, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->empty_bar_sprite2, NULL);
    f->rect_ennemy_bar2 = (sfIntRect){2, 91, currhp * 2 + 1, 7};
    sfSprite_setTextureRect(f->hero_lifebar_sprite2, f->rect_ennemy_bar2);
    sfSprite_setPosition(f->hero_lifebar_sprite2, pose);
    sfSprite_setScale(f->hero_lifebar_sprite2, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->hero_lifebar_sprite2, NULL);
}

void init_mini_barre(Global_t *m, fight_t *f, sfSprite *sprite, int who)
{
    sfVector2f pose;
    int maxhp = m->perso[who].stat_p.max_hp;
    int currhp = m->perso[who].stat_p.current_hp;

    pose = sfSprite_getPosition(sprite);
    pose.x += 6;
    pose.y -= 7;
    f->rect_empty_bar2 = (sfIntRect){2, 99, maxhp * 2 + 1, 7};
    sfSprite_setTextureRect(f->empty_bar_sprite2, f->rect_empty_bar2);
    sfSprite_setPosition(f->empty_bar_sprite2, pose);
    sfSprite_setScale(f->empty_bar_sprite2, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->empty_bar_sprite2, NULL);
    f->rect_ennemy_bar2 = (sfIntRect){2, 83, currhp * 2 + 1, 7};
    sfSprite_setTextureRect(f->hero_lifebar_sprite2, f->rect_ennemy_bar2);
    sfSprite_setPosition(f->hero_lifebar_sprite2, pose);
    sfSprite_setScale(f->hero_lifebar_sprite2, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->hero_lifebar_sprite2, NULL);
}

static void print_tour(Global_t *m)
{
    char test[20];

    sprintf(test, "Turn Left:  %d", m->univ.interface.limite_tour);
    sfText_setString(m->univ.interface.tour, test);
    sfText_setPosition(m->univ.interface.tour, (sfVector2f){10, 20});
    sfRenderWindow_drawText(m->window, m->univ.interface.tour, NULL);
}

void print_boss_barre3(Global_t *m, fight_t *f, int word)
{
    if (word >= 7 && word <= 8) {
        if (m->perso[ENEMY3_AXE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy3_axe, ENEMY3_AXE);
        if (m->perso[ENEMY3_SPEAR].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy3_spear, ENEMY3_SPEAR);
        if (m->perso[ENEMY3_SWORD].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy3_sword, ENEMY3_SWORD);
        if (m->perso[ENEMY_MAGE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy_mage, ENEMY_MAGE);
    }
}

void print_boss_barre2(Global_t *m, fight_t *f, int word)
{
    if (word >= 4 && word <= 8) {
        if (m->perso[ENEMY2_AXE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_axe, ENEMY2_AXE);
        if (m->perso[ENEMY2_SPEAR].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_spear, ENEMY2_SPEAR);
        if (m->perso[ENEMY2_SWORD].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_sword, ENEMY2_SWORD);
    }
    print_boss_barre3(m, f, word);
}

static void print_mini_barre2_1(Global_t *m, fight_t *f, int word)
{
    if (word >= 1 && word <= 8) {
        if (m->perso[ENEMY1_AXE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy1_axe, ENEMY1_AXE);
        if (m->perso[ENEMY1_SPEAR].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy1_spear, ENEMY1_SPEAR);
        if (m->perso[ENEMY1_SWORD].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy1_sword, ENEMY1_SWORD);
        if (m->perso[ENEMY2_SWORD].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_sword, ENEMY2_SWORD);
        if (word > 1 && m->perso[ENEMY2_SPEAR].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_spear, ENEMY2_SPEAR);
        if (word > 3 && m->perso[ENEMY2_AXE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy2_axe, ENEMY2_AXE);
        if (word > 4 && m->perso[ENEMY3_AXE].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy3_axe, ENEMY3_AXE);
        if (word > 5 && m->perso[ENEMY3_SPEAR].stat_p.current_hp > 0)
            init_mini_barre_emy(m, f, m->univ.spr_emy3_spear, ENEMY3_SPEAR);
    }
}

void print_mini_barre(Global_t *m, fight_t *f, int word)
{
    if (m->perso[ROY].stat_p.current_hp > 0)
        init_mini_barre(m, f, m->univ.spr_roy, ROY);
    if (m->perso[XMARANO].stat_p.current_hp > 0)
        init_mini_barre(m, f, m->univ.spr_xmara, XMARANO);
    if (m->perso[PATECARBO].stat_p.current_hp > 0)
        init_mini_barre(m, f, m->univ.spr_pate, PATECARBO);
    if (m->perso[INFENIUM].stat_p.current_hp > 0)
        init_mini_barre(m, f, m->univ.spr_infe, INFENIUM);
    if (m->perso[RACAILLOU].stat_p.current_hp > 0)
        init_mini_barre(m, f, m->univ.spr_raca, RACAILLOU);
    print_mini_barre2_1(m, f, word);
    print_tour(m);
    print_boss_barre2(m, f, word);
}

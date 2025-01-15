/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** inti2.c
*/

#include "../include/perso.h"
#include "../rpg.h"

void init_lifebars2(fight_t *fight, Global_t *m)
{
    fight->empty_bar_sprite2 = sfSprite_create();
    fight->hero_lifebar_sprite2 = sfSprite_create();
    fight->ennemy_bar_sprite2 = sfSprite_create();
    sfSprite_setScale(fight->empty_bar_sprite2, (sfVector2f){8, 8});
    SP_TXR(fight->empty_bar_sprite2, fight->globat_texture, sfFalse);
    sfSprite_setTextureRect(fight->empty_bar_sprite2, fight->rect_empty_bar2);
    SP_TXR(fight->ennemy_bar_sprite2, fight->globat_texture, sfFalse);
    SP_TXR(fight->hero_lifebar_sprite2, fight->globat_texture, sfFalse);
    init_slash(m, fight);
    fight->dead_head = sfSprite_create();
    fight->Dead_head = SET_TX("assets/fight/skull.png", NULL);
    fight->dead_head2 = sfSprite_create();
    fight->lifebar_clock = sfClock_create();
}

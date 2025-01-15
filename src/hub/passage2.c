/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passage2.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void passages_mondes8(Global_t *m, hub_t *hub)
{
    int word = 8;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 0 && hub->color.g == 0 && hub->color.b == 100
    && m->zone7.is_w7_clear == true && m->zone8.is_w8_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1175, -7});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes7(Global_t *m, hub_t *hub)
{
    int word = 7;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 0 && hub->color.g == 100 && hub->color.b == 0
    && m->zone6.is_w6_clear == true && m->zone7.is_w7_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1340, 380});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes6(Global_t *m, hub_t *hub)
{
    int word = 6;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 100 && hub->color.g == 0 && hub->color.b == 0
    && m->zone5.is_w5_clear == true && m->zone6.is_w6_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1305, 540});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes5(Global_t *m, hub_t *hub)
{
    int word = 5;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 0 && hub->color.g == 0 && hub->color.b == 255
    && m->zone4.is_w4_clear == true && m->zone5.is_w5_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){25, 165});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

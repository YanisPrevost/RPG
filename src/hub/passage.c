/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passage.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void false_to_true(hub_t *hub)
{
    if (!hub->is_talking) {
        hub->is_talking = true;
    }
}

void passages_mondes4(Global_t *m, hub_t *hub)
{
    int word = 4;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 0 && hub->color.g == 255 && hub->color.b == 255
    && m->zone3.is_w3_clear == true && m->zone4.is_w4_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){325, 675});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes3(Global_t *m, hub_t *hub)
{
    int word = 3;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 150 && hub->color.g == 150 && hub->color.b == 0 &&
    m->zone2.is_w2_clear == true && m->zone3.is_w3_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){410, 550});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes2(Global_t *m, hub_t *hub)
{
    int word = 2;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 0 && hub->color.g == 255 && hub->color.b == 0
    && m->zone1.is_w1_clear == true && m->zone2.is_w2_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){858, -7});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

static void passages_mondes1(Global_t *m, hub_t *hub)
{
    int word = 1;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 150 && hub->color.g == 0 && hub->color.b == 0 &&
    m->zone1.is_w1_clear == false && m->hub.prologue_ok == true) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){625, 285});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

static void open_shop(Global_t *m, hub_t *hub)
{
    if ((hub->color.r == 50 && hub->color.g == 50 && hub->color.b == 50)) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){310, 35});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->shop.is_select = false;
            m->current = 9;
        }
    }
}

static void prologue(Global_t *m, hub_t *hub)
{
    int word = 0;
    sfVector2f per_pose = sfSprite_getPosition(hub->sprite_perso);

    if (hub->color.r == 150 && hub->color.g == 150 &&
    hub->color.b == 150 && m->hub.prologue_ok == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){660, 400});
        if (!hub->is_talking)
            sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            false_to_true(hub);
        }
        if (hub->is_talking)
            draw_pouill_dia(m, word, per_pose, hub);
    }
}

void passages_mondes(Global_t *m, hub_t *hub)
{
    if (m->hub.prologue_ok == false)
        prologue(m, hub);
    else if (m->hub.prologue_ok == true) {
        open_shop(m, hub);
        passages_mondes1(m, hub);
        passages_mondes2(m, hub);
        passages_mondes3(m, hub);
        passages_mondes4(m, hub);
        passages_mondes5(m, hub);
        passages_mondes6(m, hub);
        passages_mondes7(m, hub);
        passages_mondes8(m, hub);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && hub->is_talking == true) {
        m->dialogue.currentLine = 0;
        sfSleep(sfSeconds(0.2));
        hub->is_talking = false;
        return;
    }
    return_and_old_current(m, 0);
}

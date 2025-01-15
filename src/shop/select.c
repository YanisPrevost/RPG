/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** select.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static void transfert(Global_t *m, Weapons_t *weap, int w)
{
    for (int i = 0; i < 5; i++) {
        if (weap[i].is_empty == true) {
            memcpy(&weap[i], &m->weapons[w], sizeof(Weapons_t));
            m->gold -= m->weapons[w].cost;
            weap[i].is_empty = false;
            return;
        }
    }
}

void import_weapon_inv(Global_t *m, int w)
{
    Perso_t *character;
    Weapons_t *weap;

    if (m->shop.buyer == 0)
        character = &m->perso[XMARANO];
    if (m->shop.buyer == 1)
        character = &m->perso[ROY];
    if (m->shop.buyer == 2)
        character = &m->perso[RACAILLOU];
    if (m->shop.buyer == 3)
        character = &m->perso[PATECARBO];
    if (m->shop.buyer == 4)
        character = &m->perso[INFENIUM];
    weap = character->inv_weapon;
    transfert(m, weap, w);
}

static void depl(Global_t *m)
{
    static int cursor_position = 0;

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (cursor_position < 4) {
            cursor_position++;
            m->shop.cursor_pose.x += 40;
            sfSprite_setPosition(m->shop.cursor, m->shop.cursor_pose);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (cursor_position > 0) {
            cursor_position--;
            m->shop.cursor_pose.x -= 40;
            sfSprite_setPosition(m->shop.cursor, m->shop.cursor_pose);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        m->shop.buyer = cursor_position;
        m->shop.is_select = true;
    }
}

void select_perso(Global_t *m)
{
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;

    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < 0.15f)
        return;
    depl(m);
    sfClock_restart(clock);
    if (m->shop.is_select == false) {
        sfClock_destroy(clock);
        clock = NULL;
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** game_cursor.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void update_move_cursor(sfVector2f pos_cursor, Global_t *m)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (pos_cursor.y < 760)
            sfSprite_move(m->univ.map_cursor_sprite, (sfVector2f){0, 40});
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (pos_cursor.y >= 40)
            sfSprite_move(m->univ.map_cursor_sprite, (sfVector2f){0, -40});
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (pos_cursor.x >= 40)
            sfSprite_move(m->univ.map_cursor_sprite, (sfVector2f){-40, 0});
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (pos_cursor.x < 1160)
            sfSprite_move(m->univ.map_cursor_sprite, (sfVector2f){40, 0});
    }
}

void move_game_cursor(Global_t *m)
{
    sfVector2f pos_cursor = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfTime time = sfClock_getElapsedTime(m->univ.clock_cursor);
    float seconds = sfTime_asMilliseconds(time) / 1000.0;

    if (seconds > 0.05) {
        if (!m->univ.interface.select_inteface)
            update_move_cursor(pos_cursor, m);
        sfClock_restart(m->univ.clock_cursor);
    }
    sfRenderWindow_drawSprite(m->window, m->univ.map_cursor_sprite, NULL);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_all_spite.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void move3(Global_t *m, int new_index)
{
    int row;
    int column;
    sfVector2f cur_pose;
    sfVector2f new_position;

    if (new_index < 0 || new_index >= m->shop.num_columns * m->shop.num_rows)
        return;
    row = new_index / m->shop.num_columns;
    column = new_index % m->shop.num_columns;
    cur_pose = sfSprite_getPosition(m->weapons[8].sprite);
    new_position.x = 420 + column * (cur_pose.x - 420 + m->shop.spacing_x);
    new_position.y = 245 + row * (cur_pose.y - 245 + m->shop.spacing_y);
    sfRectangleShape_setPosition(m->shop.hooved, new_position);
    sfSprite_setPosition(m->shop.lock, new_position);
    m->shop.hovered_index = new_index;
}

void move2(Global_t *m, int direction, sfClock *clock)
{
    int current_index = m->shop.hovered_index;
    int new_index = current_index;

    switch (direction) {
        case sfKeyLeft:
            new_index--;
            break;
        case sfKeyRight:
            new_index++;
            break;
        case sfKeyUp:
            new_index -= m->shop.num_columns;
            break;
        case sfKeyDown:
            new_index += m->shop.num_columns;
            break;
    }
    move3(m, new_index);
}

void move_hover_rect(Global_t *m, int direction)
{
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;

    m->shop.num_columns = 4;
    m->shop.num_rows = 4;
    m->shop.spacing_x = 30;
    m->shop.spacing_y = 30;
    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < 0.15f)
        return;
    sfClock_restart(clock);
    move2(m, direction, clock);
    if (clock != NULL) {
        sfClock_destroy(clock);
        clock = NULL;
    }
}

static void drw(Global_t *m, sfClock *clock)
{
    sfSprite_setPosition(m->shop.coin, (sfVector2f){627, 195});
    sfSprite_setScale(m->shop.coin, (sfVector2f){1.2, 1.2});
    sfRenderWindow_drawSprite(m->window, m->shop.coin, NULL);
    sfSprite_setPosition(m->shop.coin, (sfVector2f){500, 375});
    sfRenderWindow_drawSprite(m->window, m->shop.coin, NULL);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.1f) {
        sfClock_destroy(clock);
        clock = NULL;
    }
}

void move_coin(Global_t *m)
{
    static sfClock *clock = NULL;
    static sfIntRect rect = {0, 0, 16, 16};
    sfTime time;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.1) {
        rect.left += 16;
        if (rect.left >= 144)
            rect.left = 0;
        sfSprite_setTextureRect(m->shop.coin, rect);
        sfClock_restart(clock);
    }
    drw(m, clock);
}

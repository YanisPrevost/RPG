/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** loading_screen.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "include/worlds.h"

static sfSprite *init_sprit(char *filename, sfVector2f pos, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void destroy_loading(Global_t *m)
{
    sfSprite_destroy(m->loading.fond);
    sfSprite_destroy(m->loading.vert);
    sfSprite_destroy(m->loading.text);
    sfSprite_destroy(m->loading.back_screen);
    sfTexture_destroy(m->loading.Fond);
    sfTexture_destroy(m->loading.Vert);
    sfTexture_destroy(m->loading.Text);
    sfTexture_destroy(m->loading.Back_screen);
}

void init_loading(Global_t *m)
{
    sfVector2f pose_1 = {760, 480};
    sfVector2f common = {9, 9};
    sfVector2f pos_2 = {0, 0};
    sfVector2f one = {1, 1};

    m->loading.fond = init_sprit("assets/loading/barre.png", pose_1, common);
    m->loading.vert = init_sprit("assets/loading/vert.png", pose_1, common);
    m->loading.text = init_sprit("assets/loading/load.png", pose_1, common);
    m->loading.back_screen = init_sprit("assets/loading/back.png", pos_2, one);
}

void bcl(float time, sfClock *clock)
{
    while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - time < 0.3f);
}

static void prt(Global_t *m, sfVector2f vert_pose)
{
    sfSprite_setPosition(m->loading.vert, vert_pose);
    sfRenderWindow_drawSprite(m->window, m->loading.vert, NULL);
    sfRenderWindow_drawSprite(m->window, m->loading.fond, NULL);
    sfRenderWindow_display(m->window);
    m->current = 0;
}

void loading_screen(Global_t *m)
{
    sfVector2f vert_pose = {760, 480};
    sfClock *clock = sfClock_create();
    sfTime time;
    float elapsed_time;

    if (m->current == 14) {
        sfRenderWindow_drawSprite(m->window, m->loading.back_screen, NULL);
        sfRenderWindow_drawSprite(m->window, m->loading.text, NULL);
        for (int i = 0; i < 14; ++i) {
            prt(m, vert_pose);
            time = sfClock_getElapsedTime(clock);
            elapsed_time = sfTime_asSeconds(time);
            bcl(elapsed_time, clock);
            vert_pose.x += 27;
        }
        sfClock_destroy(clock);
        time = sfClock_getElapsedTime(clock);
        elapsed_time = sfTime_asSeconds(time);
        bcl(elapsed_time, clock);
    }
}

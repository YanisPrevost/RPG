/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void up_volume(Global_t *m, int v1, int v2, int v3)
{
    if (v1 + 10 < 100)
        v1 = v1 + 10;
    else
        v1 = 100;
    if (v2 + 10 < 100)
        v2 = v2 + 10;
    else
        v2 = 100;
    if (v3 + 10 < 100)
        v3 = v3 + 10;
    else
        v3 = 100;
    sfMusic_setVolume(m->menu.music, v1);
    sfMusic_setVolume(m->hub.music, v2);
    sfMusic_setVolume(m->setting.music, v3);
}

void down_volume(Global_t *m, int v1, int v2, int v3)
{
    if (v1 - 10 > 0)
        v1 = v1 - 10;
    else
        v1 = 0;
    if (v2 - 10 > 0)
        v2 = v2 - 10;
    else
        v2 = 0;
    if (v3 - 10 > 0)
        v3 = v3 - 10;
    else
        v3 = 0;
    sfMusic_setVolume(m->menu.music, v1);
    sfMusic_setVolume(m->hub.music, v2);
    sfMusic_setVolume(m->setting.music, v3);
}

void mute_volume(Global_t *m, int v1, int v2, int v3)
{
    if (v1 == 0)
        sfMusic_setVolume(m->menu.music, 100);
    else
        sfMusic_setVolume(m->menu.music, 0);
    if (v2 == 0)
        sfMusic_setVolume(m->hub.music, 100);
    else
        sfMusic_setVolume(m->hub.music, 0);
    if (v3 == 0)
        sfMusic_setVolume(m->setting.music, 100);
    else
        sfMusic_setVolume(m->setting.music, 0);
}

void verif_song(sfVector2i mouse, Global_t *m)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect downvol = sfText_getGlobalBounds(m->setting.volumeb);
    sfFloatRect upvol = sfText_getGlobalBounds(m->setting.volumeh);
    sfFloatRect coupvol = sfText_getGlobalBounds(m->setting.cvolume);
    int volume1 = sfMusic_getVolume(m->menu.music);
    int volume2 = sfMusic_getVolume(m->hub.music);
    int volume3 = sfMusic_getVolume(m->setting.music);

    if (sfFloatRect_contains(&downvol, mousePos.x, mousePos.y))
        up_volume(m, volume1, volume2, volume3);
    if (sfFloatRect_contains(&upvol, mousePos.x, mousePos.y))
        down_volume(m, volume1, volume2, volume3);
    if (sfFloatRect_contains(&coupvol, mousePos.x, mousePos.y))
        mute_volume(m, volume1, volume2, volume3);
}

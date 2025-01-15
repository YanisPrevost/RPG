/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** get_old_current.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void print_boss_barre(Global_t *m, int who, sfSprite *spr)
{
    float pourcentage_vie = (float)m->perso[who].stat_p.current_hp
    / (float)m->perso[who].stat_p.max_hp;
    sfVector2f pose = sfSprite_getPosition(spr);

    pose.y -= 10;
    sfRectangleShape_setPosition(m->univ.barre_de_vie, pose);
    sfRectangleShape_setPosition(m->univ.barre_fond, pose);
    pose.x -= 13;
    pose.y -= 6.5;
    sfSprite_setPosition(m->univ.image_barre, pose);
    sfRectangleShape_setScale(m->univ.barre_de_vie, (sfVector2f){0.1, 0.3});
    sfRectangleShape_setScale(m->univ.barre_fond, (sfVector2f){0.1, 0.3});
    sfSprite_setScale(m->univ.image_barre, (sfVector2f){0.1, 0.1});
    sfRectangleShape_setSize(m->univ.barre_de_vie,
    (sfVector2f){400 * pourcentage_vie, 30});
    sfRenderWindow_drawRectangleShape(m->window, m->univ.barre_fond, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->univ.barre_de_vie, NULL);
    sfRenderWindow_drawSprite(m->window, m->univ.image_barre, NULL);
}

static void set_pose_perso(char **map, char ref, sfSprite *sprite, int i)
{
    for (int y = 0; map[i][y] != '\0'; y++) {
        if (map[i][y] == ref) {
            sfSprite_setPosition(sprite,
            (sfVector2f){(y - 1) * 40, (i - 1) * 40});
        }
    }
}

void check_position(char **map, char ref, sfSprite *sprite, Global_t *m)
{
    for (int i = 0; map[i] != NULL; i++) {
        set_pose_perso(map, ref, sprite, i);
    }
    sfRenderWindow_drawSprite(m->window, sprite, NULL);
}

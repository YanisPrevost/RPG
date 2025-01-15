/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_inv.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

void init_pose(Global_t *m)
{
    m->perso->inv.inv_sprite.pos_cursor.x = 940;
    m->perso->inv.inv_sprite.pos_hooved.x = 980;
    m->perso->inv.inv_sprite.pos_cursor.y = 443;
    m->perso->inv.inv_sprite.pos_hooved.y = 443;
}

void destroy_inventaire(Global_t *m)
{
    sfRectangleShape_destroy(m->perso->inv.inv_sprite.hooved_weapon);
    sfSprite_destroy(m->perso->inv.inv_sprite.cursor);
    sfRectangleShape_destroy(m->perso->inv.inv_sprite.rect_inv);
    sfSprite_destroy(m->perso->inv.inv_sprite.inventory);
    sfSprite_destroy(m->perso->inv.inv_sprite.inventory2);
    sfClock_destroy(m->perso->swap_clock);
}

void init_inventaire(Global_t *m)
{
    char *fond_inv = "assets/inv/fond_inv.jpeg";
    char *fond = "assets/inv/inv_fond.png";
    char *fon2 = "assets/inv/inv_fond2.png";
    char *cursor = "assets/inv/cursor.png";

    m->perso->inv.inv_sprite.fond = sfSprite_create();
    m->perso->inv.inv_sprite.Fond = sfTexture_createFromFile(fond_inv, NULL);
    m->perso->inv.inv_sprite.inventory = sfSprite_create();
    m->perso->inv.inv_sprite.Inventory = sfTexture_createFromFile(fond, NULL);
    m->perso->inv.inv_sprite.inventory2 = sfSprite_create();
    m->perso->inv.inv_sprite.Inventory2 = sfTexture_createFromFile(fon2, NULL);
    m->perso->inv.inv_sprite.Cursor = sfTexture_createFromFile(cursor, NULL);
    m->perso->inv.inv_sprite.cursor = sfSprite_create();
    m->perso->inv.inv_sprite.hooved_weapon = sfRectangleShape_create();
    m->perso->inv.inv_sprite.rect_inv = sfRectangleShape_create();
    m->perso->swap_clock = sfClock_create();
    m->gold = 1500;
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_sprite.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

sfRectangleShape *hoov_inv(Global_t *m,
    sfVector2f popo, sfVector2f siz, float f)
{
    sfRectangleShape *rect = m->perso->inv.inv_sprite.rect_inv;

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setPosition(rect, popo);
    sfRectangleShape_setSize(rect, siz);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, f);
    return rect;
}

sfRectangleShape *hoov_w(Global_t *m, sfVector2f popo, sfVector2f siz, float f)
{
    sfRectangleShape *rect = m->perso->inv.inv_sprite.hooved_weapon;

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setPosition(rect, popo);
    sfRectangleShape_setSize(rect, siz);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, f);
    return rect;
}

sfSprite *set_cursor(Global_t *m)
{
    sfSprite *sprite = m->perso->inv.inv_sprite.cursor;
    sfVector2f scale = {0.3, 0.3};
    sfVector2f pos = {940, 443};
    sfTexture *Cursor = m->perso->inv.inv_sprite.Cursor;

    sfSprite_setTexture(sprite, Cursor, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = m->perso->inv.inv_sprite.inventory;
    sfVector2f pos = {600, 300};
    sfVector2f scale = {3.2, 3.2};
    sfTexture *Inv = m->perso->inv.inv_sprite.Inventory;

    sfSprite_setTexture(sprite, Inv, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = m->perso->inv.inv_sprite.inventory2;
    sfVector2f pos = {920, 300};
    sfVector2f scale = {3.2, 3.2};
    sfTexture *Inv2 = m->perso->inv.inv_sprite.Inventory2;

    sfSprite_setTexture(sprite, Inv2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

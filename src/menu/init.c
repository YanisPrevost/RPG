/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init.c
*/
#include "../rpg.h"

sfSprite *init_sprite(char *filename, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfText *init_text(Global_t *m, char *str, int size, int pos_y)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfFloatRect text_pos;
    float pos_x;

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    text_pos = sfText_getLocalBounds(text);
    pos_x = (m->menu.wsize.x - text_pos.width) / 2;
    sfText_setPosition(text, (sfVector2f){pos_x, pos_y});
    return text;
}

sfRectangleShape *init_button(Global_t *m, sfVector2f size, int pos_y)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfFloatRect rect_pos;
    float pos_x;

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
    sfRectangleShape_setOutlineThickness(shape, 6);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    rect_pos = sfRectangleShape_getLocalBounds(shape);
    pos_x = (m->menu.wsize.x - rect_pos.width) / 2;
    sfRectangleShape_setPosition(shape, (sfVector2f){pos_x + 5, pos_y});
    return shape;
}

void hover(Global_t *m, sfRectangleShape *shape, sfFloatRect *rect)
{
    if (sfFloatRect_contains(rect, m->mouse.x, m->mouse.y))
        sfRectangleShape_setFillColor(shape, sfColor_fromRGB(186, 135, 36));
    else
        sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
}

void click(Global_t *m, sfFloatRect *rect, int current)
{
    if (sfFloatRect_contains(rect, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->current = current;
            m->o.is_saved = 0;
        }
    }
}

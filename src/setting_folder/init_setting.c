/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

sfRectangleShape *init_button2(Global_t *m, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
    sfRectangleShape_setOutlineThickness(shape, 5);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    sfRectangleShape_setPosition(shape, pos);
    return shape;
}

sfText *init_text2(sfFont *font, const char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    return text;
}

void init_setting3(Global_t *m)
{
    m->setting.littlez = init_text2(m->setting.font,
    "Full screen", 50, (sfVector2f){600, 340});
    m->setting.mediumz = init_text2(m->setting.font,
    "1280 x 720", 50, (sfVector2f){600, 400});
    m->setting.bigz = init_text2(m->setting.font,
    "1920 x 1080", 50, (sfVector2f){600, 460});
    m->setting.volumeclicked = false;
    m->setting.volumeb = init_text2(m->setting.font,
    "Volume Up", 50, (sfVector2f){570, 690});
    m->setting.volumeh = init_text2(m->setting.font,
    "Volume Down", 50, (sfVector2f){570, 750});
    m->setting.cvolume = init_text2(m->setting.font,
    "Mute Music", 50, (sfVector2f){570, 810});
}

void init_setting2(Global_t *m)
{
    m->setting.synopsis = init_text2(m->setting.font,
    "synopsis", 50, (sfVector2f){160, 250});
    m->setting.buttonsynop = init_button2(m,
    (sfVector2f){200, 58}, (sfVector2f){150, 260});
    m->setting.volumetxt = init_text2(m->setting.font,
    "volume", 50, (sfVector2f){638, 600});
    m->setting.buttonvolum = init_button2(m,
    (sfVector2f){280, 58}, (sfVector2f){570, 610});
    m->setting.sizewindows = init_text2(m->setting.font,
    "window size", 50, (sfVector2f){590, 250});
    m->setting.buttonwindow = init_button2(m,
    (sfVector2f){280, 58}, (sfVector2f){570, 260});
    init_setting3(m);
}

void init_setting(Global_t *m)
{
    m->setting.font = sfFont_createFromFile("assets/font.ttf");
    m->setting.window_size = sfRenderWindow_getSize(m->window);
    m->setting.background_s = init_sprite("assets/setting/background.png"
    , (sfVector2f){0, 0});
    m->setting.retour = init_text2(m->setting.font,
    "back", 50, (sfVector2f){70, 22});
    m->setting.buttonretour = init_button2(m,
    (sfVector2f){170, 60}, (sfVector2f){30, 30});
    m->setting.titre = init_text(m, "SETTINGS", 135, 10);
    m->setting.credit = init_text2(m->setting.font,
    "credits", 50, (sfVector2f){182, 600});
    m->setting.buttoncred = init_button2(m,
    (sfVector2f){200, 58}, (sfVector2f){150, 610});
    init_setting2(m);
    check_globalbounds2(m);
}

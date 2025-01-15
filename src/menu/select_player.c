/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** select_player.c
*/
#include "../rpg.h"
#include "../include/menu.h"

sfRectangleShape *init_b_s(Global_t *m, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfFloatRect rect_pos;
    float pos_y;
    float pos_x;

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
    sfRectangleShape_setOutlineThickness(shape, 6);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    rect_pos = sfRectangleShape_getLocalBounds(shape);
    pos_y = (m->menu.wsize.y - rect_pos.height) / 2;
    pos_x = (m->menu.wsize.x - rect_pos.width) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfRectangleShape_setPosition(shape, pos);
    return shape;
}

static sfSprite *init_s_s(Global_t *m, char *filename, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfFloatRect sprite_pos;
    float pos_y;
    float pos_x;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sprite_pos = sfSprite_getLocalBounds(sprite);
    pos_y = (m->menu.wsize.y - sprite_pos.height) / 2;
    pos_x = (m->menu.wsize.x - sprite_pos.width) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfText *init_t_s(Global_t *m, char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfFloatRect text_pos;
    float pos_y;
    float pos_x;

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    text_pos = sfText_getLocalBounds(text);
    pos_x = (m->menu.wsize.x - text_pos.width) / 2;
    pos_y = (m->menu.wsize.y - text_pos.height) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfText_setPosition(text, pos);
    return text;
}

static void check_globalbounds(Global_t *m)
{
    m->s.gb_b1 = sfRectangleShape_getGlobalBounds(m->s.button1);
    m->s.gb_b2 = sfRectangleShape_getGlobalBounds(m->s.button2);
    m->s.gb_b3 = sfRectangleShape_getGlobalBounds(m->s.button3);
    m->s.gb_b4 = sfRectangleShape_getGlobalBounds(m->s.button4);
    m->s.gb_b5 = sfRectangleShape_getGlobalBounds(m->s.button5);
    m->s.gb_play = sfRectangleShape_getGlobalBounds(m->s.play);
    m->s.gb_back = sfRectangleShape_getGlobalBounds(m->s.back);
}

static void init_select_perso2(Global_t *m)
{
    m->s.button1 = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){-500, 25});
    m->s.button2 = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){-250, 25});
    m->s.button3 = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){0, 25});
    m->s.button4 = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){250, 25});
    m->s.button5 = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){500, 25});
    m->s.back = init_b_s(m, (sfVector2f){100, 50}, (sfVector2f){-625, -325});
    m->s.play = init_b_s(m, (sfVector2f){200, 75}, (sfVector2f){550, 325});
    m->s.back_txt = init_t_s(m, "back", 50, (sfVector2f){-630, -353});
    m->s.play_txt = init_t_s(m, "play", 70, (sfVector2f){543, 290});
    m->s.select1 = init_t_s(m, "select", 70, (sfVector2f){-505, -10});
    m->s.select2 = init_t_s(m, "select", 70, (sfVector2f){-255, -10});
    m->s.select3 = init_t_s(m, "select", 70, (sfVector2f){-5, -10});
    m->s.select4 = init_t_s(m, "select", 70, (sfVector2f){245, -10});
    m->s.select5 = init_t_s(m, "select", 70, (sfVector2f){495, -10});
}

void init_select_perso(Global_t *m)
{
    m->s.fond = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->s.p1 = init_s_s(m, "assets/menu/r.png", (sfVector2f){-510, -150});
    m->s.p2 = init_s_s(m, "assets/menu/x.png", (sfVector2f){-260, -145});
    m->s.p3 = init_s_s(m, "assets/menu/p.png", (sfVector2f){-10, -145});
    m->s.p4 = init_s_s(m, "assets/menu/i.png", (sfVector2f){245, -160});
    m->s.p5 = init_s_s(m, "assets/menu/r2.png", (sfVector2f){520, -145});
    m->s.p1_w = init_s_s(m, "assets/menu/r_w.png", (sfVector2f){-510, -150});
    m->s.p2_w = init_s_s(m, "assets/menu/x_w.png", (sfVector2f){-260, -145});
    m->s.p3_w = init_s_s(m, "assets/menu/p_w.png", (sfVector2f){-10, -145});
    m->s.p4_w = init_s_s(m, "assets/menu/i_w.png", (sfVector2f){245, -160});
    m->s.p5_w = init_s_s(m, "assets/menu/r2_w.png", (sfVector2f){520, -145});
    m->s.p1_d = init_s_s(m, "assets/menu/stat_r.png", (sfVector2f){0, 225});
    m->s.p2_d = init_s_s(m, "assets/menu/stat_x.png", (sfVector2f){0, 225});
    m->s.p3_d = init_s_s(m, "assets/menu/stat_p.png", (sfVector2f){0, 225});
    m->s.p4_d = init_s_s(m, "assets/menu/stat_i.png", (sfVector2f){0, 225});
    m->s.p5_d = init_s_s(m, "assets/menu/stat_r2.png", (sfVector2f){0, 225});
    m->s.title = init_text(m, "SELECT  A  PLAYER", 100, 0);
    init_select_perso2(m);
    check_globalbounds(m);
}

static void draw_select_perso2(Global_t *m)
{
    sfRenderWindow_drawText(m->window, m->s.select1, NULL);
    sfRenderWindow_drawText(m->window, m->s.select2, NULL);
    sfRenderWindow_drawText(m->window, m->s.select3, NULL);
    sfRenderWindow_drawText(m->window, m->s.select4, NULL);
    sfRenderWindow_drawText(m->window, m->s.select5, NULL);
    sfRenderWindow_drawText(m->window, m->s.back_txt, NULL);
    sfRenderWindow_drawText(m->window, m->s.play_txt, NULL);
}

void draw_select_perso(Global_t *m)
{
    if (m->current == 11) {
        sfRenderWindow_drawSprite(m->window, m->s.fond, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p1, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p2, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p3, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p4, NULL);
        sfRenderWindow_drawSprite(m->window, m->s.p5, NULL);
        check_hover_select(m);
        sfRenderWindow_drawText(m->window, m->s.title, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.button4, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.button5, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.back, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->s.play, NULL);
        draw_select_perso2(m);
    }
}

static void destroy_select_perso2(Global_t *m)
{
    sfRectangleShape_destroy(m->s.button1);
    sfRectangleShape_destroy(m->s.button2);
    sfRectangleShape_destroy(m->s.button3);
    sfRectangleShape_destroy(m->s.button4);
    sfRectangleShape_destroy(m->s.button5);
    sfRectangleShape_destroy(m->s.play);
    sfRectangleShape_destroy(m->s.back);
    sfText_destroy(m->s.play_txt);
    sfText_destroy(m->s.back_txt);
    sfText_destroy(m->s.select1);
    sfText_destroy(m->s.select2);
    sfText_destroy(m->s.select3);
    sfText_destroy(m->s.select4);
    sfText_destroy(m->s.select5);
}

void destroy_select_perso(Global_t *m)
{
    sfSprite_destroy(m->s.fond);
    sfText_destroy(m->s.title);
    sfSprite_destroy(m->s.p1);
    sfSprite_destroy(m->s.p2);
    sfSprite_destroy(m->s.p3);
    sfSprite_destroy(m->s.p4);
    sfSprite_destroy(m->s.p5);
    sfSprite_destroy(m->s.p1_w);
    sfSprite_destroy(m->s.p2_w);
    sfSprite_destroy(m->s.p3_w);
    sfSprite_destroy(m->s.p4_w);
    sfSprite_destroy(m->s.p5_w);
    sfSprite_destroy(m->s.p1_d);
    sfSprite_destroy(m->s.p2_d);
    sfSprite_destroy(m->s.p3_d);
    sfSprite_destroy(m->s.p4_d);
    sfSprite_destroy(m->s.p5_d);
    destroy_select_perso2(m);
}

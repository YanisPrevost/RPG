/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/
#include "../rpg.h"

void init_music(Global_t *m)
{
    m->menu.music = sfMusic_createFromFile("assets/music/music_menu.ogg");
    m->hub.music = sfMusic_createFromFile("assets/music/music_hub.ogg");
    m->setting.music = sfMusic_createFromFile("assets/music/music_combat.ogg");
    sfMusic_play(m->menu.music);
    sfMusic_setLoop(m->menu.music, sfTrue);
    sfMusic_setLoop(m->hub.music, sfTrue);
    sfMusic_setLoop(m->setting.music, sfTrue);
}

static void check_globalbounds(Global_t *m)
{
    m->menu.gb_b1 = sfRectangleShape_getGlobalBounds(m->menu.button1);
    m->menu.gb_b2 = sfRectangleShape_getGlobalBounds(m->menu.button2);
    m->menu.gb_b3 = sfRectangleShape_getGlobalBounds(m->menu.button3);
    m->menu.gb_b4 = sfRectangleShape_getGlobalBounds(m->menu.button4);
}

static void check_save_continue(Global_t *m)
{
    FILE *file = fopen("assets/save_party/save.txt", "r");
    int c;

    c = fgetc(file);
    if (c == EOF) {
        fclose(file);
        return;
    }
    m->is_a_save = true;
    fclose(file);
}

void init_menu(Global_t *m)
{
    sfRenderWindow_setMouseCursorVisible(m->window, sfFalse);
    m->menu.save_auto_clk = sfClock_create();
    m->current = 10;
    m->hub.clock = sfClock_create();
    m->menu.wsize = sfRenderWindow_getSize(m->window);
    m->menu.map = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->menu.lock = init_sprite("assets/menu/lock.png", (sfVector2f){0, 0});
    m->menu.cursor = init_sprite("assets/menu/cursor.png", (sfVector2f){0, 0});
    m->menu.title = init_text(m, "MY RPG", 125, 0);
    m->menu.new_game = init_text(m, "NEW GAME", 60, 300);
    m->menu.continuer = init_text(m, "CONTINUE", 60, 450);
    m->menu.settings = init_text(m, "SETTINGS", 50, 700);
    m->menu.exit = init_text(m, "EXIT", 35, 800);
    m->menu.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    m->menu.button2 = init_button(m, (sfVector2f){325, 100}, 445);
    check_save_continue(m);
    m->menu.button3 = init_button(m, (sfVector2f){270, 83}, 695);
    m->menu.button4 = init_button(m, (sfVector2f){190, 58}, 795);
    check_globalbounds(m);
}

static void hover_continue(Global_t *m)
{
    if (m->is_a_save == true) {
        if (sfFloatRect_contains(&m->menu.gb_b2, m->mouse.x, m->mouse.y))
            sfRectangleShape_setFillColor(m->menu.button2,
            sfColor_fromRGB(186, 135, 36));
        else
            sfRectangleShape_setFillColor(m->menu.button2,
            sfColor_fromRGB(245, 178, 49));
        return;
    }
    if (sfFloatRect_contains(&m->menu.gb_b2, m->mouse.x, m->mouse.y))
        sfRectangleShape_setFillColor(m->menu.button2,
        sfColor_fromRGB(100, 100, 100));
    else
        sfRectangleShape_setFillColor(m->menu.button2,
        sfColor_fromRGB(150, 150, 150));
}

static void check_hover(Global_t *m)
{
    hover(m, m->menu.button1, &m->menu.gb_b1);
    if (sfFloatRect_contains(&m->menu.gb_b1, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft))
            m->current = 11;
    hover_continue(m);
    if (sfFloatRect_contains(&m->menu.gb_b2, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft) && m->is_a_save == true) {
            sfMusic_pause(m->menu.music);
            sfMusic_play(m->hub.music);
            m->current = 12;
        }
    hover(m, m->menu.button3, &m->menu.gb_b3);
    if (sfFloatRect_contains(&m->menu.gb_b3, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->old_current = m->current;
            m->current = 13;
            init_setting(m);
        }
    hover(m, m->menu.button4, &m->menu.gb_b4);
    click(m, &m->menu.gb_b4, -1);
}

static void draw_lock(Global_t *m)
{
    sfFloatRect rect_pos;
    float pos_x;

    sfSprite_setScale(m->menu.lock, (sfVector2f){3, 3});
    rect_pos = sfSprite_getLocalBounds(m->menu.lock);
    pos_x = (m->menu.wsize.x - (rect_pos.width * 3)) / 2;
    sfSprite_setPosition(m->menu.lock, (sfVector2f){pos_x, 450});
    if (sfFloatRect_contains(&m->menu.gb_b2, m->mouse.x, m->mouse.y)
    && m->is_a_save == false)
        sfRenderWindow_drawSprite(m->window, m->menu.lock, NULL);
}

void draw_menu(Global_t *m)
{
    if (m->current == 10) {
        check_hover(m);
        sfRenderWindow_drawSprite(m->window, m->menu.map, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button4, NULL);
        sfRenderWindow_drawText(m->window, m->menu.title, NULL);
        sfRenderWindow_drawText(m->window, m->menu.new_game, NULL);
        sfRenderWindow_drawText(m->window, m->menu.continuer, NULL);
        draw_lock(m);
        sfRenderWindow_drawText(m->window, m->menu.settings, NULL);
        sfRenderWindow_drawText(m->window, m->menu.exit, NULL);
    }
}

void destroy_menu(Global_t *m)
{
    sfImage_destroy(m->image);
    sfMusic_destroy(m->menu.music);
    sfMusic_destroy(m->hub.music);
    sfMusic_destroy(m->setting.music);
    sfSprite_destroy(m->menu.cursor);
    sfSprite_destroy(m->menu.map);
    sfSprite_destroy(m->menu.lock);
    sfText_destroy(m->menu.title);
    sfText_destroy(m->menu.new_game);
    sfText_destroy(m->menu.continuer);
    sfText_destroy(m->menu.settings);
    sfText_destroy(m->menu.exit);
    sfRectangleShape_destroy(m->menu.button1);
    sfRectangleShape_destroy(m->menu.button2);
    sfRectangleShape_destroy(m->menu.button3);
    sfRectangleShape_destroy(m->menu.button4);
    sfClock_destroy(m->menu.save_auto_clk);
}

void draw_mouse(Global_t *m)
{
    sfVector2f pos_c = {m->mouse.x, m->mouse.y};

    sfRenderWindow_setMouseCursorVisible(m->window, sfFalse);
    sfSprite_setPosition(m->menu.cursor, pos_c);
    if (m->show_mouse == true && m->mouse.y > -1 &&
    m->mouse.x > -1 && m->current == 10 || m->current == 11 ||
    m->current == 13 || m->current == 20 || m->current == 21 ||
    m->current == 22 || m->current == 23 || m->current == 24 ||
    m->current == 25)
        sfRenderWindow_drawSprite(m->window, m->menu.cursor, NULL);
}

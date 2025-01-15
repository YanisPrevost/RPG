/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** player_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void dest_p_interface(Global_t *m)
{
    sfSprite_destroy(m->univ.interface.fond_interf);
    sfTexture_destroy(m->univ.interface.Fond_interf);
    sfSprite_destroy(m->univ.interface.cursor);
    sfTexture_destroy(m->univ.interface.Cursor);
    sfClock_destroy(m->univ.interface.curs_clock);
}

void init_player_interface(Global_t *m)
{
    char *link1 = "assets/fight/fond_interface.png";
    char *link2 = "assets/inv/cursor.png";

    m->univ.interface.fond_interf = sfSprite_create();
    m->univ.interface.Fond_interf = sfTexture_createFromFile(link1, NULL);
    m->univ.interface.cursor = sfSprite_create();
    m->univ.interface.Cursor = sfTexture_createFromFile(link2, NULL);
    SP_TXR(m->univ.interface.fond_interf, m->univ.interface.Fond_interf, 0);
    SP_TXR(m->univ.interface.cursor, m->univ.interface.Cursor, sfFalse);
    sfSprite_setScale(m->univ.interface.cursor, (sfVector2f){0.2, 0.2});
    m->univ.interface.curs_clock = sfClock_create();
    m->univ.interface.limite_tour = 5;
    m->univ.interface.tour = sfText_create();
    sfText_setFont(m->univ.interface.tour, m->dialogue.Font);
    sfText_setFillColor(m->univ.interface.tour, sfBlack);
    sfText_setCharacterSize(m->univ.interface.tour, 20);
    m->univ.interface.heal_capa = 5;
}

static void gest_err_pose(Global_t *m, sfVector2f pose_sp)
{
    if (pose_sp.x > 1000) {
        pose_sp.x -= 150;
        pose_sp.y -= 90;
    } else {
        pose_sp.x += 50;
        pose_sp.y -= 90;
    }
    if (pose_sp.y > 600) {
        pose_sp.y -= 150;
        pose_sp.x -= 100;
    }
    if (pose_sp.y < 20) {
        pose_sp.y += 150;
        pose_sp.x -= 100;
    }
    sfSprite_setPosition(m->univ.interface.fond_interf, pose_sp);
    sfRenderWindow_drawSprite(m->window, m->univ.interface.fond_interf, NULL);
}

static void place_interface(Global_t *m)
{
    sfVector2f pose_sp;

    if (m->univ.interface.who == 0)
        pose_sp = sfSprite_getPosition(m->univ.spr_roy);
    if (m->univ.interface.who == 1)
        pose_sp = sfSprite_getPosition(m->univ.spr_infe);
    if (m->univ.interface.who == 2)
        pose_sp = sfSprite_getPosition(m->univ.spr_pate);
    if (m->univ.interface.who == 3)
        pose_sp = sfSprite_getPosition(m->univ.spr_xmara);
    if (m->univ.interface.who == 4)
        pose_sp = sfSprite_getPosition(m->univ.spr_raca);
    gest_err_pose(m, pose_sp);
}

static void eventup(Global_t *m, int max_position)
{
    m->univ.interface.cursor_position--;
    m->univ.interface.where--;
    if (m->univ.interface.cursor_position < 0) {
        m->univ.interface.cursor_position = max_position;
        m->univ.interface.where = 2;
    }
    sfClock_restart(m->univ.interface.curs_clock);
}

static void eventdown(Global_t *m, int max_position)
{
    m->univ.interface.cursor_position++;
    m->univ.interface.where++;
    if (m->univ.interface.cursor_position > max_position) {
        m->univ.interface.cursor_position = 0;
        m->univ.interface.where = 0;
    }
    sfClock_restart(m->univ.interface.curs_clock);
}

void moove_cursor(Global_t *m)
{
    const int max_position = 2;
    const float y_increment = 48.0f;
    const float initial_y = 48.0f;
    sfTime time = sfClock_getElapsedTime(m->univ.interface.curs_clock);
    float elapsed_seconds = sfTime_asSeconds(time);

    m->univ.interface.pose_curs =
    sfSprite_getPosition(m->univ.interface.fond_interf);
    m->univ.interface.pose_curs.x += 18;
    m->univ.interface.pose_curs.y +=
    initial_y + (m->univ.interface.cursor_position * y_increment);
    if (elapsed_seconds > 0.2f) {
        if (sfKeyboard_isKeyPressed(sfKeyS))
            eventdown(m, max_position);
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            eventup(m, max_position);
    }
    sfSprite_setPosition(m->univ.interface.cursor,
    m->univ.interface.pose_curs);
}

static void gest_cursor(Global_t *m)
{
    moove_cursor(m);
    sfRenderWindow_drawSprite(m->window, m->univ.interface.cursor, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        if (m->univ.interface.where == 1)
            hp_up(m);
        if (m->univ.interface.where == 2)
            m->univ.interface.attack_gpy = true;
        m->univ.interface.select_inteface = false;
        m->univ.interface.cursor_position = 0;
        m->univ.interface.where = 0;
        m->univ.interface.limite_tour -= 1;
        passif_infenium(m);
    }
}

void draw_player_interface(Global_t *m)
{
    if (m->univ.interface.select_inteface
        && m->current >= 1 && m->current <= 8) {
        place_interface(m);
        gest_cursor(m);
        for (int i = 0; i < 5; i++)
            m->perso[i].case_visble = false;
    }
}

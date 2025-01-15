/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_tools.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static int check_buy_delay(Global_t *m)
{
    sfTime elapsed_time;
    float seconds;
    int code = 0;

    if (!m->shop.buy_clock) {
        m->shop.buy_clock = sfClock_create();
    }
    elapsed_time = sfClock_getElapsedTime(m->shop.buy_clock);
    seconds = sfTime_asSeconds(elapsed_time);
    if (seconds >= 0.5f) {
        sfClock_restart(m->shop.buy_clock);
        code = 1;
    }
    return code;
}

static void more(Global_t *m, int w, char *str)
{
    m->shop.Font = sfFont_createFromFile("assets/font.ttf");
    m->shop.text = sfText_create();
    sfText_setFont(m->shop.text, m->shop.Font);
    sfText_setString(m->shop.text, str);
    sfText_setColor(m->shop.text, sfRed);
    sfText_setCharacterSize(m->shop.text, 18);
    sfText_setPosition(m->shop.text, (sfVector2f){235, 265});
    if (m->weapons[w].cost > m->gold)
        sfRenderWindow_drawSprite(m->window, m->shop.lock, NULL);
    if ((sfKeyboard_isKeyPressed(sfKeyB)) && check_buy_delay(m)) {
        if (m->weapons[w].cost < m->gold)
            import_weapon_inv(m, w);
    }
    return;
}

sfText *init_stats(Global_t *m, int w)
{
    char str[50];
    int atk = m->weapons[w].attack;
    int rng = m->weapons[w].rng;
    int crit = m->weapons[w].crit;
    int acc = m->weapons[w].accuracy;
    int cost = m->weapons[w].cost;

    if (m->shop.text != NULL) {
        sfText_destroy(m->shop.text);
        m->shop.text = NULL;
    }
    if (m->shop.Font != NULL) {
        sfFont_destroy(m->shop.Font);
        m->shop.Font = NULL;
    }
    sprintf(str, "%d\n\n%d\n\n%d\n\n%d\n\n", atk, rng, crit, acc);
    sprintf(str + strlen(str), "%s%s%d", TABS_5, TABS_6, cost);
    more(m, w, str);
    return m->shop.text;
}

static void suite(Global_t *m)
{
    if (m->shop.hovered_index == 7)
        init_stats(m, RARE_AXE);
    if (m->shop.hovered_index == 8)
        init_stats(m, LEGENDARY_SWORD);
    if (m->shop.hovered_index == 9)
        init_stats(m, LEGENDARY_BOW);
    if (m->shop.hovered_index == 10)
        init_stats(m, LEGENDARY_SPEAR);
    if (m->shop.hovered_index == 11)
        init_stats(m, LEGENDARY_AXE);
    if (m->shop.hovered_index == 12)
        init_stats(m, THUNDER_BOOK);
    if (m->shop.hovered_index == 13)
        init_stats(m, FIRE_BOOK);
    if (m->shop.hovered_index == 14)
        init_stats(m, FREEZE_BOOK);
    if (m->shop.hovered_index == 15)
        init_stats(m, POTION);
}

void draw_stats_shop(Global_t *m)
{
    if (m->shop.hovered_index == 0)
        init_stats(m, COMMON_SWORD);
    if (m->shop.hovered_index == 1)
        init_stats(m, COMMON_BOW);
    if (m->shop.hovered_index == 2)
        init_stats(m, COMMON_SPEAR);
    if (m->shop.hovered_index == 3)
        init_stats(m, COMMON_AXE);
    if (m->shop.hovered_index == 4)
        init_stats(m, RARE_SWORD);
    if (m->shop.hovered_index == 5)
        init_stats(m, RARE_BOW);
    if (m->shop.hovered_index == 6)
        init_stats(m, RARE_SPEAR);
    suite(m);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** hub.c
*/
#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static void reading(Global_t *m)
{
    m->dialogue.pro_dia = sfText_create();
    readdialoguefromfile(m, "dialogue/prologue.txt", m->dialogue.lines);
    readdialoguefromfile(m, "dialogue/pou1.txt", m->dialogue.lines_w1);
    readdialoguefromfile(m, "dialogue/pou2.txt", m->dialogue.lines_w2);
    readdialoguefromfile(m, "dialogue/pou3.txt", m->dialogue.lines_w3);
    readdialoguefromfile(m, "dialogue/pou4.txt", m->dialogue.lines_w4);
    readdialoguefromfile(m, "dialogue/pou5.txt", m->dialogue.lines_w5);
    readdialoguefromfile(m, "dialogue/pou6.txt", m->dialogue.lines_w6);
    readdialoguefromfile(m, "dialogue/pou7.txt", m->dialogue.lines_w7);
    readdialoguefromfile(m, "dialogue/pou8.txt", m->dialogue.lines_w8);
}

static void init_hub2(Global_t *m, hub_t *h)
{
    char *link_dia_b = "assets/perso/dialogue/diaboard1.png";
    char *link_dia_b2 = "assets/perso/dialogue/diaboard2.png";

    m->hub.swap_clock = sfClock_create();
    m->dialogue.dia_name = sfText_create();
    m->dialogue.Font = sfFont_createFromFile("assets/dialogue_font.ttf");
    sfText_setFont(m->dialogue.dia_name, m->dialogue.Font);
    m->hub.cadre = sfSprite_create();
    m->hub.Cadre = SET_TX(link_dia_b, NULL);
    m->hub.Cadre2 = SET_TX(link_dia_b2, NULL);
    reading(m);
    sfSprite_setTexture(h->bulle, h->Bulle, sfFalse);
    sfSprite_setScale(h->bulle, (sfVector2f){0.07, 0.07});
    sfSprite_setScale(h->pouilleux, (sfVector2f){0.8, 0.8});
    sfSprite_setTexture(h->pouilleux, h->Pouilleux, sfFalse);
    sfSprite_setTexture(h->sprite_hub, h->texture_hub, sfFalse);
    sfSprite_setTexture(h->sprite_hub_night, h->texture_hub_night, sfFalse);
    sfSprite_setTextureRect(h->sprite_perso, h->rect);
    sfSprite_setPosition(h->sprite_perso, (sfVector2f){694, 380});
    sfSprite_setScale(h->sprite_perso, (sfVector2f){0.7, 0.7});
}

void init_hub(hub_t *h, Global_t *m)
{
    char *link_pou = "assets/perso/dialogue/npc/pouilleux.png";
    char *link_bull = "assets/perso/dialogue/bulle.png";

    h->view = sfView_createFromRect((sfFloatRect){0, 0, 1408, 800});
    h->rect = (sfIntRect){0, 512 + 65 * 2, 65, 65};
    h->sprite_perso = sfSprite_create();
    h->texture_hub = SET_TX("maps/map.png", NULL);
    h->texture_hub_night = SET_TX("maps/map_night.png", NULL);
    h->sprite_hub = sfSprite_create();
    h->sprite_hub_night = sfSprite_create();
    m->hub.normal_view = sfView_createFromRect((sfFloatRect)
    {0, 0, 1920, 1080});
    h->movement = (sfVector2f){0, 0};
    h->hitbox = sfImage_createFromFile("maps/map_d.png");
    h->pouilleux = sfSprite_create();
    h->Pouilleux = SET_TX(link_pou, NULL);
    h->bulle = sfSprite_create();
    h->Bulle = SET_TX(link_bull, NULL);
    init_rain(m);
    init_hub2(m, h);
}

void vision(Global_t *m, hub_t *h)
{
    if (m->perso->is_visible) {
        if (GET_SIZE(h->view).x < 1920 || GET_SIZE(h->view).y < 1080)
            sfView_zoom(h->view, 1.05f);
        sfRenderWindow_setView(m->window, m->hub.normal_view);
    }
    if (!m->perso->is_visible) {
        if (GET_SIZE(h->view).x > 860 || GET_SIZE(h->view).y > 800)
            sfView_zoom(h->view, 0.95f);
        sfRenderWindow_setView(m->window, h->view);
    }
}

static void draw_night(Global_t *m, hub_t *h)
{
    time_t rawtime;
    struct tm *timeinfo;

    sfSprite_setTexture(h->sprite_perso, h->texture_perso, sfTrue);
    sfRenderWindow_drawSprite(m->window, h->sprite_hub, NULL);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    if (timeinfo->tm_hour >= 10 || timeinfo->tm_hour < 10)
        sfRenderWindow_drawSprite(m->window, h->sprite_hub_night, NULL);
}

void draw_hub(Global_t *m, hub_t *h)
{
    char *perso = NULL;

    if (m->current == 0) {
        perso = m->perso[m->perso->current_perso].texture_battle;
        vision(m, h);
        if (h->texture_perso != NULL) {
            sfTexture_destroy(h->texture_perso);
            h->texture_perso = NULL;
        }
        h->texture_perso = SET_TX(perso, NULL);
        draw_night(m, h);
        if (!m->perso->is_visible)
            movecharacter(m, h);
        h->pos_sprite = sfSprite_getPosition(h->sprite_perso);
        h->color = sfImage_getPixel(h->hitbox, (h->pos_sprite.x +
        h->movement.x + 20), (h->pos_sprite.y + h->movement.y + 37));
        //if (m->is_night == true && m->zone5.is_w5_clear)
        draw_rain(m);
    }
}

void destroy_hub(Global_t *m, hub_t *h)
{
    sfClock_destroy(m->hub.clock);
    sfImage_destroy(h->hitbox);
    sfSprite_destroy(h->sprite_hub);
    sfSprite_destroy(h->sprite_hub_night);
    sfSprite_destroy(h->sprite_perso);
    sfTexture_destroy(h->texture_hub);
    sfTexture_destroy(h->texture_hub_night);
    sfTexture_destroy(h->texture_perso);
    sfSprite_destroy(h->pouilleux);
    sfTexture_destroy(h->Pouilleux);
    sfSprite_destroy(h->bulle);
    sfTexture_destroy(h->Bulle);
    sfText_destroy(m->dialogue.pro_dia);
    sfText_destroy(m->dialogue.dia_name);
    sfFont_destroy(m->dialogue.Font);
    sfTexture_destroy(m->hub.Cadre2);
    sfClock_destroy(m->hub.swap_clock);
    sfView_destroy(m->hub.normal_view);
    sfView_destroy(h->view);
    free_rain(m);
}

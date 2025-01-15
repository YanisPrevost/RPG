/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void draw_text(sfVector2f pos, char *msg, Global_t *m, fight_t *f)
{
    sfText *text = sfText_create();

    sfText_setPosition(text, pos);
    sfText_setFont(text, f->font);
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, 80);
    sfRenderWindow_drawText(m->window, text, NULL);
    sfText_destroy(text);
}

static void draw_text2(sfVector2f pos, char *msg, Global_t *m, fight_t *f)
{
    sfText *text = sfText_create();

    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1);
    sfText_setPosition(text, pos);
    sfText_setFont(text, f->font);
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(m->window, text, NULL);
    sfText_destroy(text);
}

void draw_weapon_advantage_atk(Perso_t *atk, Perso_t *def,
    fight_t *f, Global_t *m)
{
    sfSprite *logo_sprite = sfSprite_create();

    sfSprite_setTexture(logo_sprite, f->globat_texture, sfFalse);
    if (is_weapon_advantage(atk->current_weapon, def->current_weapon) == 1)
        sfSprite_setTextureRect(logo_sprite, (sfIntRect){1, 66, 17, 16});
    else if (is_weapon_advantage(atk->current_weapon,
    def->current_weapon) == -1)
        sfSprite_setTextureRect(logo_sprite, (sfIntRect){20, 66, 16, 16});
    else {
        sfSprite_destroy(logo_sprite);
        return;
    }
    sfSprite_setScale(logo_sprite, (sfVector2f){5, 5});
    sfSprite_setPosition(logo_sprite, (sfVector2f){850, 775});
    sfRenderWindow_drawSprite(m->window, logo_sprite, NULL);
    sfSprite_destroy(logo_sprite);
}

void draw_weapon_advantage_def(Perso_t *atk, Perso_t *def,
    fight_t *f, Global_t *m)
{
    sfSprite *logo_sprite = sfSprite_create();

    sfSprite_setTexture(logo_sprite, f->globat_texture, sfFalse);
    if (is_weapon_advantage(def->current_weapon, atk->current_weapon) == 1)
        sfSprite_setTextureRect(logo_sprite, (sfIntRect){1, 66, 17, 16});
    else if (is_weapon_advantage(def->current_weapon,
    atk->current_weapon) == -1)
        sfSprite_setTextureRect(logo_sprite, (sfIntRect){20, 66, 16, 16});
    else {
        sfSprite_destroy(logo_sprite);
        return;
    }
    sfSprite_setScale(logo_sprite, (sfVector2f){5, 5});
    sfSprite_setPosition(logo_sprite, (sfVector2f){1485, 775});
    sfRenderWindow_drawSprite(m->window, logo_sprite, NULL);
    sfSprite_destroy(logo_sprite);
}

static void draw_current_weapon(Perso_t *atk, Global_t *m, sfVector2f pos)
{
    atk->current_weapon->sprite = sfSprite_create();
    if (atk->current_weapon->attack > 0)
        sfSprite_setTexture(atk->current_weapon->sprite,
    SET_TX(atk->current_weapon->link_texture, NULL), sfFalse);
    sfSprite_setPosition(atk->current_weapon->sprite, pos);
    sfSprite_setScale(atk->current_weapon->sprite, (sfVector2f){5, 5});
    sfRenderWindow_drawSprite(m->window, atk->current_weapon->sprite, NULL);
    sfSprite_destroy(atk->current_weapon->sprite);
}

static void draw_stats(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    draw_text2((sfVector2f){175, 690}, ATOI(get_hit_rate(atk, def)), m, f);
    draw_text2((sfVector2f){175, 740}, ATOI(f->dmg_atk), m, f);
    draw_text2((sfVector2f){175, 790}, ATOI(get_crit_rate(atk, def)), m, f);
    draw_text2((sfVector2f){1775, 690}, ATOI(get_hit_rate(def, atk)), m, f);
    draw_text2((sfVector2f){1775, 740}, ATOI(f->dmg_def), m, f);
    draw_text2((sfVector2f){1775, 790}, ATOI(get_crit_rate(def, atk)), m, f);
    draw_text((sfVector2f){350, 760}, atk->current_weapon->name, m, f);
    draw_text((sfVector2f){1000, 760}, def->current_weapon->name, m, f);
    draw_text((sfVector2f){825, 875}, ATOI(atk->stat_p.current_hp), m, f);
    draw_text((sfVector2f){1775, 875}, ATOI(def->stat_p.current_hp), m, f);
    draw_current_weapon(atk, m, (sfVector2f){850, 775});
    draw_current_weapon(def, m, (sfVector2f){1485, 775});
    draw_weapon_advantage_atk(atk, def, f, m);
    draw_weapon_advantage_def(atk, def, f, m);
}

static void set_emy_ba(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *fight)
{
    fight->rect_empty_bar = (sfIntRect){1, 26, def->stat_p.max_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);
    sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);
    fight->rect_ennemy_bar = (sfIntRect){1, 58,
    def->stat_p.current_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->ennemy_bar_sprite, fight->rect_ennemy_bar);
    sfRenderWindow_drawSprite(m->window, fight->ennemy_bar_sprite, NULL);
    fight->rect_hero_bar = (sfIntRect){1, 50,
    atk->stat_p.current_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->hero_lifebar_sprite, fight->rect_hero_bar);
    sfRenderWindow_drawSprite(m->window, fight->hero_lifebar_sprite, NULL);
}

void print_fight_scene(Global_t *m, fight_t *fight)
{
    Perso_t *atk = &m->perso[m->univ.interface.attacker];
    Perso_t *def = &m->perso[m->univ.interface.defender];

    if (m->univ.interface.go_fight && (m->current >= 1 && m->current <= 8)) {
        sfRenderWindow_setView(m->window, m->hub.normal_view);
        sfRenderWindow_drawSprite(m->window, fight->combat_scene, NULL);
        sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){100, 900});
        fight->rect_empty_bar = (sfIntRect){1, 26,
        atk->stat_p.max_hp * 2 + 1, 7};
        sfSprite_setTextureRect(fight->empty_bar_sprite,
        fight->rect_empty_bar);
        sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);
        sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){1075, 900});
        set_emy_ba(atk, def, m, fight);
        draw_text((sfVector2f){25, 50}, atk->name_perso, m, fight);
        draw_text((sfVector2f){1525, 50}, def->name_perso, m, fight);
        draw_stats(atk, def, m, fight);
        print_sprites(atk, def, m, fight);
    }
}

void destroy_fight_struct(fight_t *fight)
{
    sfSprite_destroy(fight->empty_bar_sprite);
    sfSprite_destroy(fight->hero_lifebar_sprite);
    sfTexture_destroy(fight->globat_texture);
    sfSprite_destroy(fight->combat_scene);
    sfSprite_destroy(fight->ennemy_bar_sprite);
    sfFont_destroy(fight->font);
    sfSprite_destroy(fight->empty_bar_sprite2);
    sfSprite_destroy(fight->hero_lifebar_sprite2);
    sfSprite_destroy(fight->ennemy_bar_sprite2);
    sfSprite_destroy(fight->dead_head);
    sfSprite_destroy(fight->dead_head2);
    sfTexture_destroy(fight->Dead_head);
    free_slash(fight);
}

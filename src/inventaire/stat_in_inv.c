/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** stat_in_inv.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

static void draw_stats_text(Global_t *m, int who, sfFont *font, sfText *text)
{
    int str = m->perso[who].stat_p.str;
    int mag = m->perso[who].stat_p.mag;
    int skill = m->perso[who].stat_p.skl;
    int luck = m->perso[who].stat_p.lck;
    int def = m->perso[who].stat_p.def;
    int res = m->perso[who].stat_p.res;
    int speed = m->perso[who].stat_p.spd;
    char *con = "-----";
    char all[200];

    sprintf(all, "%d%s%d\n\n", str, TABS_5, luck);
    sprintf(all + strlen(all), "%d%s%d\n\n", mag, TABS_5, def);
    sprintf(all + strlen(all), "%d%s%d\n\n", skill, TABS_5, res);
    sprintf(all + strlen(all), "%d%s%s", speed, TABS_5, con);
    sfText_setPosition(text, (sfVector2f){1030, 380});
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, all);
    sfRenderWindow_drawText(m->window, text, NULL);
}

void set_others_stats(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    draw_stats_text(m, who, font, text);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void set_text_lvl_xd(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int level = m->perso[who].stat_p.level;
    int xp = m->perso[who].stat_p.xp;
    char str[20];

    sprintf(str, "%d\t%d", level, xp);
    if (strlen(str) <= 4) {
        sprintf(str, "%d\t  %d", level, xp);
        sfText_setPosition(text, (sfVector2f){690, 680});
    } else
        sfText_setPosition(text, (sfVector2f){684, 680});
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void set_sprite_mini(Global_t *m, int who)
{
    sfIntRect current_hero_head = {12, 713, 46, 59};
    sfSprite *sprite_perso = sfSprite_create();
    char *filename = m->perso[who].texture_battle;
    sfTexture *texture_perso = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(sprite_perso, texture_perso, sfTrue);
    sfSprite_setTextureRect(sprite_perso, current_hero_head);
    sfSprite_setPosition(sprite_perso, (sfVector2f){833, 675});
    sfSprite_setScale(sprite_perso, (sfVector2f){1.3, 1.3});
    sfRenderWindow_drawSprite(m->window, sprite_perso, NULL);
    sfSprite_destroy(sprite_perso);
    sfTexture_destroy(texture_perso);
}

void set_text_health(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int current_hp = m->perso[who].stat_p.current_hp;
    int max_hp = m->perso[who].stat_p.max_hp;
    char str[30];

    sprintf(str, "%d\t%d", current_hp, max_hp);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){693, 735});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

static void set_sprite_head(Global_t *m, int who)
{
    sfIntRect current_hero_head = {0, 0, 96, 80};
    sfSprite *sprite_perso = sfSprite_create();
    char *filename = m->perso[who].texture_dialogue;
    sfTexture *texture_perso = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(sprite_perso, texture_perso, sfTrue);
    sfSprite_setTextureRect(sprite_perso, current_hero_head);
    sfSprite_setPosition(sprite_perso, (sfVector2f){650, 369});
    sfSprite_setScale(sprite_perso, (sfVector2f){2.5, 2.5});
    sfRenderWindow_drawSprite(m->window, sprite_perso, NULL);
    sfSprite_destroy(sprite_perso);
    sfTexture_destroy(texture_perso);
}

void set_sprite_head_name(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    char dest[20];

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlack);
    if (strlen(m->perso[who].name_perso) <= 5) {
        sprintf(dest, "\t%s", m->perso[who].name_perso);
        sfText_setString(text, dest);
    } else
        sfText_setString(text, m->perso[who].name_perso);
    sfText_setPosition(text, (sfVector2f){690, 570});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
    set_sprite_head(m, who);
}

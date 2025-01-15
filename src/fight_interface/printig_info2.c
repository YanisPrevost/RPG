/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** printig_info2.c
*/

#include "../include/perso.h"
#include "../rpg.h"

int set_dmg(fight_t *fight, Global_t *m, Perso_t *atk, Perso_t *def)
{
    if (atk->stat_p.str >= atk->stat_p.mag)
        fight->dmg_atk = get_damage_physical(atk, def);
    else
        fight->dmg_atk = get_damage_magical(atk, def);
    if (def->stat_p.str >= def->stat_p.mag)
        fight->dmg_def = get_damage_physical(def, atk);
    else
        fight->dmg_def = get_damage_magical(def, atk);
}

void reset_hp_barre(fight_t *fight, Global_t *m)
{
    sfSprite_setScale(fight->combat_scene, (sfVector2f){8, 6.25});
    sfSprite_setScale(fight->empty_bar_sprite, (sfVector2f){8, 8});
    SP_TXR(fight->empty_bar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);
    SP_TXR(fight->ennemy_bar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setPosition(fight->ennemy_bar_sprite, (sfVector2f){1075, 900});
    sfSprite_setScale(fight->ennemy_bar_sprite, (sfVector2f){8, 8});
    SP_TXR(fight->hero_lifebar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setPosition(fight->hero_lifebar_sprite, (sfVector2f){100, 900});
    sfSprite_setScale(fight->hero_lifebar_sprite, (sfVector2f){8, 8});
}

void init_lifebars(fight_t *fight, Global_t *m)
{
    fight->globat_texture = SET_TX("assets/fight/combat_visualize.png", NULL);
    fight->empty_bar_sprite = sfSprite_create();
    fight->rect_empty_bar = (sfIntRect){1, 26, 81, 7};
    fight->hero_lifebar_sprite = sfSprite_create();
    fight->combat_scene = sfSprite_create();
    fight->ennemy_bar_sprite = sfSprite_create();
    fight->font = sfFont_createFromFile("assets/fight.ttf");
    fight->is_fight = sfTrue;
    sfSprite_setTexture(fight->combat_scene,
    SET_TX("assets/fight/battle_scene.png", NULL), sfFalse);
    reset_hp_barre(fight, m);
}

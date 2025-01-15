/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_weapons.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

static void destroyer(sfText *text, sfFont *font,
    sfSprite *weapon, sfTexture *Weapon)
{
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void empty_slot(Global_t *m, sfVector2f pose_sp, sfVector2f pose_txt)
{
    int who = m->perso->current_perso;
    sfSprite *weapon = sfSprite_create();
    char *filename = "assets/weapons/empty.png";
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, pose_sp);
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, "Empty slot.");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, pose_txt);
    sfRenderWindow_drawText(m->window, text, NULL);
    destroyer(text, font, weapon, Weapon);
}

static void weapon_slot5(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT4].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 595});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT4].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 586});
    sfRenderWindow_drawText(m->window, text, NULL);
    if (m->perso->what_weapons_stat == 4)
        print_weapon5_stat(m, who);
    destroyer(text, font, weapon, Weapon);
}

static void weapon_slot4(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT3].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 557});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT3].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 546});
    sfRenderWindow_drawText(m->window, text, NULL);
    if (m->perso->what_weapons_stat == 3) {
        print_weapon4_stat(m, who);
    }
    destroyer(text, font, weapon, Weapon);
}

static void weapon_slot3(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT2].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 519});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT2].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 506});
    sfRenderWindow_drawText(m->window, text, NULL);
    if (m->perso->what_weapons_stat == 2)
        print_weapon3_stat(m, who);
    destroyer(text, font, weapon, Weapon);
}

static void heal_stick(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[HEAL].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 481});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[HEAL].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 470});
    sfRenderWindow_drawText(m->window, text, NULL);
    if (m->perso->what_weapons_stat == 1)
        print_heal_stat(m, who);
    destroyer(text, font, weapon, Weapon);
}

static void weapon_slot1(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT1].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 443});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT1].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 36);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 430});
    sfRenderWindow_drawText(m->window, text, NULL);
    if (m->perso->what_weapons_stat == 0)
        print_weapon1_stat(m, who);
    destroyer(text, font, weapon, Weapon);
}

void weapons_inv_stat2(Global_t *m, sfVector2f spr_pose,
    sfVector2f err_text, int who)
{
    spr_pose.y = 519;
    err_text.y = 506;
    if (is_empty_slot(&m->perso[who].inv_weapon[SLOT2]))
        weapon_slot3(m, who);
    else
        empty_slot(m, spr_pose, err_text);
    spr_pose.y = 557;
    err_text.y = 546;
    if (is_empty_slot(&m->perso[who].inv_weapon[SLOT3]))
        weapon_slot4(m, who);
    else
        empty_slot(m, spr_pose, err_text);
    spr_pose.y = 595;
    err_text.y = 582;
    if (is_empty_slot(&m->perso[who].inv_weapon[SLOT4]))
        weapon_slot5(m, who);
    else
        empty_slot(m, spr_pose, err_text);
}

void weapons_inv_stat(Global_t *m)
{
    int who = m->perso->current_perso;
    sfVector2f empty_sprite_pose = {980, 463};
    sfVector2f err_text = {1050, 426};

    if (is_empty_slot(&m->perso[who].inv_weapon[SLOT1]))
        weapon_slot1(m, who);
    else {
        empty_sprite_pose.y -= 20;
        err_text.y += 5;
        empty_slot(m, empty_sprite_pose, err_text);
    }
    empty_sprite_pose.y = 481;
    err_text.y = 466;
    if (is_empty_slot(&m->perso[who].inv_weapon[HEAL]))
        heal_stick(m, who);
    else
        empty_slot(m, empty_sprite_pose, err_text);
    weapons_inv_stat2(m, empty_sprite_pose, err_text, who);
}

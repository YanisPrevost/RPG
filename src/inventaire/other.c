/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** other.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

void swap_current(Global_t *m)
{
    static float elapsedTime = 0.0f;
    sfTime timeElapsed = sfClock_getElapsedTime(m->perso->swap_clock);

    elapsedTime += sfTime_asSeconds(timeElapsed);
    sfClock_restart(m->perso->swap_clock);
    if (sfKeyboard_isKeyPressed(sfKeyK) && elapsedTime > 0.2f) {
        m->perso->current_perso += 1;
        if (m->perso->current_perso == 5)
            m->perso->current_perso = 0;
        elapsedTime = 0.0f;
    }
}

bool is_empty_slot(Weapons_t *weapon_slot)
{
    return weapon_slot->is_empty != true;
}

void equiped_weapon(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    char *weapon_name = m->perso[who].current_weapon->name;
    char str[30];

    sprintf(str, "Equiped :  %s", weapon_name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 33);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){940, 365});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

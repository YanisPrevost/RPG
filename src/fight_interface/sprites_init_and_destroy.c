/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** sprites_init_and _destroy.c
*/

#include "../rpg.h"
#include "../include/perso.h"

void destroy_fight_sprites(fight_t *f)
{
    sfSprite_destroy(f->sprite_atk);
    sfSprite_destroy(f->sprite_def);
    sfTexture_destroy(f->texture_atk);
    sfTexture_destroy(f->texture_def);
}

static void suitte(fight_t *f)
{
    sfSprite_setPosition(f->sprite_def, (sfVector2f){1225, 450});
    sfSprite_setPosition(f->dead_head2, (sfVector2f){1210, 450});
    sfSprite_setScale(f->sprite_def, (sfVector2f){3, 3});
    sfSprite_setScale(f->dead_head, (sfVector2f){0.4, 0.4});
    sfSprite_setScale(f->dead_head2, (sfVector2f){0.4, 0.4});
}

void init_fight_sprites(Perso_t *atk, Perso_t *def, fight_t *f, Global_t *m)
{
    sfIntRect sprite_atkrect = {0, 511 + 65 * 3, 65, 65};

    f->sprite_atk = sfSprite_create();
    f->texture_atk = sfTexture_createFromFile(atk->texture_battle, NULL);
    f->sprite_def = sfSprite_create();
    f->texture_def = sfTexture_createFromFile(def->texture_battle, NULL);
    f->has_def_attacked = sfFalse;
    sfSprite_setTexture(f->sprite_atk, f->texture_atk, sfFalse);
    sfSprite_setTexture(f->dead_head, f->Dead_head, sfFalse);
    sfSprite_setTexture(f->dead_head2, f->Dead_head, sfFalse);
    sfSprite_setTextureRect(f->sprite_atk, sprite_atkrect);
    sfSprite_setPosition(f->sprite_atk, (sfVector2f){500, 450});
    sfSprite_setPosition(f->dead_head, (sfVector2f){500, 450});
    sfSprite_setScale(f->sprite_atk, (sfVector2f){3, 3});
    sfSprite_setTexture(f->sprite_def, f->texture_def, sfFalse);
    sfSprite_setTextureRect(f->sprite_def, (sfIntRect){0, 511 + 65, 65, 65});
    suitte(f);
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

const char *ennemi_wall(int current_ennemi)
{
    switch (current_ennemi) {
        case 5:
            return "assets/perso/dialogue/boss/Boss1_dialogue.png";
        case 6:
            return "assets/perso/dialogue/boss/Boss2_dialogue.png";
        case 7:
            return "assets/perso/dialogue/boss/Boss3_dialogue.png";
        case 8:
            return "assets/perso/dialogue/boss/Boss4_dialogue.png";
        case 9:
            return "assets/perso/dialogue/boss/Boss5_dialogue.png";
        case 10:
            return "assets/perso/dialogue/boss/Boss6_dialogue.png";
        case 11:
            return "assets/perso/dialogue/boss/Boss7_dialogue.png";
        case 12:
            return "assets/perso/dialogue/boss/Boss8_dialogue.png";
        default:
            return NULL;
    }
}

const char *hero_wall(int current_perso)
{
    switch (current_perso) {
        case 0:
            return "assets/perso/dialogue/hero/dialogue_roy.png";
        case 1:
            return "assets/perso/dialogue/hero/dialogue_infenium.png";
        case 2:
            return "assets/perso/dialogue/hero/dialogue_patecarbo.png";
        case 3:
            return "assets/perso/dialogue/hero/dialogue_xmarano.png";
        case 4:
            return "assets/perso/dialogue/hero/dialogue_racaillou.png";
        default:
            return NULL;
    }
}

void affichage_mechant(RenderContext_t *context)
{
    const char *filename3 = ennemi_wall(context->current_boss);
    sfTexture *texture3 = sfTexture_createFromFile(filename3, NULL);
    sfSprite *sprite3 = sfSprite_create();
    sfVector2f position_sprite3 = {1200, 667};
    sfIntRect base = {0, 0, 91, 80};
    sfVector2f scale = {3, 3};

    if (filename3) {
        sfSprite_setTexture(sprite3, texture3, sfTrue);
        sfSprite_setPosition(sprite3, position_sprite3);
        sfSprite_setTextureRect(sprite3, base);
        sfSprite_setScale(sprite3, scale);
        sfRenderWindow_drawSprite(context->window, sprite3, NULL);
        sfSprite_destroy(sprite3);
        sfTexture_destroy(texture3);
    }
}

void affichage_hero(RenderContext_t *context)
{
    const char *filename2 = hero_wall(context->current_hero);
    sfTexture *texture2 = sfTexture_createFromFile(filename2, NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfVector2f position_sprite2 = {400, 667};
    sfIntRect base = {0, 0, 91, 80};
    sfVector2f scale = {3, 3};

    if (filename2) {
        sfSprite_setTexture(sprite2, texture2, sfTrue);
        sfSprite_setPosition(sprite2, position_sprite2);
        sfSprite_setTextureRect(sprite2, base);
        sfSprite_setScale(sprite2, scale);
        sfRenderWindow_drawSprite(context->window, sprite2, NULL);
        sfSprite_destroy(sprite2);
        sfTexture_destroy(texture2);
    }
}

/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

void draw_dialogue2(const char *str, int x, int y, RenderContext_t *context)
{
    sfText *text = sfText_create();
    sfVector2f position = {x, y};

    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void draw_dialogue(const char *str, int x, int y, RenderContext_t *context)
{
    sfText *text = sfText_create();
    sfVector2f position = {x, y};

    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void sentencept(char *phrase, RenderContext_t *context, int x, int y)
{
    sfTexture *texture = SET_TX("dialogue/wall.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f position = {x, y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(context->window, sfWhite);
    sfRenderWindow_drawSprite(context->window, sprite, NULL);
    affichage_hero(context);
    affichage_mechant(context);
    draw_dialogue(phrase, x, y, context);
    draw_dialogue2(context->name_ennemy, 1625, 882, context);
    draw_dialogue2(context->name_hero, 170, 882, context);
    sfRenderWindow_display(context->window);
    sfSleep(sfSeconds(0.01));
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

int verif_parse(char *line, RenderContext_t *context,
    int current_perso, char *last_speaker)
{
    char *speaker = strtok(line, ":");
    char *dialogue = strtok(NULL, "\n");
    int position;

    if (strchr(line, '*') != NULL) {
        return 1;
    }
    if (current_perso == 0) {
        current_perso = 5;
    }
    if (dialogue != NULL && (atoi(speaker) == current_perso ||
    !isdigit(speaker[0]))) {
        strcpy(last_speaker, speaker);
        position = atoi(speaker) == current_perso ? 0 : 1;
        wordpt(dialogue, context, last_speaker, position);
    }
    return 0;
}

static int verif_polle(Global_t *m, FILE *file, int curr)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(m->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(m->window);
            return 1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
            return 1;
        }
    }
    return 0;
}

void parse_file(char *filename, RenderContext_t *context,
    Global_t *m, int curr)
{
    FILE *file = fopen(filename, "r");
    char line[256];
    char last_speaker[256] = "";

    context->current_boss = m->current_boss;
    context->current_hero = m->perso->current_perso;
    context->name_ennemy = m->perso[m->current_boss].name_perso;
    context->name_hero = m->perso[m->perso->current_perso].name_perso;
    while (fgets(line, sizeof(line), file)) {
        if (verif_polle(m, file, curr) == 1)
            break;
        if (verif_parse(line, context, m->perso->current_perso,
        last_speaker) == 1)
            break;
    }
    m->dialogue.start_dialogue = 0;
    sfMusic_pause(m->hub.music);
    sfMusic_play(m->setting.music);
    m->current = curr;
    fclose(file);
}

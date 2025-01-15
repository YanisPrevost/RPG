/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

int skip_ennemy(char *phrase, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;
    int x_pos = window_width * 0.62;
    int y_pos = window_height * 0.97;

    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        sentencept(phrase, context, x_pos, 950);
        sfSleep(sfSeconds(0.01));
        return 1;
    }
    return 0;
}

void ennemy_speak(char *phrase, const char *num, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;
    int dialogue_x_pos = window_width * 0.62;
    int dialogue_y_pos = window_height * 0.87;
    int text_y_pos = window_height * 0.97;

    draw_dialogue(num, dialogue_x_pos, 950, context);
    sentencept(phrase, context, dialogue_x_pos, 950);
}

int skip_hero(char *phrase, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        sentencept(phrase, context, 25, 950);
        sfSleep(sfSeconds(0.01));
        return 1;
    }
    return 0;
}

void hero_speak(char *phrase, const char *num, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    draw_dialogue(num, 25, window_height - 30, context);
    sentencept(phrase, context, 25, 950);
}

void wordpt(char *str, RenderContext_t *context, const char *num, int position)
{
    char *phrase = malloc(strlen(str) + 1);
    int should_skip = 0;

    strcpy(phrase, "");
    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        if (position == 0) {
            hero_speak(phrase, num, context);
            should_skip = skip_hero(str, context);
        }
        if (position != 0){
            ennemy_speak(phrase, num, context);
            should_skip = skip_ennemy(str, context);
        }
        if (should_skip) {
            break;
        }
    }
    sfSleep(sfSeconds(1.0));
    free(phrase);
}

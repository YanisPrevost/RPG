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

static void init_s_particle(slash_t *particle)
{
    particle->texture = SET_TX("assets/fight/slash_particle.png", NULL);
    particle->spr = sfSprite_create();
    sfSprite_setTexture(particle->spr, particle->texture, sfFalse);
    sfSprite_setScale(particle->spr, (sfVector2f){2, 2});
    particle->position.x = 1225 - rand() % 100 + 100 - (125);
    particle->position.y = 450 - rand() % 30 + 30 - (150);
    sfSprite_setPosition(particle->spr, particle->position);
    particle->life_duration = 1 * 5;
}

void update_s_particle(slash_t *particle, float deltaTime)
{
    particle->position.x = 1225 - rand() % 100 + 100 - (125);
    particle->position.y = 450 - rand() % 30 + 30 - (150);
    sfSprite_setPosition(particle->spr, particle->position);
}

void init_slash(Global_t *m, fight_t *f)
{
    for (int i = 0; i < S_PARTICLES; ++i) {
        init_s_particle(&f->s_particles[i]);
    }
    f->slash_clock = sfClock_create();
}

void free_slash(fight_t *f)
{
    for (int i = 0; i < S_PARTICLES; i++) {
        sfTexture_destroy(f->s_particles[i].texture);
        sfSprite_destroy(f->s_particles[i].spr);
    }
    sfClock_destroy(f->slash_clock);
}

void draw_white_screen(Global_t *m)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setSize(rect, (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT});
    sfRenderWindow_drawRectangleShape(m->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

int draw_slash(Global_t *m, fight_t *f)
{
    float deltaTime = sfTime_asSeconds(sfClock_getElapsedTime(f->slash_clock));

    for (int i = 0; i < S_PARTICLES; ++i) {
        if (deltaTime < f->s_particles->life_duration)
            sfRenderWindow_drawSprite(m->window, f->s_particles[i].spr, NULL);
        update_s_particle(&f->s_particles[i], deltaTime);
    }
    sfClock_restart(f->slash_clock);
}

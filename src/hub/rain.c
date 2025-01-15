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

void initparticle(rain_t *particle)
{
    particle->position.x = rand() % WINDOW_WIDTH;
    particle->position.y = rand() % WINDOW_HEIGHT;
    particle->speed.x = 10.0;
    particle->speed.y = RAIN_SPEED;
}

void updateparticle(rain_t *particle, float deltaTime)
{
    particle->position.y += particle->speed.y * deltaTime;
    particle->position.x += particle->speed.x * deltaTime;
    if (particle->position.y > WINDOW_HEIGHT) {
        particle->position.y = 0 - rand() % WINDOW_HEIGHT;
        particle->position.x = rand() % WINDOW_WIDTH;
    }
}

void init_rain(Global_t *m)
{
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        initparticle(&m->hub.particles[i]);
    }
    m->hub.vertexArray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(m->hub.vertexArray, sfLines);
    m->hub.rain_clock = sfClock_create();
}

void free_rain(Global_t *m)
{
    sfVertexArray_destroy(m->hub.vertexArray);
    sfClock_destroy(m->hub.rain_clock);
}

int draw_rain(Global_t *m)
{
    float deltaTime = sfTime_asSeconds(sfClock_restart(m->hub.rain_clock));
    sfVertex vertex1;
    sfVertex vertex2;

    sfVertexArray_clear(m->hub.vertexArray);
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        updateparticle(&m->hub.particles[i], deltaTime);
        vertex1.position = m->hub.particles[i].position;
        vertex1.color = sfColor_fromRGB(0, 192, 255);
        vertex2.position.x = m->hub.particles[i].position.x + 2;
        vertex2.position.y = m->hub.particles[i].position.y + 10;
        vertex2.color = sfColor_fromRGB(0, 192, 255);
        sfVertexArray_append(m->hub.vertexArray, vertex1);
        sfVertexArray_append(m->hub.vertexArray, vertex2);
    }
    sfRenderWindow_drawVertexArray(m->window, m->hub.vertexArray, NULL);
}

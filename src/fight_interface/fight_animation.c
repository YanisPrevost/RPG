/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void print2(Perso_t *atk, Perso_t *def, fight_t *f)
{
    if (def->stat_p.mag > def->stat_p.str && def->stat_p.current_hp > 0)
        f->dmg_atk_received = damage_magical(def, atk);
    else if (def->stat_p.current_hp > 0)
        f->dmg_atk_received = damage_physical(def, atk);
    if (def->stat_p.current_hp < 0)
        def->stat_p.current_hp = 0;
    if (atk->stat_p.current_hp < 0)
        atk->stat_p.current_hp = 0;
    f->pv_atk = atk->stat_p.current_hp;
    f->has_def_attacked = sfTrue;
    get_fight_exp(atk, def);
}

static void print1(Perso_t *atk, Perso_t *def, fight_t *f)
{
    if (atk->stat_p.mag > atk->stat_p.str)
        f->dmg_def_received = damage_magical(atk, def);
    else
        f->dmg_def_received = damage_physical(atk, def);
    if (def->stat_p.current_hp < 0)
        def->stat_p.current_hp = 0;
    if (atk->stat_p.current_hp < 0)
        atk->stat_p.current_hp = 0;
    f->pv_def = def->stat_p.current_hp;
    f->is_fight = sfFalse;
}

static void reset(Global_t *m, fight_t *f, sfClock *clock)
{
    destroy_fight_sprites(f);
    m->univ.interface.go_fight = false;
    f->is_fight = true;
    f->has_def_attacked = false;
}

void draw_spr(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    if (atk->stat_p.current_hp > 0)
        sfRenderWindow_drawSprite(m->window, f->sprite_atk, NULL);
    else
        sfRenderWindow_drawSprite(m->window, f->dead_head, NULL);
    if (def->stat_p.current_hp > 0)
        sfRenderWindow_drawSprite(m->window, f->sprite_def, NULL);
    else
        sfRenderWindow_drawSprite(m->window, f->dead_head2, NULL);
}

void lifebar_animation(Perso_t *perso, fight_t *f, bool atk)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(f->lifebar_clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.01) {
        if (atk == true &&
        perso->stat_p.current_hp > f->pv_atk - f->dmg_atk_received &&
        perso->stat_p.current_hp > 0)
            perso->stat_p.current_hp -= 1;
        if (atk == false &&
        perso->stat_p.current_hp > f->pv_def - f->dmg_def_received
        && perso->stat_p.current_hp > 0)
            perso->stat_p.current_hp -= 1;
        sfClock_restart(f->lifebar_clock);
    }
}

static void battle(Perso_t *atk, Perso_t *def, fight_t *f, float seconds)
{
    if (f->is_fight == sfTrue)
        print1(atk, def, f);
    if (f->has_def_attacked == sfFalse)
        print2(atk, def, f);
    if (seconds > 1.3f && seconds < 3.0f)
        lifebar_animation(def, f, false);
    if (seconds > 3.0f && def->stat_p.current_hp > 0)
        lifebar_animation(atk, f, true);
}

void print_sprites(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    draw_spr(atk, def, m, f);
    if (seconds > 1.3f && seconds < 1.6f)
        draw_slash(m, f);
    battle(atk, def, f, seconds);
    if (seconds > 4.3f) {
        reset(m, f, clock);
        sfClock_destroy(clock);
        sfClock_destroy(f->lifebar_clock);
        clock = NULL;
    }
}

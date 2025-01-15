/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "my.h"

static void init_dev(int argc, char **argv, Global_t *m, hub_t *h)
{
    m->show_mouse = true;
    if (argc == 2) {
        if (strcmp(argv[1], "-dev") == 0) {
            m->gold = 100000;
            m->hub.prologue_ok = true;
            m->current = 25;
            m->current_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
            m->perso->current_perso = 1;
        }
    }
}

void event_click(Global_t *m, hub_t *h, fight_t *f)
{
    if (m->current == 12 && m->load_game_called == false) {
        load_game(m, h);
        m->load_game_called = true;
    }
    if (m->event.type == sfEvtClosed || m->current == -1)
        sfRenderWindow_close(m->window);
    if (m->current >= 0 && m->current <= 8)
        inventory(m, m->event);
    if (m->current == 13)
        event_setting(m->event, m);
    what_world_dia(m);
}

static void draw_mondes(Global_t *m, fight_t *f, hub_t *h)
{
    apply_passif(m);
    draw_monde1(m, f, h);
    draw_monde2(m, f, h);
    draw_monde3(m, f, h);
    draw_monde4(m, f, h);
    draw_monde5(m, f, h);
    draw_monde6(m, f, h);
    draw_monde7(m, f, h);
    draw_monde8(m, f, h);
    draw_player_interface(m);
    attack(m, f);
    attack_ally(m, f);
}

void rpg(Global_t *m, hub_t *h, fight_t *f)
{
    sfRenderWindow_clear(m->window, sfBlack);
    while (sfRenderWindow_pollEvent(m->window, &m->event))
        event_click(m, h, f);
    draw_help(m);
    draw_menu(m);
    draw_end(m, h);
    draw_select_perso(m);
    draw_menu_option_hub(m, h);
    draw_menu_option_combat(m, h);
    draw_setting(m);
    draw_mondes(m, f, h);
    draw_shop(m);
    draw_hub(m, h);
    save_auto(m);
    draw_inventaire(m, h);
    draw_mouse(m);
    print_fight_scene(m, f);
    print_save_txt(m);
    loading_screen(m);
    sfRenderWindow_display(m->window);
}

void annihilateur2sprite(Global_t *m, hub_t *h, fight_t *f)
{
    destroy_hub(m, h);
    destroy_fight_struct(f);
    destroy_inventaire(m);
    destroy_help(m);
    destroy_menu(m);
    destroy_end(m);
    destroy_select_perso(m);
    destroy_menu_option_hub(m);
    destroy_menu_option_combat(m);
    destroy_shop(m);
    destory_all_w_maps(m);
    destroy_loading(m);
    destroy_dialoque(m);
    dest_p_interface(m);
}

static void initalisateur2sprite(Global_t *m, hub_t *h, fight_t *f)
{
    import_weapons_stats(m);
    init_pouill_dialog(m);
    init_hub(h, m);
    setup_stat(m);
    init_w_sprite(m);
    init_help(m);
    init_menu(m);
    init_end(m);
    init_music(m);
    init_select_perso(m);
    init_menu_option_hub(m);
    init_menu_option_combat(m);
    init_inventaire(m);
    init_shop(m);
    init_pose(m);
    init_loading(m);
    init_player_interface(m);
    init_lifebars(f, m);
    init_lifebars2(f, m);
}

static void set_incon(Global_t *m)
{
    const sfUint8 *iconPixels;
    sfVector2u iconSize;

    m->image = sfImage_createFromFile("assets/menu/r_w.png");
    iconPixels = sfImage_getPixelsPtr(m->image);
    iconSize = sfImage_getSize(m->image);
    sfRenderWindow_setIcon(m->window, iconSize.x, iconSize.y, iconPixels);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    hub_t h = {0};
    fight_t f = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc >= 3)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    initalisateur2sprite(&m, &h, &f);
    init_dev(argc, argv, &m, &h);
    set_incon(&m);
    while (sfRenderWindow_isOpen(m.window)) {
        m.mouse = sfMouse_getPositionRenderWindow(m.window);
        rpg(&m, &h, &f);
    }
    annihilateur2sprite(&m, &h, &f);
    sfRenderWindow_destroy(m.window);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** npc.h
*/

#ifndef NPC_H
    #define NPC_H
    #include "../rpg.h"
    #include "../include/npc.h"
    #include "../my.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #define MAX_LINES 100
    #define MAX_CHARS 200

typedef struct dial {
    char lines[MAX_LINES][MAX_CHARS];
    char lines_w1[MAX_LINES][MAX_CHARS];
    char lines_w2[MAX_LINES][MAX_CHARS];
    char lines_w3[MAX_LINES][MAX_CHARS];
    char lines_w4[MAX_LINES][MAX_CHARS];
    char lines_w5[MAX_LINES][MAX_CHARS];
    char lines_w6[MAX_LINES][MAX_CHARS];
    char lines_w7[MAX_LINES][MAX_CHARS];
    char lines_w8[MAX_LINES][MAX_CHARS];
    int lineCount;
    int currentLine;
    bool displayFull;
    sfText *pro_dia;
    bool waitForEnter;
    sfText *dia_name;
    sfFont *Font;
    int start_dialogue;
} Dialogue_t;

typedef struct npc {
    char name[10];
    char link_texture[20];
} Npc_t;

#endif

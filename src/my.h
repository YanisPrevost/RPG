/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** my.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

#ifndef MY_H
    #define MY_H
    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_RESET   "\x1b[0m"

int my_atoi(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
char *my_inttostr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr_recursive(int nb);
int my_printf(const char *format, ...);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *get_buff(char *filename);
char **str_to_word_array(char *str);

#endif

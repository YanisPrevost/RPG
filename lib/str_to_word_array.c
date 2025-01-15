/*
** EPITECH PROJECT, 2023
** str_to_word_array
** File description:
** Infos
*/
#include "../src/my.h"

char *get_buff(char *filename)
{
    int fd;
    char *buffer = malloc(sizeof(char) * 750);
    int size;

    fd = open(filename, O_RDONLY);
    size = read(fd, buffer, 750);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}

int is_alphanum2(char c)
{
    if (c == '\n' || c == '\0')
        return (0);
    return (1);
}

char *my_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (n <= i) {
        dest[i] = '\0';
    }
    return (dest);
}

char **str_to_word_array(char *str)
{
    int x = 0;
    int i = 0;
    int size = 0;
    char **arr = malloc(sizeof(char) * (1200));

    while (str[i] != '\0') {
        if (is_alphanum2(str[i]))
            size++;
        if (is_alphanum2(str[i]) == 1 && is_alphanum2(str[i + 1]) == 0) {
            arr[x] = malloc(sizeof(char) * (size + 1));
            arr[x] = my_strncpy(arr[x], &str[i - size + 1], size);
            size = 0;
            x++;
        }
        i++;
    }
    arr[x] = NULL;
    return (arr);
}

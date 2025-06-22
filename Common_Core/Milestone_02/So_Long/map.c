/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:31:31 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 19:14:56 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int count_lines(int fd)
{
    int lines = 0;
    char c;
    while (read(fd, &c, 1) > 0)
        if (c == '\n')
            lines++;
    return (lines + 1);
}

char	**read_map(char *file, t_game *game)
{
    int		fd;
    int		i;
    int		lines;
    char	**map;
    char	buffer[10000];
    ssize_t	size;
    char	*line_start;
    char	*line_end;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        exit(write(2, "Erro ao abrir o mapa\n", 22));
    lines = count_lines(fd);
    close(fd);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        exit(write(2, "Erro de alocação de memória\n", 28));
    fd = open(file, O_RDONLY);
    size = read(fd, buffer, 9999);
    close(fd);
    if (size <= 0)
    {
        free(map);
        exit(write(2, "Erro ao ler o mapa ou mapa vazio\n", 34));
    }
    buffer[size] = '\0';
    i = 0;
    line_start = buffer;
    while ((line_end = strchr(line_start, '\n')))
    {
        *line_end = '\0';
        map[i++] = strdup(line_start);
        line_start = line_end + 1;
    }
    if (*line_start)
        map[i++] = strdup(line_start);
    map[i] = NULL;
    game->height = i;
    if (game->height == 0)
    {
        write(2, "Erro: O mapa está vazio.\n", 26);
        free(map);
        exit(1);
    }
    game->width = strlen(map[0]);
    for (i = 1; i < game->height; i++)
    {
        if (strlen(map[i]) != (size_t)game->width)
        {
            write(2, "Erro: O mapa não é retangular.\n", 32);
            free_map(map);
            exit(1);
        }
    }
    return (map);
}

void free_map(char **map)
{
    int i = 0;
    while (map[i])
        free(map[i++]);
    free(map);
}

int count_collectibles(char **map)
{
    int x = 0, y = 0, count = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}
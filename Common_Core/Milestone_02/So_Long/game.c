/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:31:53 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 19:21:20 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void init_game(t_game *g, char *map_path)
{
    g->width = 800;  // Set the window width
    g->height = 600; // Set the window height
    g->moves = 0;    // Initialize the step counter
    g->mlx = mlx_init();
    g->map = read_map(map_path, g);
    g->total_collectibles = count_collectibles(g->map);
    g->collected = 0;
    g->moves = 0;
    g->game_over = 0;   

    for (int y = 0; g->map[y]; y++)
        for (int x = 0; g->map[y][x]; x++)
            if (g->map[y][x] == 'P')
            {
                g->player_x = x;
                g->player_y = y;
            }

    g->win = mlx_new_window(g->mlx, g->width * TILE, g->height * TILE, "Baús do Guerreiro");
    g->enemy_count = 0;
    for (int y = 0; g->map[y]; y++)
        for (int x = 0; g->map[y][x]; x++)
            if (g->map[y][x] == 'I')
                g->enemy_count++;
    g->enemies = malloc(sizeof(t_enemy) * g->enemy_count);
    int i = 0;
    for (int y = 0; g->map[y]; y++)
        for (int x = 0; g->map[y][x]; x++)
            if (g->map[y][x] == 'I')
            {
                g->enemies[i].x = x;
                g->enemies[i].y = y;
                g->enemies[i].direction = 0; // Inicialmente movendo para cima
                i++;
            }
    load_images(g);
    render_map(g);
}

int close_game(t_game *g)
{
    free_map(g->map);
    exit(0);
    return (0);
}

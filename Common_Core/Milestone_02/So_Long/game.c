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
    load_images(g);
    render_map(g);
}

int close_game(t_game *g)
{
    free_map(g->map);
    exit(0);
    return (0);
}

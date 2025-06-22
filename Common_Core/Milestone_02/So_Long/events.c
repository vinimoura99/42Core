/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:32:20 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 18:32:21 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void move_player(t_game *g, int dx, int dy, int dir)
{
    int nx = g->player_x + dx;
    int ny = g->player_y + dy;
    if (g->map[ny][nx] == '1') return;

    if (g->map[ny][nx] == 'C')
    {
        g->collected++;
        g->map[ny][nx] = '0';
    }
    if (g->map[ny][nx] == 'E' && g->collected == g->total_collectibles)
    {
        mlx_clear_window(g->mlx, g->win);
        draw_tile(g, g->img_victory, 0, 0);
        g->game_over = 1;
        return;
    }
    g->player_x = nx;
    g->player_y = ny;
    g->player_dir = dir;
    g->moves++;
    render_map(g);
}

int handle_key(int key, t_game *g)
{
    if (key == 65307) // ESC
        close_game(g);
    if (g->game_over)
        return (0);
    if (key == 'w')
        move_player(g, 0, -1, 0);
    else if (key == 's')
        move_player(g, 0, 1, 1);
    else if (key == 'a')
        move_player(g, -1, 0, 2);
    else if (key == 'd')
        move_player(g, 1, 0, 3);
    return (0);
}

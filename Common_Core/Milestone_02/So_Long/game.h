/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:27:31 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 19:19:04 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define TILE 64
// Direções do jogador (para o array img_player)
# define DIR_DOWN  0
# define DIR_UP    1
# define DIR_LEFT  2
# define DIR_RIGHT 3

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collected;
    int     total_collectibles;
    int     moves;
    int     game_over;

    // Imagens
    void    *img_wall;
    void    *img_floor;
    void    *img_player[4];
    void    *img_chest;
    void    *img_door_closed;
    void    *img_door_open;
    void    *img_victory;

    int     player_dir;
}   t_game;

void    init_game(t_game *game, char *map_path);
void    render_map(t_game *game);
void    load_images(t_game *game);
void    draw_tile(t_game *game, void *img, int x, int y);
int     handle_key(int key, t_game *game);
int     close_game(t_game *game);
char    **read_map(char *file, t_game *game);
void    free_map(char **map);
int     count_collectibles(char **map);
int ft_printf(const char *format, ...);

#endif
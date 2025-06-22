/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:32:10 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 19:19:28 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // Para perror

// Função auxiliar para carregar uma imagem e verificar erros
static void	*load_single_texture(t_game *game, char *path)
{
    void	*img;
    int		width;
    int		height;

    img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
    if (!img)
    {
        write(2, "Erro: Falha ao carregar textura: ", 33);
        write(2, path, strlen(path));
        write(2, "\n", 1);
        // Aqui você deve chamar uma função para limpar a memória antes de sair
        exit(EXIT_FAILURE);
    }
    return (img);
}

/*
** Carrega todas as imagens do jogo, usando os campos da sua struct t_game.
** Chame esta função no seu main, logo após mlx_init().
*/
void	load_images(t_game *game)
{
    game->img_wall = load_single_texture(game, "assets/wall.xpm");
    game->img_floor = load_single_texture(game, "assets/floor.xpm");
    game->img_chest = load_single_texture(game, "assets/chest.xpm");
    game->img_door_closed = load_single_texture(game, "assets/door_closed.xpm");
    game->img_door_open = load_single_texture(game, "assets/door_open.xpm");
    game->img_victory = load_single_texture(game, "assets/victory.xpm");

    // Carrega as imagens do jogador no array
    game->img_player[DIR_DOWN] = load_single_texture(game, "assets/player_down.xpm");
    game->img_player[DIR_UP] = load_single_texture(game, "assets/player_up.xpm");
    game->img_player[DIR_LEFT] = load_single_texture(game, "assets/player_left.xpm");
    game->img_player[DIR_RIGHT] = load_single_texture(game, "assets/player_right.xpm");

    // Define a direção inicial do jogador
    game->player_dir = DIR_DOWN;
}
void draw_tile(t_game *g, void *img, int x, int y)
{
    mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

void render_map(t_game *g)
{
    int x, y;

    for (y = 0; g->map[y]; y++)
    {
        for (x = 0; g->map[y][x]; x++)
        {
            draw_tile(g, g->img_floor, x, y);
            if (g->map[y][x] == '1')
                draw_tile(g, g->img_wall, x, y);
            else if (g->map[y][x] == 'C')
                draw_tile(g, g->img_chest, x, y);
            else if (g->map[y][x] == 'E')
            {
                if (g->collected == g->total_collectibles)
                    draw_tile(g, g->img_door_open, x, y);
                else
                    draw_tile(g, g->img_door_closed, x, y);
            }
        }
    }
    draw_tile(g, g->img_player[g->player_dir], g->player_x, g->player_y);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoura-d <vmoura-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:27:18 by vmoura-d          #+#    #+#             */
/*   Updated: 2025/06/22 18:31:04 by vmoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_printf("\033[0;31mUso: ./baus_do_guerreiro <mapa.ber>\n\033[0m");
        return (1);
    }
    init_game(&game, argv[1]);
    mlx_hook(game.win, 2, 1L<<0, handle_key, &game);
    mlx_hook(game.win, 17, 0L, close_game, &game);
    mlx_loop(game.mlx);
    return (0);
}
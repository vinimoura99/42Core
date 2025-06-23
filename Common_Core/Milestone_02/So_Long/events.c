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
#include <time.h>


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

int move_enemies(void *param)
{
    static clock_t last_move = 0; // Armazena o tempo da última movimentação
    clock_t current_time = clock(); // Tempo atual

    // Definir intervalo de movimentação (em segundos)
    double interval = 0.5; // Movimentar a cada 0.5 segundos

    if (((double)(current_time - last_move) / CLOCKS_PER_SEC) < interval)
        return 0; // Não movimentar ainda

    last_move = current_time; // Atualizar o tempo da última movimentação

    t_game *g = (t_game *)param; // Converter o parâmetro para t_game *

    for (int i = 0; i < g->enemy_count; i++)
    {
        int nx = g->enemies[i].x;
        int ny = g->enemies[i].y;

        // Determinar a direção do movimento
        if (g->enemies[i].direction == 0) ny--; // Cima
        else if (g->enemies[i].direction == 1) ny++; // Baixo
        else if (g->enemies[i].direction == 2) nx--; // Esquerda
        else if (g->enemies[i].direction == 3) nx++; // Direita

        // Verificar colisões com paredes ou armadilhas
        if (g->map[ny][nx] != '1' && g->map[ny][nx] != 'T') // Não pode passar por paredes ou armadilhas
        {
            g->enemies[i].x = nx;
            g->enemies[i].y = ny;
        }
        else
        {
            // Alterar direção ao colidir
            g->enemies[i].direction = rand() % 4; // Escolher uma nova direção aleatória
        }

        // Verificar colisão entre jogador e inimigo
        if (g->enemies[i].x == g->player_x && g->enemies[i].y == g->player_y)
        {
            write(1, "Você foi atingido por um inimigo! Game Over.\n", 45);
            exit(EXIT_FAILURE);
        }
    }

    // Renderizar o mapa novamente para atualizar a posição dos inimigos
    render_map(g);

    // Retornar 0 para satisfazer a assinatura exigida pelo MiniLibX
    return 0;
}

int handle_key(int keycode, t_game *g)
{
    if (keycode == 65307) // Tecla ESC para sair
        exit(EXIT_SUCCESS);

    int dx = 0, dy = 0;

    // Determinar direção do movimento
    if (keycode == 119 || keycode == 65362) // W ou seta para cima
    {
        dy = -1;
        g->player_dir = DIR_UP; // Atualizar direção para cima
    }
    else if (keycode == 115 || keycode == 65364) // S ou seta para baixo
    {
        dy = 1;
        g->player_dir = DIR_DOWN; // Atualizar direção para baixo
    }
    else if (keycode == 97 || keycode == 65361) // A ou seta para esquerda
    {
        dx = -1;
        g->player_dir = DIR_LEFT; // Atualizar direção para esquerda
    }
    else if (keycode == 100 || keycode == 65363) // D ou seta para direita
    {
        dx = 1;
        g->player_dir = DIR_RIGHT; // Atualizar direção para direita
    }

    int nx = g->player_x + dx;
    int ny = g->player_y + dy;

    // Verificar colisão com paredes
    if (g->map[ny][nx] == '1')
        return 0;

    // Verificar colisão com inimigos
    for (int i = 0; i < g->enemy_count; i++)
    {
        if (g->enemies[i].x == nx && g->enemies[i].y == ny)
        {
            write(1, "Você foi atingido por um inimigo! Game Over.\n", 45);
            exit(EXIT_FAILURE);
        }
    }

    // Verificar colisão com baús (collectibles)
    if (g->map[ny][nx] == 'C')
    {
        g->collected++;
        g->map[ny][nx] = '0'; // Remover o baú do mapa
    }

    // Verificar colisão com a porta
    if (g->map[ny][nx] == 'E' && g->collected == g->total_collectibles)
    {
        write(1, "Você venceu! Parabéns!\n", 23);
        exit(EXIT_SUCCESS); // Finalizar o jogo com sucesso
    }

    // Atualizar posição do jogador
    g->player_x = nx;
    g->player_y = ny;
    g->moves++;

    // Renderizar o mapa novamente
    render_map(g);

    return 0;
}


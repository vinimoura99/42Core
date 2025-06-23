#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char **map, int **visited, int x, int y, int width, int height)
{
    // Verificar limites do mapa
    if (x < 0 || y < 0 || x >= width || y >= height)
        return;

    // Verificar se já foi visitado ou se é uma parede ou armadilha
    if (visited[y][x] || map[y][x] == '1' || map[y][x] == 'T')
        return;

    // Marcar como visitado
    visited[y][x] = 1;

    // Explorar os vizinhos (cima, baixo, esquerda, direita)
    dfs(map, visited, x, y - 1, width, height); // Cima
    dfs(map, visited, x, y + 1, width, height); // Baixo
    dfs(map, visited, x - 1, y, width, height); // Esquerda
    dfs(map, visited, x + 1, y, width, height); // Direita
}

void validate_map(t_game *g)
{
    int player_count = 0;
    int collectible_count = 0;
    int exit_count = 0;
    int x, y;

    int width = strlen(g->map[0]);
    int height = 0;
    while (g->map[height])
        height++;

    // Verificar elementos do mapa
    for (y = 0; g->map[y]; y++)
    {
        for (x = 0; g->map[y][x]; x++)
        {
            if (g->map[y][x] == 'P')
                player_count++;
            else if (g->map[y][x] == 'C')
                collectible_count++;
            else if (g->map[y][x] == 'E')
                exit_count++;
            else if (g->map[y][x] != '1' && g->map[y][x] != '0' &&
                     g->map[y][x] != 'T' && g->map[y][x] != 'I') // Adicionar 'I' como válido
            {
                write(2, "Erro: Mapa contém caracteres inválidos.\n", 40);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Verificar se há exatamente um personagem
    if (player_count != 1)
    {
        write(2, "Erro: O mapa deve conter exatamente um personagem ('P').\n", 56);
        exit(EXIT_FAILURE);
    }

    // Verificar se há pelo menos um collectible
    if (collectible_count < 1)
    {
        write(2, "Erro: O mapa deve conter pelo menos um collectible ('C').\n", 57);
        exit(EXIT_FAILURE);
    }

    // Verificar se há pelo menos uma porta
    if (exit_count < 1)
    {
        write(2, "Erro: O mapa deve conter pelo menos uma porta ('E').\n", 52);
        exit(EXIT_FAILURE);
    }

    // Verificar conectividade
    int **visited = malloc(height * sizeof(int *));
    for (y = 0; y < height; y++)
        visited[y] = calloc(width, sizeof(int));

    // Encontrar a posição inicial do jogador ('P')
    int player_x = -1, player_y = -1;
    for (y = 0; g->map[y]; y++)
    {
        for (x = 0; g->map[y][x]; x++)
        {
            if (g->map[y][x] == 'P')
            {
                player_x = x;
                player_y = y;
                break;
            }
        }
    }

    // Executar DFS a partir da posição do jogador
    dfs(g->map, visited, player_x, player_y, width, height);

    // Verificar se todos os collectibles e a porta foram alcançados
    for (y = 0; g->map[y]; y++)
    {
        for (x = 0; g->map[y][x]; x++)
        {
            if ((g->map[y][x] == 'C' || g->map[y][x] == 'E') && !visited[y][x])
            {
                write(2, "Erro: O jogador não consegue alcançar todos os elementos.\n", 58);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Liberar memória
    for (y = 0; y < height; y++)
        free(visited[y]);
    free(visited);
}
#ifndef	LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	int	width;
	int	height;
	int	**board;
} t_board;

typedef struct
{
	int 	x;
	int	y;
	int	pen_down;
} t_pen;

t_board	*create_board(int width, int height);
void	free_board(t_board *board);
void	draw_commands(t_board *board, char *commands);
void	simulate_life(t_board *board, int iterations);
void	print_board(t_board *board);

int	count_neighbors(t_board *board, int x, int y);
void	game_step(t_board *board);

#endif

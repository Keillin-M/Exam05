#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct { int x, y, draw; } Pen;

char **create_board(int w, int h) {
    char **b = malloc(h * sizeof(char*));
    for (int i = 0; i < h; i++) {
        b[i] = malloc(w);
        for (int j = 0; j < w; j++) 
			b[i][j] = ' ';
    }
    return b;
}

void free_board(char **b, int h) {
    for (int i = 0; i < h; i++) 
		free(b[i]);
    free(b);
}

int count_neighbors(char **b, int y, int x, int w, int h) {
    int c = 0;
    for (int dy = -1; dy <= 1; dy++) {
		for (int dx = -1; dx <= 1; dx++) {
        	if ((dx || dy) && y+dy >= 0 && y+dy < h && x+dx >= 0 && x+dx < w && b[y+dy][x+dx] == 'O') 
				c++;
		}
	}
    return c;
}

void iter_game(char **b, int w, int h) {
    char **nb = create_board(w, h);
    for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
        	int n = count_neighbors(b, y, x, w, h);
        	if (b[y][x] == 'O' ? (n == 2 || n == 3) : n == 3) 
				nb[y][x] = 'O';
   		}
	}
    for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) 
			b[y][x] = nb[y][x];
	}
    free_board(nb, h);
}

void print_board(char **b, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) 
			putchar(b[i][j]);
        putchar('\n');
    }
}

int main(int ac, char **av) {
    if (ac != 4) return 1;
    int w = atoi(av[1]), h = atoi(av[2]), it = atoi(av[3]);
    char **b = create_board(w, h), cmd;
    Pen p = {0, 0, 0};
    while (read(0, &cmd, 1) > 0) {
        if (cmd == 'w' && p.y > 0) 
			p.y--;
        else if (cmd == 's' && p.y < h-1) 
			p.y++;
        else if (cmd == 'a' && p.x > 0) 
			p.x--;
        else if (cmd == 'd' && p.x < w-1) 
			p.x++;
        else if (cmd == 'x') 
			p.draw = !p.draw;
        if (p.draw && (cmd == 'w' || cmd == 'a' || cmd == 's' || cmd == 'd' || cmd == 'x')) 
			b[p.y][p.x] = 'O';
    }
    print_board(b, w, h);
    for (int i = 0; i < it; i++) 
		iter_game(b, w, h);
    print_board(b, w, h);
    free_board(b, h);
    return 0;
}

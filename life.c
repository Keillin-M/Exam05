#include "life.h"

t_board *create_board(int width, int height)
{
    t_board *board = malloc(sizeof(t_board));
    if (!board)
        return NULL;

    board->width = width;
    board->height = height;
    board->board = malloc(height * sizeof(int *));
    if (!board->board)
    {
        free(board);
        return NULL;
    }

    for (int i = 0; i < height; i++)
    {
        board->board[i] = calloc(width, sizeof(int));
        if (!board->board[i])
        {
            for (int j = 0; j < i; j++)
                free(board->board[j]);
            free(board->board);
            free(board);
            return NULL;
        }
    }
    return board;
}

void free_board(t_board *board)
{
    if (board)
    {
        if (board->board)
        {
            for (int i = 0; i < board->height; i++)
                free(board->board[i]);
            free(board->board);
        }
        free(board);
    }
}

void draw_commands(t_board *board, char *commands)
{
    t_pen pen = {0, 0, 0};

    for (int i = 0; commands[i]; i++)
    {
        char cmd = commands[i];

        if (cmd == 'x')
        {
            pen.pen_down = !pen.pen_down;
            if (pen.pen_down)
                board->board[pen.y][pen.x] = 1;
        }
        else if (cmd == 'w' && pen.y > 0)
        {
            pen.y--;
            if (pen.pen_down)
                board->board[pen.y][pen.x] = 1;
        }
        else if (cmd == 's' && pen.y < board->height - 1)
        {
            pen.y++;
            if (pen.pen_down)
                board->board[pen.y][pen.x] = 1;
        }
        else if (cmd == 'a' && pen.x > 0)
        {
            pen.x--;
            if (pen.pen_down)
                board->board[pen.y][pen.x] = 1;
        }
        else if (cmd == 'd' && pen.x < board->width - 1)
        {
            pen.x++;
            if (pen.pen_down)
                board->board[pen.y][pen.x] = 1;
        }
    }
}

int count_neighbors(t_board *board, int x, int y)
{
    int count = 0;

    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < board->width && ny >= 0 && ny < board->height)
                count += board->board[ny][nx];
        }
    }
    return count;
}

void game_step(t_board *board)
{
    int **new_board = malloc(board->height * sizeof(int *));
    for (int i = 0; i < board->height; i++)
        new_board[i] = calloc(board->width, sizeof(int));

    for (int y = 0; y < board->height; y++)
    {
        for (int x = 0; x < board->width; x++)
        {
            int neighbors = count_neighbors(board, x, y);
            int current = board->board[y][x];

            if (current && (neighbors == 2 || neighbors == 3))
                new_board[y][x] = 1;
            else if (!current && neighbors == 3)
                new_board[y][x] = 1;
        }
    }

    for (int i = 0; i < board->height; i++)
    {
        free(board->board[i]);
        board->board[i] = new_board[i];
    }
    free(new_board);
}

void simulate_life(t_board *board, int iterations)
{
    for (int i = 0; i < iterations; i++)
        game_step(board);
}

void print_board(t_board *board)
{
    for (int y = 0; y < board->height; y++)
    {
        for (int x = 0; x < board->width; x++)
            putchar(board->board[y][x] ? 'O' : ' ');
        putchar('\n');
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);

    if (width <= 0 || height <= 0 || iterations < 0)
        return 1;

    t_board *board = create_board(width, height);
    if (!board)
        return 1;

    char buffer[10000];
    int len = 0;
    char c;
    while (read(0, &c, 1) > 0 && len < 9999)
        buffer[len++] = c;
    buffer[len] = '\0';

    draw_commands(board, buffer);
    simulate_life(board, iterations);
    print_board(board);
    free_board(board);
    return 0;
}

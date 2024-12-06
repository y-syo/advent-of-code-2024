#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"

typedef struct s_state{
    int x;
	int y;
    char direction;
} t_state;

typedef struct s_coord{
    int x;
	int y;
} t_coord;

char	**cpy_grid(char **grid)
{
	char	**new;

	new = calloc(sizeof(char *), 131);
	for (int i = 0; grid[i]; i++)
		new[i] = strdup(grid[i]);
	return (new);
}

int	has_visited(t_state *visited, int count, int x, int y, char direction) {
    for (int i = 0; i < count; i++)
        if (visited[i].x == x && visited[i].y == y && visited[i].direction == direction)
            return (1);
    return (0);
}

int	add_solution(t_coord *solutions, int count, int x, int y)
{
	for (int i = 0; i < count; i++)
		if (solutions[i].x == x && solutions[i].y == y)
			return (0);
	return (1);
}

int	check_ray(char **old_grid, int x, int y, char dir)
{
	int old_x = x;
	int old_y = y;
	int c = 0;

	char **grid = cpy_grid(old_grid);
	t_state *visited = ft_calloc(sizeof(t_state), (strlen(grid[0]) * strlen(grid[0])) * 4);
	int visited_index = 0;

	switch (dir)
	{
	case '^':
		if (grid[y][x - 1] == '^')
			grid[y - 1][x - 1] = '^';
		grid[y][x - 1] = '#';
		break;
	case '>':
		if (grid[y - 1][x] == '^')
			grid[y - 2][x] = '^';
		grid[y - 1][x] = '#';
		break;
	case 'v':
		if (grid[y][x + 1] == '^')
			grid[y - 1][x + 1] = '^';
		grid[y][x + 1] = '#';
		break;
	case '<':
		if (grid[y][x] == '^')
			grid[y][x] = '^';
		grid[y + 1][x] = '#';
		break;
	}

	for (int i = 0; grid[i]; i++)
	{
		for (int j = 0; grid[i][j]; j++)
		{
			if (grid[i][j] == '^')
			{
				x = j;
				y = i;
				goto next_check_ray;
			}
		}
	}
next_check_ray:

	
	for(;;)
	{
		switch (grid[y][x])
		{
			case '^':
				if (y == 0 || y == (strlen(grid[0]) - 1))
					return (0);

				if (grid[y - 1][x] == '#')
					grid[y][x] = '>';
				else
				{
					grid[y - 1][x] = '^';
					y--;
				}
				break;
			case '>':
				if (x == 0 || x == (strlen(grid[0]) - 1))
					return (0);

				if (grid[y][x + 1] == '#')
					grid[y][x] = 'v';
				else
				{
					grid[y][x + 1] = '>';
					x++;
				}
				break;
			case 'v':
				if (y == 0 || y == (strlen(grid[0]) - 1))
					return (0);

				if (grid[y + 1][x] == '#')
					grid[y][x] = '<';
				else
				{
					grid[y + 1][x] = 'v';
					y++;
				}
				break;
			case '<':
				if (x == 0 || x == (strlen(grid[0] - 1)))
					return (0);

				if (grid[y][x - 1] == '#')
					grid[y][x] = '^';
				else
				{
					grid[y][x - 1] = '<';
					x--;
				}
				break;
		}
		if (has_visited(visited, visited_index, x, y, grid[y][x]))
			return (1);
		visited[visited_index++] = (t_state){x, y, grid[y][x]};
	}
}

int	main(void)
{
	char	*content, **grid;
	int	fd;

	if ((fd = open("./input.txt", O_RDONLY)) > 0)
	{
		content = calloc(sizeof(char), 17030);
		read(fd, content, 17029);
	}
	else
	{
		content = "....#.....\n.........#\n..........\n..#.......\n.......#..\n..........\n.#..^.....\n........#.\n#.........\n......#...";
	}
	grid = ft_split(content, '\n');

	char **clean_grid = cpy_grid(grid);
	t_coord *solutions = calloc(sizeof(t_coord), strlen(grid[0]) * strlen(grid[0]));
	int	solutions_index = 0;
	int x, y = 0;

	for (int i = 0; grid[i]; i++)
	{
		for (int j = 0; grid[i][j]; j++)
		{
			if (grid[i][j] == '^')
			{
				x = j;
				y = i;
				goto next;
			}
		}
	}
next:
	for(;;)
	{
		switch (grid[y][x]) {
			case '^':
				grid[y][x] = '+';
				while (y != 0 && y != (strlen(grid[0]) - 1) && grid[y - 1][x] != '#')
				{
					if (grid[y][x] == '.')
						grid[y][x] = '^';
					else
						grid[y][x] = '+';
					if(check_ray(clean_grid, x, y, '>'))
						if (add_solution(solutions, solutions_index, x, y - 1))
							solutions[solutions_index++] = (t_coord){x, y - 1};
					//res += check_ray(clean_grid, x, y, '>');
					y--;
				}
				if (y == 0 || y == (strlen(grid[0]) - 1))
				{
					printf("%d\n", solutions_index);
					return (0);
				}
				if (grid[y - 1][x] == '#')
					grid[y][x] = '>';
				break;


			case '>':
				grid[y][x] = '+';
				while (x != 0 && x != (strlen(grid[0]) - 1) && grid[y][x + 1] != '#')
				{
					if (grid[y][x] == '.')
						grid[y][x] = '>';
					else
						grid[y][x] = '+';
					if(check_ray(clean_grid, x, y, 'v'))
						if (add_solution(solutions, solutions_index, x + 1, y))
							solutions[solutions_index++] = (t_coord){x + 1, y};
					//res += check_ray(clean_grid, x, y, 'v');
					x++;
				}
				if (x == 0 || x == (strlen(grid[0]) - 1))
				{
					printf("%d\n", solutions_index);
					return (0);
				}
				if (grid[y][x + 1] == '#')
				{
					grid[y][x] = 'v';
				}
				break;


			case 'v':
				grid[y][x] = '+';
				while (y != 0 && y != (strlen(grid[0]) - 1) && grid[y + 1][x] != '#')
				{
					if (grid[y][x] == '.')
						grid[y][x] = 'v';
					else
						grid[y][x] = '+';
					if(check_ray(clean_grid, x, y, '<'))
						if (add_solution(solutions, solutions_index, x, y + 1))
							solutions[solutions_index++] = (t_coord){x, y + 1};
					//res += check_ray(clean_grid, x, y, '<');
					y++;
				}
				if (y == 0 || y == (strlen(grid[0]) - 1))
				{
					printf("%d\n", solutions_index);
					return (0);
				}
				if (grid[y + 1][x] == '#')
				{
					grid[y][x] = '<';
				}
				break;


			case '<':
				grid[y][x] = '+';
				while (x != 0 && x != (strlen(grid[0]) - 1) && grid[y][x - 1] != '#')
				{
					if (grid[y][x] == '.')
						grid[y][x] = '<';
					else
						grid[y][x] = '+';
					if(check_ray(clean_grid, x, y, '^'))
						if (add_solution(solutions, solutions_index, x - 1, y))
							solutions[solutions_index++] = (t_coord){x - 1, y};
					//res += check_ray(clean_grid, x, y, '^');
					x--;
				}
				if (x == 0 || x == (strlen(grid[0] - 1)))
				{
					printf("%d\n", solutions_index);
					return (0);
				}
				if (grid[y][x - 1] == '#')
				{
					grid[y][x] = '^';
				}
				break;


		}
		//for (int i = 0; grid[i]; i++)
		//	printf("%s\n", grid[i]);
		//printf("\n\n");
	}
}

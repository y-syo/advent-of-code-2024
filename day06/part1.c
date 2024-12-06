#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"

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
	//for (int i = 0; grid[i]; i++)
	//	printf("%s\n", grid[i]);
	
	int res, x, y = 0;

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
				if (y == 0 || y == (strlen(grid[0]) - 1))
				{
					res++;
					printf("%d\n", res);
					return (0);
				}

				if (grid[y - 1][x] == '#')
					grid[y][x] = '>';
				else
				{
					res += grid[y - 1][x] == '.';
					grid[y - 1][x] = '^';
					grid[y][x] = 'X';
					y--;
				}
				break;
			case '>':
				if (x == 0 || x == (strlen(grid[0]) - 1))
				{
					res++;
					printf("%d\n", res);
					return (0);
				}

				if (grid[y][x + 1] == '#')
				{
					grid[y][x] = 'v';
				}
				else
				{
					res += grid[y][x + 1] == '.';
					grid[y][x + 1] = '>';
					grid[y][x] = 'X';
					x++;
				}
				break;
			case 'v':
				if (y == 0 || y == (strlen(grid[0]) - 1))
				{
					res++;
					printf("%d\n", res);
					return (0);
				}

				if (grid[y + 1][x] == '#')
				{
					grid[y][x] = '<';
				}
				else
				{
					res += grid[y + 1][x] == '.';
					grid[y + 1][x] = 'v';
					grid[y][x] = 'X';
					y++;
				}
				break;
			case '<':
				if (x == 0 || x == (strlen(grid[0] - 1)))
				{
					res++;
					printf("%d\n", res);
					return (0);
				}

				if (grid[y][x - 1] == '#')
				{
					grid[y][x] = '^';
				}
				else
				{
					res += grid[y][x - 1] == '.';
					grid[y][x - 1] = '<';
					grid[y][x] = 'X';
					x--;
				}
				break;
		}
	}
}

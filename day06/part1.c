#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int	free_list(char **result, int j)
{
	while (j)
	{
		free(result[j]);
		j--;
	}
	return (1);
}

static int	word_counter(const char *str, char ch)
{
	int	i;
	int	c;
	int	bool_c;

	i = 0;
	c = 0;
	bool_c = 1;
	while (str[i])
	{
		if (str[i] == ch)
		{
			bool_c = 1;
		}
		else if (str[i] != ch && bool_c)
		{
			c++;
			bool_c = 0;
		}
		i++;
	}
	return (c);
}

static int	per_word_fill(char **result, const char *str, char ch)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (str[i])
	{
		c = 0;
		while (str[i] != ch && str[i])
		{
			c++;
			i++;
		}
		if (c != 0)
		{
			result[j] = calloc(sizeof(char), c + 1);
			if (result[j++] == NULL)
				return (free_list(result, j - 2));
		}
		if (str[i])
			i++;
	}
	result[j] = NULL;
	return (0);
}

static void	ft_split_resolver(char **result, const char *str, char ch)
{
	int	i;
	int	j;
	int	wi;
	int	bool_w;

	i = 0;
	j = 0;
	wi = 0;
	bool_w = 0;
	while (str[i])
	{
		if (str[i] == ch && bool_w)
		{
			bool_w = 0;
			wi = 0;
			j++;
		}
		else if (str[i] != ch)
		{
			bool_w = 1;
			result[j][wi] = str[i];
			wi++;
		}
		i++;
	}
}

char	**ft_split(const char *str, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (word_counter(str, c) + 1));
	if (result == NULL)
		return (NULL);
	if (per_word_fill(result, str, c))
		return (NULL);
	ft_split_resolver(result, str, c);
	return (result);
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

/* + - + - + - +  - + - + - + - + - + - + */
/*    --- Day 5: Binary Boarding ---      */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day05.c ../libft/libft.a

#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

char	*free_null(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

int	 calc(char *line, int higher, int lower, int limit)
{
	int	 i = 0;
	int	 ret = 0;

	while (line[i] && i < limit)
	{
		if (line[i] == 'F' || line[i] == 'L')
		{
			ret = (higher + lower) / 2;
			higher = ret;
		}
		else if (line[i] == 'B' || line[i] == 'R')
		{
			ret = (higher+ lower) / 2 + 1;
			lower = ret;
		}
		i++;
	}
	return (ret);
}

int	 calculate_id_value(char *line)
{
	int	 id_value = 0;
	int	 row = 0;
	int	 column = 0;
	int	 row_hig = 127;
	int	 row_low = 0;
	int	 row_num = 7;
	int	 col_hig = 7;
	int	 col_low = 0;
	int	 col_num = 3;

	row = calc(line, row_hig, row_low, row_num);
	column = calc(line + row_num, col_hig, col_low, col_num);
	return (id_value = row * 8 + column);
}

int		main(int argc, char **argv)
{
	int			fd = open(argv[1], O_RDONLY);
	char		*line = NULL;
	int		 highest = 0;
	int		 id = 0;

	if (argc != 2)
	{
		printf("You should put a file in argument\n");
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		id = calculate_id_value(line);
		if (id > highest)
			highest = id;
		line = free_null(line);
	}
	printf("%d is the highest seat ID\n", highest);
	line = free_null(line);
//	system("leaks a.out");
	return (0);
}
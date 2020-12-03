/* + - + - + - +  - + - + - + - + - + - + */
/*   --- Day 3: Toboggan Trajectory ---   */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day03.c ../libft/libft.a

#include <stdio.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

char	*free_null(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

int		is_tree(char *line, int index)
{
	if (line[index] == '#')
		return (1);
	return (0);
}

int		main()
{
	int		fd = open("input", O_RDONLY);
	char	*line;
	int		tree = 0;
	int		index = 0;

	while (get_next_line(fd, &line))
	{
		if (is_tree(line, index))
			tree++;
		index += 3;
		if (index >= ft_strlen(line))
			index = index - ft_strlen(line);
		line = free_null(line);
	}
	line = free_null(line);
	printf("There is %d trees\n", tree);
//	system("leaks a.out");
	return (0);
}

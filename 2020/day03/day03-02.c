/* + - + - + - +  - + - + - + - + - + - + */
/*   --- Day 3: Toboggan Trajectory ---   */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day03-02.c ../libft/libft.a

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

int		how_many_tree(int tree, int move, int code)
{
	int		fd = open("input", O_RDONLY);
	char	*line;
	int		index = 0;
	int		line_count = 0;

	while (get_next_line(fd, &line))
	{
		if (((line_count % 2 == 0) && code) || !code)
		{
			if (is_tree(line, index))
				tree++;
			index += move;
		}
		if (index >= ft_strlen(line))
			index = index - ft_strlen(line);
		line = free_null(line);
		line_count++;
	}
	line = free_null(line);
	printf("There is %d trees for move = %d, %d line skip\n", tree, move, code);
	return (tree);
}

int		main(void)
{
	int		tree = 0;
	long long int		total = 0;

	tree = how_many_tree(tree, 1, 0);
	total = tree;	

	tree = 0;
	tree = how_many_tree(tree, 3, 0);
	total = total * tree;

	tree = 0;
	tree = how_many_tree(tree, 5, 0);
	total = total * tree;

	tree = 0;
	tree = how_many_tree(tree, 7, 0);
	total = total * tree;

	tree = 0;
	tree = how_many_tree(tree, 1, 1);
	total = total * tree;

	printf("There is %lld trees\n", total);
//	system("leaks a.out");
	return (0);
}

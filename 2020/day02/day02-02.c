/* + - + - + - +  - + - + - + - + - + - + */
/*   Find how many passwords are valid    */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day02-02.c ../libft/libft.a

#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

char	*free_null(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

typedef struct	s_string
{
	int		first;
	int		second;
	char	c;
	char	*psswrd;
}				t_str;

void	init_s(t_str *s)
{
	s->first = 0;
	s->second = 0;
	s->c = '\0';
	s->psswrd = NULL;
}

void	set_numbers(char *line, t_str *s)
{
	char	*first;
	char	*second;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_isdigit(line[i]))
		i++;
	first = ft_substr(line, 0, i);
	if (line[i] == '-')
		i++;
	j = i;
	while (ft_isdigit(line[i]) || line[i] != ' ')
		i++;
	i -= 2;
	second = ft_substr(line, j, i);
	s->first = ft_atoi(first);
	s->second = ft_atoi(second);
	first = free_null(first);
	second = free_null(second);
}

void	set_c_and_str(char *line, t_str *s)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (line[i] && line[i] != ':')
		i++;
	s->c = line[i - 1];
	i += 2;
	k = i;
	while (line[k])
		k++;
	tmp = ft_substr(line, i, k + 1);
	s->psswrd = ft_strdup(tmp);
	tmp = free_null(tmp);
}

int		is_valid(char *line, t_str *s)
{
	int i = 0;
	int count = 0;
	set_numbers(line, s);
	set_c_and_str(line, s);

	if ((s->psswrd[s->first - 1] == s->c && s->psswrd[s->second - 1] != s->c)
		|| s->psswrd[s->first - 1] != s->c && s->psswrd[s->second - 1] == s->c)
		return (1);
	else
		return (0);
}

int		main(void)
{
	int		fd;
	char	*line;
	int		valid_psswrd;
	t_str	s;
/*	int		ret = 1;							// To check if the input is correctly read*/

	init_s(&s);
	fd = open("input", O_RDONLY);
	valid_psswrd = 0;
	while (get_next_line(fd, &line))
	{
/*		printf("line num %d: %s\n", ret, line);
		ret++;									// To check if the input is correctly read*/
		if (is_valid(line, &s))
			valid_psswrd++;
		s.psswrd = free_null(s.psswrd);
		line = free_null(line);
	}
	printf("Valid passwords: %d\n", valid_psswrd);
	s.psswrd = free_null(s.psswrd);
	line = free_null(line);
	system("leaks a.out");
	return (0);
}
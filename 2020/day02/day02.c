/* + - + - + - +  - + - + - + - + - + - + */
/*   Find how many passwords are valid    */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day02.c ../libft/libft.a

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
	int		start;
	int		end;
	char	c;
	char	*psswrd;
}				t_str;

void	init_s(t_str *s)
{
	s->start = 0;
	s->end = 0;
	s->c = '\0';
	s->psswrd = NULL;
}

void	set_numbers(char *line, t_str *s)
{
	char	*start;
	char	*end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_isdigit(line[i]))
		i++;
	start = ft_substr(line, 0, i);
	if (line[i] == '-')
		i++;
	j = i;
	while (ft_isdigit(line[i]) || line[i] != ' ')
		i++;
	i -= 2;
	end = ft_substr(line, j, i);
	s->start = ft_atoi(start);
	s->end = ft_atoi(end);
	start = free_null(start);
	end = free_null(end);
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

	while (s->psswrd[i])
	{
		if (s->psswrd[i] == s->c)
			count++;
		i++;
	}
	if (count < s->start || count > s->end)
		return (0);
	else
		return (1);	
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
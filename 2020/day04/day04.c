/* + - + - + - +  - + - + - + - + - + - + */
/*   --- Day 4: Passport Processing ---   */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day04.c ../libft/libft.a

#include <fcntl.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

char	*free_null(char *str)
{
	if (str != NULL)
		free(str);
	return (NULL);
}

typedef struct	s_pssprt
{
	int		byr;
	int		iyr;
	int		eyr;
	int		hgt;
	int		hcl;
	int		ecl;
	int		pid;
	int		cid;
}				t_pssprt;

void	init_passeport(t_pssprt *p)
{
	p->byr = 0;
	p->iyr = 0;
	p->eyr = 0;
	p->hgt = 0;
	p->hcl = 0;
	p->ecl = 0;
	p->pid = 0;
	p->cid = 0;
}

int		is_valid_passport()
{

	return (0);
}

int		main(int argc, char **argv)
{
	int			fd = open(argv[1], O_RDONLY);
	char		*line = NULL;
	int			pssport = 0;
	t_pssprt	p;

	if (argc != 2)
	{
		printf("You should put a file in argument\n");
		return (-1);
	}
	init_passeport(&p);
	while (get_next_line(fd, &line))
	{
		if (*line == '\0')
		{
			if (p.byr && p.ecl && p.eyr && p.hcl && p.hgt && p.iyr && p.pid)
				pssport++;		
			init_passeport(&p);
		}
		if (ft_strnstr(line, "byr", ft_strlen(line)))
			p.byr = 1;
		if (ft_strnstr(line, "ecl", ft_strlen(line)))
			p.ecl = 1;
		if (ft_strnstr(line, "eyr", ft_strlen(line)))
			p.eyr = 1;
		if (ft_strnstr(line, "hcl", ft_strlen(line)))
			p.hcl = 1;
		if (ft_strnstr(line, "hgt", ft_strlen(line)))
			p.hgt = 1;
		if (ft_strnstr(line, "iyr", ft_strlen(line)))
			p.iyr = 1;
		if (ft_strnstr(line, "pid", ft_strlen(line)))
			p.pid = 1;
		line = free_null(line);
	}
	if (p.byr && p.ecl && p.eyr && p.hcl && p.hgt && p.iyr && p.pid)
		pssport++;
	printf("There is %d valid passeports\n", pssport);
	line = free_null(line);
//	system("leaks a.out");
	return (0);
}
/* + - + - + - +  - + - + - + - + - + - + */
/*   --- Day 4: Passport Processing ---   */
/* + - + - + - +  - + - + - + - + - + - + */

// To compil with libft: clang day04-02.c ../libft/libft.a

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

void	check_byr(char *line, t_pssprt *p, int i)
{
	int		byr = 0;
	char	*tmp;

//	printf("line %s\n",line);
	while (line[i] != ':')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line));
	byr = ft_atoi(tmp);
	tmp = free_null(tmp);
	if (byr >= 1920 && byr <= 2002)
	    p->byr = 1;
//	printf("byr %d\n",p->byr);
}

void	check_iyr(char *line, t_pssprt *p, int i)
{
	int		iyr = 0;
	char	*tmp;

//	printf("line %s\n",line);
	while (line[i] != ':')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line));
	iyr = ft_atoi(tmp);
	tmp = free_null(tmp);
	if (iyr >= 2010 && iyr <= 2020)
	    p->iyr = 1;
//	printf("iyr %d\n",p->iyr);
}

void	check_eyr(char *line, t_pssprt *p, int i)
{
	int		eyr = 0;
	char	*tmp;

//	printf("line %s\n",line);
	while (line[i] != ':')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line));
	eyr = ft_atoi(tmp);
	tmp = free_null(tmp);
	if (eyr >= 2020 && eyr <= 2030)
		p->eyr = 1;
//	printf("eyr %d\n",p->eyr);
}

void	check_ecl(char *line, t_pssprt *p, int i)
{
	while(line[i] != ':')
		i++;
	i++;
//	printf("line %s\n",line);
	if (ft_strncmp("amb", line + i, 3) == 0 || ft_strncmp("blu", line + i, 3) == 0 || \
	ft_strncmp("brn", line + i, 3) == 0 || ft_strncmp("gry", line + i, 3) == 0 || \
	ft_strncmp("grn", line + i, 3) == 0 || ft_strncmp("hzl", line + i, 3) == 0 || \
	ft_strncmp("oth", line + i, 3) == 0)
		p->ecl = 1;
//	printf("ecl %d\n",p->ecl);
}

void	check_pid(char *line, t_pssprt *p, int i)
{
	int		count = 0;

	while (line[i] != ':')
		i++;
	i++;
//	printf("line %s\n",line);
	while (ft_isdigit(line[i]))
	{
		i++;
		count++;
	}
	if (count == 9)
		p->pid = 1;
//	printf("pid %d\n",p->pid);
}

void	check_hcl(char *line, t_pssprt *p, int i)
{
	int		count = 0;

//	printf("line %s\n",line);
	while (line[i] != ':')
		i++;
	i++;
	if (line[i] == '#')
	{
		i++;
		while (ft_isalpha(line[i]) || ft_isalnum(line[i]))
		{
			count++;
			i++;
		}
		if (count == 6)
			p->hcl = 1;
	}
//	printf("hcl %d\n",p->hcl);
}

void	check_hgt(char *line, t_pssprt *p, int i)
{
	int		hgt = 0;

//	printf("line %s\n",line);
	while(line[i] != ':')
		i++;
	i++;
	hgt = ft_atoi(line + i);
	while(!ft_isalpha(line[i]) && line[i])
		i++;
	if (hgt >= 150 && hgt <= 193)
	{
		if (line[i] && line[i + 1] && ft_strncmp("cm", line + i, 2) == 0)
			p->hgt = 1;
	}
	else if (hgt >= 59 && hgt <= 76)
	{
		if (line[i] && line[i + 1] && ft_strncmp("in", line + i, 2) == 0)
			p->hgt = 1;
	}
//	printf("hgt %d\n",p->hgt);
}

void	check_field(char *line, t_pssprt *p)
{
	int		i = 0;

	while(line[i] && line[i + 2])
	{
		if (line[i] == 'b' && line[i + 1] == 'y' && line[i + 2] == 'r')
			check_byr(line, p, i);
		else if (line[i] == 'i' && line[i + 1] == 'y' && line[i + 2] == 'r')
			check_iyr(line, p, i);
		else if (line[i] == 'e' && line[i + 1] == 'y' && line[i + 2] == 'r')
			check_eyr(line, p, i);
		else if (line[i] == 'h' && line[i + 1] == 'g' && line[i + 2] == 't')
			check_hgt(line, p, i);
		else if (line[i] == 'h' && line[i + 1] == 'c' && line[i + 2] == 'l')
			check_hcl(line, p, i);
		else if (line[i] == 'e' && line[i + 1] == 'c' && line[i + 2] == 'l')
			check_ecl(line, p, i);
		else if (line[i] == 'p' && line[i + 1] == 'i' && line[i + 2] == 'd')
			check_pid(line, p, i);
		i++;
	}
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
		if (line[0] == '\0')
		{
			if (p.byr && p.ecl && p.eyr && p.hcl && p.hgt && p.iyr && p.pid)
				pssport++;		
			init_passeport(&p);
		}
		check_field(line, &p);
		line = free_null(line);
	}
	if (p.byr && p.ecl && p.eyr && p.hcl && p.hgt && p.iyr && p.pid)
		pssport++;
	printf("There is %d valid passeports\n", pssport);
	line = free_null(line);
//	system("leaks a.out");
	return (0);
}
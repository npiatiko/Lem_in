#include "lemin.h"

int ft_isnbr(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return 1;
}
int main()
{
//	ft_printf("%.20f", 9.2);

	char **words;
	char *line;
	int ants;
	char typeroom;

	ants = 0;
	typeroom = 'n';
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isnbr(line))
		{
			ants = ft_atoi(line);
			free(line);
			continue;
		}
		if (line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue;
		}
		if (ft_strncmp(line, "##", 2))
		{
			typeroom = (char)(ft_strequ(line, "##start") ? 's' : 'n');
			typeroom = (char)(ft_strequ(line, "##end") ? 'e' : typeroom);
			free(line);
			continue;
		}
	}
	return 0;
}
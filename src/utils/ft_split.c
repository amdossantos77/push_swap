#include "../../include/push_swap.h"

int	delimeter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ft_split(char *str)
{
	int		x;
	int		y;
	int		len;
	char	**matriz;

	y = 0;
	while (*str && delimeter(*str))
		str++;
	len = ft_strlen(str);
	while (str[len])
		len++;
	matriz = malloc(sizeof(char *) * (len + 1));
	while (*str)
	{
		x = 0;
		matriz[y] = malloc(sizeof(char *) * (len + 1));
		while (*str && !delimeter(*str))
			matriz[y][x++] = *(str++);
		while (*str && delimeter(*str))
			str++;
		matriz[y++][x] = '\0';
	}
	matriz[y] = NULL;
	return (matriz);
}

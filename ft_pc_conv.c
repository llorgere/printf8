#include "libftprintf.h"

char	*ft_pc_conv()
{
	char	*tab;

	if(!(tab = malloc(sizeof(char) * 2)))
		return (NULL);
	tab[0] = '%';
	tab[1] = '\0';
	return (tab);
}

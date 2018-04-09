#include "libftprintf.h"

int		main(void)
{
	unsigned char	c;
	unsigned int	i;
	char			*tab = NULL;
	char			*tmp = NULL;
	
	i = 531;
	//c = 0xe1;
	//write(1, &c, 1);
	//c = 0x88;
	//write(1, &c, 1);
	c = 200;
	write(1, &c, 1);
	c = 131;
	write(1, &c, 1);
	tab = ft_uitoa_bin(i);
	ft_putstr(tab);
	tmp = ft_uniconv(tab);
	ft_putstr(tmp);
	free(tmp);
	free(tab);
	return (0);
}

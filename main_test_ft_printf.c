#include "libftprintf.h"
#include <stdio.h>
int		main(void)
{
	int		a = -48963155;
	short int	b = -32767;
	char	c = -125;
	ssize_t	d = -9223372036854775807;
	char *e = "Salut Les Copains";
	char f = 'a';
	long long g = -3;
//	printf("e est %s", e);
	ft_printf("le test de printf a[%-15.12u] b[%hu] c[%hhd] d[%jd] e[%#10s] f[%c] g[%lld]\n", a, b, c, d, e, f, g);
	return (0);
}

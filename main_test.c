#include <stdio.h>
//#include <stdlib.h>
#include "libftprintf.h"
/*char	**ft_watinit(const char *arg0, int sizetab);
int		ft_size_tab(const char *str);
char	*ft_strndup(const char *s, size_t n);
*/
int		main(void)
{
//	const char	*str = "salut les %d copains %.+3d dwadi %%%d awd %deyt";
//	const char	*str = "salut les % hZ  copains %.+3d dwadi %%%d awd %deyt";
	const char	*str = "{%05}";
//	const char	*str = "salut les copains";
	int			st;
//	char		**tab;
	wii			wtest;
	int 		i;
//	char	*tmp;

//	tmp = str;
	i = 0;
	st = 0;
	printf("debut de la fct\n");
	st = ft_size_tab(str);
	printf("st est %d\n", st);
	wtest = ft_watinit(str, st);
	printf("watinit bien passe dans le main\n");
	while (wtest.tab[i])
	{
		printf("[%s]\n", wtest.tab[i]);
		i++;
	}
	printf("test de nb_conv [%d]\n", wtest.nb_conv);
	i = 0;
	printf("test de pos_conv\n");
	while (wtest.pos_conv[i] != -1)
	{
		printf("[%d]", wtest.pos_conv[i]);
		i++;
	}
	printf("\nfin test de pos_conv\n");
	free(wtest.tab);
	free(wtest.pos_conv);
	return (0);
}

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
/*char	**ft_watinit(const char *arg0, int sizetab);
//int		ft_size_tab(const char *str);
char	*ft_strndup(const char *s, size_t n);
*/
int		ft_size_tab(const char *str)
{
	int		i;
	int		sizetab;
	const char	*tmp;

//		while (tmp[i] != '%' && tmp[i] != '\0')
	i = 0;
	tmp = str;
	sizetab = 0;
//	printf("test de ft_size_tab 1 et arg0 est [%s]\n", tmp);
	while (tmp[i] != '\0')
	{
//		printf("test de ft_size_tab 2 et arg0 est [%s]\n", tmp);
		while (tmp[i] != '%' && tmp[i] != '\0')
		{
//			printf("test de ft_size_tab 2.1 et arg0 est [%s]\n", tmp);
			i++;
			if (tmp[i] == '\0' || tmp[i] == '%')
			{
				sizetab++;
	//			printf("test sizetab 1\n");
			}
//			printf("test de ft_size_tab 2.2 et arg0 est [%c] et sizetab est %d\n", tmp[i], sizetab);
		}
//		printf("test de ft_size_tab 3 et arg0[i] = [%c], sizetab = [%d]\n", tmp[i], sizetab);
		if (tmp[i] == '\0')
		{
//			printf("test de ft_size_tab 4\n");
			return (sizetab);
		}
		else if (tmp[i] == '%')
		{
//			printf("test de ft_size_tab 6\n");
			i++;
			while (tmp[i] != 'd' && tmp[i] != 'i' && tmp[i] != 's' && tmp[i] != 'p' && tmp[i] != 'S' && tmp[i] !='D' && tmp[i] !='U' && tmp[i] !='O' && tmp[i] != 'o' && tmp[i] !='u' && tmp[i] !='x' && tmp[i] !='X' && tmp[i] !='c' && tmp[i] !='C'  && tmp[i] !='\0' && tmp[i] != '%')
			{
//				printf("test de ft_size_tab 6.1 et tmp[i] est [%c]\n", tmp[i]);
				if (tmp[i] == '+' || tmp[i] == ' ' || tmp[i] == '#' || tmp[i] == '-' || tmp[i] == '.' || (tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == 'h' || tmp[i] == 'j' || tmp[i] == 'z' || tmp[i] == 'l')
					i++;
				else
				{
					i++;
					while (tmp[i] != '\0' && tmp[i] != '%')
						i++;
					if(tmp[i] == '%')
						i--;
					break;
				}
		//		printf("test de ft_size_tab 6.2 et tmp[i] est [%c]\n", tmp[i]);
			}
/*			if(tmp[i] == '%');
				i++;
			printf("test de ft_size_tab 7\n");
*/			sizetab++;
	//		printf("sizetab 2\n");
			if(tmp[i] == '\0')
				return (sizetab);
			i++;
		}
		else 
		{
			i++;
//			printf("test de size_tab 8.1 incre de fin\n");
		}
//		printf("test de ft_size_tab 8\n");
	}
//	printf("test de ft_size_tab 9 sizetab est %d\n", sizetab);
	return (sizetab);
}

/*		else if (tmp[i] == '%' && tmp[i + 1] == '%')
		{
//			printf("test de ft_size_tab 5\n");
			i = i + 2;
			sizetab++;
		}
*/

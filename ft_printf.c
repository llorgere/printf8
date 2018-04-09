#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			j;
	flag_type	flag;
	wii			wiit;
	char		*cur_arg = (char *)format;
	int			ret;
	char		*ret_tab;
	char		*tmp;
	char		*tmp_wide;
	int			ret_wide;
	spe_c		spec;
	
	ret_wide = 0;
	tmp_wide = NULL;
	ret = 0;
	ret_tab = NULL;
	i = 0;
	if (format == NULL)
		return (-1);
	wiit = ft_watinit(format, ft_size_tab(format));
//	printf("test de watinit, sizetab est %d\n", ft_size_tab(format));
	va_start(ap, format);
	while(wiit.tab[i])
	{
/*		if (wiit.pos_conv[i] == 0)
		{
			ret = ret + ft_strlen(wiit.tab[i]);
			ft_putstr(wiit.tab[i]);
			free(wiit.tab[i]);
		}
*///		printf("test des boucles 1 et tmp_wide est [%s] et ret_wide [%d]\n", tmp_wide, ret_wide);
		if (wiit.pos_conv[i] == 0)
		{
	//		printf("test des boucles 2\n");
			ret = ret + ft_strlen(wiit.tab[i]);
			if(!ret_tab)
				ret_tab = ft_strdup(wiit.tab[i]);
			else
			{
	//			printf("test des boucles 2.1\n");
				if(!(tmp = malloc(sizeof(char) * ret + 1)))
					return (0);
	//			printf("test des boucles 2.15 ret_tab est [%s] et wiit.tab[i] est [%s] ret-len(wiit.tab) est [%lu] et ret est [%d]\n", ret_tab, wiit.tab[i], ret - ft_strlen(wiit.tab[i]), ret);
/*				tmp = ft_strcpy(tmp, ret_tab);
				tmp = ft_strcat(tmp, wiit.tab[i]);
*/				tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(wiit.tab[i]), ret + 1);
	//			printf("test des boucles 2.2\n");
				tmp = ft_strncatpf(tmp, wiit.tab[i], ret - ft_strlen(wiit.tab[i]), ft_strlen(wiit.tab[i]));
	//			printf("test des boucles 2.3 tmp est [%s]\n", tmp);
				free(ret_tab);
				ret_tab = tmp;
	//			printf("test des boucles 2.4\n");
//				free(wiit.tab[i]);
			//	free(tmp);
	//			printf("test des boucles 2.5\n");
			}
			free(wiit.tab[i]);
	//		printf("test des boucles 3 ret_tab est [%s]\n", ret_tab);
		}
		else if (wiit.pos_conv[i] == 1)
		{
//			printf("wiit.tab[i] est [%s]", wiit.tab[i]);
	//		printf("test des boucles 4\n");
			flag = ft_arg_conv(wiit.tab[i]); 
//			printf("test des valeurs des flags\ncn : [%d] | wi : [%d] | pr : [%d] | - : [%d] | + : [%d] | # : [%d] | 0 : [%d] | sp : [%d] | . : [%d] |\n", flag.conv_num, flag.width, flag.preci, flag.minus, flag.plus, flag.dies, flag.zero, flag.space, flag.point);
			cur_arg = ft_what_type(flag.conv_num, ap, &flag);
	//		printf("wiit.tab[i] est [%s]", wiit.tab[i]);
	//		printf("cur_arg[i] est [%s]", cur_arg);
//			printf("cur_arg est [%c%c]", cur_arg[0], cur_arg[1]);
		//	printf("str est [%s]\n", cur_arg);
		//	printf("flag.w est [%d] && cura_arg[flag.w - 1] est [%c]\n", flag.W, cur_arg[flag.W - 1]);
	/*		if(flag.conv_num == -1)
			{
//				printf("1 l'argument est [%s]\n", cur_arg);
				if (flag.tab == NULL)
					cur_arg = ft_strdup(wiit.tab[i]);
				else
				{
					cur_arg = ft_strdup(flag.tab);
					free(flag.tab);
				}
				ret = ret + ft_strlen(cur_arg) ;
				ft_putstr(cur_arg);
//				free(cur_arg);
			}
			printf("test des boucles 5 et cur_arg est [%s]\n", cur_arg);
	*/		if(flag.conv_num == -1)
			{
//				printf("1 l'argument est [%s]\n", cur_arg);
//				printf("test des boucles 6\n");
				if (flag.tab == NULL)
					cur_arg = ft_strdup(wiit.tab[i]);
				else
				{
					cur_arg = ft_strdup(flag.tab);
					free(flag.tab);
				}
				ret = ret + ft_strlen(cur_arg) ;
				if(!ret_tab)
				{
					ret_tab = ft_strdup(cur_arg);
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
				//	tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret);
				//	tmp = ft_strncatpf(tmp, cur_arg, ret, ft_strlen(cur_arg));
					tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret + 1);
//					printf("test des boucles 6.2\n");
					tmp = ft_strncatpf(tmp, cur_arg, ret - ft_strlen(cur_arg), ft_strlen(cur_arg));
//					printf("test des boucles 6.3 tmp est [%s]\n", tmp);
					free(ret_tab);
					ret_tab = tmp;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				//	free(tmp);
				}
			//	ft_putstr(cur_arg);
//				free(cur_arg);
			}
			else if ((flag.W > -1 && flag.preci == -1) || (flag.W > -1 && flag.preci > flag.W))
			{
//				printf("test des boucles 7\n");
				free(cur_arg);
	//			i++;
				while(wiit.tab[i])
				{
					free(wiit.tab[i]);
					i++;
				}
			//	free(wiit.tab[i]);
				va_end(ap);
				free(wiit.pos_conv);
				free(wiit.tab);
				free(ret_tab);
				if(tmp_wide != NULL)
				{
					ft_nputstr(tmp_wide, ret_wide);
					free(tmp_wide);
				}
	//			free (tmp_wide);
		//		return (ret);
				return (-1);
			}
		/*	else if (flag.conv_num == 6 || flag.conv_num == 14)
			{
//				printf("2 l'argument est [%s]\n", cur_arg);
				spec = ft_special_c(cur_arg, flag);
				if(!(spec.tab))
					return (-1);
				ft_nputstr(spec.tab, spec.len);
				ret = ret + spec.len;
				if(flag.width > 1)
					free(spec.tab);
//				free(cur_arg);
			}
		*/	else if (flag.conv_num == 6 || flag.conv_num == 14)
			{
//				printf("2 l'argument est [%s]\n", cur_arg);
//				printf("test des boucles 8\n");
				spec = ft_special_c(cur_arg, flag);
				if(!(spec.tab))
					return (-1);
//				ft_nputstr(spec.tab, spec.len);
				ret = ret + spec.len;
				if(!ret_tab)
				{
					j = 0;
					if(!(ret_tab = malloc(sizeof(char) * ret + 1)))
						return (0);
					while (j <= ret)
					{
						ret_tab[j] = spec.tab[j];
						j++;
					}
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
					if(tmp_wide != NULL)
						free(tmp_wide);
			//		tmp_wide = ret_tab;
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
				//	ret_tab = cur_arg;
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
				/*	tmp = ft_strncpypf(tmp, ret_tab, ret - spec.len, ret);
					tmp = ft_strncatpf(tmp, cur_arg, ret, spec.len);
					ret_tab = tmp;
					free(tmp);
//				*/	tmp = ft_strncpypf(tmp, ret_tab, ret - spec.len, ret + 1);
//					printf("test des boucles 8.2\n");
					tmp = ft_strncatpf(tmp, spec.tab, ret - spec.len, spec.len);
//					printf("test des boucles 8.3 tmp est [%s]\n", tmp);
					free(ret_tab);
					ret_tab = tmp;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
				}
//				if(flag.width > 1)
					//free(spec.tab);
		//		free(spec.tab);
//				free(cur_arg);
			}
			else
			{
//	//		printf("3 l'argument est [%s]\n", cur_arg);
//				printf("test des boucles 9\n");
				cur_arg = ft_flag_use(cur_arg, flag);
	//			printf("9.1 l'argument est [%s]\n", cur_arg);
				ret = ret + ft_strlen(cur_arg);

				//ft_putstr(cur_arg);
				if(!ret_tab)
				{
	//			printf("9.14 l'argument est [%s]\n", ret_tab);
					if(flag.conv_num == 0 || cur_arg == NULL)
						ret_tab = NULL;
					else
					{
						ret_tab = ft_strdup(cur_arg);
			//			tmp_wide = ret_tab;
						if(tmp_wide != NULL)
							free(tmp_wide);
						tmp_wide = ft_nstrdup(ret_tab, ret);
						ret_wide = ret;
					}
	//			printf("9.15 l'argument est [%s]\n", ret_tab);
				}
				else
				{
					if(!(tmp = malloc(sizeof(char) * ret + 1)))
						return (0);
			/*		tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret);
					tmp = ft_strncatpf(tmp, cur_arg, ret, ft_strlen(cur_arg));
					ret_tab = tmp;
					free(spec.tab);
			*/		tmp = ft_strncpypf(tmp, ret_tab, ret - ft_strlen(cur_arg), ret + 1);
//					printf("test des boucles 9.2\n");
					tmp = ft_strncatpf(tmp, cur_arg, ret - ft_strlen(cur_arg), ft_strlen(cur_arg));
//					printf("test des boucles 9.3 tmp est [%s]\n", tmp);
					free(ret_tab);
					ret_tab = tmp;
				//	tmp_wide = ret_tab;
					if(tmp_wide != NULL)
						free(tmp_wide);
					tmp_wide = ft_nstrdup(ret_tab, ret);
					ret_wide = ret;
			//		free(tmp);
				}
//				printf("9.2 l'argument est [%s]\n", ret_tab);
//				free(cur_arg);
			}
/*			if (flag.conv_num == 6 || 14)
			{
				ft_nputstr(spec.tab, spec.len);
				ret = ret + spec.len;
				free(spec.tab);
			}
			else 
			{
				ret = ret + ft_strlen(cur_arg) ;
				ft_putstr(cur_arg);
				free(cur_arg);
			}
*///			printf("4 l'argument est [%s]\n", cur_arg);
			free(cur_arg);
//			printf("9.3 l'argument est [%s] et wiit.tab[i] est [%s]\n", ret_tab, wiit.tab[i]);
			free(wiit.tab[i]);
//			printf("9.4 l'argument est [%s]\n", ret_tab);
		}
//		printf("9.5 l'argument est [%s]\n", ret_tab);
		i++;
	}
	va_end(ap);
	free(wiit.pos_conv);
	free(wiit.tab);
	if(tmp_wide != NULL)
		free(tmp_wide);
	ft_nputstr(ret_tab, ret);
	free(ret_tab);
	return (ret);
}

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <inttypes.h>
# include <stddef.h>
# include <sys/types.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <limits.h>

typedef struct
{
	int				pos_conv;
	char			**tab;
	int				sizetab;
}					conv_type;
typedef struct
{
	int				nb_conv;
	int				*pos_conv;
	char			**tab;
}					wii;
typedef struct
{
	int				conv_num;
	int				width;
	int				preci;
	int				minus;
	int				plus;
	int				dies;
	int				zero;
	int				space;
	int				point;
	int				h;
	int				j;
	int				z;
	int				l;
	char			*tab;
	int				W;
}					flag_type;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct
{
	int		len;
	char	*tab;
}					spe_c;

unsigned char		*ft_uniconv(char *bin);
char				*ft_uitoa_bin(unsigned int n);
char				*ft_nstrdup(const char *s, size_t n);
spe_c				ft_special_c(char *str, flag_type flag);
void				ft_nputstr(char const *s, int n);
char				*ft_strduppf(const char	*s);
char				*ft_pc_conv();
char				*ft_add_preci_empty();
char				*ft_add_plus(char *str, int len);
char				*ft_add_space(char *str, int len);
char				*ft_add_dies_o(char *str, int len);
char				*ft_add_dies_x(char *str, int len);
char				*ft_add_dies_X(char *str, int len);
char				*ft_add_dies(char *str, flag_type flag, int len);
char				*ft_addw(char *str, flag_type flag, int len);
char				*ft_addw0(char *str, flag_type flag, int len);
char				*ft_addwmin(char *str, flag_type flag, int len);
char				*ft_addwf(char *str, flag_type flag, int len);
char				*ft_winopr(char *str, flag_type flag, int len);
char				*ft_nowipr(char *str, flag_type flag, int len);
char				*ft_nowinopr(char *str, flag_type flag, int len);
char				*ft_wipr(char *str, flag_type flag, int len);
char				*ft_flag_use(char *str, flag_type flag);
flag_type			ft_flag_adjust(flag_type flag);
int					ft_printf(const char *format, ...);
flag_type			ft_arg_conv(char *tab);
char				*ft_what_type(int n, va_list ap, flag_type* flag);
char				*ft_strndup(const char *s, size_t n);
wii					ft_watinit(const char *arg0, int sizetab);
int					ft_size_tab(const char *str);
int					ft_what_conv(char *str);
int					ft_three_conv(char *str);
int					ft_two_conv(char *str);
int					ft_one_conv(char *str);
int					ft_two_j_conv(char *str);
int					ft_two_z_conv(char *str);
int					ft_two_h_conv(char *str);
int					ft_two_l_conv(char *str);
int					ft_three_l_conv(char *str);
int					ft_three_h_conv(char *str);
char				*ft_ctoa(char n);
char				*ft_litoa(long int n);
char				*ft_llitoa(long long int n);
char				*ft_imtoa(intmax_t n);
char				*ft_sitoa(short int n);
char				*ft_ssttoa(ssize_t n);
char				*ft_ch_to_hex_low(unsigned char n);
char				*ft_ch_to_hex_up(unsigned char n);
char				*ft_ch_to_octal(unsigned char n);
char				*ft_uctoa(unsigned char n);
char				*ft_uimtoa(uintmax_t n);
char				*ft_uim_to_hex_low(uintmax_t n);
char				*ft_uim_to_hex_up(uintmax_t n);
char				*ft_uim_to_octal(uintmax_t n);
char				*ft_int_to_octal(unsigned int n);
char				*ft_uitoa(unsigned int n);
char				*ft_int_to_hex_up(unsigned int n);
char				*ft_int_to_hex_low(unsigned int n);
char				*ft_lg_to_octal(unsigned long int n);
char				*ft_lg_to_hex_low(unsigned long int n);
char				*ft_lg_to_hex_up(unsigned long int n);
char				*ft_luitoa(unsigned long int n);
char				*ft_lluitoa(unsigned long long int n);
char				*ft_llg_to_octal(unsigned long long int n);
char				*ft_llg_to_hex_up(unsigned long long int n);
char				*ft_llg_to_hex_low(unsigned long long int n);
char				*ft_sh_to_octal(unsigned short int n);
char				*ft_sh_to_hex_low(unsigned short int n);
char				*ft_sh_to_hex_up(unsigned short int n);
char				*ft_suitoa(unsigned short int n);
char				*ft_sttoa(size_t n);
char				*ft_st_to_hex_up(size_t n);
char				*ft_st_to_hex_low(size_t n);
char				*ft_st_to_octal(size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strduppf(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strncpypf(char *dest, char *src, size_t n, size_t m);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t nb);
char				*ft_strncatpf(char *dest, const char *src, size_t lend, size_t lens);
size_t				ft_strlcat(char	*dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_chardup(unsigned char s);
char				*ft_wchardup(wchar_t *s, flag_type *flag);
char				*ft_wintdup(wchar_t s, flag_type *flag);
char				*ft_p_conv(long long unsigned int s);

#endif

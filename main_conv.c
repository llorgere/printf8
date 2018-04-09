#include <stdio.h>
#include <stdlib.h>
char	*ft_dec_to_oct(unsigned int dec);
char	*ft_dec_to_hex_up(unsigned int dec);
char	*ft_dec_to_hex_low(unsigned int dec);
int		main(void)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;
	char	*A;
	char	*B;
	char	*C;
	char	*D;
	char	*E;
	char	*F;

	a = 511;
	b = 512;
	c = 4095;
	d = 4096;
	e = 4095;
	f = 4096;

	printf("avant conversion : a est %d et b est %d\n", a, b);
	printf("avant conversion : c est %d et d est %d\n", c, d);
	printf("avant conversion : e est %d et f est %d\n", e, f);
	A = ft_dec_to_oct(a);
	B = ft_dec_to_oct(b);
	C = ft_dec_to_hex_up(c);
	D = ft_dec_to_hex_up(d);
	E = ft_dec_to_hex_low(e);
	F = ft_dec_to_hex_low(f);
	printf("apres conversion : a est [%s] et b est [%s]\n", A, B);
	printf("apres conversion : c est [%s] et d est [%s]\n", C, D);
	printf("apres conversion : c est [%s] et d est [%s]\n", E, F);
	free(A);
	free(B);
	free(C);
	free(D);
	free(E);
	free(F);
	return (0);
}
